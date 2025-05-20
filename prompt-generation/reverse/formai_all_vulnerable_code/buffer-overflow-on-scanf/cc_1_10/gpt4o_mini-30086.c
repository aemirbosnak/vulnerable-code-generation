//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_FILES 10
#define MAX_VIRUSES 5
#define BUFFER_SIZE 256

// Virus signatures
const char *virus_signatures[MAX_VIRUSES] = {
    "VIRUS_SIGNATURE_1",
    "MALWARE_SIG_ABC",
    "TROJAN_SUSPECT_123",
    "WORM_SIG_XYZ",
    "SPYWARE_SIG_QWE"
};

// Structure to hold file information
typedef struct {
    char filename[BUFFER_SIZE];
    int user_id;
} FileScanRequest;

// Function to simulate scanning a file for viruses
void *scan_file(void *arg) {
    FileScanRequest *request = (FileScanRequest *)arg;
    char buffer[BUFFER_SIZE];
    int found_virus = 0;

    // Open the file to scan
    FILE *file = fopen(request->filename, "r");
    if (file == NULL) {
        printf("User %d: Failed to open file %s\n", request->user_id, request->filename);
        return NULL;
    }

    printf("User %d: Scanning file %s...\n", request->user_id, request->filename);

    // Read file line by line
    while (fgets(buffer, BUFFER_SIZE, file)) {
        for (int i = 0; i < MAX_VIRUSES; i++) {
            if (strstr(buffer, virus_signatures[i])) {
                printf("User %d: Found virus signature in %s: %s\n", request->user_id, request->filename, virus_signatures[i]);
                found_virus = 1;
                break;
            }
        }
        if (found_virus) break; // Stop scanning if a virus is found
    }

    if (!found_virus) {
        printf("User %d: No virus found in file %s.\n", request->user_id, request->filename);
    }

    fclose(file);
    return NULL;
}

int main() {
    pthread_t threads[MAX_FILES];
    FileScanRequest requests[MAX_FILES];
    int num_files;

    printf("Antivirus Scanner - Multiplayer Mode\n");
    printf("Enter the number of files to scan (max %d): ", MAX_FILES);
    scanf("%d", &num_files);

    if (num_files > MAX_FILES || num_files <= 0) {
        printf("Invalid number of files. Exiting.\n");
        return -1;
    }

    // Input file names and assign user IDs
    for (int i = 0; i < num_files; i++) {
        printf("Enter filename for user %d: ", i + 1);
        scanf("%s", requests[i].filename);
        requests[i].user_id = i + 1;

        // Create a thread for each file scan
        if (pthread_create(&threads[i], NULL, scan_file, (void *)&requests[i]) != 0) {
            printf("Failed to create thread for user %d\n", requests[i].user_id);
            return -1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_files; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Scanning complete for all files.\n");
    return 0;
}
//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: portable
#include <stdio.h>
#include <string.h>

#define MAX_PATH_LENGTH 256
#define MAX_FILE_LENGTH 4096
#define SIGNATURE_SIZE 16
#define TRUE 1
#define FALSE 0

// Define virus signature
const char virus_signature[SIGNATURE_SIZE] = {0x55, 0x48, 0x89, 0xE5, 0x53, 0x83, 0xEC, 0x10, 0xC7, 0x44, 0x24, 0x04, 0x00, 0x00, 0x00, 0x00};

int scan_file(const char* filename) {
    FILE *file;
    char buffer[MAX_FILE_LENGTH];
    int buffer_len, scan_len, match;
    file = fopen(filename, "rb");
    if (file == NULL) {
        perror("fopen");
        return FALSE;
    }
    while ((buffer_len = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        scan_len = buffer_len - SIGNATURE_SIZE + 1;
        for (int i = 0; i < scan_len; ++i) {
            match = memcmp(buffer + i, virus_signature, SIGNATURE_SIZE);
            if (match == 0) {
                fclose(file);
                return TRUE;
            }
        }
    }
    fclose(file);
    return FALSE;
}

int scan_directory(const char *direc) {
    char path[MAX_PATH_LENGTH];
    snprintf(path, sizeof(path), "%s/*", direc);
    int has_virus = FALSE;
    FILE* fp;
    char full_path[MAX_PATH_LENGTH];
    if ((fp = popen(path, "r")) == NULL) {
        perror("popen");
        return FALSE;
    }
    while (fgets(full_path, MAX_PATH_LENGTH, fp) != NULL) {
        full_path[strlen(full_path) - 1] = '\0';
        if (strcmp(full_path, ".") == 0 || strcmp(full_path, "..") == 0) {
            continue;
        }
        if (scan_file(full_path) == TRUE) {
            printf("Virus detected in: %s\n", full_path);
            has_virus = TRUE;
        }
    }
    pclose(fp);
    return has_virus;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }
    int has_virus = scan_directory(argv[1]);
    if (has_virus == FALSE) {
        printf("No viruses found.\n");
    }
    return 0;
}
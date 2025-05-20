//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10240
#define MAX_SCAN_FILES 100

typedef struct {
    char name[256];
    int size;
} file_info;

// Function to scan a file for viruses
void scan_file(char *filename) {
    FILE *f;
    char buffer[MAX_FILE_SIZE];
    int size, i;
    f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Unable to open file %s for scanning\n", filename);
        return;
    }
    fseek(f, 0L, SEEK_END);
    size = ftell(f);
    fseek(f, 0L, SEEK_SET);
    fread(buffer, size, 1, f);
    for (i = 0; i < size - 4; i++) {
        if (buffer[i] == 'v' && buffer[i+1] == 'i' && buffer[i+2] == 'r' && buffer[i+3] == 'u' && buffer[i+4] == 's') {
            printf("Virus found in file %s\n", filename);
            fclose(f);
            return;
        }
    }
    fclose(f);
    printf("File %s is clean\n", filename);
}

int main() {
    file_info files[MAX_SCAN_FILES];
    int num_files = 0;
    char buffer[256];
    printf("C Antivirus Scanner\n");
    printf("-------------------\n");
    while (num_files < MAX_SCAN_FILES) {
        printf("Enter name of file to scan (or 'done' to finish): ");
        scanf("%s", buffer);
        if (strcmp(buffer, "done") == 0) {
            break;
        }
        else {
            strcpy(files[num_files].name, buffer);
            FILE *f = fopen(buffer, "rb");
            if (f == NULL) {
                printf("Unable to open file %s for scanning\n", buffer);
            }
            else {
                fseek(f, 0L, SEEK_END);
                files[num_files].size = ftell(f);
                fclose(f);
                num_files++;
            }
        }
    }
    printf("Scanning %d files...\n", num_files);
    for (int i = 0; i < num_files; i++) {
        scan_file(files[i].name);
    }
    printf("Scan complete\n");
    return 0;
}
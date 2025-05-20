//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 512
#define MAX_FILES 1000

typedef struct {
    char name[MAX_PATH_LENGTH];
    long size;
} File;

void surrealize(File *files, int count) {
    for (int i = 0; i < count; i++) {
        files[i].size = (files[i].size + (rand() % 50) - 25); // Add a twist to the size
        if (files[i].size < 0) {
            files[i].size = 0; // Files can't have negative sizes, they simply disappear!
        }
    }
}

void whisper_to_files(File *files, int count) {
    printf("\nWhispering sweet nothings to files...\n");
    for (int i = 0; i < count; i++) {
        printf("File: %s - Size: %ld bytes\n", files[i].name, files[i].size);
    }
}

void print_disk_report(File *files, int count) {
    long total_size = 0;
    printf("\nDisk Space Analysis Report:\n");
    for (int i = 0; i < count; i++) {
        printf("%s consumes the ghostly size of %ld bytes.\n", files[i].name, files[i].size);
        total_size += files[i].size;
    }
    printf("Total Size of all files: %ld bytes.\n", total_size);
}

void dance_of_the_files(File *files, int count) {
    printf("\nIt's a dance party!\n");
    for (int i = 0; i < count; i++) {
        if (files[i].size > 100) {
            printf("The file %s does a graceful pirouette!\n", files[i].name);
        } else {
            printf("The file %s sways gently in the breeze.\n", files[i].name);
        }
    }
}

void retrieve_files_from_ether(File *files, int *count) {
    FILE *disk = popen("ls -l | awk '{print $9, $5}'", "r");
    char buffer[MAX_PATH_LENGTH + 20];

    if (disk == NULL) {
        perror("Failed to run command");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof(buffer), disk) != NULL && *count < MAX_FILES) {
        sscanf(buffer, "%s %ld", files[*count].name, &files[*count].size);
        (*count)++;
    }
    pclose(disk);
}

int main() {
    File files[MAX_FILES];
    int count = 0;

    printf("Welcome to the Surreal Disk Space Analyzer.\n\n");
    retrieve_files_from_ether(files, &count);
    
    printf("The files have floated into existence:\n");
    for (int i = 0; i < count; i++) {
        printf("Found: %s with an ethereal size of %ld bytes.\n", files[i].name, files[i].size);
    }

    surrealize(files, count);
    whisper_to_files(files, count);
    print_disk_report(files, count);
    dance_of_the_files(files, count);

    printf("\nAs the day fades, the files take their leave...\n");

    return 0;
}
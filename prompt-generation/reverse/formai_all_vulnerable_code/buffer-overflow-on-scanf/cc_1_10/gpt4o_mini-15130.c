//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define SECTOR_SIZE 512
#define MAX_FILES 100
#define FILE_NAME_LENGTH 256

typedef struct {
    char name[FILE_NAME_LENGTH];
    unsigned long size;
    long start_sector;
} FileEntry;

void restore_file(const char* disk_image_path, FileEntry* file) {
    FILE *disk_image = fopen(disk_image_path, "rb");
    if (!disk_image) {
        perror("Failed to open disk image");
        return;
    }

    // Move to the start sector of the file
    fseek(disk_image, file->start_sector * SECTOR_SIZE, SEEK_SET);

    // Allocate buffer for the file data
    char *buffer = (char*)malloc(file->size);
    if (!buffer) {
        perror("Failed to allocate memory");
        fclose(disk_image);
        return;
    }

    // Read the file data
    fread(buffer, 1, file->size, disk_image);
    fclose(disk_image);

    // Create the file in the current directory
    FILE *output_file = fopen(file->name, "wb");
    if (!output_file) {
        perror("Failed to create output file");
        free(buffer);
        return;
    }

    // Write the data to the output file
    fwrite(buffer, 1, file->size, output_file);
    fclose(output_file);
    free(buffer);

    printf("Restored file: %s (Size: %lu bytes)\n", file->name, file->size);
}

void print_menu() {
    printf("\n--- Data Recovery Tool ---\n");
    printf("1. Restore File\n");
    printf("2. Exit\n");
    printf("Select an option: ");
}

int main() {
    char disk_image_path[FILE_NAME_LENGTH];
    FileEntry files[MAX_FILES];
    int file_count = 0;

    printf("Enter path to disk image: ");
    scanf("%s", disk_image_path);

    // Simulated file entries for demonstration
    strncpy(files[file_count].name, "recovered_file1.txt", FILE_NAME_LENGTH);
    files[file_count].size = 1024; // Let's assume it's 1024 bytes
    files[file_count].start_sector = 10; // Example starting sector
    file_count++;

    strncpy(files[file_count].name, "recovered_file2.txt", FILE_NAME_LENGTH);
    files[file_count].size = 2048; // Let's assume it's 2048 bytes
    files[file_count].start_sector = 20; // Example starting sector
    file_count++;

    while (1) {
        print_menu();
        int option;
        scanf("%d", &option);

        if (option == 1) {
            printf("Select file to restore (1 - %d): ", file_count);
            int file_index;
            scanf("%d", &file_index);
            if (file_index < 1 || file_index > file_count) {
                printf("Invalid file selection.\n");
                continue;
            }
            restore_file(disk_image_path, &files[file_index - 1]);
        } else if (option == 2) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
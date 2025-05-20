//FormAI DATASET v1.0 Category: File Backup System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to copy a file
void copy_file(char *src_file_path, char *dst_file_path) {
    FILE *src_fp, *dst_fp;
    char ch;

    // Open source file
    src_fp = fopen(src_file_path, "rb");
    if (src_fp == NULL) {
        printf("Error opening source file.\n");
        exit(EXIT_FAILURE);
    }

    // Open destination file in write mode
    dst_fp = fopen(dst_file_path, "wb");
    if (dst_fp == NULL) {
        printf("Error opening destination file.\n");
        fclose(src_fp);
        exit(EXIT_FAILURE);
    }

    // Copy contents of source file to destination file
    while ((ch = fgetc(src_fp)) != EOF) {
        fputc(ch, dst_fp);
    }

    // Close source and destination files
    fclose(src_fp);
    fclose(dst_fp);
}

int main() {
    char command[1000];
    char src_path[512], dst_path[512];
    int choice;

    // Loop through menu until user chooses to exit
    while (1) {
        printf("\n\nFile Backup System\n");
        printf("-------------------\n");
        printf("1. Backup a file\n");
        printf("2. Backup a directory\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            exit(EXIT_SUCCESS);
        } else if (choice == 1) {
            // Backup a file
            printf("\nEnter the source file path: ");
            scanf("%s", src_path);
            printf("Enter the destination file path: ");
            scanf("%s", dst_path);
            copy_file(src_path, dst_path);
            printf("\nBackup completed successfully!\n");
        } else if (choice == 2) {
            // Backup a directory
			printf("\nEnter the source directory path: ");
            scanf("%s", src_path);
            printf("Enter the destination directory path: ");
            scanf("%s", dst_path);
            strcpy(command, "cp -R ");
            strcat(command, src_path);
            strcat(command, " ");
            strcat(command, dst_path);
            system(command);
            printf("\nBackup completed successfully!\n");
        } else {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}
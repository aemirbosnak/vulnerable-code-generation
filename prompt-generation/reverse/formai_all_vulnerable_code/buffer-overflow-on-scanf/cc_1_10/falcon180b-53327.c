//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_FILE_SIZE 1000000

int main() {
    char file_name[MAX_FILE_NAME_LEN];
    FILE *fp;
    char ch;

    // Prompt user for file name
    printf("Enter file name: ");
    scanf("%s", file_name);

    // Open file for reading
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Create backup file name
    char backup_file_name[MAX_FILE_NAME_LEN];
    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, ".bak");

    // Open backup file for writing
    FILE *backup_fp = fopen(backup_file_name, "w");
    if (backup_fp == NULL) {
        printf("Error creating backup file.\n");
        exit(1);
    }

    // Read file and write to backup file
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            // Convert letter to uppercase
            ch = toupper(ch);
        }
        fputc(ch, backup_fp);
    }

    // Close files
    fclose(fp);
    fclose(backup_fp);

    // Print success message
    printf("Backup file created successfully.\n");

    return 0;
}
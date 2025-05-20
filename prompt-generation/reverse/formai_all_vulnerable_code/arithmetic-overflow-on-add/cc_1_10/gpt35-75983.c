//FormAI DATASET v1.0 Category: File Backup System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char file_name[50];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int day = tm.tm_mday;
    int month = tm.tm_mon + 1;
    int year = tm.tm_year + 1900;

    printf("Enter the name of the file to back up: ");
    scanf("%s", file_name);

    // Open original file in read mode
    FILE *original_file = fopen(file_name, "r");
    if (original_file == NULL) {
        printf("Error: cannot open file %s\n", file_name);
        return 1;
    }

    // Create a name for the backup file
    char backup_file_name[50];
    sprintf(backup_file_name, "%d-%d-%d_%s", year, month, day, file_name);

    // Open backup file in write mode
    FILE *backup_file = fopen(backup_file_name, "w+");
    if (backup_file == NULL) {
        printf("Error: cannot create backup file\n");
        fclose(original_file);
        return 1;
    }

    // Copy contents of the original file to the backup file
    char c = fgetc(original_file);
    while (c != EOF) {
        fputc(c, backup_file);
        c = fgetc(original_file);
    }

    printf("Backup created successfully as %s\n", backup_file_name);

    // Close files
    fclose(original_file);
    fclose(backup_file);

    return 0;
}
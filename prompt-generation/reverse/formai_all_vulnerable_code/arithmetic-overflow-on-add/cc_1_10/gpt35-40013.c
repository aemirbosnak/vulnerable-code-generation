//FormAI DATASET v1.0 Category: File Backup System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 100

// Function to generate random 10 character string
char* rand_string() {
    char* str = malloc(11);
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 10; i++) {
        int index = rand() % (sizeof(charset) - 1);
        str[i] = charset[index];
    }
    str[10] = '\0';
    return str;
}

int main() {
    srand(time(NULL)); // Initialize random seed

    char* backup_directory = "./backups/"; // Directory for backups
    char* filename = malloc(MAX_FILENAME_LENGTH); // Filename variable

    time_t t = time(NULL); // Get current time
    struct tm* current_time = localtime(&t); // Convert time to local time format

    // Create and open new backup file in write mode with current date and time in filename
    sprintf(filename, "%s%d_%d_%d_%d_%d_%d.txt", backup_directory, current_time->tm_year + 1900, current_time->tm_mon + 1, current_time->tm_mday, current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
    FILE* backup_file = fopen(filename, "w");

    if (backup_file == NULL) {
        printf("Error: Unable to create backup file.\n");
        return 1;
    }

    // Write backup data to file
    fprintf(backup_file, "This is a backup file generated on %d/%d/%d at %02d:%02d:%02d.\n\nBackup data:\n", current_time->tm_mday, current_time->tm_mon + 1, current_time->tm_year + 1900, current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
    for (int i = 0; i < 10; i++) {
        char* str = rand_string();
        fprintf(backup_file, "%s\n", str);
        free(str);
    }

    // Close file
    fclose(backup_file);

    printf("Backup created successfully!\n");
    printf("Filename: %s\n", filename);

    free(filename); // Free filename variable

    return 0;
}
//FormAI DATASET v1.0 Category: File Backup System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void backup_file(char* filename) {
    // Opens the original file for reading
    FILE* original_file = fopen(filename, "rb");
    if (original_file == NULL) {
        printf("Cannot open file: %s\n", filename);
        return;
    }

    // Prepares the filename for the backup file
    char backup_filename[256];
    strcpy(backup_filename, filename);
    time_t now = time(NULL);
    struct tm* current_time = localtime(&now);
    char timestamp[32];
    strftime(timestamp, 32, "%Y%m%d_%H%M%S", current_time);
    strcat(backup_filename, "_bkp_");
    strcat(backup_filename, timestamp);

    // Opens the backup file for writing
    FILE* backup_file = fopen(backup_filename, "wb");
    if (backup_file == NULL) {
        printf("Cannot create backup file: %s\n", backup_filename);
        fclose(original_file);
        return;
    }

    // Reads data from the original file and writes it to the backup file
    int buffer_size = 1024;
    char buffer[buffer_size];
    int bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), buffer_size, original_file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, backup_file);
    }

    // Closes the files
    fclose(original_file);
    fclose(backup_file);

    printf("Backup created successfully: %s\n", backup_filename);
}

int main() {
    char filename[256];
    printf("Enter the name of the file to backup: ");
    scanf("%s", filename);
    backup_file(filename);

    return 0;
}
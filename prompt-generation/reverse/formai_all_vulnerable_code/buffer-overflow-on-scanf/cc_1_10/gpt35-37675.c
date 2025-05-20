//FormAI DATASET v1.0 Category: File Backup System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1000000 // maximum file size in bytes
#define MAX_BACKUPS 10 // maximum number of backups to keep

char* get_timestamp();
void backup_file(char*, char*);

int main() {
    char input_filename[256];
    char output_filename[256];
    
    printf("Enter the filename to backup: ");
    scanf("%s", input_filename);
    
    strcpy(output_filename, input_filename);
    strcat(output_filename, ".");
    strcat(output_filename, get_timestamp());
    
    backup_file(input_filename, output_filename);
    
    return 0;
}

// Get current timestamp as a string
char* get_timestamp() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char* timestamp = malloc(20);
    sprintf(timestamp, "%d-%02d-%02d_%02d-%02d-%02d", tm.tm_year + 1900,
                                                      tm.tm_mon + 1,
                                                      tm.tm_mday,
                                                      tm.tm_hour,
                                                      tm.tm_min,
                                                      tm.tm_sec);
    return timestamp;
}

// Create a backup of the specified file with the given output filename
void backup_file(char* input_filename, char* output_filename) {
    FILE* input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error: could not open input file %s\n", input_filename);
        return;
    }
    
    FILE* output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error: could not open output file %s\n", output_filename);
        fclose(input_file);
        return;
    }
    
    // Copy the input file to the output file one chunk at a time
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read = fread(buffer, 1, sizeof(buffer), input_file);
    while (bytes_read > 0) {
        fwrite(buffer, 1, bytes_read, output_file);
        bytes_read = fread(buffer, 1, sizeof(buffer), input_file);
    }
    
    fclose(input_file);
    fclose(output_file);
    
    // Delete old backups if necessary
    int i;
    char backup_filename[256];
    for (i = MAX_BACKUPS - 1; i >= 0; i--) {
        sprintf(backup_filename, "%s.%d", input_filename, i);
        if (remove(backup_filename) == 0) {
            printf("Deleted old backup %s\n", backup_filename);
        }
    }
    
    // Rename backups to make room for the new backup
    for (i = MAX_BACKUPS - 2; i >= 0; i--) {
        sprintf(backup_filename, "%s.%d", input_filename, i);
        sprintf(output_filename, "%s.%d", input_filename, i + 1);
        if (rename(backup_filename, output_filename) == 0) {
            printf("Renamed %s to %s\n", backup_filename, output_filename);
        }
    }
    
    // Rename the new backup to the first backup filename
    sprintf(output_filename, "%s.%d", input_filename, 0);
    if (rename(output_filename, input_filename) == 0) {
        printf("Renamed %s to %s\n", output_filename, input_filename);
    }
}
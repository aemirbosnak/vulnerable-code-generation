//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_SIZE 1000

// Function to get current date and time
void get_current_time(char* time_buffer) {
    time_t now = time(NULL);
    strftime(time_buffer, 100, "%Y-%m-%d %H:%M:%S", localtime(&now));
}

// Function to create a backup file name
char* create_backup_file_name(char* file_name) {
    char* backup_file_name = malloc(strlen(file_name) + 10);
    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, ".bak");
    return backup_file_name;
}

// Function to copy a file
void copy_file(char* source_file_name, char* destination_file_name) {
    FILE* source_file = fopen(source_file_name, "rb");
    FILE* destination_file = fopen(destination_file_name, "wb");

    if (source_file == NULL || destination_file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char buffer[4096];
    while (fread(buffer, sizeof(char), sizeof(buffer), source_file) > 0) {
        fwrite(buffer, sizeof(char), sizeof(buffer), destination_file);
    }

    fclose(source_file);
    fclose(destination_file);
}

// Function to backup a file
void backup_file(char* file_name) {
    char* backup_file_name = create_backup_file_name(file_name);
    char* destination_file_name = malloc(strlen(file_name) + 10);
    strcpy(destination_file_name, file_name);
    strcat(destination_file_name, ".bak");

    copy_file(file_name, destination_file_name);

    printf("Backup created: %s\n", backup_file_name);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    char* file_name = argv[1];

    if (strcmp(file_name, ".") == 0 || strcmp(file_name, "..") == 0) {
        printf("Invalid file name\n");
        return 1;
    }

    char time_buffer[100];
    get_current_time(time_buffer);

    backup_file(file_name);

    return 0;
}
//FormAI DATASET v1.0 Category: File Backup System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 20

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    time_t last_backup;
} file;

file files[MAX_FILES];
int num_files = 0;

char* get_current_time() {
    time_t t = time(NULL);
    return asctime(localtime(&t));
}

void add_file(char* filename) {
    if (num_files == MAX_FILES) {
        printf("Error: Max number of files reached.\n");
        return;
    }
    
    for (int i = 0; i < num_files; i++) {
        if (strcmp(filename, files[i].filename) == 0) {
            printf("Error: File already exists.\n");
            return;
        }
    }

    file new_file;
    strncpy(new_file.filename, filename, MAX_FILENAME_LENGTH);
    new_file.last_backup = time(NULL);
    files[num_files++] = new_file;
    printf("File added successfully.\n");
}

void backup_files() {
    for (int i = 0; i < num_files; i++) {
        char backup_filename[MAX_FILENAME_LENGTH + 30];
        sprintf(backup_filename, "backup_%s_%ld.txt", files[i].filename, files[i].last_backup);
        FILE* original_file = fopen(files[i].filename, "r");
        FILE* backup_file = fopen(backup_filename, "w");

        if (original_file == NULL) {
            printf("Error: Could not open file: %s\n", files[i].filename);
            continue;
        }

        if (backup_file == NULL) {
            printf("Error: Could not create backup file: %s\n", backup_filename);
            fclose(original_file);
            continue;
        }

        char buffer[100];
        while (fgets(buffer, 100, original_file) != NULL) {
            fprintf(backup_file, "%s", buffer);
        }

        fclose(original_file);
        fclose(backup_file);
        files[i].last_backup = time(NULL);
        printf("File backed up successfully: %s\n", files[i].filename);
    }
}

void display_files() {
    if (num_files == 0) {
        printf("No files found.\n");
        return;
    }

    printf("Files:\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s (Last backed up: %s)", files[i].filename, get_current_time());
    }
}

int main() {
    while (1) {
        printf("Enter command (add [filename], backup, display, or exit): ");

        char input[100];
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            char filename[MAX_FILENAME_LENGTH];
            scanf("%s", filename);
            add_file(filename);
        } else if (strcmp(input, "backup") == 0) {
            backup_files();
        } else if (strcmp(input, "display") == 0) {
            display_files();
        } else if (strcmp(input, "exit") == 0) {
            return 0;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}
//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_BACKUP_FILES 10

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
} backup_file_t;

void backup_file(char* file_name, char* backup_file_name) {
    FILE* input_file = fopen(file_name, "r");
    FILE* output_file = fopen(backup_file_name, "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error: could not open file(s)\n");
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), input_file)!= NULL) {
        fputs(buffer, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    int num_files;
    printf("Enter the number of files to backup: ");
    scanf("%d", &num_files);

    backup_file_t backup_files[MAX_BACKUP_FILES];

    for (int i = 0; i < num_files; i++) {
        printf("Enter the file name for file %d: ", i+1);
        scanf("%s", backup_files[i].file_name);

        char* file_extension = strrchr(backup_files[i].file_name, '.');
        if (file_extension == NULL) {
            strcat(backup_files[i].file_name, ".bak");
        } else {
            strcat(backup_files[i].file_name, ".bak");
            strcat(backup_files[i].backup_file_name, file_extension);
        }

        backup_file(backup_files[i].file_name, backup_files[i].backup_file_name);
    }

    return 0;
}
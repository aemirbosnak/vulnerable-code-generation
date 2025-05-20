//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char file_name[MAX_SIZE];
    char backup_name[MAX_SIZE];
} file_t;

void read_files(file_t files[], int *num_files) {
    FILE *fp;
    char line[MAX_SIZE];
    int i = 0;

    // Open the input file
    fp = fopen("files.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    // Read each line from the input file
    while (fgets(line, MAX_SIZE, fp)!= NULL) {
        // Split the line into file name and backup name
        char *token = strtok(line, " ");
        strcpy(files[i].file_name, token);

        token = strtok(NULL, " ");
        strcpy(files[i].backup_name, token);

        i++;
    }

    // Close the input file
    fclose(fp);

    // Set the number of files read
    *num_files = i;
}

void backup_files(file_t files[], int num_files) {
    int i;

    // Loop through each file
    for (i = 0; i < num_files; i++) {
        // Create the backup file name
        char backup_file[MAX_SIZE];
        strcpy(backup_file, files[i].backup_name);
        strcat(backup_file, ".bak");

        // Backup the file
        rename(files[i].file_name, backup_file);
        printf("File '%s' backed up to '%s'.\n", files[i].file_name, backup_file);
    }
}

int main() {
    file_t files[MAX_SIZE];
    int num_files = 0;

    // Read the files from the input file
    read_files(files, &num_files);

    // Backup the files
    backup_files(files, num_files);

    return 0;
}
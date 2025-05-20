//FormAI DATASET v1.0 Category: File Synchronizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 100 // maximum size of a filename (including extension)
#define MAX_FILE_SIZE 100000 // maximum size of a file in bytes (100 KB)
#define MAX_FILES 10 // maximum number of files to synchronize

int main() {
    char filenames[MAX_FILES][MAX_FILENAME_SIZE]; // array of filenames to synchronize
    char filedata[MAX_FILES][MAX_FILE_SIZE]; // array to store file data
    int num_files; // number of files to synchronize

    // get user input for files to synchronize
    printf("Enter the number of files to synchronize: ");
    scanf("%d", &num_files);

    for (int i = 0; i < num_files; i++) {
        printf("Enter filename %d: ", i+1);
        scanf("%s", filenames[i]);

        // open file and read data
        FILE *file = fopen(filenames[i], "r");

        if (file == NULL) {
            printf("Error: unable to open file %s\n", filenames[i]);
            exit(1);
        }

        fseek(file, 0, SEEK_END);
        int file_size = ftell(file);
        fseek(file, 0, SEEK_SET);

        if (file_size > MAX_FILE_SIZE) {
            printf("Error: file %s is too large (max size %d bytes)\n", filenames[i], MAX_FILE_SIZE);
            exit(1);
        }

        fread(filedata[i], 1, file_size, file);
        fclose(file);
    }

    // compare file data and synchronize
    for (int i = 0; i < num_files-1; i++) {
        for (int j = i+1; j < num_files; j++) {
            if (strcmp(filedata[i], filedata[j]) != 0) {
                printf("Warning: file %s is different from file %s\n", filenames[i], filenames[j]);

                // ask user which file to keep
                char keep_file[MAX_FILENAME_SIZE];
                printf("Which file do you want to keep? Enter filename: ");
                scanf("%s", keep_file);

                if (strcmp(keep_file, filenames[i]) == 0) {
                    // copy file data from i to j
                    strcpy(filedata[j], filedata[i]);
                } else if (strcmp(keep_file, filenames[j]) == 0) {
                    // copy file data from j to i
                    strcpy(filedata[i], filedata[j]);
                } else {
                    printf("Error: invalid filename entered\n");
                    exit(1);
                }
            }
        }
    }

    // write new data to files
    for (int i = 0; i < num_files; i++) {
        FILE *file = fopen(filenames[i], "w");

        if (file == NULL) {
            printf("Error: unable to open file %s\n", filenames[i]);
            exit(1);
        }

        fwrite(filedata[i], 1, strlen(filedata[i]), file);
        fclose(file);
    }

    printf("All files synchronized successfully\n");

    return 0;
}
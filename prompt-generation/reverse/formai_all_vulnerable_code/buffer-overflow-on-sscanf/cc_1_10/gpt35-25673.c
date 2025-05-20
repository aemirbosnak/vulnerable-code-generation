//FormAI DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10000
#define MAX_FILENAME_LENGTH 100

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char filedata[MAX_FILE_SIZE];
} RecoveryFile;

int main(void) {
    FILE *fp;
    char filename[MAX_FILENAME_LENGTH];
    char buffer[MAX_FILE_SIZE];
    int buffer_size, total_files = 0;
    RecoveryFile *recovered_files;

    printf("Enter the name of the file to recover: ");
    scanf("%s", filename);

    // Allocate memory for recovered_files array
    recovered_files = (RecoveryFile*)malloc(sizeof(RecoveryFile));

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File '%s' not found\n", filename);
        return 0;
    }

    while (fgets(buffer, MAX_FILE_SIZE, fp) != NULL) {
        // Check if we have enough memory for this file
        if ((total_files + 1) * sizeof(RecoveryFile) > sizeof(recovered_files)) {
            // realloc() to increase memory of recovered_files array by double
            recovered_files = (RecoveryFile*)realloc(recovered_files, 2 * sizeof(recovered_files));
        }

        // Get filename and filedata from buffer
        sscanf(buffer, "%s %[^\n]", recovered_files[total_files].filename, recovered_files[total_files].filedata);

        total_files++;
    }

    // Close the file pointer
    fclose(fp);

    printf("Total %d files have been recovered:\n", total_files);

    // Loop through all the recovered files and print their filenames and content
    for (int i = 0; i < total_files; i++) {
        printf("File %d : %s\n", i+1, recovered_files[i].filename);
        printf("%s\n", recovered_files[i].filedata);
        printf("------------------------\n");
    }

    // Free the memory allocated to recovered_files array
    free(recovered_files);

    return 0;
}
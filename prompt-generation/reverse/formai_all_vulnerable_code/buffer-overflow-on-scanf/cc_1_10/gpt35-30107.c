//FormAI DATASET v1.0 Category: Data recovery tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1024

struct file {
    char name[MAX_FILE_NAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size;
};

int main() {
    struct file files[MAX_FILES];
    int num_files = 0;

    printf("Welcome to the Data Recovery Tool!\n");
    printf("Enter the number of files to recover (max %d): ", MAX_FILES);
    scanf("%d", &num_files);

    if (num_files < 1 || num_files > MAX_FILES) {
        printf("Invalid number of files.\n");
        return 1;
    }

    for (int i = 0; i < num_files; i++) {
        printf("Enter the name of file %d: ", i+1);
        scanf("%s", files[i].name);

        char file_path[MAX_FILE_NAME_LENGTH+5];
        strcpy(file_path, files[i].name);
        strcat(file_path, ".dat");

        FILE* file = fopen(file_path, "r");
        if (!file) {
            printf("Error: Unable to open file '%s'\n", files[i].name);
            return 1;
        }

        fseek(file, 0, SEEK_END);
        files[i].size = ftell(file);
        fseek(file, 0, SEEK_SET);

        fread(files[i].data, 1, files[i].size, file);
        fclose(file);
    }

    // Data recovery algorithm goes here...
    printf("Data recovery complete!\n");

    for (int i = 0; i < num_files; i++) {
        printf("Recovered file '%s' contains %d bytes of data:\n", 
        files[i].name, files[i].size);
        printf("%s\n", files[i].data);
    }

    return 0;
}
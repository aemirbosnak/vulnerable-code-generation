//FormAI DATASET v1.0 Category: File Synchronizer ; Style: energetic
// Hey there! Welcome to the File Synchronizer program written in C!
// This program is designed to synchronize two files of the same name in two different directories.
// With this program, you can easily update a file in one directory and have it automatically updated in the other directory.
// Let's dive into the code and see how it works!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 1024

// This function takes two file names and directories as arguments and synchronizes the files.
void synchronizeFiles(char *fileName, char *dir1, char *dir2) {
    char file1[BUFF_SIZE], file2[BUFF_SIZE];
    sprintf(file1, "%s/%s", dir1, fileName);
    sprintf(file2, "%s/%s", dir2, fileName);

    FILE *filePtr1 = fopen(file1, "r");
    FILE *filePtr2 = fopen(file2, "r");

    if (filePtr1 == NULL || filePtr2 == NULL) {
        printf("Error: File pointer is NULL.\n");
        return;
    }

    char c1 = fgetc(filePtr1), c2 = fgetc(filePtr2);
    int flag = 1;

    while (c1 != EOF && c2 != EOF) {
        if (c1 != c2) {
            flag = 0;
            break;
        }
        c1 = fgetc(filePtr1);
        c2 = fgetc(filePtr2);
    }

    if (flag == 1) {
        printf("No changes have been made in the file: %s.\n", fileName);
    } else {
        fclose(filePtr1);
        fclose(filePtr2);
        filePtr1 = fopen(file1, "w");
        filePtr2 = fopen(file2, "w");

        if (filePtr1 == NULL || filePtr2 == NULL) {
            printf("Error: File pointer is NULL.\n");
            return;
        }

        c1 = fgetc(filePtr1);
        while (c1 != EOF) {
            fputc(c1, filePtr2);
            c1 = fgetc(filePtr1);
        }

        printf("File %s has been synchronized.\n", fileName);
    }

    fclose(filePtr1);
    fclose(filePtr2);
}

// Main function that calls the synchronizeFiles function for each file in the directories.
int main(int argc, char const *argv[]) {
    if (argc == 3) {
        char *dir1 = argv[1];
        char *dir2 = argv[2];

        char command[BUFF_SIZE], fileName[BUFF_SIZE];
        sprintf(command, "ls %s > temp1.txt", dir1);
        system(command);
        sprintf(command, "ls %s > temp2.txt", dir2);
        system(command);

        FILE *filePtr1 = fopen("temp1.txt", "r");
        FILE *filePtr2 = fopen("temp2.txt", "r");

        while (fscanf(filePtr1, "%s", fileName) == 1) {
            synchronizeFiles(fileName, dir1, dir2);
        }

        fclose(filePtr1);
        fclose(filePtr2);

        remove("temp1.txt");
        remove("temp2.txt");
    } else {
        printf("Two directories are required.\n");
    }

    return 0;
}
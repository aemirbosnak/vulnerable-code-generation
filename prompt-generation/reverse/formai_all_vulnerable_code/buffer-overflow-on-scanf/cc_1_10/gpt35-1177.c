//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_SIZE 1024

void synchronizeFiles(char file1[], char file2[]) {
    FILE *fp1, *fp2;
    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");
    char data1[MAX_FILE_SIZE], data2[MAX_FILE_SIZE];

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error: Unable to open the file(s)\n");
        return;
    }

    fgets(data1, MAX_FILE_SIZE, fp1);
    fgets(data2, MAX_FILE_SIZE, fp2);

    if (strcmp(data1, data2) == 0) {
        printf("The files are already synchronized.\n");
        return;
    } else {
        printf("The files are not synchronized. Updating them...\n");
        fp1 = freopen(file1, "w", fp1);
        fprintf(fp1, "%s", data2);

        fp2 = freopen(file2, "w", fp2);
        fprintf(fp2, "%s", data1);
    }

    fclose(fp1);
    fclose(fp2);

    printf("Files have been synchronized successfully.\n");
}

int main() {
    char file1[MAX_FILE_SIZE];
    char file2[MAX_FILE_SIZE];

    printf("Enter the name of the first file: ");
    scanf("%s", file1);

    printf("Enter the name of the second file: ");
    scanf("%s", file2);

    synchronizeFiles(file1, file2);

    return 0;
}
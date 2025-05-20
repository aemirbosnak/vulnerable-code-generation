//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

void fileSync(const char *file1, const char *file2) {
    FILE *fp1, *fp2;
    char line[MAX_FILENAME_LENGTH];
    char *content1, *content2;
    int lineNum1, lineNum2;

    fp1 = fopen(file1, "r");
    if (fp1 == NULL) {
        printf("Error opening file %s\n", file1);
        return;
    }

    fp2 = fopen(file2, "r");
    if (fp2 == NULL) {
        printf("Error opening file %s\n", file2);
        fclose(fp1);
        return;
    }

    content1 = (char*) malloc(MAX_FILENAME_LENGTH);
    content2 = (char*) malloc(MAX_FILENAME_LENGTH);

    while (fgets(line, sizeof(line), fp1)!= NULL) {
        lineNum1++;
        if (strlen(line) > 0) {
            content1 = strcat(content1, line);
        }
    }

    while (fgets(line, sizeof(line), fp2)!= NULL) {
        lineNum2++;
        if (strlen(line) > 0) {
            content2 = strcat(content2, line);
        }
    }

    if (strlen(content1)!= strlen(content2)) {
        printf("Files are not synchronized\n");
        free(content1);
        free(content2);
        fclose(fp1);
        fclose(fp2);
        return;
    }

    if (strncmp(content1, content2, strlen(content1))!= 0) {
        printf("Files are not synchronized\n");
        free(content1);
        free(content2);
        fclose(fp1);
        fclose(fp2);
        return;
    }

    printf("Files are synchronized\n");
    free(content1);
    free(content2);
    fclose(fp1);
    fclose(fp2);
}

int main() {
    fileSync("file1.txt", "file2.txt");
    return 0;
}
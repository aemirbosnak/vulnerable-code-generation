//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    FILE *file1, *file2;
    char line1[MAX_LINE_LENGTH], line2[MAX_LINE_LENGTH];
    char *token1, *token2;
    int i, j;

    if (argc!= 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        return 1;
    }

    file1 = fopen(argv[1], "r");
    file2 = fopen(argv[2], "r");

    if (file1 == NULL || file2 == NULL) {
        printf("Error opening file(s).\n");
        return 1;
    }

    printf("Synchronizing files...\n");

    while (fgets(line1, MAX_LINE_LENGTH, file1)!= NULL &&
           fgets(line2, MAX_LINE_LENGTH, file2)!= NULL) {
        token1 = strtok(line1, "\n");
        token2 = strtok(line2, "\n");

        while (token1!= NULL && token2!= NULL) {
            if (strcmp(token1, token2)!= 0) {
                printf("Mismatch at line %d:\n", i+1);
                printf("File1: %s\n", line1);
                printf("File2: %s\n", line2);
                return 1;
            }

            token1 = strtok(NULL, "\n");
            token2 = strtok(NULL, "\n");
        }

        i++;
    }

    if (feof(file1) && feof(file2)) {
        printf("Files are synchronized.\n");
        return 0;
    } else if (feof(file1)) {
        printf("File1 is shorter than File2.\n");
        return 1;
    } else {
        printf("File2 is shorter than File1.\n");
        return 1;
    }
}
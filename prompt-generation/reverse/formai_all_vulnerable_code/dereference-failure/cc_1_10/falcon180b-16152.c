//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    char line1[MAX_LINE_LEN], line2[MAX_LINE_LEN];
    char *token1, *token2;
    int cmp;

    if (argc!= 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(1);
    }

    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    while (fgets(line1, MAX_LINE_LEN, fp1)!= NULL &&
           fgets(line2, MAX_LINE_LEN, fp2)!= NULL) {
        token1 = strtok(line1, "\n");
        token2 = strtok(line2, "\n");

        cmp = strcmp(token1, token2);

        if (cmp!= 0) {
            printf("Mismatch at line %d:\n", 1 + count_lines(fp1));
            printf("File 1: %s\n", line1);
            printf("File 2: %s\n", line2);
            exit(1);
        }
    }

    if (feof(fp1)!= feof(fp2)) {
        printf("Files are of different lengths.\n");
        exit(1);
    }

    fclose(fp1);
    fclose(fp2);

    printf("Files are synchronized.\n");
    return 0;
}

int count_lines(FILE *fp) {
    int count = 0;
    char ch;

    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            count++;
        }
    }

    return count;
}
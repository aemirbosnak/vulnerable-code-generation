//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

int main() {
    char file1[MAX_LINE_LENGTH];
    char file2[MAX_LINE_LENGTH];
    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];
    char *token;
    FILE *fp1, *fp2;

    printf("Enter the path of the first file: ");
    scanf("%s", file1);
    printf("Enter the path of the second file: ");
    scanf("%s", file2);

    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error: Couldn't open file.\n");
        exit(1);
    }

    while (fgets(line1, MAX_LINE_LENGTH, fp1)!= NULL && fgets(line2, MAX_LINE_LENGTH, fp2)!= NULL) {
        token = strtok(line1, "\n");
        while (token!= NULL) {
            if (isalpha(token[0])) {
                printf("%s ", token);
            }
            token = strtok(NULL, " ");
        }
        printf("\n");

        token = strtok(line2, "\n");
        while (token!= NULL) {
            if (isalpha(token[0])) {
                printf("%s ", token);
            }
            token = strtok(NULL, " ");
        }
        printf("\n");
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
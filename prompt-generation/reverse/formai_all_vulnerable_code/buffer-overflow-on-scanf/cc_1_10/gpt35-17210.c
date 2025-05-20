//FormAI DATASET v1.0 Category: File handling ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[50];
    char input[100];
    int num_lines = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");

    if(fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    printf("Enter text (type 'exit' to stop):\n");
    while(1) {
        scanf("%s", input);

        if(strcmp(input, "exit") == 0) {
            break;
        }

        fprintf(fp, "%s ", input);
        num_lines++;
    }

    fclose(fp);

    printf("%d lines written to file '%s'.\n", num_lines, filename);

    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    printf("\nContents of file '%s':\n", filename);
    while(fscanf(fp, "%s", input) != EOF) {
        printf("%s ", input);
    }

    fclose(fp);

    return 0;
}
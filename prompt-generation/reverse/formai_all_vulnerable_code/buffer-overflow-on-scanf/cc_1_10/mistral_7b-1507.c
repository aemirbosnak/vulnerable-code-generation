//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 256

int main(void) {
    FILE *file;
    char filename[MAX_LINE_LEN];
    char line[MAX_LINE_LEN];
    char *token;
    int line_num = 0;

    printf("\n************ SHOCKED TEXT PROCESSOR ************\n");

    printf("Enter file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s.\n", filename);
        return EXIT_FAILURE;
    }

    while (fgets(line, MAX_LINE_LEN, file) != NULL) {
        line_num++;
        printf("\n%d: %s", line_num, line);

        token = strtok(line, " \t\n\r.,;:!?");
        while (token != NULL) {
            if (isalpha(*token)) {
                for (int i = 0; token[i] != '\0'; i++) {
                    if (token[i] >= 'a' && token[i] <= 'z') {
                        token[i] = token[i] - 32;
                    }
                }
            }
            printf(" -> %s", token);
            token = strtok(NULL, " \t\n\r.,;:!?");
        }
        printf("\n");
    }

    fclose(file);

    printf("************ PROCESSING COMPLETED ************\n");

    return EXIT_SUCCESS;
}
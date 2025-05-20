//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    printf("Welcome to CSV Reader!\n\n");

    char fileName[100];
    printf("Please enter the file name: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    printf("File opened successfully!\n\n");

    char line[100];
    int lineNum = 0;
    int numOfCols;
    char **data = NULL;

    while (fgets(line, sizeof(line), file)) {

        if (lineNum == 0) {

            char *token = strtok(line, ",");
            numOfCols = 0;

            while (token) {
                numOfCols++;
                data = (char **) realloc(data, numOfCols * sizeof(char *));
                data[numOfCols - 1] = (char *) malloc(strlen(token) + 1);
                strcpy(data[numOfCols - 1], token);
                token = strtok(NULL, ",");
            }

        } else {

            char *token = strtok(line, ",");
            int colNum = 0;

            while (token) {
                if (colNum < numOfCols) {
                    data[colNum] = (char *) realloc(data[colNum], strlen(token) + 1);
                    strcpy(data[colNum], token);
                }

                token = strtok(NULL, ",");
                colNum++;
            }

            for (int i = 0; i < numOfCols; i++) {
                printf("%s ", data[i]);
            }

            printf("\n");

        }

        lineNum++;
    }

    printf("\nCSV file has been read successfully!\n\n");

    for (int i = 0; i < numOfCols; i++) {
        free(data[i]);
    }

    free(data);
    fclose(file);

    return 0;

}
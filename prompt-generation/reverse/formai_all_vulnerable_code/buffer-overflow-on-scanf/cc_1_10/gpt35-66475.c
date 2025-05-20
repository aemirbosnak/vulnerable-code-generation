//FormAI DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *filePointer;
    char filePath[50];
    char line[200];

    printf("Enter the path of the file you want to read: ");
    scanf("%s", filePath);
    filePointer = fopen(filePath, "r");

    if (filePointer == NULL) {
        printf("Unable to open file!\n");
        exit(1);
    }

    while (fgets(line, 200, filePointer)) {
        printf("%s", line);
    }

    fclose(filePointer);

    printf("\nEnter some text to write to the file: ");
    char input[200];
    scanf("%s", input);
    filePointer = fopen(filePath, "w");

    if (filePointer == NULL) {
        printf("Unable to open file!\n");
        exit(1);
    }

    fprintf(filePointer, "%s", input);
    fclose(filePointer);

    printf("\nThe contents of the file after writing: \n");

    filePointer = fopen(filePath, "r");
    if (filePointer == NULL) {
        printf("Unable to open file!\n");
        exit(1);
    }

    while (fgets(line, 200, filePointer)) {
        printf("%s", line);
    }

    fclose(filePointer);

    return 0;
}
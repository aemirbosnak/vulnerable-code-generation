//Falcon-180B DATASET v1.0 Category: File handling ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_NAME_LENGTH 100

// Function to check if a given string is a valid file name
bool isValidFileName(char* fileName) {
    int length = strlen(fileName);
    if (length == 0 || length > MAX_FILE_NAME_LENGTH) {
        return false;
    }
    for (int i = 0; i < length; i++) {
        char c = tolower(fileName[i]);
        if (!isalpha(c) && c!= '_') {
            return false;
        }
    }
    return true;
}

int main() {
    char fileName[MAX_FILE_NAME_LENGTH];
    printf("Enter a file name: ");
    scanf("%s", fileName);

    if (!isValidFileName(fileName)) {
        printf("Invalid file name.\n");
        exit(1);
    }

    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[1000];
    while (fgets(line, sizeof(line), file)!= NULL) {
        int length = strlen(line);
        if (length > 0 && line[length - 1] == '\n') {
            line[--length] = '\0';
        }
        printf("%s", line);
    }

    fclose(file);

    return 0;
}
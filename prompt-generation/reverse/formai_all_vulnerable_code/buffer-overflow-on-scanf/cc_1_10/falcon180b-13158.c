//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two strings
int compare(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int minLen = len1 < len2? len1 : len2;

    for (int i = 0; i < minLen; i++) {
        if (str1[i]!= str2[i]) {
            return 0;
        }
    }

    return 1;
}

// Function to search for a pattern in a text file
void searchFile(FILE *file, char *pattern) {
    char line[1024];
    char *token;
    int found = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            if (compare(token, pattern)) {
                found = 1;
                break;
            }
            token = strtok(NULL, " ");
        }

        if (found) {
            printf("%s", line);
            found = 0;
        }
    }
}

int main() {
    FILE *file;
    char filename[256];
    char pattern[256];

    // Get input from user
    printf("Enter filename: ");
    scanf("%s", filename);
    printf("Enter pattern: ");
    scanf("%s", pattern);

    // Open file for reading
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Search for pattern in file
    searchFile(file, pattern);

    // Close file
    fclose(file);

    return 0;
}
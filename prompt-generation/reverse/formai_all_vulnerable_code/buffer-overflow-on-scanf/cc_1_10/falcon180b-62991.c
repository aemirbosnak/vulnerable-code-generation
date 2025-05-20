//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Function to count words in a string
int countWords(char* str) {
    int count = 0;
    bool inWord = false;
    for (int i = 0; str[i]!= '\0'; i++) {
        if (isspace(str[i])) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            count++;
        }
    }
    return count;
}

// Function to read file and count words
int countFileWords(FILE* file) {
    char str[1000];
    int count = 0;
    while (fgets(str, sizeof(str), file)!= NULL) {
        count += countWords(str);
    }
    return count;
}

int main() {
    FILE* file;
    char filename[100];

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    file = fopen(filename, "r");

    // Check if file exists
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    // Count words in file
    int wordCount = countFileWords(file);

    // Print word count
    printf("The file contains %d words.\n", wordCount);

    // Close file
    fclose(file);

    return 0;
}
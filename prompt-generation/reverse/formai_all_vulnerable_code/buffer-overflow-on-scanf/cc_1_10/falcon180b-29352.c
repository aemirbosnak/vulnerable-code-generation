//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count words in a string
int countWords(char *str) {
    int count = 0;
    char *word = strtok(str, ",.?!;:");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, ",.?!;:");
    }
    return count;
}

// Function to count lines in a string
int countLines(char *str) {
    int count = 0;
    char *line = strtok(str, "\n");
    while (line!= NULL) {
        count++;
        line = strtok(NULL, "\n");
    }
    return count;
}

// Function to count characters in a string
int countChars(char *str) {
    int count = 0;
    while (*str!= '\0') {
        count++;
        str++;
    }
    return count;
}

int main() {
    char input[1000];
    printf("Enter a string: ");
    scanf("%[^\n]s", input);
    
    // Count words
    int wordCount = countWords(input);
    printf("Word count: %d\n", wordCount);
    
    // Count lines
    int lineCount = countLines(input);
    printf("Line count: %d\n", lineCount);
    
    // Count characters
    int charCount = countChars(input);
    printf("Character count: %d\n", charCount);
    
    return 0;
}
//FormAI DATASET v1.0 Category: String manipulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

char* shuffleString(char*);
char* reverseString(char*);

int main() {
    char str[MAX];
    printf("Enter a string:\n");
    fgets(str, MAX, stdin);

    // Remove newline character from the end of the string
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    // Shuffle the string
    char* shuffledStr = shuffleString(str);
    printf("Shuffled String: %s\n", shuffledStr);

    // Reverse the string
    char* reversedStr = reverseString(shuffledStr);
    printf("Reversed String: %s\n", reversedStr);

    // Replace vowels with underscores
    for (int i = 0; i < strlen(reversedStr); i++) {
        if (reversedStr[i] == 'a' || reversedStr[i] == 'e' || reversedStr[i] == 'i' || reversedStr[i] == 'o' || reversedStr[i] == 'u') {
            reversedStr[i] = '_';
        }
    }
    printf("Vowels Replaced: %s\n", reversedStr);

    // Count number of digits in the string
    int count = 0;
    for (int i = 0; i < strlen(reversedStr); i++) {
        if (isdigit(reversedStr[i])) {
            count++;
        }
    }
    printf("Number of digits: %d\n", count);

    // Free memory allocated to shuffled and reversed strings
    free(shuffledStr);
    free(reversedStr);

    return 0;
}

char* shuffleString(char* str) {
    int n = strlen(str);
    char* shuffledStr = (char*) malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        int j = rand() % (n - i);
        shuffledStr[i] = str[j];
        for (int k = j; k < n - i - 1; k++) {
            str[k] = str[k + 1];
        }
    }
    shuffledStr[n] = '\0';
    return shuffledStr;
}

char* reverseString(char* str) {
    int n = strlen(str);
    char* reversedStr = (char*) malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        reversedStr[i] = str[n - i - 1];
    }
    reversedStr[n] = '\0';
    return reversedStr;
}
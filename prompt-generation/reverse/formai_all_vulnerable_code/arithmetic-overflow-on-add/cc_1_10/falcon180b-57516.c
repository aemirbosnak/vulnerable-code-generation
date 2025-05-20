//Falcon-180B DATASET v1.0 Category: Recursive ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum length of a string
#define MAX_LENGTH 100

// Function to generate a random string
char* generateRandomString(int length) {
    char* result = malloc(length + 1);
    if (result == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        result[i] = rand() % 26 + 'a';
    }
    result[length] = '\0';

    return result;
}

// Function to print a string in reverse order
void printReverse(char* str) {
    for (int i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

// Recursive function to print all possible permutations of a string
void permute(char* str, int start, int end) {
    if (start == end) {
        printReverse(str);
    } else {
        for (int i = start; i <= end; i++) {
            str[start] = str[i];
            permute(str, start + 1, end);
        }
    }
}

// Main function
int main() {
    char* input;
    int length;

    // Get input from user
    printf("Enter the length of the string: ");
    scanf("%d", &length);

    input = generateRandomString(length);

    // Print all possible permutations of the string
    permute(input, 0, length - 1);

    free(input);
    return 0;
}
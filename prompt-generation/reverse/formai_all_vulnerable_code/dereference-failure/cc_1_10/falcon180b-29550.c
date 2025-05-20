//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// Function to convert a string to uppercase
void convertToUpper(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to calculate the checksum
int calculateChecksum(char* input) {
    int sum = 0;
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        sum += input[i];
    }
    return sum;
}

// Function to validate the input
bool validateInput(char* input) {
    int len = strlen(input);
    if (len == 0) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }
    return true;
}

// Function to read input from user
char* readInput() {
    char* input = malloc(100 * sizeof(char));
    printf("Enter input: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0';
    return input;
}

// Function to print the result
void printResult(int checksum) {
    printf("Checksum: %d\n", checksum);
}

int main() {
    char* input = readInput();
    convertToUpper(input);
    if (!validateInput(input)) {
        printf("Invalid input. Please enter a valid input.\n");
        return 1;
    }
    int checksum = calculateChecksum(input);
    printResult(checksum);
    free(input);
    return 0;
}
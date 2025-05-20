//Code Llama-13B DATASET v1.0 Category: Text processing ; Style: creative
// A creative C program to process text
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to reverse a string
void reverse(char str[]) {
    int len = strlen(str);
    char temp;
    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to capitalize the first letter of a string
void capitalize(char str[]) {
    str[0] = toupper(str[0]);
}

// Function to convert all letters to uppercase
void uppercase(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to convert all letters to lowercase
void lowercase(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    // Get input from the user
    char input[100];
    printf("Enter a sentence: ");
    scanf("%[^\n]", input);

    // Reverse the sentence
    reverse(input);

    // Capitalize the first letter of the sentence
    capitalize(input);

    // Convert all letters to uppercase
    uppercase(input);

    // Convert all letters to lowercase
    lowercase(input);

    // Print the output
    printf("Reversed sentence: %s\n", input);

    return 0;
}
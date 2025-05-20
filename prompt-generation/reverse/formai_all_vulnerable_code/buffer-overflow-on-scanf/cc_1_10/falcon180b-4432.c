//Falcon-180B DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count the number of words in a string
int count_words(char *str) {
    int count = 0;
    char *token;

    // Tokenize the string using space as delimiter
    token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}

// Function to reverse a string
void reverse_string(char *str, int len) {
    int i, j;
    char temp;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to convert a string to uppercase
void strtoupper(char *str) {
    int i;

    for (i = 0; str[i]!= '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to convert a string to lowercase
void strtolower(char *str) {
    int i;

    for (i = 0; str[i]!= '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char input_string[100];

    // Prompt user for input
    printf("Enter a string: ");
    scanf("%s", input_string);

    // Count the number of words in the string
    int num_words = count_words(input_string);
    printf("Number of words: %d\n", num_words);

    // Reverse the string
    reverse_string(input_string, strlen(input_string));
    printf("Reversed string: %s\n", input_string);

    // Convert the string to uppercase
    strtoupper(input_string);
    printf("String in uppercase: %s\n", input_string);

    // Convert the string to lowercase
    strtolower(input_string);
    printf("String in lowercase: %s\n", input_string);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Text processing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to reverse a string
void reverse(char *str) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to count the number of words in a string
int count_words(char *str) {
    int count = 0;
    char *token;
    token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to convert all characters to lowercase
void to_lower(char *str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char input_str[1000];
    char *token;
    int num_tokens;
    char *reversed_str;

    // Get input string from user
    printf("Enter a string: ");
    fgets(input_str, 1000, stdin);

    // Remove trailing newline character
    input_str[strcspn(input_str, "\n")] = '\0';

    // Convert all characters to lowercase
    to_lower(input_str);

    // Count the number of words in the input string
    num_tokens = count_words(input_str);

    // Reverse the order of the words
    reversed_str = malloc(strlen(input_str) + 1);
    strcpy(reversed_str, input_str);
    reverse(reversed_str);

    // Print the reversed string
    printf("Reversed string: %s\n", reversed_str);

    // Free memory
    free(reversed_str);

    return 0;
}
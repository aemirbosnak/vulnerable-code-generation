//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char string1[MAX_SIZE];
    char string2[MAX_SIZE];
    char concatenated_string[MAX_SIZE];
    char reversed_string[MAX_SIZE];
    char *token;
    int i, j, k;

    // Prompt user to enter two strings
    printf("Enter first string: ");
    fgets(string1, MAX_SIZE, stdin);
    printf("Enter second string: ");
    fgets(string2, MAX_SIZE, stdin);

    // Concatenate the two strings
    strcat(string1, string2);
    printf("Concatenated string: %s\n", string1);

    // Reverse the concatenated string
    for (i = strlen(string1) - 1, j = 0; i >= 0; i--, j++) {
        reversed_string[j] = string1[i];
    }
    reversed_string[j] = '\0';
    printf("Reversed string: %s\n", reversed_string);

    // Tokenize the concatenated string
    token = strtok(string1, " ");
    while (token!= NULL) {
        printf("%s ", token);
        token = strtok(NULL, " ");
    }
    printf("\n");

    // Count the number of occurrences of a given character in the concatenated string
    char search_char;
    printf("Enter a character to search for: ");
    scanf("%c", &search_char);
    for (i = 0, j = 0; i < strlen(string1); i++) {
        if (string1[i] == search_char) {
            j++;
        }
    }
    printf("Number of occurrences of '%c': %d\n", search_char, j);

    // Replace all occurrences of a given character with another character in the concatenated string
    char replace_char;
    printf("Enter a character to replace: ");
    scanf("%c", &replace_char);
    printf("Enter a replacement character: ");
    scanf("%c", &replace_char);
    for (i = 0, j = 0; i < strlen(string1); i++) {
        if (string1[i] == replace_char) {
            string1[i] = replace_char;
            j++;
        }
    }
    printf("Number of replacements made: %d\n", j);

    return 0;
}
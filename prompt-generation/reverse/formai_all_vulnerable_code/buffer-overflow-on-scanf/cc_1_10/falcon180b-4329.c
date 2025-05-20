//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main() {
    char str[MAX_SIZE];
    int i, j, n;
    char *ptr;
    char *token;
    char *reverse;
    char *uppercase;
    char *lowercase;
    char *copy;

    // Get input string
    printf("Enter a string: ");
    scanf("%s", str);

    // Remove leading and trailing spaces
    i = 0;
    while (isspace(str[i])) {
        i++;
    }
    n = strlen(str) - 1;
    while (isspace(str[n])) {
        n--;
    }
    str[n] = '\0';

    // Reverse the string
    reverse = strdup(str);
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // Convert to uppercase
    uppercase = strdup(str);
    for (i = 0; str[i]!= '\0'; i++) {
        str[i] = toupper(str[i]);
    }

    // Convert to lowercase
    lowercase = strdup(str);
    for (i = 0; str[i]!= '\0'; i++) {
        str[i] = tolower(str[i]);
    }

    // Copy the string
    copy = strdup(str);

    // Tokenize the string
    token = strtok(str, " ");
    while (token!= NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    // Print the original string
    printf("Original string: %s\n", str);

    // Print the reversed string
    printf("Reversed string: %s\n", reverse);

    // Print the uppercase string
    printf("Uppercase string: %s\n", uppercase);

    // Print the lowercase string
    printf("Lowercase string: %s\n", lowercase);

    // Print the copy of the string
    printf("Copy of the string: %s\n", copy);

    // Free memory
    free(reverse);
    free(uppercase);
    free(lowercase);
    free(copy);

    return 0;
}
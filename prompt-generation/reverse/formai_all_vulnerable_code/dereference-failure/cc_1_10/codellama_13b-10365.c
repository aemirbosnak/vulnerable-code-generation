//Code Llama-13B DATASET v1.0 Category: String manipulation ; Style: artistic
// String manipulation example program
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *str = "Hello, World!";
    char *new_str = (char *)malloc(strlen(str) + 1);
    strcpy(new_str, str);

    printf("Original string: %s\n", str);

    // Uppercase all letters
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            new_str[i] = str[i] - 32;
        }
    }

    printf("Uppercase string: %s\n", new_str);

    // Reverse the string
    int j = strlen(str) - 1;
    for (int i = 0; i < strlen(str) / 2; i++) {
        char tmp = new_str[i];
        new_str[i] = new_str[j];
        new_str[j] = tmp;
        j--;
    }

    printf("Reversed string: %s\n", new_str);

    // Replace all occurrences of 'o' with 'x'
    for (int i = 0; i < strlen(str); i++) {
        if (new_str[i] == 'o') {
            new_str[i] = 'x';
        }
    }

    printf("Replaced string: %s\n", new_str);

    // Concatenate two strings
    char *str2 = " Goodbye, World!";
    char *new_str2 = (char *)malloc(strlen(new_str) + strlen(str2) + 1);
    strcpy(new_str2, new_str);
    strcat(new_str2, str2);

    printf("Concatenated string: %s\n", new_str2);

    return 0;
}
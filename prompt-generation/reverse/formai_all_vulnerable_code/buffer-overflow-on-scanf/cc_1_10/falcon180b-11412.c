//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: accurate
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 100

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    char result[MAX_LENGTH];
    char delimiter;
    int i, j, k;
    bool is_first_word = true;

    // Get the first string from user
    printf("Enter the first string: ");
    scanf("%s", str1);

    // Get the second string from user
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Get the delimiter character from user
    printf("Enter the delimiter character: ");
    scanf(" %c", &delimiter);

    // Concatenate the two strings with delimiter
    strcat(str1, &delimiter);
    strcat(str1, str2);

    // Reverse the concatenated string
    for (i = strlen(str1) - 1, j = 0; i >= 0; i--, j++) {
        result[j] = str1[i];
    }
    result[j] = '\0';

    // Print the reversed string
    printf("The reversed concatenated string is: %s\n", result);

    // Count the number of words in the first string
    int word_count = 0;
    for (i = 0; str1[i]!= '\0'; i++) {
        if (is_first_word &&!isspace(str1[i])) {
            word_count++;
            is_first_word = false;
        }
        if (str1[i] == delimiter) {
            is_first_word = true;
        }
    }

    // Print the word count
    printf("The first string contains %d words.\n", word_count);

    return 0;
}
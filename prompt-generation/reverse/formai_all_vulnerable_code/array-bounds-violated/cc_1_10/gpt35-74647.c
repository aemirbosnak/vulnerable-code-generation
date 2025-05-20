//FormAI DATASET v1.0 Category: String manipulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[] = "Thank you for visiting!"; // Our input string
    int len = strlen(str); // Length of the input string
    char new_str[len + 1]; // New string that can fit the input string and the extra characters we will be adding
    int i, j = 0;

    // Let's loop through the input string and add an exclamation mark after every word
    for (i = 0; i < len; i++) {
        new_str[j++] = str[i];
        if (str[i] == ' ') {
            new_str[j++] = '!';
        }
    }

    // Let's add a heartfelt message at the end of the new string
    strcat(new_str, " We are grateful for you!");

    // Let's print out the new string
    printf("%s\n", new_str);

    // Let's copy every second letter into a new string
    char second_letters[len / 2 + 1]; // New string that can fit half of the input string and the null character
    j = 0;
    for (i = 0; i < len; i += 2) {
        second_letters[j++] = str[i];
    }
    second_letters[j] = '\0'; // Add the null character to the end of the second_letters string

    // Let's print out the second_letters string
    printf("%s\n", second_letters);

    // Let's reverse the input string
    char reversed_str[len + 1]; // New string that can fit the reversed input string and the null character
    j = 0;
    for (i = len - 1; i >= 0; i--) {
        reversed_str[j++] = str[i];
    }
    reversed_str[j] = '\0'; // Add the null character to the end of the reversed_str string

    // Let's print out the reversed_str string
    printf("%s\n", reversed_str);

    // Let's convert the input string to ASCII values
    printf("ASCII values of the characters in the input string:\n");
    for (i = 0; i < len; i++) {
        printf("%d ", str[i]);
    }
    printf("\n");

    return 0;
}
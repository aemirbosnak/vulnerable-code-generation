//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int main() {
    char string1[MAX_STRING_LENGTH];
    char string2[MAX_STRING_LENGTH];
    char string3[MAX_STRING_LENGTH];

    // Prompt the user to enter the first string
    printf("Enter the first string: ");
    scanf("%s", string1);

    // Prompt the user to enter the second string
    printf("Enter the second string: ");
    scanf("%s", string2);

    // Concatenate the two strings
    strcat(string1, string2);

    // Display the concatenated string
    printf("Concatenated string: %s\n", string1);

    // Prompt the user to enter a substring to search for
    printf("Enter a substring to search for: ");
    scanf("%s", string3);

    // Search for the substring in the concatenated string
    char *result = strstr(string1, string3);

    // Check if the substring was found
    if (result!= NULL) {
        printf("Substring found at position: %d\n", (int)(result - string1));
    } else {
        printf("Substring not found.\n");
    }

    // Prompt the user to enter a character to count
    printf("Enter a character to count: ");
    scanf(" %c", &string1[0]);

    // Count the number of occurrences of the character
    int count = 0;
    for (int i = 0; i < strlen(string1); i++) {
        if (string1[i] == string1[0]) {
            count++;
        }
    }

    // Display the count of the character
    printf("Number of occurrences of '%c': %d\n", string1[0], count);

    return 0;
}
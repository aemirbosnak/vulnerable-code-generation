//FormAI DATASET v1.0 Category: String manipulation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int i, len1, len2;

    printf("Enter the first string:\n");
    fgets(str1, 100, stdin);
    sscanf(str1, "%s", str1); // Removing any trailing '\n' from the string

    printf("Enter the second string:\n");
    fgets(str2, 100, stdin);
    sscanf(str2, "%s", str2); // Removing any trailing '\n' from the string

    len1 = strlen(str1);
    len2 = strlen(str2);

    // Concatenating the two strings and printing the result
    printf("\nString concatenation:\n");
    for(i = 0; i < len1; i++) {
        printf("%c", str1[i]);
    }
    for(i = 0; i < len2; i++) {
        printf("%c", str2[i]);
    }

    // Reversing the first string and printing the result
    printf("\n\nString reversal:\n");
    for(i = len1-1; i >= 0; i--) {
        printf("%c", str1[i]);
    }

    // Comparing the two strings and printing the result
    printf("\n\nString comparison:\n");
    if(strcmp(str1, str2) == 0) {
        printf("The strings are equal.\n");
    }
    else {
        printf("The strings are not equal.\n");
    }

    // Finding the first occurrence of a character in the first string and printing the result
    char c;
    printf("\nEnter a character to search in the first string:\n");
    scanf("%c", &c);
    for(i = 0; i < len1; i++) {
        if(str1[i] == c) {
            printf("'%c' found at index %d in the first string.\n", c, i);
            break;
        }
    }
    if(i >= len1) {
        printf("'%c' not found in the first string.\n", c);
    }

    return 0;
}
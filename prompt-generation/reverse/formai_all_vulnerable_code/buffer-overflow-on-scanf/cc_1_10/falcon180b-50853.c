//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    char str3[MAX_LENGTH];
    char str4[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    printf("Enter third string: ");
    scanf("%s", str3);

    printf("Enter fourth string: ");
    scanf("%s", str4);

    // Concatenate two strings
    char str_concat[MAX_LENGTH];
    strcat(str_concat, str1);
    strcat(str_concat, str2);

    printf("Concatenated string: %s\n", str_concat);

    // Compare two strings
    int result = strcmp(str1, str2);

    if (result == 0) {
        printf("Strings are equal.\n");
    } else if (result < 0) {
        printf("String 1 is less than String 2.\n");
    } else {
        printf("String 1 is greater than String 2.\n");
    }

    // Copy one string to another
    strcpy(str3, str1);

    printf("Copied string: %s\n", str3);

    // Convert string to uppercase
    for (int i = 0; i < strlen(str1); i++) {
        str1[i] = toupper(str1[i]);
    }

    printf("Uppercase string: %s\n", str1);

    // Reverse a string
    char reversed_str[MAX_LENGTH];
    strcpy(reversed_str, str4);

    for (int i = strlen(reversed_str) - 1; i >= 0; i--) {
        reversed_str[i] = reversed_str[strlen(reversed_str) - 1 - i];
    }

    printf("Reversed string: %s\n", reversed_str);

    return 0;
}
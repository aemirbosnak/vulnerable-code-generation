//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str1[] = "Hello, World!";
    char str2[] = "How are you?";
    char str3[50];

    // Concatenating two strings
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);

    // Copying a string
    strcpy(str3, str1);
    printf("Copied string: %s\n", str3);

    // Comparing two strings
    if (strcmp(str1, str2) == 0) {
        printf("Strings are equal.\n");
    } else {
        printf("Strings are not equal.\n");
    }

    // Converting a string to uppercase
    char str4[] = "Hello, World!";
    for (int i = 0; i < strlen(str4); i++) {
        str4[i] = toupper(str4[i]);
    }
    printf("Uppercase string: %s\n", str4);

    // Converting a string to lowercase
    char str5[] = "Hello, World!";
    for (int i = 0; i < strlen(str5); i++) {
        str5[i] = tolower(str5[i]);
    }
    printf("Lowercase string: %s\n", str5);

    // Reversing a string
    char str6[] = "Hello, World!";
    int len = strlen(str6);
    for (int i = 0; i < len / 2; i++) {
        char temp = str6[i];
        str6[i] = str6[len - i - 1];
        str6[len - i - 1] = temp;
    }
    printf("Reversed string: %s\n", str6);

    // Finding the length of a string
    char str7[] = "Hello, World!";
    int length = strlen(str7);
    printf("Length of string: %d\n", length);

    // Finding a substring in a string
    char str8[] = "The quick brown fox jumps over the lazy dog";
    char substr[] = "brown";
    char *pos = strstr(str8, substr);
    if (pos!= NULL) {
        printf("Substring found at position %d.\n", pos - str8);
    } else {
        printf("Substring not found.\n");
    }

    // Replacing a substring in a string
    char str9[] = "Hello, World!";
    char substr2[] = "World";
    char replacement[] = "Universe";
    char *pos2 = strstr(str9, substr2);
    strcpy(pos2, replacement);
    printf("Modified string: %s\n", str9);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str1[100], str2[100], str3[200];
    int i, j, k;

    // Input strings
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Concatenate strings
    strcat(str1, str2);
    printf("\nConcatenated string: %s\n", str1);

    // Copy string
    strcpy(str3, str1);
    printf("\nCopied string: %s\n", str3);

    // Compare strings
    if (strcmp(str1, str2) == 0) {
        printf("\nStrings are equal.\n");
    } else {
        printf("\nStrings are not equal.\n");
    }

    // Reverse string
    for (i = strlen(str1) - 1, j = 0; i >= 0; i--, j++) {
        str1[j] = str1[i];
    }
    printf("\nReversed string: %s\n", str1);

    // Replace characters
    for (i = 0; str1[i]!= '\0'; i++) {
        if (str1[i] == 'a') {
            str1[i] = 'b';
        }
    }
    printf("\nModified string: %s\n", str1);

    // Find substring
    char *ptr = strstr(str1, "world");
    if (ptr!= NULL) {
        printf("\nSubstring found at position %d.\n", ptr - str1 + 1);
    } else {
        printf("\nSubstring not found.\n");
    }

    return 0;
}
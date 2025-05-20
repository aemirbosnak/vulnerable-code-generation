//FormAI DATASET v1.0 Category: String manipulation ; Style: systematic
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], str3[100];
    int i, j;

    // Input first string
    printf("Enter the first string: ");
    scanf("%s", str1);

    // Input second string
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Copying str1 to str3
    strcpy(str3, str1);

    // Concatenating str1 and str2
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);

    // Reversing str3 using loop
    j = 0;
    for (i = strlen(str3) - 1; i >= 0; i--) {
        str3[j++] = str1[i];
    }
    str3[j] = '\0';

    printf("Original string: %s\n", str1);
    printf("Reversed string: %s\n", str3);

    // Checking if str1 is a palindrome
    for (i = 0, j = strlen(str1) - 1; i <= j; i++, j--) {
        if (str1[i] != str1[j]) {
            printf("%s is not a palindrome.\n", str1);
            break;
        }
    }
    if (i > j) {
        printf("%s is a palindrome.\n", str1);
    }

    // Extracting a portion of str1
    memmove(str1, str1 + 5, 7);
    str1[7] = '\0';
    printf("Extracted portion: %s\n", str1);

    return 0;
}
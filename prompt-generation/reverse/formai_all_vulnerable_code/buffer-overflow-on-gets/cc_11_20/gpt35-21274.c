//FormAI DATASET v1.0 Category: String manipulation ; Style: beginner-friendly
#include <stdio.h>

int main() {
    char str1[50], str2[50];
    printf("Enter the first string: ");
    gets(str1);
    printf("Enter the second string: ");
    gets(str2);

    // concatenating two strings
    int len1 = 0, len2 = 0;
    while (str1[len1] != '\0') {
        len1++;
    }
    while (str2[len2] != '\0') {
        str1[len1++] = str2[len2++];
    }
    str1[len1] = '\0';
    printf("Concatenated string is: %s\n", str1);

    // comparing two strings
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            printf("Strings are not equal\n");
            break;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        printf("Strings are equal\n");
    }

    // printing reverse of a string
    int len = 0;
    while (str1[len] != '\0') {
        len++;
    }
    printf("Reverse of string is: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str1[i]);
    }
    printf("\n");

    // converting string to uppercase
    i = 0;
    while (str1[i] != '\0') {
        if (str1[i] >= 'a' && str1[i] <= 'z') {
            str1[i] = str1[i] - 32;
        }
        i++;
    }
    printf("Uppercase string is: %s\n", str1);

    // counting the number of vowels in a string
    i = 0;
    int vowels = 0;
    while (str1[i] != '\0') {
        if (str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u') {
            vowels++;
        }
        i++;
    }
    printf("Number of vowels in string is: %d\n", vowels);
    
    return 0;
}
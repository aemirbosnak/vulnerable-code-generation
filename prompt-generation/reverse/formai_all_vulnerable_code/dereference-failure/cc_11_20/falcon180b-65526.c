//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main() {
    char str[MAX_SIZE];
    char *ptr;
    int len;
    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);
    len = strlen(str);
    printf("Original string: %s\n", str);

    // Reverse the string
    ptr = str + len - 1;
    while (ptr >= str) {
        printf("%c", *ptr);
        ptr--;
    }
    printf("\n");

    // Convert to uppercase
    for (ptr = str; *ptr!= '\0'; ptr++) {
        if (isalpha(*ptr)) {
            *ptr = toupper(*ptr);
        }
    }
    printf("Uppercase string: %s\n", str);

    // Count the number of vowels
    int count = 0;
    for (ptr = str; *ptr!= '\0'; ptr++) {
        if (isalpha(*ptr) && (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u')) {
            count++;
        }
    }
    printf("Number of vowels: %d\n", count);

    // Replace all occurrences of a character with another character
    char ch1, ch2;
    printf("Enter the character to replace: ");
    scanf(" %c", &ch1);
    printf("Enter the replacement character: ");
    scanf(" %c", &ch2);
    for (ptr = str; *ptr!= '\0'; ptr++) {
        if (*ptr == ch1) {
            *ptr = ch2;
        }
    }
    printf("Modified string: %s\n", str);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int main() {
    char input[MAX_SIZE];
    char reverse[MAX_SIZE];
    char *ptr;
    int i, j, len;

    printf("Enter a string: ");
    scanf("%[^\n]", input);
    len = strlen(input);

    printf("Original string: %s\n", input);

    // Reverse the string
    ptr = input;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        char temp = *ptr;
        *ptr = *(ptr + j);
        *(ptr + j) = temp;
        ptr++;
    }

    printf("Reversed string: %s\n", input);

    // Remove all vowels from the string
    ptr = input;
    while (*ptr) {
        if (isalpha(*ptr)) {
            if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u' || *ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U') {
                *ptr = '\0';
            }
        }
        ptr++;
    }

    printf("String without vowels: %s\n", input);

    // Convert the string to uppercase
    ptr = input;
    while (*ptr) {
        *ptr = toupper(*ptr);
        ptr++;
    }

    printf("String in uppercase: %s\n", input);

    return 0;
}
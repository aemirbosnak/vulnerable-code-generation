//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

int main() {
    char str[MAX_LENGTH];
    int i, j, k, len;
    char temp;

    // Get string from user
    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the string
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // Print the reversed string
    printf("Reversed string: %s\n", str);

    // Convert the string to uppercase
    for (i = 0; str[i]!= '\0'; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }

    // Print the uppercase string
    printf("Uppercase string: %s\n", str);

    // Count the number of vowels in the string
    len = strlen(str);
    for (i = 0, j = 0; i < len; i++) {
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            j++;
        }
    }

    // Print the number of vowels
    printf("Number of vowels: %d\n", j);

    // Remove all vowels from the string
    for (i = 0; i < len; i++) {
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            for (k = i; k < len - 1; k++) {
                str[k] = str[k + 1];
            }
            len--;
        }
    }

    // Print the string without vowels
    printf("String without vowels: %s\n", str);

    return 0;
}
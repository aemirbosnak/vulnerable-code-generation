//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    char *ptr;
    int count = 0;
    int i, j;

    // Take input from user
    printf("Enter a string: ");
    scanf("%s", str);

    // Count the number of vowels in the string
    for (i = 0; str[i]!= '\0'; i++) {
        if (isalpha(str[i])) {
            if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u') {
                count++;
            }
        }
    }

    // Reverse the string
    for (i = strlen(str) - 1, j = 0; i >= 0; i--, j++) {
        str[j] = str[i];
    }
    str[j] = '\0';

    // Remove all vowels from the string
    for (i = 0; str[i]!= '\0'; i++) {
        if (isalpha(str[i])) {
            if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u') {
                str[i] = '\0';
            }
        }
    }

    // Remove all consonants from the string
    for (i = 0; str[i]!= '\0'; i++) {
        if (isalpha(str[i])) {
            if (tolower(str[i])!= 'a' && tolower(str[i])!= 'e' && tolower(str[i])!= 'i' && tolower(str[i])!= 'o' && tolower(str[i])!= 'u') {
                str[i] = '\0';
            }
        }
    }

    // Convert the string to uppercase
    for (i = 0; str[i]!= '\0'; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }

    // Print the modified string
    printf("Modified string: %s\n", str);

    // Count the number of words in the string
    ptr = strtok(str, " ");
    while (ptr!= NULL) {
        count++;
        ptr = strtok(NULL, " ");
    }

    printf("Number of words: %d\n", count);

    return 0;
}
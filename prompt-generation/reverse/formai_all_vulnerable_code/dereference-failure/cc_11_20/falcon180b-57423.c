//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    char *p;
    int i, j, length;

    // Prompt user for input
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove leading and trailing white spaces
    p = input;
    while (isspace(*p)) {
        p++;
    }
    length = strlen(p);
    while (isspace(p[length-1])) {
        p[length-1] = '\0';
        length--;
    }

    // Reverse the string
    p = input;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        char temp = p[i];
        p[i] = p[j];
        p[j] = temp;
    }

    // Convert to uppercase
    for (p = input; *p; p++) {
        *p = toupper(*p);
    }

    // Convert to lowercase
    for (p = input; *p; p++) {
        *p = tolower(*p);
    }

    // Count the number of vowels
    p = input;
    int count = 0;
    while (*p) {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u') {
            count++;
        }
        p++;
    }

    // Remove all vowels
    p = input;
    while (*p) {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u') {
            p++;
            continue;
        }
        strncat(output, p, 1);
        p++;
    }
    output[strlen(output)-1] = '\0';

    // Output the results
    printf("Original string: %s\n", input);
    printf("Reversed string: %s\n", input);
    printf("Uppercase string: %s\n", input);
    printf("Lowercase string: %s\n", input);
    printf("Number of vowels: %d\n", count);
    printf("String without vowels: %s\n", output);

    return 0;
}
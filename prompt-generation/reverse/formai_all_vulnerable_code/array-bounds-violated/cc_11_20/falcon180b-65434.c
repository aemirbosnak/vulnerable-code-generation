//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);
    int length = strlen(input);

    // Remove leading/trailing whitespace
    while (isspace(input[0])) {
        memmove(input, input + 1, length - 1);
        length--;
    }
    while (isspace(input[length - 1])) {
        input[--length] = '\0';
    }

    // Reverse the string
    char *ptr = input + length - 1;
    while (ptr > input) {
        *ptr = *ptr - 1;
        ptr--;
    }

    // Count the number of vowels
    int vowelCount = 0;
    for (int i = 0; i < length; i++) {
        if (tolower(input[i]) == 'a' || tolower(input[i]) == 'e' ||
            tolower(input[i]) == 'i' || tolower(input[i]) == 'o' ||
            tolower(input[i]) == 'u') {
            vowelCount++;
        }
    }

    // Count the number of consonants
    int consonantCount = 0;
    for (int i = 0; i < length; i++) {
        if (!isalpha(input[i])) {
            continue;
        }
        if (tolower(input[i])!= 'a' && tolower(input[i])!= 'e' &&
            tolower(input[i])!= 'i' && tolower(input[i])!= 'o' &&
            tolower(input[i])!= 'u') {
            consonantCount++;
        }
    }

    // Print the results
    printf("Reversed string: %s\n", input);
    printf("Number of vowels: %d\n", vowelCount);
    printf("Number of consonants: %d\n", consonantCount);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    char reversed[MAX_LENGTH];
    char *p;

    // Prompt the user to enter a string
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove any leading or trailing white spaces
    p = input;
    while (isspace(*p)) {
        p++;
    }
    while (*p!= '\0') {
        p++;
    }
    *p = '\0';

    // Reverse the string
    strcpy(reversed, input);
    p = reversed + strlen(reversed) - 1;
    while (p >= reversed) {
        *p = tolower(*p);
        p--;
    }

    // Print the reversed string
    printf("Reversed string: %s\n", reversed);

    // Count the number of vowels and consonants in the string
    int vowels = 0, consonants = 0;
    p = input;
    while (*p!= '\0') {
        if (isalpha(*p)) {
            if (isupper(*p)) {
                *p = tolower(*p);
            }
            if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
        p++;
    }

    // Print the number of vowels and consonants
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}
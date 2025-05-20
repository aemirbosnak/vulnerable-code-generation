//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    int i, j, k, n, m;
    char str[100];
    float x, y, z;

    // Prompt user for input
    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the string
    for (i = strlen(str) - 1, j = 0; i >= 0; i--, j++) {
        str[j] = tolower(str[i]);
    }

    // Count the number of vowels
    n = 0;
    for (i = 0; str[i]!= '\0'; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            n++;
        }
    }

    // Calculate the average vowel frequency
    x = (float) n / strlen(str);

    // Count the number of consonants
    n = 0;
    for (i = 0; str[i]!= '\0'; i++) {
        if (isalpha(str[i]) && (str[i]!= 'a' && str[i]!= 'e' && str[i]!= 'i' && str[i]!= 'o' && str[i]!= 'u')) {
            n++;
        }
    }

    // Calculate the average consonant frequency
    y = (float) n / strlen(str);

    // Calculate the average word length
    m = 0;
    for (i = 0; str[i]!= '\0'; i++) {
        if (isalpha(str[i])) {
            m++;
        }
    }
    z = (float) m / strlen(str);

    // Print the results
    printf("Reversed string: %s\n", str);
    printf("Number of vowels: %d\n", n);
    printf("Vowel frequency: %.2f\n", x);
    printf("Number of consonants: %d\n", n);
    printf("Consonant frequency: %.2f\n", y);
    printf("Average word length: %.2f\n", z);

    return 0;
}
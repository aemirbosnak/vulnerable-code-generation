#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    int words = 0, chars = 0, spec_chars = 0;
    float entropy = 0.0;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            words++;
        } else if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            chars++;
        } else if (!isspace(text[i])) {
            spec_chars++;
        }
    }

    // Introduce integer overflow vulnerability
    int large_number = 2147483647; // Maximum value of int
    large_number += 1; // Overflow

    entropy = (float)spec_chars / (chars + 1); // Avoid division by zero

    printf("Word count: %d\n", words);
    printf("Character count: %d\n", chars);
    printf("Special character count: %d\n", spec_chars);
    printf("Entropy: %.2f\n", entropy);

    return 0;
}

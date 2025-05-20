//FormAI DATASET v1.0 Category: String manipulation ; Style: lively
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[500];
    char reversed[500];
    int i, j, k, length;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove newline character
    length = strlen(sentence);
    if (sentence[length-1] == '\n') {
        sentence[length-1] = '\0';
        length--;
    }

    // Reverse sentence
    j = 0;
    for (i = length-1; i >= 0; i--) {
        if (sentence[i-1] == ' ' || i == 0) {
            for (k = i; k < length; k++) {
                reversed[j++] = sentence[k];
            }
            reversed[j++] = ' ';
            length = i - 1;
        }
    }

    // Print reversed sentence
    reversed[j] = '\0';
    printf("Reversed sentence: %s\n", reversed);

    // Count vowels and consonants
    int vowels = 0, consonants = 0;
    length = strlen(sentence);
    for (i = 0; i < length; i++) {
        if (sentence[i] >= 'a' && sentence[i] <= 'z' || sentence[i] >= 'A' && sentence[i] <= 'Z') {
            if (sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u' || 
                sentence[i] == 'A' || sentence[i] == 'E' || sentence[i] == 'I' || sentence[i] == 'O' || sentence[i] == 'U') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}
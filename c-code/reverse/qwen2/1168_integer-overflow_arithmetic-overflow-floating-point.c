#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char text[1024];
    int words = 0, chars = 0, spec_chars = 0;
    double avg_word_len = 0.0;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            words++;
        }
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            chars++;
        } else if (!isspace(text[i])) {
            spec_chars++;
        }
    }

    words++; // Count the last word

    if (chars > 0) {
        avg_word_len = (double)chars / words;
    }

    printf("Word count: %d\n", words);
    printf("Special character count: %d\n", spec_chars);
    printf("Average word length: %.2f\n", avg_word_len);

    return 0;
}

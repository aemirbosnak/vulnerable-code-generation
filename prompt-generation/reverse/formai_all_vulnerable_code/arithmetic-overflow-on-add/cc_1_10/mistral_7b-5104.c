//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ALPHABET_SIZE 256

typedef struct {
    int count;
    char letter;
} count_t;

void count_letters(char *text, count_t *letter_counts) {
    int i;

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            for (int j = 0; j < ALPHABET_SIZE; j++) {
                if (letter_counts[j].letter == text[i]) {
                    letter_counts[j].count++;
                    break;
                }
                if (j == ALPHABET_SIZE - 1) {
                    letter_counts[i] = (count_t) {1, text[i]};
                    break;
                }
            }
        }
    }
}

double calculate_entropy(count_t *letter_counts, int text_length) {
    double entropy = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        double probability = (double) letter_counts[i].count / text_length;
        entropy += probability * log2(probability);
    }

    return entropy;
}

int main() {
    char text[1000];
    count_t letter_counts[ALPHABET_SIZE];
    int apple_count = 0;
    int text_length;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text_length = strlen(text);

    count_letters(text, letter_counts);

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (letter_counts[i].letter == 'a' || letter_counts[i].letter == 'e' || letter_counts[i].letter == 'p' || letter_counts[i].letter == 'l' || letter_counts[i].letter == 'o') {
            apple_count += letter_counts[i].count;
        }
    }

    printf("Text entropy: %.12f\n", calculate_entropy(letter_counts, text_length));
    printf("Number of apples: %d\n", apple_count);

    return 0;
}
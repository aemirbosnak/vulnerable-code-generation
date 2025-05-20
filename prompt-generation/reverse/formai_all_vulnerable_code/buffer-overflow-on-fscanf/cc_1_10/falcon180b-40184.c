//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define NUM_CLASSES 2
#define NUM_WORDS 5000
#define NUM_CLASSES_PER_WORD 2
#define NUM_BYTES_PER_CLASS 4
#define NUM_BITS_PER_BYTE 8

typedef struct {
    char word[MAX_WORD_LENGTH];
    int class;
} Word;

void read_words(Word *words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open words file.\n");
        exit(1);
    }

    int num_words = 0;
    while (fscanf(file, "%s %d", words[num_words].word, &words[num_words].class)!= EOF) {
        num_words++;
    }

    fclose(file);
}

void train(Word *words, int num_classes, int num_classes_per_word, int num_bytes_per_class, int num_bits_per_byte) {
    for (int i = 0; i < num_classes; i++) {
        int count = 0;
        for (int j = 0; j < num_classes_per_word; j++) {
            if (words[i*num_classes_per_word + j].class == i) {
                count++;
            }
        }
        printf("Class %d: %d\n", i, count);
    }
}

int main() {
    Word words[NUM_WORDS];
    read_words(words);

    int num_classes = NUM_CLASSES;
    int num_classes_per_word = NUM_CLASSES_PER_WORD;
    int num_bytes_per_class = NUM_BYTES_PER_CLASS;
    int num_bits_per_byte = NUM_BITS_PER_BYTE;

    train(words, num_classes, num_classes_per_word, num_bytes_per_class, num_bits_per_byte);

    return 0;
}
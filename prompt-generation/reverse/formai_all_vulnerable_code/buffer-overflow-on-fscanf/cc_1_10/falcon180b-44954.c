//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50
#define NUM_CLASSES 10

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
    int class;
} Word;

Word words[MAX_WORDS];
int num_words;

int get_class(char* word) {
    int length = strlen(word);
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (isalpha(word[i])) {
            sum += tolower(word[i]) - 'a' + 1;
        }
    }
    return sum % NUM_CLASSES + 1;
}

void add_word(char* word, int class) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            break;
        }
    }
    if (i == num_words) {
        strcpy(words[num_words].word, word);
        words[num_words].count = 1;
        words[num_words].class = class;
        num_words++;
    }
}

void train() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(input_file, "%s", word)!= EOF) {
        int class = get_class(word);
        add_word(word, class);
    }
    fclose(input_file);
}

int classify(char* word) {
    int length = strlen(word);
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (isalpha(word[i])) {
            sum += tolower(word[i]) - 'a' + 1;
        }
    }
    return sum % NUM_CLASSES + 1;
}

int main() {
    srand(time(NULL));
    train();
    char word[MAX_WORD_LENGTH];
    while (scanf("%s", word)!= EOF) {
        int class = classify(word);
        printf("%s -> class %d\n", word, class);
    }
    return 0;
}
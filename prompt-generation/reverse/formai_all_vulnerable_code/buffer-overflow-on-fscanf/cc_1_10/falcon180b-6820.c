//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generate_words(Word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s", words[count].word)!= EOF) {
        words[count].length = strlen(words[count].word);
        count++;
        if (count >= MAX_WORDS) {
            break;
        }
    }

    fclose(file);
}

void print_words(Word words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s (%d)", words[i].word, words[i].length);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}

int main() {
    srand(time(NULL));

    Word words[MAX_WORDS];
    generate_words(words);

    int num_words = rand() % MAX_WORDS + 1;
    Word *selected_words = malloc(num_words * sizeof(Word));

    for (int i = 0; i < num_words; i++) {
        selected_words[i] = words[rand() % MAX_WORDS];
    }

    printf("Selected words:\n");
    print_words(selected_words, num_words);

    free(selected_words);

    return 0;
}
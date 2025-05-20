//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generate_words(Word words[], int num_words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    for (int i = 0; i < num_words; i++) {
        if (fscanf(file, "%s", words[i].word)!= 1) {
            printf("Error: could not read word from words.txt\n");
            exit(1);
        }
        words[i].length = strlen(words[i].word);
    }

    fclose(file);
}

void print_word(Word word) {
    for (int i = 0; i < word.length; i++) {
        printf("*");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int num_words;
    printf("Enter the number of words to type: ");
    scanf("%d", &num_words);

    Word words[MAX_WORDS];
    generate_words(words, num_words);

    int num_correct = 0;
    int num_incorrect = 0;

    for (int i = 0; i < num_words; i++) {
        printf("Type the word '%s': ", words[i].word);
        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[i].word) == 0) {
            num_correct++;
        } else {
            num_incorrect++;
        }

        print_word(words[i]);
    }

    printf("You typed %d words correctly and %d words incorrectly.\n", num_correct, num_incorrect);

    return 0;
}
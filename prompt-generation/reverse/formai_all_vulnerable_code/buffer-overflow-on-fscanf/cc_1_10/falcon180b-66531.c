//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generate_words(Word words[], int num_words) {
    FILE *dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    int num_words_read = 0;
    while (num_words_read < num_words && fscanf(dict_file, "%s", words[num_words_read].word)!= EOF) {
        words[num_words_read].length = strlen(words[num_words_read].word);
        num_words_read++;
    }

    fclose(dict_file);
}

int main() {
    int num_words;

    printf("Enter the number of words to type: ");
    scanf("%d", &num_words);

    Word words[MAX_WORDS];
    generate_words(words, num_words);

    int i, j, correct_words = 0, incorrect_words = 0;
    char user_input[MAX_WORD_LENGTH];

    for (i = 0; i < num_words; i++) {
        printf("Type the word %s: ", words[i].word);
        fgets(user_input, MAX_WORD_LENGTH, stdin);

        char *input_word = strtok(user_input, "\n");
        if (strcmp(input_word, words[i].word) == 0) {
            correct_words++;
        } else {
            incorrect_words++;
        }
    }

    double correct_percentage = (double)correct_words / num_words * 100.0;
    double wpm = ((double)num_words / (5.0 * (double)correct_words)) * 60.0;

    printf("\nResults:\n");
    printf("Correct words: %d\n", correct_words);
    printf("Incorrect words: %d\n", incorrect_words);
    printf("Correct percentage: %.2f%%\n", correct_percentage);
    printf("Words per minute: %.2f\n", wpm);

    return 0;
}
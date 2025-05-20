//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_WORDS 10
#define MAX_WORDS 100

typedef struct {
    char *word;
    int length;
} Word;

Word *generate_random_words(int num_words) {
    Word *words = (Word *) malloc(num_words * sizeof(Word));
    for (int i = 0; i < num_words; i++) {
        words[i].length = rand() % 20 + 5;
        words[i].word = (char *) malloc((words[i].length + 1) * sizeof(char));
        for (int j = 0; j < words[i].length; j++) {
            words[i].word[j] = 'a' + (rand() % 26);
        }
        words[i].word[words[i].length] = '\0';
    }
    return words;
}

void print_words(Word *words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i].word);
    }
    printf("\n");
}

void free_memory(Word *words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        free(words[i].word);
    }
    free(words);
}

int main() {
    srand(time(NULL));

    int num_words;
    printf("Enter the number of words to be tested (min %d, max %d): ", MIN_WORDS, MAX_WORDS);
    scanf("%d", &num_words);

    Word *words = generate_random_words(num_words);

    clock_t start = clock();
    print_words(words, num_words);

    for (int i = 0; i < num_words; i++) {
        char user_input[words[i].length + 1];
        scanf("%s", user_input);

        if (strcmp(words[i].word, user_input) != 0) {
            printf("Error: Incorrect word - %s, expected %s.\n", user_input, words[i].word);
            break;
        }
    }

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Test completed in %.2f seconds.\n", time_taken);

    free_memory(words, num_words);

    return 0;
}
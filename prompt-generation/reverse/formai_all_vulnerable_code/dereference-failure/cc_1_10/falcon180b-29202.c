//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

char *words[MAX_WORDS];
int num_words;
int word_lengths[MAX_WORDS];

void load_words(void) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open words.txt.\n");
        exit(1);
    }

    num_words = 0;
    while ((read = getline(&line, &len, fp))!= -1) {
        if (num_words >= MAX_WORDS) {
            printf("Warning: too many words in words.txt.\n");
            break;
        }
        words[num_words] = line;
        word_lengths[num_words] = strlen(line);
        num_words++;
    }
    fclose(fp);
}

void random_word(char *word) {
    int i;

    i = rand() % num_words;
    *word = words[i][0];
    for (i = 1; i < word_lengths[i]; i++) {
        word[i] = words[i][rand() % word_lengths[i]];
    }
    word[word_lengths[i]] = '\0';
}

int main(void) {
    int i, j, correct = 0;
    char word[MAX_WORD_LENGTH + 1];
    time_t start_time, end_time;

    srand(time(NULL));
    load_words();

    printf("Welcome to the C Typing Speed Test!\n");
    printf("How many words do you want to type? ");
    scanf("%d", &num_words);

    printf("Type the following %d words as quickly and accurately as possible:\n", num_words);

    start_time = time(NULL);
    for (i = 0; i < num_words; i++) {
        random_word(word);
        printf("%s ", word);
        for (j = 0; j < strlen(word); j++) {
            if (j < strlen(word) - 1) {
                printf("*");
            } else {
                printf("\n");
            }
        }
    }

    end_time = time(NULL);

    printf("\nYou typed %d words in %ld seconds.\n", num_words, end_time - start_time);

    return 0;
}
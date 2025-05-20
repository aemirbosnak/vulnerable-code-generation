//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int length;
};

void generate_word(char *word, int length) {
    int i;
    for (i = 0; i < length; i++) {
        word[i] = 'a' + rand() % 26;
    }
    word[length] = '\0';
}

int main() {
    int num_words, max_words = MAX_WORDS;
    char **words = malloc(sizeof(char *) * max_words);
    int *lengths = malloc(sizeof(int) * max_words);
    int i, j, correct = 0;
    double time_elapsed, wpm;

    srand(time(NULL));

    printf("Enter the number of words (1-%d): ", max_words);
    scanf("%d", &num_words);

    for (i = 0; i < num_words; i++) {
        words[i] = malloc(sizeof(char) * MAX_WORD_LENGTH);
        generate_word(words[i], rand() % MAX_WORD_LENGTH + 1);
        lengths[i] = strlen(words[i]);
    }

    printf("Type the following words:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }

    time_elapsed = 0;
    for (i = 0; i < num_words; i++) {
        printf("Type %s: ", words[i]);
        fflush(stdout);
        if (fgets(words[i], lengths[i], stdin) == NULL) {
            printf("Error reading input\n");
            exit(1);
        }
        time_elapsed += (double)clock() / CLOCKS_PER_SEC;
    }

    for (i = 0; i < num_words; i++) {
        if (strcmp(words[i], "") == 0) {
            continue;
        }
        if (strcasecmp(words[i], words[i - 1]) == 0) {
            printf("Error: repeated word\n");
            exit(1);
        }
        if (strlen(words[i])!= lengths[i]) {
            printf("Error: incorrect length\n");
            exit(1);
        }
    }

    wpm = (double)num_words * lengths[0] / time_elapsed;
    printf("You typed %d words with a speed of %.2f WPM\n", num_words, wpm);

    for (i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);
    free(lengths);

    return 0;
}
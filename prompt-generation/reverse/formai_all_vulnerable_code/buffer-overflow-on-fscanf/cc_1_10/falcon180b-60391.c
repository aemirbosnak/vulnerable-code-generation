//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MAX_TIME 60

struct word {
    char text[MAX_WORD_LENGTH + 1];
    int length;
};

void load_words(struct word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words file.\n");
        exit(1);
    }

    int count = 0;
    while (count < MAX_WORDS && fscanf(file, "%s", words[count].text)!= EOF) {
        words[count].length = strlen(words[count].text);
        count++;
    }

    fclose(file);
}

int main() {
    struct word words[MAX_WORDS];
    load_words(words);

    int num_words = rand() % MAX_WORDS;
    int total_length = 0;

    for (int i = 0; i < num_words; i++) {
        total_length += words[i].length;
    }

    int time_limit = MAX_TIME - total_length;

    printf("You have %d seconds to type the following:\n", time_limit);

    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i].text);
    }

    printf("\nPress enter when finished.\n");

    time_t start_time = time(NULL);
    char input[MAX_WORD_LENGTH + 1];
    int correct = 0;

    while (fgets(input, MAX_WORD_LENGTH + 1, stdin)) {
        input[strcspn(input, "\n")] = '\0';

        if (strcasecmp(input, words[correct].text) == 0) {
            correct++;
        } else {
            printf("Incorrect!\n");
        }

        if (correct == num_words) {
            time_t end_time = time(NULL);
            int elapsed_time = difftime(end_time, start_time);

            printf("You finished in %d seconds.\n", elapsed_time);
            return 0;
        }
    }

    return 0;
}
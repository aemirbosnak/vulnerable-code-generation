//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH_MIN 3
#define WORD_LENGTH_MAX 10

char *words[MAX_WORDS];
int num_words;

void generate_words() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open words file.\n");
        exit(1);
    }

    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            char word[WORD_LENGTH_MAX + 1];
            int i = 0;
            while (isalpha(ch) && i < WORD_LENGTH_MAX) {
                word[i] = ch;
                i++;
                ch = fgetc(file);
            }
            word[i] = '\0';

            if (i >= WORD_LENGTH_MIN) {
                words[num_words] = strdup(word);
                num_words++;
            }
        }
    }

    fclose(file);
}

void shuffle_words() {
    for (int i = 0; i < num_words; i++) {
        int j = rand() % num_words;
        char *temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

void print_words() {
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    generate_words();
    shuffle_words();

    int correct = 0;
    int incorrect = 0;

    char input[WORD_LENGTH_MAX + 1];
    while (1) {
        print_words();
        printf("Enter the words:\n");
        scanf("%s", input);

        if (strcasecmp(input, words[0]) == 0) {
            correct++;
        } else {
            incorrect++;
        }

        if (getchar() == '\n') {
            break;
        }
    }

    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);

    return 0;
}
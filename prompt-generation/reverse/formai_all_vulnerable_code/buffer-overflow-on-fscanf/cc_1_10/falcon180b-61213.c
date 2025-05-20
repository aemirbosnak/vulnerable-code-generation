//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 10

char words[MAX_WORDS][MAX_WORD_LEN];
int num_words;
int current_word;

void init_words() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: unable to open words.txt\n");
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[num_words], word);
        num_words++;
    }

    fclose(file);
}

void display_word() {
    int i;
    for (i = 0; i < strlen(words[current_word]); i++) {
        printf("%c", words[current_word][i]);
    }
}

int main() {
    srand(time(NULL));
    init_words();

    int score = 0;
    int correct = 0;
    int incorrect = 0;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be typing %d words.\n", num_words);

    while (current_word < num_words) {
        int word_len = strlen(words[current_word]);
        int start_time = clock();

        while (1) {
            char c = getchar();

            if (c == '\n') {
                int end_time = clock();
                int elapsed_time = end_time - start_time;

                if (elapsed_time > 0) {
                    score += (int) ((double) word_len / (double) elapsed_time * 60);
                    correct++;
                } else {
                    incorrect++;
                }

                break;
            }

            if (c!= words[current_word][0]) {
                printf("\a");
            }

            if (c!= words[current_word][0]) {
                incorrect++;
                break;
            }

            if (strlen(words[current_word]) == 1) {
                break;
            }

            printf("\r%s", words[current_word]);
            current_word++;
        }

        if (current_word >= num_words) {
            break;
        }

        printf("\n");
    }

    printf("Your score is: %d words per minute\n", score);
    printf("You got %d correct and %d incorrect.\n", correct, incorrect);

    return 0;
}
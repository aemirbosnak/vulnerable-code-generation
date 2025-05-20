//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int length;
};

void generate_words(struct word words[], int num_words) {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    int i = 0;

    file = fopen("words.txt", "r");

    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL && i < num_words) {
        strcpy(words[i].word, line);
        words[i].length = strlen(line);
        i++;
    }

    fclose(file);
}

int main() {
    struct word words[MAX_WORDS];
    int num_words, i, correct = 0;
    char input[MAX_WORD_LENGTH];
    int input_length, word_length;
    double speed = 0;

    printf("Welcome to the Happy C Typing Speed Test!\n\n");
    printf("Please enter the number of words you want to type: ");
    scanf("%d", &num_words);

    generate_words(words, num_words);

    clock_t start_time, end_time;

    start_time = clock();

    for (i = 0; i < num_words; i++) {
        printf("\nWord %d: ", i + 1);
        fflush(stdout);
        word_length = words[i].length;
        input_length = 0;

        while (input_length < word_length) {
            if (fgetc(stdin) == words[i].word[input_length]) {
                input_length++;
            } else {
                input_length = 0;
            }
        }

        if (input_length == word_length) {
            correct++;
        } else {
            printf("\nIncorrect! Try again.\n");
        }
    }

    end_time = clock();
    speed = (double) (num_words * 60) / (end_time - start_time);

    printf("\nYou typed %d words correctly!\n", correct);
    printf("Your typing speed is %.2f words per minute.\n", speed);

    return 0;
}
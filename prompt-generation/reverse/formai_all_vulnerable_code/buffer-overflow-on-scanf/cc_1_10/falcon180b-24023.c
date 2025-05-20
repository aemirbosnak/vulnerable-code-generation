//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 10

char words[MAX_WORDS][WORD_LENGTH];
int num_words;

void load_words(char *filename) {
    FILE *fp;
    char ch;
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            words[i][strlen(words[i])-1] = '\0';
            i++;
        } else {
            words[i][strlen(words[i])] = ch;
        }
    }

    num_words = i;
    fclose(fp);
}

int main() {
    int i, j, correct = 0;
    int word_index, start_time, end_time;
    char input[WORD_LENGTH];

    load_words("words.txt");

    printf("Enter your name: ");
    scanf("%s", input);
    printf("Hello %s, welcome to the typing speed test!\n", input);

    for (i = 0; i < num_words; i++) {
        word_index = rand() % num_words;
        start_time = clock();
        printf("Type the word: %s\n", words[word_index]);
        fgets(input, WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        end_time = clock();
        if (strcmp(input, words[word_index]) == 0) {
            correct++;
        }

        printf("You typed '%s' in %d milliseconds.\n", input, end_time - start_time);
    }

    printf("Your final score is %d out of %d.\n", correct, num_words);

    return 0;
}
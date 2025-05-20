//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MAX_TIME 60

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;
int correct_words;
int wrong_words;
int time_left;

void init_words() {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int i = 0;
    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[i], word);
        i++;
        if (i >= MAX_WORDS) {
            break;
        }
    }
    num_words = i;
    fclose(file);
}

void display_score() {
    printf("Score:\n");
    printf("Correct words: %d\n", correct_words);
    printf("Wrong words: %d\n", wrong_words);
    printf("Accuracy: %.2f%%\n", (float)correct_words / num_words * 100);
}

void main() {
    srand(time(NULL));
    init_words();
    printf("Welcome to the Typing Speed Test!\n");
    printf("You have %d seconds to type as many words as possible.\n", MAX_TIME);
    printf("Press enter to start:\n");
    getchar();
    time_left = MAX_TIME;
    while (time_left > 0) {
        int i = rand() % num_words;
        char word[MAX_WORD_LENGTH];
        strcpy(word, words[i]);
        printf("%s\n", word);
        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(word, input) == 0) {
            correct_words++;
        } else {
            wrong_words++;
        }
        time_left--;
    }
    printf("\nTime's up! Press enter to see your score:\n");
    getchar();
    display_score();
}
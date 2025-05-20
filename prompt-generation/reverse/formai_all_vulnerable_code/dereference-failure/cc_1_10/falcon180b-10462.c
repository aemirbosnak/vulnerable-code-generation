//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 1000
#define MAX_CONSPIRACY_WORDS 10

typedef struct {
    char *word;
    int length;
} ConspiracyWord;

ConspiracyWord conspiracy_words[] = {
    {"illuminati", 10},
    {"area 51", 7},
    {"flat earth", 10},
    {"chemtrails", 10},
    {"lizard people", 14},
    {"moon landing hoax", 17},
    {"9/11 conspiracy", 14},
    {"covid-19", 7},
    {"qanon", 6},
    {"5g", 3}
};

int main() {
    srand(time(NULL));

    int num_words = rand() % MAX_CONSPIRACY_WORDS + 1;
    ConspiracyWord *selected_words = malloc(sizeof(ConspiracyWord) * num_words);

    int total_length = 0;
    for (int i = 0; i < num_words; i++) {
        int index = rand() % MAX_CONSPIRACY_WORDS;
        selected_words[i] = conspiracy_words[index];
        total_length += selected_words[i].length;
    }

    char conspiracy[MAX_CONSPIRACY_LENGTH];
    int curr_length = 0;

    for (int i = 0; i < num_words; i++) {
        strncat(conspiracy, selected_words[i].word, selected_words[i].length);
        curr_length += selected_words[i].length;

        if (curr_length >= total_length - 10) {
            conspiracy[curr_length] = '\0';
            break;
        }
    }

    printf("Random Conspiracy Theory: %s\n", conspiracy);

    free(selected_words);
    return 0;
}
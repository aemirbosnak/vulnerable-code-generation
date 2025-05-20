//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 1000
#define MAX_CONSPIRACY_WORDS 10
#define WORD_LIST_SIZE 50

char *word_list[WORD_LIST_SIZE] = {
    "aliens",
    "chemtrails",
    "illuminati",
    "lizard people",
    "moon landing hoax",
    "new world order",
    "secret government experiments",
    "time travel",
    "ufos",
    "zombie apocalypse"
};

void generate_conspiracy(char *conspiracy, int length) {
    for (int i = 0; i < length; i++) {
        conspiracy[i] = word_list[rand() % WORD_LIST_SIZE][rand() % strlen(word_list[rand() % WORD_LIST_SIZE])];
    }
    conspiracy[length] = '\0';
}

int main() {
    srand(time(NULL));

    int num_conspiracies;
    printf("How many surrealist conspiracies do you want to generate? ");
    scanf("%d", &num_conspiracies);

    char **conspiracies = malloc(num_conspiracies * sizeof(char *));

    for (int i = 0; i < num_conspiracies; i++) {
        conspiracies[i] = malloc(MAX_CONSPIRACY_LENGTH * sizeof(char));
        generate_conspiracy(conspiracies[i], rand() % MAX_CONSPIRACY_LENGTH + 1);
        printf("Conspiracy #%d: %s\n", i + 1, conspiracies[i]);
    }

    for (int i = 0; i < num_conspiracies; i++) {
        free(conspiracies[i]);
    }
    free(conspiracies);

    return 0;
}
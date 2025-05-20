//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MAX_USERS 10

typedef struct {
    char name[20];
    int score;
    float speed;
} User;

void init(User* users) {
    for (int i = 0; i < MAX_USERS; i++) {
        users[i].score = 0;
        users[i].speed = 0.0;
    }
}

void loadWords(char* words[], int count) {
    FILE* fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error loading words\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s", words[i])!= EOF && i < count) {
        i++;
    }

    fclose(fp);
}

int main() {
    User users[MAX_USERS];
    init(users);

    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int wordCount = 0;

    loadWords(words, MAX_WORDS);
    wordCount = 0;

    srand(time(NULL));
    int index = rand() % wordCount;

    printf("Type the following words:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (i == index) {
            printf("%s\n", words[i]);
        } else {
            printf("%s ", words[i]);
        }
    }

    int correct = 0;
    int incorrect = 0;

    for (int i = 0; i < MAX_USERS; i++) {
        printf("\nUser %d's score: %d\n", i + 1, users[i].score);
    }

    return 0;
}
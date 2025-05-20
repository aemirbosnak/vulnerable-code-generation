//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MAX_USERS 10
#define MIN_WPM 20
#define MAX_WPM 200

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

typedef struct {
    char name[MAX_WORD_LENGTH];
    int score;
} User;

void generateWords(Word words[], int numWords) {
    const char *const nouns[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine", "orange", "pear", "quince", "raspberry", "strawberry", "tangerine", "watermelon", "xylophone", "yellow", "zebra"};
    const char *const verbs[] = {"run", "jump", "swim", "dance", "sing", "write", "read", "draw", "cook", "clean", "drive", "walk", "talk", "laugh", "cry", "smile", "frown", "think", "dream", "sleep", "eat", "drink"};
    const char *const adjectives[] = {"happy", "sad", "angry", "excited", "bored", "tired", "energetic", "lazy", "kind", "mean", "funny", "serious", "silly", "smart", "dumb", "pretty", "ugly", "short", "tall", "fat", "thin"};

    srand(time(NULL));

    for (int i = 0; i < numWords; i++) {
        int randIndex = rand() % 3;
        if (randIndex == 0) {
            strcpy(words[i].word, adjectives[rand() % 20]);
            words[i].length = strlen(words[i].word);
        } else if (randIndex == 1) {
            strcpy(words[i].word, verbs[rand() % 20]);
            words[i].length = strlen(words[i].word);
        } else {
            strcpy(words[i].word, nouns[rand() % 20]);
            words[i].length = strlen(words[i].word);
        }
    }
}

void printWords(Word words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s ", words[i].word);
    }
}

int main() {
    int numUsers, numWords;
    printf("Enter the number of users: ");
    scanf("%d", &numUsers);

    User users[MAX_USERS];
    for (int i = 0; i < numUsers; i++) {
        printf("Enter the name of user %d: ", i + 1);
        scanf("%s", users[i].name);
        users[i].score = 0;
    }

    printf("Enter the number of words: ");
    scanf("%d", &numWords);

    Word words[MAX_WORDS];
    generateWords(words, numWords);

    int correctWords[MAX_USERS];
    memset(correctWords, 0, sizeof(correctWords));

    for (int i = 0; i < numUsers; i++) {
        printf("\n%s's turn:\n", users[i].name);
        int numCorrect = 0;
        for (int j = 0; j < numWords; j++) {
            char input[MAX_WORD_LENGTH];
            printf("%s ", words[j].word);
            fgets(input, MAX_WORD_LENGTH, stdin);
            input[strcspn(input, "\n")] = '\0';
            if (strcmp(input, words[j].word) == 0) {
                numCorrect++;
            }
        }
        correctWords[i] += numCorrect;
        printf("\n%s scored %d out of %d\n\n", users[i].name, numCorrect, numWords);
    }

    printf("Final scores:\n");
    for (int i = 0; i < numUsers; i++) {
        printf("%s: %d\n", users[i].name, correctWords[i]);
    }

    return 0;
}
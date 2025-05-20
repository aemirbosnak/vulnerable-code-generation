//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MAX_USERS 10
#define MAX_USER_NAME_LENGTH 50
#define MAX_USER_EMAIL_LENGTH 100
#define MAX_USER_PASSWORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
    int correct;
} Word;

typedef struct {
    char name[MAX_USER_NAME_LENGTH];
    char email[MAX_USER_EMAIL_LENGTH];
    char password[MAX_USER_PASSWORD_LENGTH];
    int score;
} User;

void initWords(Word words[]) {
    char wordsFile[] = "words.txt";
    FILE *file = fopen(wordsFile, "r");
    if (file == NULL) {
        printf("Error: Could not open words file.\n");
        exit(1);
    }
    int wordCount = 0;
    while (fscanf(file, "%s", words[wordCount].word)!= EOF) {
        words[wordCount].length = strlen(words[wordCount].word);
        wordCount++;
        if (wordCount >= MAX_WORDS) {
            break;
        }
    }
    fclose(file);
}

void initUser(User user) {
    user.score = 0;
}

void initUsers(User users[]) {
    for (int i = 0; i < MAX_USERS; i++) {
        initUser(users[i]);
    }
}

int main() {
    Word words[MAX_WORDS];
    initWords(words);

    User users[MAX_USERS];
    initUsers(users);

    int numUsers = 0;
    while (numUsers < MAX_USERS && numUsers < 10) {
        printf("Enter name (leave blank to stop adding users):\n");
        scanf("%s", users[numUsers].name);
        if (strlen(users[numUsers].name) == 0) {
            break;
        }
        printf("Enter email:\n");
        scanf("%s", users[numUsers].email);
        printf("Enter password:\n");
        scanf("%s", users[numUsers].password);
        numUsers++;
    }

    int numCorrect = 0;
    int totalWords = 0;
    for (int i = 0; i < numUsers; i++) {
        printf("User: %s\n", users[i].name);
        for (int j = 0; j < MAX_WORDS; j++) {
            totalWords++;
            printf("Word: %s\n", words[j].word);
            char input[MAX_WORD_LENGTH];
            scanf("%s", input);
            int correct = 0;
            for (int k = 0; k < words[j].length; k++) {
                if (input[k] == words[j].word[k]) {
                    correct++;
                }
            }
            if (correct == words[j].length) {
                numCorrect++;
            }
        }
        printf("\n");
    }

    printf("Total words: %d\n", totalWords);
    printf("Correct words: %d\n", numCorrect);
    printf("Accuracy: %.2f%%\n", (float)numCorrect / totalWords * 100.0);

    return 0;
}
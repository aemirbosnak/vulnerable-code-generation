//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MAX_USERS 10

typedef struct {
    char name[20];
    int score;
    int words_typed;
    double speed;
} User;

void initialize_user(User* user) {
    strcpy(user->name, "");
    user->score = 0;
    user->words_typed = 0;
    user->speed = 0;
}

void add_word(User* user, char* word) {
    strcat(user->name, word);
    user->words_typed++;
    user->speed = (double)user->words_typed / (double)user->score;
}

void print_user_info(User* user) {
    printf("Name: %s\n", user->name);
    printf("Score: %d\n", user->score);
    printf("Words Typed: %d\n", user->words_typed);
    printf("Speed: %.2f wpm\n\n", user->speed);
}

int main() {
    int num_users;
    User users[MAX_USERS];

    printf("Welcome to the Typing Speed Test!\n\n");

    printf("How many users will be participating? ");
    scanf("%d", &num_users);

    for (int i = 0; i < num_users; i++) {
        printf("Enter the name of user #%d: ", i + 1);
        scanf("%s", users[i].name);

        printf("User #%d, you will be typing the following words:\n", i + 1);
        char word[MAX_WORD_LENGTH];
        for (int j = 0; j < MAX_WORDS; j++) {
            printf("Word #%d: ", j + 1);
            scanf("%s", word);
            add_word(&users[i], word);
        }

        printf("\nUser #%d, your score is %d and your speed is %.2f wpm.\n\n", i + 1, users[i].score, users[i].speed);
    }

    printf("\nFinal results:\n");
    for (int i = 0; i < num_users; i++) {
        print_user_info(&users[i]);
    }

    return 0;
}
//Code Llama-13B DATASET v1.0 Category: Automated Fortune Teller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 10

struct User {
    char name[20];
    char question[50];
    char answer[50];
};

void generate_answer(struct User *user) {
    srand(time(NULL));
    int index = rand() % 10;
    switch (index) {
        case 0:
            strcpy(user->answer, "It is certain.");
            break;
        case 1:
            strcpy(user->answer, "It is decidedly so.");
            break;
        case 2:
            strcpy(user->answer, "Without a doubt.");
            break;
        case 3:
            strcpy(user->answer, "Yes, definitely.");
            break;
        case 4:
            strcpy(user->answer, "You may rely on it.");
            break;
        case 5:
            strcpy(user->answer, "As I see it, yes.");
            break;
        case 6:
            strcpy(user->answer, "Most likely.");
            break;
        case 7:
            strcpy(user->answer, "Outlook good.");
            break;
        case 8:
            strcpy(user->answer, "Yes.");
            break;
        case 9:
            strcpy(user->answer, "Signs point to yes.");
            break;
        default:
            strcpy(user->answer, "Reply hazy, try again.");
            break;
    }
}

int main() {
    struct User users[MAX_USERS];
    int num_users = 0;

    while (num_users < MAX_USERS) {
        printf("Enter your name: ");
        scanf("%s", users[num_users].name);

        printf("Enter your question: ");
        scanf("%s", users[num_users].question);

        generate_answer(&users[num_users]);

        printf("Answer: %s\n", users[num_users].answer);

        num_users++;
    }

    return 0;
}
//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LENGTH 100

struct knight {
    char name[MAX_STR_LENGTH];
    char coat_of_arms[MAX_STR_LENGTH];
};

void create_knight(struct knight *knight) {
    printf("What is thy name, fair knight? ");
    fgets(knight->name, MAX_STR_LENGTH, stdin);
    printf("What is thy coat of arms, brave knight? ");
    fgets(knight->coat_of_arms, MAX_STR_LENGTH, stdin);
}

void joust(struct knight *knight1, struct knight *knight2) {
    char winner[MAX_STR_LENGTH];
    char loser[MAX_STR_LENGTH];
    int score1 = 0, score2 = 0;

    printf("The two knights face off in the lists:\n");
    printf("Knight1: %s\n", knight1->name);
    printf("Knight2: %s\n", knight2->name);

    do {
        printf("Knight1 charges with lance in hand, but Knight2 parries the blow with his shield. Score: 0-0\n");
        score1 = getchar() - '0';
        score2 = getchar() - '0';
        if (score1 > score2) {
            strcpy(winner, knight1->name);
            strcpy(loser, knight2->name);
        } else if (score1 < score2) {
            strcpy(winner, knight2->name);
            strcpy(loser, knight1->name);
        } else {
            printf("The two knights clash, but neither scores a blow. Score remains 0-0\n");
        }
    } while (score1 == score2);

    printf("The winner is: %s\n", winner);
    printf("The loser is: %s\n", loser);
}

int main() {
    struct knight knight1, knight2;

    create_knight(&knight1);
    create_knight(&knight2);

    joust(&knight1, &knight2);

    return 0;
}
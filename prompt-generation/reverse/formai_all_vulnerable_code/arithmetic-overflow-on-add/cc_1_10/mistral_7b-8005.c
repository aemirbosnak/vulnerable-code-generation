//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define ALIEN_NAME_SIZE 50
#define VOTE_COUNT 10
#define MAX_ALIENS 1000

typedef struct Alien {
    char name[ALIEN_NAME_SIZE];
    int vote[VOTE_COUNT];
} Alien;

typedef struct Election {
    Alien aliens[MAX_ALIENS];
    int num_aliens;
    int current_vote;
} Election;

void welcome(void) {
    printf("*\n* Welcome to the Intergalactic Cosmic Council\n* Electronic Voting System\n*");
    sleep(1);
    printf("*\n* Please align your minds and concentrate\n* on the voting process.\n*\n");
}

void register_alien(Election *election) {
    if (election->num_aliens >= MAX_ALIENS) {
        printf("*\n* Maximum number of aliens reached\n*");
        return;
    }

    printf("*\n* Enter Alien Name: ");
    scanf("%s", election->aliens[election->num_aliens].name);
    election->num_aliens++;
}

void cast_vote(Election *election) {
    if (election->num_aliens <= 0) {
        printf("*\n* No aliens registered yet\n*");
        return;
    }

    if (election->current_vote >= VOTE_COUNT) {
        printf("*\n* All votes have been casted\n*");
        return;
    }

    int alien_index;
    printf("*\n* Enter Alien Index: ");
    scanf("%d", &alien_index);

    if (alien_index >= election->num_aliens || alien_index < 0) {
        printf("*\n* Invalid Alien Index\n*");
        return;
    }

    printf("*\n* Alien %s is casting vote for candidate %d\n*", election->aliens[alien_index].name, election->current_vote + 1);
    election->aliens[alien_index].vote[election->current_vote]++;
    election->current_vote++;
}

void display_results(Election *election) {
    if (election->current_vote >= VOTE_COUNT) {
        printf("*\n* Voting results:\n*");

        int max_votes = 0;
        int winning_index = 0;

        for (int i = 0; i < election->num_aliens; i++) {
            int sum_votes = 0;

            for (int j = 0; j < VOTE_COUNT; j++) {
                sum_votes += election->aliens[i].vote[j];
            }

            if (sum_votes > max_votes) {
                max_votes = sum_votes;
                winning_index = i;
            }
        }

        printf("*\n* The winner is Alien %s with %d votes\n*", election->aliens[winning_index].name, max_votes);
    } else {
        printf("*\n* Voting is still in progress\n*");
    }
}

int main() {
    srand(time(NULL));

    Election iccevs;
    iccevs.num_aliens = 0;
    iccevs.current_vote = 0;

    welcome();

    for (int i = 0; i < rand() % 10 + 5; i++) {
        register_alien(&iccevs);
    }

    while (true) {
        cast_vote(&iccevs);
    }

    display_results(&iccevs);

    return 0;
}
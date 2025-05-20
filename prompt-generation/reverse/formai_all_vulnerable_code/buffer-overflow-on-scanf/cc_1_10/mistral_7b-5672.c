//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VOTERS 50
#define MAX_STARS 5

typedef struct {
    char name[30];
    int votes[MAX_STARS];
} Voter;

void print_stars() {
    for(int i = 1; i <= MAX_STARS; i++) {
        printf("Star %d: ", i);
    }
    printf("\n");
}

int main() {
    int num_voters = 0;
    Voter voters[MAX_VOTERS];
    int total_votes = 0;

    printf("\n------------------------\n");
    printf("* StarVote - Ada Lovelace's Voting System *\n");
    printf("------------------------\n");

    do {
        char voter_name[30];
        int voter_age;
        int star_voted;

        printf("\nEnter your name: ");
        scanf("%s", voter_name);
        printf("Enter your age: ");
        scanf("%d", &voter_age);

        if(voter_age < 18 || strlen(voter_name) > 29) {
            printf("\nYou are not eligible to vote.\n");
            continue;
        }

        strcpy(voters[num_voters].name, voter_name);

        print_stars();
        for(int i = 0; i < MAX_STARS; i++) {
            int choice;
            do {
                printf("Enter your choice (0 to abandon): ");
                scanf("%d", &choice);
                if(choice < 0 || choice > MAX_STARS) {
                    printf("\nInvalid choice. Please choose a valid star number.\n");
                }
            } while(choice < 0 || choice > MAX_STARS);

            voters[num_voters].votes[i] = choice;
        }

        total_votes += MAX_STARS;
        num_voters++;

    } while(num_voters < MAX_VOTERS);

    printf("\n------------------------\n");
    printf("* Results *\n");
    printf("------------------------\n");

    for(int i = 0; i < num_voters; i++) {
        printf("\nName: %s", voters[i].name);
        printf("\nVotes:");
        for(int j = 0; j < MAX_STARS; j++) {
            printf("\nStar %d: %d votes", j+1, voters[i].votes[j]);
        }
    }

    printf("\n------------------------\n");
    printf("* Total votes: %d *\n", total_votes);
    printf("------------------------\n");

    return 0;
}
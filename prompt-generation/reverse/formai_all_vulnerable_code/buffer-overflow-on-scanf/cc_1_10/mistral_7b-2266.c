//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int id;
    char name[50];
    char choice[10];
} Voter;

void register_voter(Voter voters[], int *num_voters) {
    Voter new_voter;
    if (*num_voters < 100) {
        printf("Enter voter ID: ");
        scanf("%d", &new_voter.id);
        printf("Enter voter name: ");
        scanf("%s", new_voter.name);
        strcpy(new_voter.choice, "Love"); // Every voter will choose love in this romantic system!
        voters[*num_voters++] = new_voter;
        printf("Voter registered successfully!\n");
    } else {
        printf("Maximum number of voters reached!\n");
    }
}

void count_votes(Voter voters[], int num_voters) {
    int love_votes = 0;
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(voters[i].choice, "Love") == 0) {
            love_votes++;
        }
    }
    printf("Total number of voters: %d\n", num_voters);
    printf("Number of voters who chose Love: %d\n", love_votes);
}

int main() {
    Voter voters[100];
    int num_voters = 0;
    bool continue_registering = true;
    while (continue_registering) {
        register_voter(voters, &num_voters);
        printf("Do you want to register another voter? (y/n): ");
        char answer[10];
        scanf("%s", answer);
        if (strcmp(answer, "n") == 0) {
            continue_registering = false;
        }
    }
    count_votes(voters, num_voters);
    return 0;
}

// In this romantic C Electronic Voting System, every voter is bound to choose 'Love'!
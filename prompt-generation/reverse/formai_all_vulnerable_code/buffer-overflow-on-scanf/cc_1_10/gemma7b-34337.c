//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
    char name[50];
    int vote;
    int uniqueID;
} Voter;

Voter voters[MAX_VOTES];

void initializeVoters() {
    for (int i = 0; i < MAX_VOTES; i++) {
        voters[i].uniqueID = i;
    }
}

void castVote(char candidate) {
    for (int i = 0; i < MAX_VOTES; i++) {
        if (voters[i].vote == candidate) {
            printf("Error: You have already voted.\n");
            return;
        }
    }

    for (int i = 0; i < MAX_VOTES; i++) {
        if (voters[i].uniqueID == 0) {
            voters[i].vote = candidate;
            break;
        }
    }

    printf("Vote cast successfully.\n");
}

int main() {
    initializeVoters();

    char candidate;

    printf("Enter the candidate you want to vote for (1-5): ");
    scanf("%c", &candidate);

    castVote(candidate);

    return 0;
}
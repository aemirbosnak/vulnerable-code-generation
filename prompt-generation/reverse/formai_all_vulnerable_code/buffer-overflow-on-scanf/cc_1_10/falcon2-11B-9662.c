//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    char* name;
    int age;
} Person;

typedef struct {
    char* name;
    int votes;
} Candidate;

int main() {
    // Initializing candidate data
    Candidate candidates[] = {
        {"Candidate A", 0},
        {"Candidate B", 0},
        {"Candidate C", 0},
        {"Candidate D", 0},
        {"Candidate E", 0},
    };
    int numCandidates = sizeof(candidates) / sizeof(Candidate);

    // Voting process
    for (int i = 0; i < numCandidates; i++) {
        printf("Candidate: %s\n", candidates[i].name);
        int choice;
        printf("Enter your vote: ");
        scanf("%d", &choice);
        candidates[i].votes++;
    }

    // Counting votes
    int maxVotes = 0;
    int maxIndex = 0;
    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            maxIndex = i;
        }
    }

    // Outputting the winner
    printf("The winner is: %s with %d votes.\n", candidates[maxIndex].name, maxVotes);

    return 0;
}
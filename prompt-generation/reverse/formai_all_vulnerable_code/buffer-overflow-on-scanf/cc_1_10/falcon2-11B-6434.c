//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VOTERS 100
#define MAX_NOMINEES 10
#define MAX_VOTES 10

// Candidate struct
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Candidate array
Candidate candidates[MAX_NOMINEES];

// Voter struct
typedef struct {
    char name[50];
    int vote[MAX_VOTES];
} Voter;

// Voter array
Voter voters[MAX_VOTERS];

// Main function
int main() {
    srand(time(NULL));

    // Initialize candidate names and votes
    for(int i = 0; i < MAX_NOMINEES; i++) {
        candidates[i].name[0] = 'A';
        candidates[i].name[1] = 'r' + rand() % 26;
        candidates[i].name[2] = 'b' + rand() % 26;
        candidates[i].name[3] = 'u' + rand() % 26;
        candidates[i].name[4] = 't';
        candidates[i].votes = 0;
    }

    // Initialize voter names
    for(int i = 0; i < MAX_VOTERS; i++) {
        voters[i].name[0] = 'V';
        voters[i].name[1] = 'o' + rand() % 26;
        voters[i].name[2] = 't' + rand() % 26;
        voters[i].name[3] = 'e' + rand() % 26;
        voters[i].name[4] = 'r';
    }

    // Print out candidates and voters
    printf("Candidates:\n");
    for(int i = 0; i < MAX_NOMINEES; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("\nVoters:\n");
    for(int i = 0; i < MAX_VOTERS; i++) {
        printf("%s\n", voters[i].name);
    }

    // Voting process
    printf("Voting in progress...\n");
    for(int i = 0; i < MAX_VOTERS; i++) {
        printf("Vote for candidate: ");
        scanf("%d", &voters[i].vote[0]);
        for(int j = 1; j < MAX_VOTES; j++) {
            printf("Vote for candidate: ");
            scanf("%d", &voters[i].vote[j]);
        }
        printf("\n");
    }

    // Calculate winner
    int max_votes = 0;
    int winner_index = -1;
    for(int i = 0; i < MAX_NOMINEES; i++) {
        if(candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }
    printf("Winner: %s - %d votes\n", candidates[winner_index].name, max_votes);

    return 0;
}
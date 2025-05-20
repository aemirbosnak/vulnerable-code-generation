//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct candidate {
    char name[MAX];
    int votes;
};

struct voter {
    char name[MAX];
    int id;
    int hasVoted;
};

struct candidate candidates[50];
struct voter voters[50];
int numCandidates = 0;
int numVoters = 0;

void add_candidate(char name[MAX]) {
    strcpy(candidates[numCandidates].name, name);
    candidates[numCandidates].votes = 0;
    numCandidates++;
}

void add_voter(char name[MAX], int id) {
    strcpy(voters[numVoters].name, name);
    voters[numVoters].id = id;
    voters[numVoters].hasVoted = 0;
    numVoters++;
}

int check_voter(int id) {
    int i;
    for (i = 0; i < numVoters; i++) {
        if (voters[i].id == id) {
            if (voters[i].hasVoted == 0) {
                voters[i].hasVoted = 1;
                return 1;
            } else {
                return 0;
            }
        }
    }
    return 0;
}

void print_results() {
    int i;
    printf("\n-------- RESULTS --------\n");
    for (i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("-------------------------\n\n");
}

int main() {

    add_candidate("John Doe");
    add_candidate("Jane Smith");

    add_voter("Bob", 1234);
    add_voter("Alice", 5678);

    int vote = -1;
    int id;

    while (vote != 0) {
        printf("Enter your voter ID (0 to exit): ");
        scanf("%d", &id);

        if (id == 0)
            break;

        if (check_voter(id)) {
            printf("Choose a candidate:\n");
            int i;
            for (i = 0; i < numCandidates; i++) {
                printf("%d. %s\n", i+1, candidates[i].name);
            }
            scanf("%d", &vote);

            if (vote >= 1 && vote <= numCandidates) {
                candidates[vote-1].votes++;
                printf("Thank you for voting!\n");
            } else {
                printf("Invalid candidate number.\n");
            }
        } else {
            printf("You have already voted.\n");
        }
    }

    print_results();

    return 0;
}
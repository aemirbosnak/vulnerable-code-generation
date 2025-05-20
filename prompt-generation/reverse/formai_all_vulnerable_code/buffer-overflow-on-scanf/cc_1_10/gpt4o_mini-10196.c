//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 5
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[NAME_LENGTH];
    int age;
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void registerCandidate() {
    if (candidateCount < MAX_CANDIDATES) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[candidateCount].name);
        candidates[candidateCount].votes = 0;
        candidateCount++;
        printf("Candidate %s has been registered!\n", candidates[candidateCount - 1].name);
    } else {
        printf("Cannot register more candidates. Maximum limit reached!\n");
    }
}

void registerVoter() {
    if (voterCount < MAX_VOTERS) {
        printf("Enter your name: ");
        scanf("%s", voters[voterCount].name);
        printf("Enter your age: ");
        scanf("%d", &voters[voterCount].age);
        voters[voterCount].hasVoted = 0;
        voterCount++;
        printf("Voter %s has been registered!\n", voters[voterCount - 1].name);
    } else {
        printf("Cannot register more voters. Maximum limit reached!\n");
    }
}

void castVote() {
    char voterName[NAME_LENGTH];
    printf("Enter your name to cast your vote: ");
    scanf("%s", voterName);
    
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            if (voters[i].hasVoted == 0) {
                printf("Choose a candidate to vote:\n");
                for (int j = 0; j < candidateCount; j++) {
                    printf("%d: %s\n", j + 1, candidates[j].name);
                }
                int choice;
                printf("Enter candidate number: ");
                scanf("%d", &choice);
                if (choice > 0 && choice <= candidateCount) {
                    candidates[choice - 1].votes++;
                    voters[i].hasVoted = 1;
                    printf("Your vote for %s has been cast!\n", candidates[choice - 1].name);
                } else {
                    printf("Invalid choice! Voting session terminated!\n");
                }
            } else {
                printf("You have already voted!\n");
            }
            return;
        }
    }
    printf("Voter not found!\n");
}

void displayResults() {
    printf("\n------ Election Results ------\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void dramaticTwist() {
    printf("\n!! SHOCKING TWIST !! The voting system was rigged!!\n");
    printf("All votes will be reversed! Prepare for chaos...\n");

    for (int i = 0; i < candidateCount; i++) {
        candidates[i].votes = -candidates[i].votes; // Inverts votes for shock
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Register Candidate\n2. Register Voter\n3. Cast Vote\n4. Display Results\n5. Dramatic Twist!\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerCandidate();
                break;
            case 2:
                registerVoter();
                break;
            case 3:
                castVote();
                break;
            case 4:
                displayResults();
                break;
            case 5:
                dramaticTwist();
                break;
            case 6:
                printf("Exiting the voting system. Chaos is unavoidable!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
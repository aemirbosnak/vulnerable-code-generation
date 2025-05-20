//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 5

typedef struct {
    char name[50];
    int voteCount;
} Candidate;

typedef struct {
    char name[50];
    int voted; // 0 = not voted, 1 = voted
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void addCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("🎉 Maximum candidates reached! 🎉\n");
        return;
    }
    
    printf("Enter the candidate's name: ");
    scanf("%s", candidates[candidateCount].name);
    candidates[candidateCount].voteCount = 0;
    candidateCount++;
    printf("🎊 Candidate %s added successfully! 🎊\n", candidates[candidateCount - 1].name);
}

void registerVoter() {
    if (voterCount >= MAX_VOTERS) {
        printf("🎉 Maximum voters reached! 🎉\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", voters[voterCount].name);
    voters[voterCount].voted = 0;
    voterCount++;
    printf("🗳️ Welcome %s, you are registered to vote! 🗳️\n", voters[voterCount - 1].name);
}

void castVote() {
    char voterName[50];
    
    printf("Enter your name: ");
    scanf("%s", voterName);
    
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voterName, voters[i].name) == 0) {
            if (voters[i].voted) {
                printf("🚫 Oops! You have already voted! 🚫\n");
                return;
            }

            printf("🎈 Here are the candidates! 🎈\n");
            for (int j = 0; j < candidateCount; j++) {
                printf("%d. %s\n", j + 1, candidates[j].name);
            }

            int choice;
            printf("Please enter the number of your choice: ");
            scanf("%d", &choice);
            
            if (choice > 0 && choice <= candidateCount) {
                candidates[choice - 1].voteCount++;
                voters[i].voted = 1;
                printf("🎉 Thank you for voting! Your vote for %s has been counted! 🎉\n", candidates[choice - 1].name);
            } else {
                printf("🚫 Invalid choice! Please try again. 🚫\n");
            }
            return;
        }
    }
    printf("🚫 Voter not found! Please register first. 🚫\n");
}

void tallyVotes() {
    printf("\n🏆 Voting Results 🏆\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].voteCount);
    }
}

void displayMenu() {
    printf("\n🎉 Welcome to the Electronic Voting System! 🎉\n");
    printf("1. Add Candidate\n");
    printf("2. Register Voter\n");
    printf("3. Cast Vote\n");
    printf("4. Tally Votes\n");
    printf("5. Exit\n");
    printf("Please select an option: ");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                registerVoter();
                break;
            case 3:
                castVote();
                break;
            case 4:
                tallyVotes();
                break;
            case 5:
                printf("🎊 Thank you for using the Electronic Voting System! Goodbye! 🎊\n");
                exit(0);
            default:
                printf("🚫 Invalid selection! Please choose again. 🚫\n");
        }
    }
    
    return 0;
}
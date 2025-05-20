//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10
#define CANDIDATE_NAME_LENGTH 50

typedef struct {
    char name[CANDIDATE_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    int voterId;
    char ballot[MAX_CANDIDATES];
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];

int candidateCount = 0;
int voterCount = 0;

void surrealWelcome() {
    printf("Welcome to the land of whimsical ballots and ephemeral choices!\n");
    printf("In this realm, your vote dances like a butterfly before the moonlight.\n");
}

void addCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("The canvas is full, no more candidates can be added!\n");
        return;
    }
    printf("Enter the name of the candidate (%d remaining): ", MAX_CANDIDATES - candidateCount);
    scanf("%s", candidates[candidateCount].name);
    candidates[candidateCount].votes = 0;
    candidateCount++;
    printf("Oh! A new candidate has sprung to life, like a flower in the desert!\n");
}

void castVote() {
    if (voterCount >= MAX_VOTERS) {
        printf("The tapestry of voters is complete; no more souls can wander in!\n");
        return;
    }

    int id = voterCount + 1;
    printf("Welcome, voter %d, step forth and inscribe your desires!\n", id);
    printf("Choices are as follows:\n");

    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    int choice;
    printf("Choose the number of your chosen candidate: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > candidateCount) {
        printf("Ah, but you have reached for a void! Please choose a valid candidate.\n");
    } else {
        voters[voterCount].voterId = id;
        voters[voterCount].ballot[0] = choice - 1; // Save choice
        candidates[choice - 1].votes++;
        voterCount++;

        printf("Your vote has taken flight, painting the night with dreams!\n");
    }
}

void displayResults() {
    printf("\n--- Election Results ---\n");
    
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
	
    printf("\nMay the best candidate bloom into the sunlight of destiny!\n");
}

void sprinkleConfetti() {
    printf("\n✨✨ Sprinkling virtual confetti everywhere! ✨✨\n");
}

int main() {
    srand(time(NULL));
    surrealWelcome();

    int action;
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add Candidate\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit into the ether of oblivion\n");
        printf("Enter your choice: ");
        scanf("%d", &action);
        
        switch (action) {
            case 1:
                addCandidate();
                break;
            case 2:
                castVote();
                break;
            case 3:
                displayResults();
                sprinkleConfetti();
                break;
            case 4:
                printf("You have chosen to retreat into the shadows...\n");
                exit(0);
            default:
                printf("The echoes of confusion haunt this choice!\n");
                break;
        }
    }
    return 0;
}
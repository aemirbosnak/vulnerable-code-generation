//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

// Function prototypes
void initializeCandidates(Candidate candidates[], int count);
void castVote(Candidate candidates[], int count);
void displayVoteCounts(Candidate candidates[], int count);
void displayMenu();
int getUserChoice();

int main() {
    Candidate candidates[MAX_CANDIDATES];
    initializeCandidates(candidates, MAX_CANDIDATES);

    printf("🎉 Welcome to the Electronic Voting System! 🎉\n\n");
    
    int choice;
    do {
        displayMenu();
        choice = getUserChoice();

        switch (choice) {
            case 1:
                castVote(candidates, MAX_CANDIDATES);
                break;
            case 2:
                displayVoteCounts(candidates, MAX_CANDIDATES);
                break;
            case 3:
                printf("🚪 Thank you for participating! Goodbye! 🚪\n");
                break;
            default:
                printf("❌ Invalid choice! Please try again. ❌\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

void initializeCandidates(Candidate candidates[], int count) {
    strcpy(candidates[0].name, "Clever Carl");
    strcpy(candidates[1].name, "Brilliant Bella");
    strcpy(candidates[2].name, "Daring Dave");
    strcpy(candidates[3].name, "Fabulous Fiona");
    strcpy(candidates[4].name, "Genius Greg");
    for (int i = 0; i < count; i++) {
        candidates[i].votes = 0; 
    }
}

void castVote(Candidate candidates[], int count) {
    printf("\n🗳️ Please choose your candidate by entering the corresponding number:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    
    int vote;
    printf("Your vote: ");
    scanf("%d", &vote);

    if (vote < 1 || vote > count) {
        printf("🚫 Invalid candidate number! Please try again. 🚫\n");
    } else {
        candidates[vote - 1].votes++;
        printf("🎉 Thank you for voting for %s! 🎉\n", candidates[vote - 1].name);
    }
}

void displayVoteCounts(Candidate candidates[], int count) {
    printf("\n📊 Current Vote Counts 📊\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("\n");
}

void displayMenu() {
    printf("\n🌟 Menu 🌟\n");
    printf("1. Cast a Vote\n");
    printf("2. Display Vote Counts\n");
    printf("3. Exit\n");
}

int getUserChoice() {
    int choice;
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    return choice;
}
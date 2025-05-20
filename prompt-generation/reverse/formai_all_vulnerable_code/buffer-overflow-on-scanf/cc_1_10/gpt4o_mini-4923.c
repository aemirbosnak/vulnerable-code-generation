//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_CANDIDATES 5

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char username[50];
    int hasVoted;
} User;

void registerUser(User users[], int *userCount) {
    char username[50];
    printf("Enter username to register: ");
    scanf("%s", username);

    for(int i = 0; i < *userCount; i++) {
        if(strcmp(users[i].username, username) == 0) {
            printf("Username already exists! Try again.\n");
            return;
        }
    }

    strcpy(users[*userCount].username, username);
    users[*userCount].hasVoted = 0;
    (*userCount)++;
    printf("User registered successfully!\n");
}

void castVote(User users[], int userCount, Candidate candidates[], int candidateCount) {
    char username[50];
    printf("Enter username to vote: ");
    scanf("%s", username);

    int userIndex = -1;
    for(int i = 0; i < userCount; i++) {
        if(strcmp(users[i].username, username) == 0) {
            userIndex = i;
            break;
        }
    }

    if(userIndex == -1) {
        printf("User not found! Please register first.\n");
        return;
    }
    
    if(users[userIndex].hasVoted) {
        printf("User has already voted! Cannot vote again.\n");
        return;
    }

    printf("Available candidates:\n");
    for(int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    int vote;
    printf("Choose candidate number: ");
    scanf("%d", &vote);

    if(vote < 1 || vote > candidateCount) {
        printf("Invalid candidate number! Vote not counted.\n");
        return;
    }

    candidates[vote - 1].votes++;
    users[userIndex].hasVoted = 1;
    printf("Vote recorded for %s!\n", candidates[vote - 1].name);
}

void displayResults(Candidate candidates[], int candidateCount) {
    printf("Voting Results:\n");
    for(int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    User users[MAX_USERS];
    int userCount = 0;

    Candidate candidates[MAX_CANDIDATES] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Charlie", 0},
        {"Diana", 0},
        {"Eve", 0}
    };
    int candidateCount = MAX_CANDIDATES;

    int choice;
    do {
        printf("\nElectronic Voting System\n");
        printf("1. Register User\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser(users, &userCount);
                break;
            case 2:
                castVote(users, userCount, candidates, candidateCount);
                break;
            case 3:
                displayResults(candidates, candidateCount);
                break;
            case 4:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
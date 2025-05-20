//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ID 1000
#define NUM_CANDIDATES 5

// Struct to store candidate information
typedef struct {
    int id;
    char name[20];
    int votes;
} Candidate;

Candidate candidates[NUM_CANDIDATES];

// Function to check if ID is valid
bool isValidID(int id) {
    return id >= 0 && id < MAX_ID;
}

// Function to check if candidate number is valid
bool isValidCandidate(int candidate) {
    return candidate >= 0 && candidate < NUM_CANDIDATES;
}

int main() {
    // Initialize candidate names
    strcpy(candidates[0].name, "John Doe");
    strcpy(candidates[1].name, "Jane Smith");
    strcpy(candidates[2].name, "Mike Johnson");
    strcpy(candidates[3].name, "Sarah Lee");
    strcpy(candidates[4].name, "Bob Brown");

    int id, candidate;

    while (true) {
        printf("Please enter your ID number: ");
        scanf("%d", &id);

        if (!isValidID(id)) {
            printf("Invalid ID number. Please try again.\n");
            continue;
        }

        printf("Please enter the number of the candidate you wish to vote for: ");
        scanf("%d", &candidate);

        if (!isValidCandidate(candidate)) {
            printf("Invalid candidate number. Please try again.\n");
            continue;
        }

        candidates[candidate].votes++;
        printf("Thank you for voting. Your vote has been recorded.\n");

        printf("Do you have another ID number to register? (1 for yes, 0 for no): ");
        int anotherID;
        scanf("%d", &anotherID);

        if (anotherID == 0) {
            break;
        }
    }

    printf("\nFinal results:\n");

    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}
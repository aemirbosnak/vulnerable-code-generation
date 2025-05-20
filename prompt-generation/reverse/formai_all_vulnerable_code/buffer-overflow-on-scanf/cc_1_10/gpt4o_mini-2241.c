//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_LENGTH 50

typedef struct {
    char name[MAX_LENGTH];
    int votes;
} Candidate;

typedef struct {
    Candidate candidates[MAX_CANDIDATES];
    int candidate_count;
} Election;

void initElection(Election* election) {
    election->candidate_count = 0;
}

void addCandidate(Election* election, const char* name) {
    if (election->candidate_count >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }
    strcpy(election->candidates[election->candidate_count].name, name);
    election->candidates[election->candidate_count].votes = 0;
    election->candidate_count++;
}

void castVote(Election* election, const char* name) {
    for (int i = 0; i < election->candidate_count; i++) {
        if (strcmp(election->candidates[i].name, name) == 0) {
            election->candidates[i].votes++;
            return;
        }
    }
    printf("Candidate not found: %s\n", name);
}

void displayResults(const Election* election) {
    printf("Election Results:\n");
    for (int i = 0; i < election->candidate_count; i++) {
        printf("%s: %d votes\n", election->candidates[i].name, election->candidates[i].votes);
    }
}

void declareWinner(const Election* election) {
    int max_votes = -1;
    char winner[MAX_LENGTH];
    
    for (int i = 0; i < election->candidate_count; i++) {
        if (election->candidates[i].votes > max_votes) {
            max_votes = election->candidates[i].votes;
            strcpy(winner, election->candidates[i].name);
        }
    }

    if (max_votes == 0) {
        printf("No votes were cast.\n");
    } else {
        printf("The winner is: %s with %d votes!\n", winner, max_votes);
    }
}

void saveResultsToFile(const Election* election, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    for (int i = 0; i < election->candidate_count; i++) {
        fprintf(file, "%s: %d votes\n", election->candidates[i].name, election->candidates[i].votes);
    }

    fclose(file);
}

char* getInput(char* buffer, size_t size) {
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
    return buffer;
}

int main() {
    Election election;
    initElection(&election);
    char name[MAX_LENGTH];
    int choice;

    printf("Welcome to the Electronic Voting System!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Candidate\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Declare Winner\n");
        printf("5. Save Results to File\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        
        scanf("%d", &choice);
        getchar();  // consume the newline character left in the buffer

        switch (choice) {
            case 1:
                printf("Enter candidate name: ");
                getInput(name, MAX_LENGTH);
                addCandidate(&election, name);
                break;
            case 2:
                printf("Enter candidate name to vote: ");
                getInput(name, MAX_LENGTH);
                castVote(&election, name);
                break;
            case 3:
                displayResults(&election);
                break;
            case 4:
                declareWinner(&election);
                break;
            case 5:
                saveResultsToFile(&election, "results.txt");
                printf("Results saved to results.txt\n");
                break;
            case 6:
                printf("Exiting the Electronic Voting System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}
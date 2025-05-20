//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 5

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char name[50];
    int hasVoted;
} Voter;

// Function prototypes
void registerVoter(Voter voters[], int *voterCount);
void castVote(Candidate candidates[], Voter voters[], int voterCount);
void viewResults(Candidate candidates[], int candidateCount);
void loadCandidates(Candidate candidates[], int *candidateCount);
void saveResults(Candidate candidates[], int candidateCount);

int main() {
    Voter voters[MAX_VOTERS];
    Candidate candidates[MAX_CANDIDATES];
    int voterCount = 0;
    int candidateCount = 0;
    int choice;

    loadCandidates(candidates, &candidateCount);

    do {
        printf("\n===== Electronic Voting System =====\n");
        printf("1. Register to vote\n");
        printf("2. Cast your vote\n");
        printf("3. View results\n");
        printf("4. Exit\n");
        printf("====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerVoter(voters, &voterCount);
                break;
            case 2:
                castVote(candidates, voters, voterCount);
                break;
            case 3:
                viewResults(candidates, candidateCount);
                break;
            case 4:
                saveResults(candidates, candidateCount);
                printf("Thank you for using the E-Voting System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void registerVoter(Voter voters[], int *voterCount) {
    if (*voterCount >= MAX_VOTERS) {
        printf("Voter registration limit reached.\n");
        return;
    }

    char name[50];
    printf("Enter your name to register: ");
    scanf("%s", name);

    // Check if the voter is already registered
    for (int i = 0; i < *voterCount; i++) {
        if (strcmp(voters[i].name, name) == 0) {
            printf("You are already registered.\n");
            return;
        }
    }

    // Register the voter
    strcpy(voters[*voterCount].name, name);
    voters[*voterCount].hasVoted = 0; // Initially has not voted
    (*voterCount)++;
    printf("Successfully registered %s.\n", name);
}

void castVote(Candidate candidates[], Voter voters[], int voterCount) {
    char name[50];
    printf("Enter your name to vote: ");
    scanf("%s", name);

    // Find the voter
    int voterIndex = -1;
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].name, name) == 0) {
            voterIndex = i;
            break;
        }
    }

    if (voterIndex == -1) {
        printf("You need to register before voting.\n");
        return;
    }

    if (voters[voterIndex].hasVoted) {
        printf("You have already voted!\n");
        return;
    }

    printf("Candidates:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    int choice;
    printf("Enter the number of the candidate you want to vote for: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > MAX_CANDIDATES) {
        printf("Invalid candidate choice!\n");
        return;
    }

    candidates[choice - 1].votes++;
    voters[voterIndex].hasVoted = 1;
    printf("Thank you for voting for %s!\n", candidates[choice - 1].name);
}

void viewResults(Candidate candidates[], int candidateCount) {
    printf("\n===== Voting Results =====\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("===========================\n");
}

void loadCandidates(Candidate candidates[], int *candidateCount) {
    FILE *file = fopen("candidates.txt", "r");
    if (file == NULL) {
        printf("Error loading candidates. Please check if the file exists.\n");
        exit(1);
    }

    while (fscanf(file, "%s", candidates[*candidateCount].name) != EOF) {
        candidates[*candidateCount].votes = 0; // Initialize vote count to zero
        (*candidateCount)++;
    }

    fclose(file);
}

void saveResults(Candidate candidates[], int candidateCount) {
    FILE *file = fopen("results.txt", "w");
    if (file == NULL) {
        printf("Error saving results.\n");
        return;
    }

    for (int i = 0; i < candidateCount; i++) {
        fprintf(file, "%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    fclose(file);
}
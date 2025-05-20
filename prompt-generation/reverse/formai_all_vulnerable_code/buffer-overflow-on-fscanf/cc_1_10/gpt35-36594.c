//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* STRUCTS */

typedef struct candidate {
    int id;
    char name[50];
    int votes;
} candidate;

typedef struct voter {
    int id;
    char name[50];
    int hasVoted;
} voter;

/* FUNCTIONS */

/* counts number of lines in file */
int count_lines(FILE* file) {
    int lines = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') lines++;
    }
    rewind(file); // return to beginning of file
    return lines;
}

/* reads in candidates from file */
void read_candidates(candidate* candidates, FILE* file) {
    int i = 0;
    while (fscanf(file, "%d %s", &(candidates[i].id), candidates[i].name) != EOF) {
        candidates[i].votes = 0;
        i++;
    }
}

/* reads in voters from file */
void read_voters(voter* voters, FILE* file) {
    int i = 0;
    while (fscanf(file, "%d %s", &(voters[i].id), voters[i].name) != EOF) {
        voters[i].hasVoted = 0;
        i++;
    }
}

/* prints out list of candidates */
void print_candidates(candidate* candidates, int numCandidates) {
    printf("Candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }
    printf("\n");
}

/* prints out list of voters */
void print_voters(voter* voters, int numVoters) {
    printf("Voters:\n");
    for (int i = 0; i < numVoters; i++) {
        printf("%d. %s\n", voters[i].id, voters[i].name);
    }
    printf("\n");
}

/* allows voter to cast vote */
void vote(candidate* candidates, int numCandidates, voter* voters, int numVoters) {
    int voterId, candidateId;
    printf("Enter your ID: ");
    scanf("%d", &voterId);
    for (int i = 0; i < numVoters; i++) {
        if (voters[i].id == voterId) {
            if (voters[i].hasVoted) {
                printf("You have already voted!\n");
                return;
            }
            printf("Enter candidate ID: ");
            scanf("%d", &candidateId);
            for (int j = 0; j < numCandidates; j++) {
                if (candidates[j].id == candidateId) {
                    candidates[j].votes++;
                    voters[i].hasVoted = 1;
                    printf("Vote cast for %s\n", candidates[j].name);
                    return;
                }
            }
            printf("Invalid candidate ID\n");
            return;
        }
    }
    printf("Invalid voter ID\n");
    return;
}

/* selects winner of election */
void select_winner(candidate* candidates, int numCandidates) {
    candidate winner = candidates[0];
    for (int i = 1; i < numCandidates; i++) {
        if (candidates[i].votes > winner.votes) {
            winner = candidates[i];
        }
    }
    printf("The winner is %s with %d votes!\n", winner.name, winner.votes);
}

/* MAIN PROGRAM */

int main() {
    FILE* candidateFile;
    FILE* voterFile;
    candidateFile = fopen("candidates.txt", "r");
    voterFile = fopen("voters.txt", "r");

    if (candidateFile == NULL || voterFile == NULL) {
        printf("Error reading input files\n");
        return 0;
    }

    int numCandidates = count_lines(candidateFile);
    int numVoters = count_lines(voterFile);

    candidate* candidates = (candidate*)malloc(numCandidates * sizeof(candidate));
    voter* voters = (voter*)malloc(numVoters * sizeof(voter));

    read_candidates(candidates, candidateFile);
    read_voters(voters, voterFile);

    printf("Welcome to the post-apocalyptic electronic voting system!\n");

    int choice;
    do {
        printf("1. Print list of candidates and voters\n");
        printf("2. Cast vote\n");
        printf("3. Select winner\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                print_candidates(candidates, numCandidates);
                print_voters(voters, numVoters);
                break;
            case 2:
                vote(candidates, numCandidates, voters, numVoters);
                break;
            case 3:
                select_winner(candidates, numCandidates);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);

    fclose(candidateFile);
    fclose(voterFile);
    free(candidates);
    free(voters);

    return 0;
}
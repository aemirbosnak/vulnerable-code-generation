//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VOTERS 1000
#define MAX_OPTIONS 5

typedef struct {
    char name[50];
    int age;
    int option;
} Voter;

int main() {
    int num_voters, i, option, total_votes = 0;
    Voter voters[MAX_VOTERS];
    char fileName[50] = "voting_log.txt";

    printf("Welcome to the Electronic Voting System!\n");
    printf("--------------------------------------\n");

    // Read the number of voters from a file or user input
    FILE *file = fopen(fileName, "r");
    if (file != NULL) {
        fscanf(file, "%d", &num_voters);
        fclose(file);
    } else {
        printf("Error: Could not read the number of voters.\n");
        return 1;
    }

    printf("There are %d registered voters.\n", num_voters);

    for (i = 0; i < num_voters; i++) {
        printf("\nVoter %d:\n", i + 1);
        printf("Enter your name: ");
        scanf("%s", voters[i].name);
        printf("Enter your age: ");
        scanf("%d", &voters[i].age);

        // Allow the voter to cast their vote
        printf("Choose your preferred option (1-5): ");
        scanf("%d", &option);
        voters[i].option = option;

        // Increment the total number of votes
        total_votes++;
    }

    // Count the number of votes for each option
    int votes[MAX_OPTIONS] = {0};

    for (i = 0; i < num_voters; i++) {
        votes[voters[i].option - 1]++;
    }

    // Display the results
    printf("\nResults:\n");
    for (i = 0; i < MAX_OPTIONS; i++) {
        printf("Option %d: %d votes\n", i + 1, votes[i]);
    }

    // Save the voting data to a file
    file = fopen(fileName, "w");
    if (file != NULL) {
        fprintf(file, "%d\n", num_voters);
        for (i = 0; i < num_voters; i++) {
            fprintf(file, "%s %d %d\n", voters[i].name, voters[i].age, voters[i].option);
        }
        fclose(file);
    } else {
        printf("Error: Could not write to the voting log file.\n");
        return 1;
    }

    printf("\nVoting completed successfully!\n");

    return 0;
}
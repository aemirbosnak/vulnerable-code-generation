//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPTIONS 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 20

typedef struct Option {
    int optionID;
    char optionName[MAX_NAME_LENGTH];
    int voteCount; 
} Option;

typedef struct Voter {
    int voterID;
    char voterName[MAX_NAME_LENGTH];
    int hasVoted;
} Voter;

void printOptions(Option options[], int numOptions) {
    printf("Options:\n");
    for (int i = 0; i < numOptions; i++) {
        printf("%d. %s\n", options[i].optionID, options[i].optionName);
    }
}

void printVoters(Voter voters[], int numVoters) {
    printf("Voters:\n");
    for (int i = 0; i < numVoters; i++) {
        printf("%d. %s\n", voters[i].voterID, voters[i].voterName);
    }
}

int isValidOption(int selectedOption, Option options[], int numOptions) {
    for (int i = 0; i < numOptions; i++) {
        if (options[i].optionID == selectedOption) {
            return 1;
        }
    }
    return 0;
}

int isValidVoter(int voterID, Voter voters[], int numVoters) {
    for (int i = 0; i < numVoters; i++) {
        if (voters[i].voterID == voterID && voters[i].hasVoted == 0) {
            return 1;
        }
    }
    return 0;
}

void vote(int selectedOption, Option options[], int numOptions, int voterID, Voter voters[], int numVoters) {
    for (int i = 0; i < numOptions; i++) {
        if (options[i].optionID == selectedOption) {
            options[i].voteCount++;
        }
    }
    for (int i = 0; i < numVoters; i++) {
        if (voters[i].voterID == voterID) {
            voters[i].hasVoted = 1;
        }
    }
    printf("Successful vote!\n");
}

int main() {
    int numOptions;
    printf("Enter the number of voting candidates: ");
    scanf("%d", &numOptions);

    Option options[MAX_OPTIONS];
    for (int i = 0; i < numOptions; i++) {
        options[i].optionID = i+1;
        printf("Enter the name of candidate #%d: ", i+1);
        scanf("%s", options[i].optionName);
        options[i].voteCount = 0;
    }

    int numVoters;
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);

    Voter voters[MAX_VOTERS];
    for (int i = 0; i < numVoters; i++) {
        voters[i].voterID = i+1;
        printf("Enter the name of voter #%d: ", i+1);
        scanf("%s", voters[i].voterName);
        voters[i].hasVoted = 0;
    }

    printOptions(options, numOptions);
    printVoters(voters, numVoters);

    int selectedOption, voterID;
    printf("Enter your voter ID: ");
    scanf("%d", &voterID);

    if (isValidVoter(voterID, voters, numVoters)) {
        printOptions(options, numOptions);
        printf("Choose an option: ");
        scanf("%d", &selectedOption);
        if (isValidOption(selectedOption, options, numOptions)) {
            vote(selectedOption, options, numOptions, voterID, voters, numVoters);
        } else {
            printf("Invalid option!\n");
        }
    } else {
        printf("Invalid voter ID or voter has already voted!\n");
    }

    return 0;
}
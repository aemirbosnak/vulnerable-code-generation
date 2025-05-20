//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to store voter information
typedef struct voter {
    char name[50];
    char address[100];
    int age;
    int hasVoted;
    struct voter *next;
} Voter;

// structure to store candidate information
typedef struct candidate {
    char name[50];
    char party[50];
    int votes;
    struct candidate *next;
} Candidate;

// function to add a new voter
void addVoter(Voter **head) {
    Voter *newVoter = (Voter*)malloc(sizeof(Voter));
    printf("Enter voter name: ");
    scanf("%s", newVoter->name);
    printf("Enter voter address: ");
    scanf("%s", newVoter->address);
    printf("Enter voter age: ");
    scanf("%d", &newVoter->age);
    newVoter->hasVoted = 0;
    newVoter->next = NULL;

    if (*head == NULL) {
        *head = newVoter;
    } else {
        Voter *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newVoter;
    }
    printf("New Voter Added Successfully!\n");
}

// function to add a new candidate
void addCandidate(Candidate **head) {
    Candidate *newCandidate = (Candidate*)malloc(sizeof(Candidate));
    printf("Enter candidate name: ");
    scanf("%s", newCandidate->name);
    printf("Enter candidate party: ");
    scanf("%s", newCandidate->party);
    newCandidate->votes = 0;
    newCandidate->next = NULL;

    if (*head == NULL) {
        *head = newCandidate;
    } else {
        Candidate *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newCandidate;
    }
    printf("New Candidate Added Successfully!\n");
}

// function to display all voters
void displayVoters(Voter *head) {
    printf("List of All Voters:\n");
    while (head != NULL) {
        printf("Name: %s\n", head->name);
        printf("Age: %d\n", head->age);
        printf("Address: %s\n", head->address);
        if (head->hasVoted == 1) {
            printf("Has Voted: Yes\n");
        } else {
            printf("Has Voted: No\n");
        }
        printf("------------------------------\n");
        head = head->next;
    }
}

// function to display all candidates
void displayCandidates(Candidate *head) {
    printf("List of All Candidates:\n");
    while (head != NULL) {
        printf("Name: %s\n", head->name);
        printf("Party: %s\n", head->party);
        printf("Votes: %d\n", head->votes);
        printf("------------------------------\n");
        head = head->next;
    }
}

// function to vote for a candidate
void vote(Voter **head, Candidate **candidates) {
    char voterName[50];
    char candidateName[50];
    printf("Enter your name: ");
    scanf("%s", voterName);
    printf("Enter candidate name: ");
    scanf("%s", candidateName);

    // check if voter has already voted
    Voter *currentVoter = *head;
    while (currentVoter != NULL) {
        if (strcmp(currentVoter->name, voterName) == 0) {
            if (currentVoter->hasVoted == 1) {
                printf("Sorry, You can only vote once!\n");
                return;
            } else {
                currentVoter->hasVoted = 1;
            }
        }
        currentVoter = currentVoter->next;
    }

    // increment candidate vote count
    Candidate *currentCandidate = *candidates;
    while (currentCandidate != NULL) {
        if (strcmp(currentCandidate->name, candidateName) == 0) {
            currentCandidate->votes += 1;
            printf("Vote Successfully Submitted!\n");
            return;
        }
        currentCandidate = currentCandidate->next;
    }
    printf("Invalid Candidate Name!\n");
}

// function to print the winner of the election
void getWinner(Candidate *candidates) {
    int maxVotes = 0;
    char winner[50];
    while (candidates != NULL) {
        if (candidates->votes > maxVotes) {
            maxVotes = candidates->votes;
            strcpy(winner, candidates->name);
        }
        candidates = candidates->next;
    }
    printf("The Winner is %s with %d votes!\n", winner, maxVotes);
}

int main() {
    int choice = 0;
    Voter *voterList = NULL;
    Candidate *candidateList = NULL;

    printf("Welcome to the Electronic Voting System!\n");
    while (choice != 5) {
        printf("Choose an option from the menu:\n");
        printf("1. Add a new voter\n");
        printf("2. Add a new candidate\n");
        printf("3. Vote for a candidate\n");
        printf("4. Display election results\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addVoter(&voterList);
                break;
            case 2:
                addCandidate(&candidateList);
                break;
            case 3:
                vote(&voterList, &candidateList);
                break;
            case 4:
                displayVoters(voterList);
                displayCandidates(candidateList);
                getWinner(candidateList);
                break;
            case 5:
                printf("Thank you for using Electronic Voting System!\n");
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }
        printf("\n");
    }
    return 0;
}
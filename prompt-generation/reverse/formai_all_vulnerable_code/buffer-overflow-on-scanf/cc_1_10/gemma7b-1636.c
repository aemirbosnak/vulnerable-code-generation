//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of voters
#define MAX_VOTERS 100

// Define the structure of a voter
typedef struct voter {
    char name[50];
    int vote;
    struct voter* next;
} voter;

// Function to add a voter to the end of the list
void addVoter(voter** head) {
    voter* newVoter = (voter*)malloc(sizeof(voter));
    printf("Enter your name: ");
    scanf("%s", newVoter->name);
    newVoter->vote = 0;
    newVoter->next = NULL;

    if (*head == NULL) {
        *head = newVoter;
    } else {
        (*head)->next = newVoter;
    }
}

// Function to vote
void vote(voter* head) {
    printf("Enter the candidate number you want to vote for: ");
    int candidateNumber;
    scanf("%d", &candidateNumber);

    // Iterate over the list of voters and find the voter with the same name
    voter* currentVoter = head;
    while (currentVoter) {
        if (strcmp(currentVoter->name, head->name) == 0) {
            // If the voter has already voted, display an error message
            if (currentVoter->vote == 1) {
                printf("You have already voted.\n");
                return;
            }

            // Set the voter's vote to 1
            currentVoter->vote = 1;

            // Add the vote to the candidate's total votes
            // (In a real-world system, this would be done in a separate module)
            printf("Thank you for voting, %s.\n", currentVoter->name);
            return;
        }
        currentVoter = currentVoter->next;
    }

    // If the voter is not found, display an error message
    printf("Error: Voter not found.\n");
}

int main() {
    // Create a linked list of voters
    voter* head = NULL;

    // Add some voters to the list
    addVoter(&head);
    addVoter(&head);
    addVoter(&head);

    // Vote
    vote(head);

    return 0;
}
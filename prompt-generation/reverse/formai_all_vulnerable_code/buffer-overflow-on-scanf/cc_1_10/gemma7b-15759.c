//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
    char name[20];
    int vote;
    struct Voter* next;
} Voter;

void insertVoter(Voter** head) {
    Voter* newVoter = malloc(sizeof(Voter));
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

void vote(Voter* head) {
    printf("Enter the number of the candidate you want to vote for: ");
    int candidateNumber;
    scanf("%d", &candidateNumber);

    for (Voter* currentVoter = head; currentVoter; currentVoter = currentVoter->next) {
        if (strcmp(currentVoter->name, head->name) == 0) {
            currentVoter->vote = candidateNumber;
            break;
        }
    }
}

void displayResults(Voter* head) {
    int totalVotes = 0;
    for (Voter* currentVoter = head; currentVoter; currentVoter = currentVoter->next) {
        totalVotes++;
    }

    printf("Total number of votes: %d\n", totalVotes);

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        int votes = 0;
        for (Voter* currentVoter = head; currentVoter; currentVoter = currentVoter->next) {
            if (currentVoter->vote == i) {
                votes++;
            }
        }

        printf("Candidate %d: %d votes\n", i, votes);
    }
}

int main() {
    Voter* head = NULL;
    insertVoter(&head);
    insertVoter(&head);
    insertVoter(&head);
    vote(head);
    displayResults(head);

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VOTERS 100

typedef struct Voter {
    char name[50];
    int vote;
    struct Voter* next;
} Voter;

void insertVoter(Voter** head) {
    Voter* newVoter = (Voter*)malloc(sizeof(Voter));
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

void vote(Voter** head) {
    printf("Enter the candidate number you want to vote for: ");
    int candidateNum;
    scanf("%d", &candidateNum);

    Voter* currentVoter = *head;
    while (currentVoter) {
        if (strcmp(currentVoter->name, "John Doe") == 0) {
            currentVoter->vote = candidateNum;
            break;
        }
        currentVoter = currentVoter->next;
    }

    if (currentVoter == NULL) {
        printf("Error: voter not found.\n");
    } else {
        printf("Your vote has been recorded.\n");
    }
}

void displayResults(Voter** head) {
    int totalVotes = 0;
    int candidateVotes[MAX_VOTERS] = {0};

    Voter* currentVoter = *head;
    while (currentVoter) {
        candidateVotes[currentVoter->vote]++;
        totalVotes++;
        currentVoter = currentVoter->next;
    }

    printf("Total votes: %d\n", totalVotes);

    for (int i = 0; i < MAX_VOTERS; i++) {
        if (candidateVotes[i] > 0) {
            printf("Candidate %d: %d votes\n", i, candidateVotes[i]);
        }
    }
}

int main() {
    Voter* head = NULL;

    insertVoter(&head);
    insertVoter(&head);
    insertVoter(&head);
    insertVoter(&head);

    vote(&head);
    vote(&head);

    displayResults(&head);

    return 0;
}
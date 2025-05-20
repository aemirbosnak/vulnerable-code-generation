//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 10

typedef struct Candidate {
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

Candidate* insertCandidate(Candidate* head) {
    Candidate* newNode = (Candidate*)malloc(sizeof(Candidate));
    scanf("%s", newNode->name);
    newNode->votes = 0;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void vote(Candidate* head) {
    char voterName[20];
    scanf("%s", voterName);

    Candidate* currentCandidate = head;
    while (currentCandidate) {
        if (strcmp(currentCandidate->name, voterName) == 0) {
            currentCandidate->votes++;
            break;
        }
        currentCandidate = currentCandidate->next;
    }

    if (currentCandidate == NULL) {
        printf("Voter not found.\n");
    }
}

int main() {
    Candidate* head = NULL;

    // Insert candidates
    head = insertCandidate(head);
    insertCandidate(head);
    insertCandidate(head);

    // Vote
    vote(head);

    // Print results
    Candidate* currentCandidate = head;
    while (currentCandidate) {
        printf("%s: %d votes\n", currentCandidate->name, currentCandidate->votes);
        currentCandidate = currentCandidate->next;
    }

    return 0;
}
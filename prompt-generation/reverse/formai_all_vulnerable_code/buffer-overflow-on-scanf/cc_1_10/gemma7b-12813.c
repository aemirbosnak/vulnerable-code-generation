//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure to store candidate information
typedef struct Candidate
{
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

// Define a function to add a candidate to the end of the list
void addCandidate(Candidate** head)
{
    Candidate* newCandidate = malloc(sizeof(Candidate));
    printf("Enter candidate name: ");
    scanf("%s", newCandidate->name);
    newCandidate->votes = 0;
    newCandidate->next = NULL;

    if (*head == NULL)
    {
        *head = newCandidate;
    }
    else
    {
        (*head)->next = newCandidate;
    }
}

// Define a function to vote for a candidate
void voteForCandidate(Candidate* head)
{
    char candidateName[20];
    printf("Enter candidate name: ");
    scanf("%s", candidateName);

    Candidate* currentCandidate = head;
    while (currentCandidate)
    {
        if (strcmp(candidateName, currentCandidate->name) == 0)
        {
            currentCandidate->votes++;
            printf("Vote cast for %s\n", currentCandidate->name);
            break;
        }
        currentCandidate = currentCandidate->next;
    }

    if (currentCandidate == NULL)
    {
        printf("Candidate not found\n");
    }
}

// Define a function to display the results of the election
void displayResults(Candidate* head)
{
    Candidate* currentCandidate = head;
    printf("Election Results:\n");
    while (currentCandidate)
    {
        printf("%s: %d votes\n", currentCandidate->name, currentCandidate->votes);
        currentCandidate = currentCandidate->next;
    }

    printf("The winner is: %s\n", currentCandidate->name);
}

int main()
{
    Candidate* head = NULL;

    // Add candidates to the list
    addCandidate(&head);
    addCandidate(&head);
    addCandidate(&head);

    // Vote for a candidate
    voteForCandidate(head);

    // Display the results of the election
    displayResults(head);

    return 0;
}
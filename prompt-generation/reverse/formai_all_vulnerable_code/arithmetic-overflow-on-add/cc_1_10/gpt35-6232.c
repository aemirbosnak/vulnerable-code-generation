//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: visionary
#include<stdio.h>
#include<stdlib.h>

struct node {
    int id;
    int count;
    struct node *next;
}*start = NULL;

// Function to create a new node
struct node *create_node(int id, int count) {
    struct node *temp;
    temp = (struct node *) malloc(sizeof(struct node));
    temp->id = id;
    temp->count = count;
    temp->next = NULL;
    return temp;
}

// Function to add a new candidate to the list
void add_candidate(int id) {
    struct node *temp, *current;
    if(start == NULL) {
        start = create_node(id, 0);
        return;
    }
    current = start;
    while(current->next != NULL) {
        current = current->next;
    }
    temp = create_node(id, 0);
    current->next = temp;
}

// Function to display all candidates
void display() {
    struct node *current;
    printf("\n\nCandidates\n");
    printf("-----------------------------------\n");
    current = start;
    while(current != NULL) {
        printf("ID: %d, Votes: %d\n", current->id, current->count);
        current = current->next;
    }
}

// Function to cast a vote
void cast_vote(int id) {
    struct node *current;
    current = start;
    while(current->id != id) {
        current = current->next;
    }
    current->count++;
}

int main() {
    int choice, id;
    while(1) {
        printf("\n---------------Election Voting System---------------\n");
        printf("1. Add Candidate\n");
        printf("2. Display Candidates\n");
        printf("3. Cast Vote\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter Candidate ID: ");
                    scanf("%d", &id);
                    add_candidate(id);
                    printf("Candidate Added Successfully!\n");
                    break;
            case 2: display();
                    break;
            case 3: printf("Enter Candidate ID: ");
                    scanf("%d", &id);
                    cast_vote(id);
                    printf("Vote Casted Successfully!\n");
                    break;
            case 4: printf("Exiting...\n");
                    exit(0);
            default: printf("Invalid Choice!\n");
                     break;
        }
    }
    return 0;
}
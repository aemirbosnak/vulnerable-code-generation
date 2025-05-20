//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct candidate {
    int id;
    char name[20];
    int votes;
} Candidate;

Candidate candidates[5] = {
    {1, "Alice", 0},
    {2, "Bob", 0},
    {3, "Charlie", 0},
    {4, "Dave", 0},
    {5, "Eve", 0}
};

void print_candidates() {
    printf("Candidate List:\n");
    printf("ID\tName\n");
    for(int i=0; i<5; i++) {
        printf("%d\t%s\n", candidates[i].id, candidates[i].name);
    }
}

void vote(int id) {
    for(int i=0; i<5; i++) {
        if(candidates[i].id == id) {
            candidates[i].votes++;
            printf("Successfully voted for %s\n", candidates[i].name);
            return;
        }
    }
    printf("Error: Invalid candidate ID %d\n", id);
}

void print_results() {
    printf("Election Results:\n");
    printf("Name\tVotes\n");
    for(int i=0; i<5; i++) {
        printf("%s\t%d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice, id;
    while(1) {
        printf("1. View Candidate List\n");
        printf("2. Vote for a Candidate\n");
        printf("3. View Election Results\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                print_candidates();
                break;
            case 2:
                printf("Enter candidate ID: ");
                scanf("%d", &id);
                vote(id);
                break;
            case 3:
                print_results();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
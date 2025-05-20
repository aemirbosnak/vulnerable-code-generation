//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} candidate_t;

candidate_t candidates[MAX_CANDIDATES];

void add_candidate(char* name) {
    int i;
    for(i=0; i<MAX_CANDIDATES; i++) {
        if(candidates[i].votes == 0) {
            strcpy(candidates[i].name, name);
            break;
        }
    }
}

void vote(char* voter_name, int candidate_index) {
    if(candidate_index >= 0 && candidate_index < MAX_CANDIDATES) {
        candidates[candidate_index].votes++;
    }
}

void print_results() {
    int i;
    for(i=0; i<MAX_CANDIDATES; i++) {
        if(candidates[i].votes > 0) {
            printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        }
    }
}

int main() {
    int i, j, choice;
    char name[50];

    printf("Welcome to the Electronic Voting System!\n");

    do {
        printf("\n");
        printf("1. Add candidate\n");
        printf("2. Vote\n");
        printf("3. View results\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", name);
                add_candidate(name);
                break;
            case 2:
                printf("Enter voter name: ");
                scanf("%s", name);
                printf("Enter candidate index (0 to %d): ", MAX_CANDIDATES-1);
                scanf("%d", &j);
                vote(name, j);
                break;
            case 3:
                printf("\n");
                print_results();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 4);

    return 0;
}
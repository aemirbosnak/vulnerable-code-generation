//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[100];
    int votes;
} candidate;

typedef struct {
    char name[100];
    int voted;
    int choice;
} voter;

candidate candidates[MAX_CANDIDATES];
voter voters[MAX_VOTERS];
int num_candidates = 0;
int num_voters = 0;

void add_candidate() {
    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void add_voter() {
    printf("Enter voter name: ");
    scanf("%s", voters[num_voters].name);
    voters[num_voters].voted = 0;
    voters[num_voters].choice = -1;
    num_voters++;
}

void vote() {
    printf("Enter voter name: ");
    char name[100];
    scanf("%s", name);
    int i;
    for(i=0; i<num_voters; i++) {
        if(strcmp(name, voters[i].name) == 0) {
            printf("Enter candidate number: ");
            int choice;
            scanf("%d", &choice);
            if(choice >= 0 && choice < num_candidates) {
                voters[i].voted = 1;
                voters[i].choice = choice;
                candidates[choice].votes++;
            } else {
                printf("Invalid choice\n");
            }
            return;
        }
    }
    printf("Voter not found\n");
}

void display_results() {
    int i;
    printf("\nResults:\n");
    for(i=0; i<num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    while(1) {
        printf("\nElectronic Voting System\n");
        printf("1. Add candidate\n");
        printf("2. Add voter\n");
        printf("3. Vote\n");
        printf("4. Display results\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                add_voter();
                break;
            case 3:
                vote();
                break;
            case 4:
                display_results();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
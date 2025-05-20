//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char name[50];
    int votes;
} candidate;

candidate candidates[10];
int num_candidates = 0;

void add_candidate() {
    printf("Enter the name of the candidate: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void display_candidates() {
    printf("\nCandidates:\n");
    for(int i=0; i<num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

void cast_vote() {
    int choice;
    printf("Enter the number of the candidate you want to vote for: ");
    scanf("%d", &choice);
    candidates[choice-1].votes++;
}

void display_results() {
    printf("\nResults:\n");
    for(int i=0; i<num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("\nElectronic Voting System\n");
        printf("1. Add candidate\n2. Display candidates\n3. Cast vote\n4. Display results\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                display_candidates();
                break;
            case 3:
                cast_vote();
                break;
            case 4:
                display_results();
                break;
            case 5:
                printf("Thank you for using the Electronic Voting System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= 5);

    return 0;
}
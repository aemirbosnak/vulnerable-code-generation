//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char name[50];
    int votes;
} candidate;

candidate candidates[10];

void add_candidate() {
    int i;
    printf("Enter the number of candidates (max 10): ");
    scanf("%d", &i);
    for(int j=0; j<i; j++) {
        printf("Enter the name of candidate %d: ", j+1);
        scanf("%s", candidates[j].name);
        candidates[j].votes = 0;
    }
}

void display_candidates() {
    printf("\nList of candidates:\n");
    for(int i=0; i<10; i++) {
        if(candidates[i].name[0]!= '\0') {
            printf("%d. %s\n", i+1, candidates[i].name);
        }
    }
}

void vote() {
    int choice, found=0;
    printf("\nEnter the number of the candidate you want to vote for: ");
    scanf("%d", &choice);
    for(int i=0; i<10; i++) {
        if(candidates[i].name[0]!= '\0' && i+1 == choice) {
            candidates[i].votes++;
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Invalid choice.\n");
    }
}

void display_results() {
    printf("\nResults:\n");
    for(int i=0; i<10; i++) {
        if(candidates[i].name[0]!= '\0') {
            printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        }
    }
}

int main() {
    srand(time(NULL));
    add_candidate();
    int choice;
    while(1) {
        system("clear");
        display_candidates();
        printf("\nPress 1 to vote, 2 to display results, 0 to exit: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                vote();
                break;
            case 2:
                display_results();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
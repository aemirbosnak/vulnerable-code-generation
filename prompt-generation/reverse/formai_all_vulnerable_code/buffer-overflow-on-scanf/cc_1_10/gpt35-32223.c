//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_OPTIONS 10
#define MAX_ELECTORS 1000

typedef struct {
    char name[50];
    int count;
} Option;

int nOptions;
Option options[MAX_OPTIONS];
int electors[MAX_ELECTORS];

int castVote(int elector_id) {
    int vote = -1;
    printf("\nEnter your option number: ");
    scanf("%d", &vote);

    if(vote < 1 || vote > nOptions) {
        printf("\nInvalid option number, please try again!");
        return 0;
    }

    options[vote-1].count++;
    electors[elector_id] = 1; // Mark elector as voted
    printf("\nThank you for voting!");
    return 1;
}

void displayResults() {
    printf("\nVoting Results\n");
    for(int i=0; i<nOptions; i++)
        printf("%d. %s - %d votes\n", i+1, options[i].name, options[i].count);
}

int main() {
    printf("Welcome to Electronic Voting System\n");
    printf("Please enter number of options: ");
    scanf("%d", &nOptions);

    for(int i=0; i<nOptions; i++) {
        printf("Enter name of option %d: ", i+1);
        scanf("%s", options[i].name);
        options[i].count = 0;
    }

    int nElectors;
    printf("Enter number of electors: ");
    scanf("%d", &nElectors);

    // Initialize electors
    for(int i=0; i<nElectors; i++) {
        electors[i] = 0;
    }

    char c;
    do {
        printf("\nAre you an elector? (Y/N): ");
        scanf(" %c", &c);

        if(c == 'Y' || c == 'y') {
            int id;
            printf("\nEnter your id: ");
            scanf("%d", &id);

            if(id < 0 || id >= nElectors) {
                printf("\nInvalid elector id, please try again!");
            }
            else if(electors[id] == 1) {
                printf("\nYou have already voted, thank you!");
            }
            else if(castVote(id)) {
                printf("\nWould you like to continue voting? (Y/N): ");
                scanf(" %c", &c);
            }
        }
    } while(c == 'Y' || c == 'y');

    displayResults();
    return 0;
}
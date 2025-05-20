//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int votes;
} candidate;

candidate candidates[10];

int main() {
    int i, j, choice, total_votes = 0;
    char ch;

    srand(time(0));

    // Populate candidates
    for(i = 0; i < 10; i++) {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    for(i = 0; i < 10; i++) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[i].name);
    }

    // Voting process
    while(1) {
        system("clear");
        printf("\nVoting System\n");
        for(i = 0; i < 10; i++) {
            printf("%d. %s (%d votes)\n", i+1, candidates[i].name, candidates[i].votes);
        }
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice < 1 || choice > 10) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        candidates[choice-1].votes++;
        total_votes++;

        printf("\nThank you for voting! Your vote has been counted.\n\n");

        if(total_votes >= 100) {
            printf("\nVoting closed. Results:\n");
            for(i = 0; i < 10; i++) {
                printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
            }
            break;
        }
    }

    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int age;
} Candidate;

int main() {
    Candidate candidates[4];
    int i, j;
    int total_votes = 0;

    for (i = 0; i < 4; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        printf("Enter age of candidate %d: ", i + 1);
        scanf("%d", &candidates[i].age);
    }

    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 4; j++) {
            if (strcmp(candidates[i].name, candidates[j].name) < 0) {
                char temp[strlen(candidates[i].name) + 1];
                strcpy(temp, candidates[i].name);
                strcpy(candidates[i].name, candidates[j].name);
                strcpy(candidates[j].name, temp);
            }
        }
    }

    printf("\nCandidates sorted by name:\n");
    for (i = 0; i < 4; i++) {
        printf("%d. %s - %d years old\n", i + 1, candidates[i].name, candidates[i].age);
    }

    printf("\nEnter your votes (separated by spaces): ");
    fflush(stdin);
    scanf("%s", candidates[0].name);
    scanf("%s", candidates[1].name);
    scanf("%s", candidates[2].name);
    scanf("%s", candidates[3].name);

    for (i = 0; i < 4; i++) {
        total_votes += (candidates[i].name == candidates[0].name)? 1 : 0;
    }

    if (total_votes == 4) {
        printf("\nYou voted for all candidates.\n");
    } else {
        printf("\nYou voted for: ");
        for (i = 0; i < 4; i++) {
            if (total_votes == (candidates[i].name == candidates[0].name)) {
                printf("%s ", candidates[i].name);
            }
        }
        printf("\n");
    }

    return 0;
}
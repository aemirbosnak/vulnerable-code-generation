//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct candidate {
    char* name;
    int votes;
};

struct candidate candidates[] = {
    { "A", 0 },
    { "B", 0 },
    { "C", 0 },
    { "D", 0 },
};

int main() {
    int i, total_votes = 0;
    char candidate_name[100];

    for (i = 0; i < 4; i++) {
        printf("Enter candidate name: ");
        fgets(candidate_name, 100, stdin);
        candidate_name[strcspn(candidate_name, "\n")] = '\0'; // remove newline character

        candidates[i].name = strdup(candidate_name);
        printf("Vote for %s? (y/n): ", candidate_name);
        scanf(" %c", &i);
        if (i == 'y') {
            candidates[i].votes++;
        }
    }

    srand(time(NULL));
    int winner = rand() % candidates[0].votes;
    for (i = 0; i < 4; i++) {
        if (candidates[i].votes > winner) {
            winner = candidates[i].votes;
        }
    }

    printf("Election results:\n");
    printf("---------------------\n");
    printf("Total votes: %d\n", total_votes);
    printf("---------------------\n");
    printf("Winner: %s (%d votes)\n", candidates[winner].name, candidates[winner].votes);

    return 0;
}
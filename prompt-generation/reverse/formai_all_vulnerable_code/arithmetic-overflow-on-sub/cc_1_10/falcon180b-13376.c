//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char name[50];
    int votes;
} candidate;

int main() {
    int num_candidates, num_voters, i, j, valid_vote = 0, max_votes = 0;
    char choice;
    candidate candidates[10];
    time_t start_time, end_time;

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    srand(time(NULL));
    start_time = time(NULL);

    for (i = 0; i < num_voters; i++) {
        valid_vote = 0;

        while (!valid_vote) {
            printf("Voter %d, enter your choice (1-%d): ", i + 1, num_candidates);
            scanf("%c", &choice);

            for (j = 0; j < num_candidates; j++) {
                if (tolower(choice) == tolower(candidates[j].name[0])) {
                    candidates[j].votes++;
                    valid_vote = 1;
                    break;
                }
            }

            if (!valid_vote) {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }

    end_time = time(NULL);

    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    max_votes = 0;
    for (i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
        }
    }

    printf("\nTotal votes cast: %d\n", max_votes * num_voters);
    printf("Time taken: %ld seconds\n", end_time - start_time);

    return 0;
}
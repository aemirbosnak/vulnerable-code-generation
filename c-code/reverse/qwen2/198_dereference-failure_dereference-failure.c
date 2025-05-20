#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 100
#define MAX_NAME_LENGTH 50

int main() {
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    if (num_candidates <= 0 || num_candidates > MAX_CANDIDATES) {
        printf("Invalid number of candidates.\n");
        return 1;
    }

    char *names[MAX_CANDIDATES];
    int votes[MAX_CANDIDATES] = {0};

    for (int i = 0; i < num_candidates; i++) {
        names[i] = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
        if (names[i] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        printf("Enter name for candidate %d: ", i + 1);
        scanf("%s", names[i]);
    }

    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    for (int i = 0; i < num_voters; i++) {
        int vote;
        printf("Voter %d, enter your choice (1-%d): ", i + 1, num_candidates);
        scanf("%d", &vote);

        if (vote < 1 || vote > num_candidates) {
            printf("Invalid vote.\n");
            continue;
        }

        votes[vote - 1]++;
    }

    int max_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        if (votes[i] > max_votes) {
            max_votes = votes[i];
        }
    }

    printf("Winner(s): ");
    for (int i = 0; i < num_candidates; i++) {
        if (votes[i] == max_votes) {
            printf("%s ", names[i]);
        }
    }
    printf("\n");

    for (int i = 0; i < num_candidates; i++) {
        free(names[i]);
    }

    return 0;
}

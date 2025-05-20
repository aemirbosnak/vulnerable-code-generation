#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_VOTERS 100

void vote(char candidates[MAX_NAME_LENGTH][MAX_NAME_LENGTH], int *votes, char name[MAX_NAME_LENGTH]) {
    int i;
    for (i = 0; i < MAX_VOTERS; ++i) {
        printf("Enter candidate name: ");
        scanf("%s", name);
        for (int j = 0; j < MAX_NAME_LENGTH; ++j) {
            candidates[i][j] = name[j];
        }
        ++votes[i];
    }
}

int main() {
    char candidates[MAX_VOTERS][MAX_NAME_LENGTH];
    int votes[MAX_VOTERS];
    int num_voters;

    printf("Enter number of voters: ");
    scanf("%d", &num_voters);

    vote(candidates, votes, candidates[0]);

    for (int i = 0; i < num_voters; ++i) {
        printf("%s received %d votes\n", candidates[i], votes[i]);
    }

    return 0;
}

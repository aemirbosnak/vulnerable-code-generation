//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define VOTE_FILE "votes.dat"

struct candidate {
    char name[50];
    int votes;
};

int main(int argc, char *argv[]) {
    int choice, i;
    struct candidate candidates[MAX_CANDIDATES];
    FILE *fp;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++) {
        strcpy(candidates[i].name, "Candidate Unknown");
        candidates[i].votes = 0;
    }

    // Read votes from file (if exists)
    fp = fopen(VOTE_FILE, "r");
    if (fp != NULL) {
        for (i = 0; i < MAX_CANDIDATES && fscanf(fp, "%s %d", candidates[i].name, &candidates[i].votes) != EOF; i++);
        fclose(fp);
    }

    // Print candidates and their current votes
    printf("\nELECTRONIC VOTING SYSTEM\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("\n%s : %d votes", candidates[i].name, candidates[i].votes);
    }

    // Vote for a candidate
    do {
        printf("\nEnter the number of the candidate you want to vote for : ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > MAX_CANDIDATES);

    // Increment the vote for the chosen candidate
    candidates[choice - 1].votes++;

    // Save votes to file
    fp = fopen(VOTE_FILE, "w");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        fprintf(fp, "%s %d\n", candidates[i].name, candidates[i].votes);
    }
    fclose(fp);

    printf("\nYour vote has been recorded.\n");

    return 0;
}
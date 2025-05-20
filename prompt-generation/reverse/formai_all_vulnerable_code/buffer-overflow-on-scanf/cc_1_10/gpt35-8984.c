//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

// Function to count the votes for each candidate
void count_votes(char *candidate) {
    FILE *fp;
    char buffer[255];
    int count = 0;
    fp = fopen("votes.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    while (fgets(buffer, 255, fp)) {
        if (strcmp(buffer, candidate) == 0) {
            count++;
        }
    }
    printf("%s: %d\n", candidate, count);
    fclose(fp);
}

// Function to add a vote to the file
void add_vote(char *candidate) {
    FILE *fp;
    fp = fopen("votes.txt", "a+");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fputs(candidate, fp);
    fclose(fp);
}

// Thread function to take votes
void *vote(void *arg) {
    int id = *(int*)arg;
    char candidate[255];
    printf("Voter %d, please enter the name of your candidate: ", id);
    scanf("%s", candidate);
    add_vote(candidate);
    printf("Thank you for voting!\n");
    return NULL;
}

int main() {
    pthread_t voters[5];
    int voter_ids[5] = {1, 2, 3, 4, 5};
    printf("Welcome to the Electronic Voting System!\n");
    for (int i = 0; i < 5; i++) {
        pthread_create(&voters[i], NULL, vote, &voter_ids[i]);
    }
    for (int i = 0; i < 5; i++) {
        pthread_join(voters[i], NULL);
    }
    printf("Vote counting in progress...\n");
    count_votes("Candidate A");
    count_votes("Candidate B");
    count_votes("Candidate C");
    return 0;
}
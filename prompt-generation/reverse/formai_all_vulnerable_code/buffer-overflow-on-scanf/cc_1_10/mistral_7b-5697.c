//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_VOTERS 1000
#define MAX_OPTIONS 5
#define VOTE_FILE "votes.dat"

typedef struct {
    int voter_id;
    int option;
} Vote;

int main(void) {
    int fd, voter_id, option;
    Vote vote;

    // Initialize file if not exists
    if (access(VOTE_FILE, F_OK) != 0) {
        fd = open(VOTE_FILE, O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        close(fd);
    }

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter your voter ID:\n");
    scanf("%d", &voter_id);

    while (voter_id < 1 || voter_id > MAX_VOTERS) {
        printf("Invalid voter ID! Please try again:\n");
        scanf("%d", &voter_id);
    }

    printf("Please select an option (1-%d):\n", MAX_OPTIONS);
    for (int i = 1; i <= MAX_OPTIONS; i++) {
        printf("%d. Option %d\n", i, i);
    }
    scanf("%d", &option);

    while (option < 1 || option > MAX_OPTIONS) {
        printf("Invalid option! Please try again:\n");
        scanf("%d", &option);
    }

    vote.voter_id = voter_id;
    vote.option = option;

    fd = open(VOTE_FILE, O_RDWR);
    lseek(fd, (voter_id - 1) * sizeof(Vote), SEEK_SET);
    write(fd, &vote, sizeof(Vote));
    close(fd);

    printf("Thank you for voting! Your vote has been recorded.\n");

    return 0;
}
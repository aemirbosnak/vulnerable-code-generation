//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <time.h>
#include <signal.h>

#define VOTING_FILE "/tmp/voting.bin"
#define VOTE_SIZE 32

typedef struct {
    char name[32];
    int votes;
} Candidate;

volatile sig_atomic_t exit_flag = 0;

void handler(int sig) {
    exit_flag = 1;
}

void write_vote(int index) {
    int fd;
    char vote[VOTE_SIZE];
    Candidate *candidates;
    size_t size;

    fd = open(VOTING_FILE, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd < 0) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    size = mmap(NULL, getpagesize(), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (size == MAP_FAILED) {
        perror("Failed to map memory");
        exit(EXIT_FAILURE);
    }

    candidates = (Candidate *) size;

    strcpy(candidates[index].name, "Neo");
    candidates[index].votes++;

    msync(candidates, size, MS_ASYNC);

    close(fd);

    munmap(candidates, size);
}

int main() {
    int index;
    struct sigaction act;

    signal(SIGINT, handler);

    while (1) {
        printf("Enter candidate index (0-9): ");
        scanf("%d", &index);

        if (index < 0 || index > 9) {
            printf("Invalid index\n");
            continue;
        }

        write_vote(index);
        printf("Your vote has been registered.\n");

        sleep(1);

        if (exit_flag) {
            printf("Exiting...\n");
            exit(EXIT_SUCCESS);
        }
    }

    return EXIT_SUCCESS;
}
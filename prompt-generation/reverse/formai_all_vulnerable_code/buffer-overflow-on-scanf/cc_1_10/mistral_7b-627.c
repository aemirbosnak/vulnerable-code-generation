//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <sys/wait.h>

#define MAX_CHAR 10000
#define NUM_ELEPHANTS 5

typedef struct Elephant {
    char name[50];
    int age;
    float weight;
} Elephant;

void signal_handler(int signo) {
    printf("\nSurprise! Caught you trying to run away.\n");
    exit(1);
}

int main() {
    Elephant elephants[NUM_ELEPHANTS];
    int i;

    // Set up signal handler
    signal(SIGINT, signal_handler);

    printf("\nWelcome to the Magical Elephant Farm!\n");

    for (i = 0; i < NUM_ELEPHANTS; i++) {
        printf("\nEnter name for elephant %d: ", i + 1);
        fgets(elephants[i].name, MAX_CHAR, stdin);
        strtok(elephants[i].name, "\n");

        printf("\nEnter age for %s: ", elephants[i].name);
        scanf("%d", &elephants[i].age);

        printf("\nEnter weight for %s: ", elephants[i].name);
        scanf("%f", &elephants[i].weight);

        printf("\n%s, the %d-year-old elephant weighing %.2f tons, has been added to the farm!\n", elephants[i].name, elephants[i].age, elephants[i].weight);
    }

    printf("\nNow, let's create a surprise birthday cake for the elephants!\n");

    int fd[2], status;
    pid_t pid;

    if (pipe(fd) < 0) {
        perror("Pipe failed");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) {
        close(fd[0]);
        write(fd[1], "SURPRISE! HAPPY BIRTHDAY TO ALL OUR ELEPHANTS!\n", strlen("SURPRISE! HAPPY BIRTHDAY TO ALL OUR ELEPHANTS!\n"));
        close(fd[1]);
        wait(&status);
    } else {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        execlp("/bin/sh", "sh", "-c", "cat > /dev/tty", NULL);
    }

    for (i = 0; i < NUM_ELEPHANTS; i++) {
        printf("\n%s, it's your birthday today!\n", elephants[i].name);
    }

    return 0;
}
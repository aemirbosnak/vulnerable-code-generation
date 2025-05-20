//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

typedef struct {
    char* name;
    int id;
} Person;

void send_message(int fd, Person* person) {
    if (write(fd, person, sizeof(Person))!= sizeof(Person)) {
        fprintf(stderr, "Failed to send message: %s\n", strerror(errno));
        exit(1);
    }
}

void receive_message(int fd, Person* person) {
    if (read(fd, person, sizeof(Person))!= sizeof(Person)) {
        fprintf(stderr, "Failed to receive message: %s\n", strerror(errno));
        exit(1);
    }
}

int main() {
    int fd[2];
    if (pipe(fd) == -1) {
        fprintf(stderr, "Failed to create pipe: %s\n", strerror(errno));
        exit(1);
    }

    Person alice = {"Alice", 1};
    Person bob = {"Bob", 2};

    pid_t pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Failed to fork: %s\n", strerror(errno));
        exit(1);
    } else if (pid > 0) {
        // Parent process
        close(fd[0]);
        send_message(fd[1], &alice);
        receive_message(fd[1], &bob);
        printf("Parent received message from child: %s\n", bob.name);
        close(fd[1]);
    } else {
        // Child process
        close(fd[1]);
        receive_message(fd[0], &alice);
        printf("Child received message from parent: %s\n", alice.name);
        send_message(fd[0], &bob);
        close(fd[0]);
    }

    return 0;
}
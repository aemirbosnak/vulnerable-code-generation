//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define SIZE 1000

typedef struct {
    int id;
    char name[50];
} data_t;

void send_data(int fd, data_t* data) {
    write(fd, data, sizeof(data_t));
}

data_t* receive_data(int fd) {
    data_t* data = (data_t*) malloc(sizeof(data_t));
    read(fd, data, sizeof(data_t));
    return data;
}

void print_data(data_t* data) {
    printf("ID: %d, Name: %s\n", data->id, data->name);
}

int main() {
    int fd[2];
    pid_t child_pid;

    if (pipe(fd) == -1) {
        perror("Pipe Failed");
        exit(1);
    }

    child_pid = fork();

    if (child_pid == -1) {
        perror("Fork Failed");
        exit(1);
    } else if (child_pid == 0) {
        data_t data;
        strcpy(data.name, "Child Process");
        data.id = getpid();

        send_data(fd[1], &data);

        close(fd[0]);
        close(fd[1]);

        exit(0);
    } else {
        data_t data;
        strcpy(data.name, "Parent Process");
        data.id = getpid();

        send_data(fd[0], &data);

        data_t* received_data = receive_data(fd[1]);
        print_data(received_data);

        close(fd[0]);
        close(fd[1]);

        exit(0);
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0
#define READ 0
#define WRITE 1

typedef struct {
    int fd;
    char *name;
    int mode;
} file_t;

int main() {
    int fd1, fd2, n;
    char buffer[MAX_SIZE];
    char *name = "test.txt";

    // Create a file for interprocess communication
    fd1 = open(name, O_CREAT | O_RDWR, 0666);
    if (fd1 == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }
    else if (pid == 0) {
        // Child process
        close(fd1);
        fd2 = open(name, O_RDWR);
        if (fd2 == -1) {
            printf("Error: %s\n", strerror(errno));
            exit(1);
        }
        while (TRUE) {
            n = read(fd2, buffer, MAX_SIZE);
            if (n == 0) {
                printf("End of file reached\n");
                break;
            }
            buffer[n] = '\0';
            printf("Received message: %s\n", buffer);
        }
        close(fd2);
        exit(0);
    }
    else {
        // Parent process
        close(fd1);
        while (TRUE) {
            printf("Enter message to send: ");
            scanf("%s", buffer);
            write(fd1, buffer, strlen(buffer));
        }
        close(fd1);
        wait(NULL);
        exit(0);
    }

    return 0;
}
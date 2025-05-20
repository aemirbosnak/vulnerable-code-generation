//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    int fd1[2];
    int fd2[2];

    if (pipe(fd1) == -1) {
        printf("Pipe 1 Failed");
        return 1;
    }
    if (pipe(fd2) == -1) {
        printf("Pipe 2 Failed");
        return 1;
    }

    pid_t p = fork();

    if (p < 0) {
        printf("Fork Failed");
        return 1;
    }

    // parent process
    else if (p > 0) {
        close(fd1[0]);
        close(fd2[1]);
        
        char encrypted_message[100];
        printf("Enter message to encrypt: ");
        scanf("%s", encrypted_message);
        int length = strlen(encrypted_message) + 1;
        write(fd1[1], &length, sizeof(length));
        write(fd1[1], encrypted_message, length);

        int result;
        read(fd2[0], &result, sizeof(result));
        printf("Parent has received the encrypted message from child: %d\n", result);

        wait(NULL);
        close(fd1[1]);
        close(fd2[0]);
    }

    // child process
    else {
        close(fd1[1]);
        close(fd2[0]);

        int length;
        read(fd1[0], &length, sizeof(length));
        char received_message[length];
        read(fd1[0], received_message, length);
        printf("Child has received the message from parent: %s\n", received_message);

        // encrypt the message
        for(int i=0; received_message[i]!='\0'; i++) {
            received_message[i] = received_message[i] + 3; 
        }
        int result = strlen(received_message) + 1;
        write(fd2[1], &result, sizeof(result));
        printf("Child has send the encrypted message back to the parent\n");

        close(fd1[0]);
        close(fd2[1]);

        exit(0);
    }
    return 0;
}
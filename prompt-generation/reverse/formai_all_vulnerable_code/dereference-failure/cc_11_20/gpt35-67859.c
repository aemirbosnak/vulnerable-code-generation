//FormAI DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define BUFSIZE 128

int main(int argc, char *argv[]){
    char *fifo1 = "fifo1";
    char *fifo2 = "fifo2";
    pid_t pid;
    int fd1, fd2;
    char buf[BUFSIZE];

    // Create First named pipe (FIFO)
    if((mkfifo(fifo1, S_IFIFO | 0666) == -1) && (errno != EEXIST)){
        perror("Error: Can't create fifo1");
        exit(-1);
    }

    // Create Second named pipe (FIFO)
    if((mkfifo(fifo2, S_IFIFO | 0666) == -1) && (errno != EEXIST)){
        perror("Error: Can't create fifo2");
        exit(-1);
    }

    // Fork a child process
    if((pid = fork()) < 0){
        perror("Error: Can't fork child process");
        exit(-1);
    }

    // Child process
    else if(pid == 0){
        char buffer[BUFSIZE];
        printf("Enter a message for the parent: ");
        fgets(buffer, BUFSIZE, stdin);

        // Open the first fifo for writing
        if((fd1 = open(fifo1, O_WRONLY)) == -1){
            perror("Error: Can't open fifo1 for writing");
            exit(-1);
        }

        // Send message to parent
        if(write(fd1, buffer, strlen(buffer)) == -1){
            perror("Error: Can't write to fifo1");
            exit(-1);
        }

        // Close the first FIFO
        close(fd1);

        // Wait for message from parent
        if((fd2 = open(fifo2, O_RDONLY)) == -1){
            perror("Error: Can't open fifo2 for reading");
            exit(-1);
        }

        // Read message from parent
        if(read(fd2, buf, BUFSIZE) == -1){
            perror("Error: Can't read from fifo2");
            exit(-1);
        }

        // Display received message
        printf("Child: received message from parent: %s", buf);

        // Close the second FIFO
        close(fd2);

        exit(0);
    }

    // Parent process
    else{
        // Open the first fifo for reading
        if((fd1 = open(fifo1, O_RDONLY)) == -1){
            perror("Error: Can't open fifo1 for reading");
            exit(-1);
        }

        // Read message from child
        if(read(fd1, buf, BUFSIZE) == -1){
            perror("Error: Can't read from fifo1");
            exit(-1);
        }

        // Display received message
        printf("Parent: received message from child: %s", buf);

        // Close first FIFO
        close(fd1);

        // Open the second FIFO for writing
        if((fd2 = open(fifo2, O_WRONLY)) == -1){
            perror("Error: Can't open fifo2 for writing");
            exit(-1);
        }

        // Send message to child
        char s[] = "Hello from parent!";
        if(write(fd2, s, strlen(s)) == -1){
            perror("Error: Can't write to fifo2");
            exit(-1);
        }

        // Close second FIFO
        close(fd2);

        // Wait for child process to finish
        wait(0);
    }

    // Remove the FIFOs
    remove(fifo1);
    remove(fifo2);

    return 0;
}
//FormAI DATASET v1.0 Category: Interprocess communication ; Style: innovative
/* 
   This program demonstrates a unique method of interprocess communication 
   using named pipes in a UNIX-based operating system.
   In this program, two processes namely, "sender" and "receiver" communicate
   with each other by sending and receiving messages through a named pipe. 
   The "sender" process sends an integer value to the "receiver" process.
   The "receiver" process then multiplies the received integer by 10 
   and sends the result back to the "sender" process to display it.

   Author: AI Chatbot
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 20

int main()
{
    // Create a named pipe
    char *pipe_name = "my_pipe";
    mkfifo(pipe_name, 0666);

    // Create a child process
    pid_t pid = fork();

    if (pid == -1) // Error creating child process
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) // Child process acts as "receiver"
    {
        // Open the named pipe for reading
        int fd = open(pipe_name, O_RDONLY);

        // Read the integer sent by "sender"
        int num;
        read(fd, &num, sizeof(num));

        // Multiply the received integer by 10
        int result = num * 10;

        // Send the result back to "sender"
        write(fd, &result, sizeof(result));

        // Close the pipe
        close(fd);
    }
    else // Parent process acts as "sender"
    {
        // Open the named pipe for writing
        int fd = open(pipe_name, O_WRONLY);

        // Send an integer value to "receiver"
        int num = 5;
        write(fd, &num, sizeof(num));

        // Wait for the result sent by "receiver"
        int result;
        read(fd, &result, sizeof(result));

        // Display the result
        printf("Result: %d\n", result);

        // Close the pipe and delete the named pipe
        close(fd);
        unlink(pipe_name);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Claude Shannon
/* 

Title: A Secure Interprocess Communication System using Pipes and Encryption
Author: Claude Shannon

*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

#define MAX_BUF 1024 // Maximum size of the buffer
#define SECRET_KEY 13 // Secret key for encryption


int main()
{

    int fd; // file descriptor
    char * myfifo = "/tmp/myfifo"; // file path of FIFO
    char buffer[MAX_BUF]; // buffer to hold the data
    char encrypted_buffer[MAX_BUF]; // buffer to hold the encrypted data
    char decrypted_buffer[MAX_BUF]; // buffer to hold the decrypted data

    // Creating the FIFO file
    mkfifo(myfifo, 0666);

    // Child process to write the data into the pipe
    if (fork() == 0) 
    {
        // Open write-only file descriptor
        fd = open(myfifo, O_WRONLY);

        printf("\nEnter the message for communication: ");
        scanf("%[^\n]", buffer); // Reading the input from the user

        // Encrypting the message using STRADDLE cipher
        for(int i=0; i<strlen(buffer); i++)
        {
            encrypted_buffer[i] = buffer[i] + SECRET_KEY;
        }

        write(fd, encrypted_buffer, strlen(encrypted_buffer)+1);
        close(fd);
    }

    // Parent process to read the data from the pipe
    else 
    {
        // Open read-only file descriptor
        fd = open(myfifo, O_RDONLY);
        read(fd, encrypted_buffer, MAX_BUF);

        // Decrypting the message using STRADDLE cipher
        for(int i=0; i<strlen(encrypted_buffer); i++)
        {
            decrypted_buffer[i] = encrypted_buffer[i] - SECRET_KEY;
        }

        printf("\nEncrypted message received is: %s\n", encrypted_buffer);
        printf("\nDecrypted message is: %s\n", decrypted_buffer);
        close(fd);

        // Deleting the FIFO file
        unlink(myfifo); 
        return 0;
    }

}
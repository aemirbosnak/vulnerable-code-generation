//FormAI DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFSIZE 1024
#define DELAY_TIME 1000000

void asyncToUpper(const char *inputFilePath, const char *outputFilePath) {
    char buffer[BUFSIZE];
    ssize_t bytesRead, bytesWritten;
    int inFd, outFd;
    off_t offset = 0;

    // Open input file for reading
    inFd = open(inputFilePath, O_RDONLY);
    if (inFd == -1) {
        perror("Could not open input file");
        exit(1);
    }

    // Open output file for writing
    outFd = open(outputFilePath, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (outFd == -1) {
        perror("Could not open output file");
        exit(1);
    }

    // Set output file pointer offset to 0
    lseek(outFd, 0, SEEK_SET);

    // Loop over input file, reading and processing data asynchronously
    do {
        // Read data from input file
        bytesRead = read(inFd, buffer, BUFSIZE);
        if (bytesRead == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("Read error");
                exit(1);
            }
        } else if (bytesRead == 0) {
            break;
        }

        // Simulate processing delay...
        usleep(DELAY_TIME);

        // Convert data to upper case
        for (int i = 0; i < bytesRead; i++) {
            if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] -= 32;
            }
        }

        // Write processed data to output file at appropriate offset
        bytesWritten = pwrite(outFd, buffer, bytesRead, offset);
        if (bytesWritten == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("Write error");
                exit(1);
            }
        }

        // Update output file pointer offset
        offset += bytesWritten;
    } while (1);

    // Close file descriptors
    close(inFd);
    close(outFd);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: async-string <input-file-path> <output-file-path>\n");
        exit(1);
    }

    clock_t startTime = clock();

    pid_t childPid = fork();
    if (childPid == -1) {
        perror("Fork error");
        exit(1);
    } else if (childPid == 0) {
        // Child process
        asyncToUpper(argv[1], argv[2]);
        exit(0);
    }

    // Parent process
    int status;
    waitpid(childPid, &status, 0);

    if (status == 0) {
        // Async string manipulation complete
        printf("Async string manipulation complete in %.2f seconds\n",
            (float)(clock() - startTime) / CLOCKS_PER_SEC);
    } else {
        printf("Async string manipulation failed\n");
    }

    return 0;
}
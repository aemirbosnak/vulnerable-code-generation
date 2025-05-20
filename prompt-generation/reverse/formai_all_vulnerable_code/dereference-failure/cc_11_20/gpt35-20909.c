//FormAI DATASET v1.0 Category: QR code reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CODE_LEN 256

int main(int argc, char *argv[]) {
    bool fileFlag = false; // flag to indicate if file is present
    int fd; // file descriptor
    ssize_t numRead; // number of bytes read from file

    if (argc != 2 && argc != 3) { // check for valid number of arguments
        fprintf(stderr, "Usage: %s <code> [file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (argc == 3) { // check if file is present
        if ((fd = open(argv[2], O_RDONLY)) == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        fileFlag = true; // set flag to true
    }

    char code[MAX_CODE_LEN]; // initialize buffer to hold code
    if (strlen(argv[1]) > MAX_CODE_LEN) { // check if code exceeds buffer size
        fprintf(stderr, "Code length exceeds maximum buffer size\n");
        exit(EXIT_FAILURE);
    }
    strcpy(code, argv[1]); // copy code to buffer

    if (fileFlag) { // append code from file to buffer
        char buffer[MAX_CODE_LEN];
        while ((numRead = read(fd, buffer, MAX_CODE_LEN)) > 0) {
            buffer[numRead] = '\0'; // add null terminator
            strcat(code, buffer); // append to buffer
        }
        if (numRead == -1) { // check for read error
            perror("read");
            exit(EXIT_FAILURE);
        }
    }

    printf("Code: %s\n", code); // print code

    if (fileFlag) { // close file if present
        if (close(fd) == -1) {
            perror("close");
            exit(EXIT_FAILURE);
        }
    }

    return EXIT_SUCCESS;
}
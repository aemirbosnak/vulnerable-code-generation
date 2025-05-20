//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_BUF_SIZE 1024
#define FILE_PERMISSIONS 0644

int main() {
    char inputFileName[MAX_BUF_SIZE];
    char outputFileName[MAX_BUF_SIZE];
    int inputFileFD = 0, outputFileFD = 0;
    ssize_t readBytes = 0;
    char buffer[MAX_BUF_SIZE] = {0};

    printf("Enter the name of input file: ");
    scanf("%s", inputFileName);

    if (access(inputFileName, F_OK) != 0) {
        perror("Input file does not exist");
        exit(EXIT_FAILURE);
    }

    printf("Enter the name of output file: ");
    scanf("%s", outputFileName);

    umask(0);

    inputFileFD = open(inputFileName, O_RDONLY);
    if (inputFileFD < 0) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    outputFileFD = open(outputFileName, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMISSIONS);
    if (outputFileFD < 0) {
        perror("Error opening output file");
        close(inputFileFD);
        exit(EXIT_FAILURE);
    }

    while ((readBytes = read(inputFileFD, buffer, MAX_BUF_SIZE)) > 0) {
        if (write(outputFileFD, buffer, readBytes) != readBytes) {
            perror("Error writing to output file");
            close(inputFileFD);
            close(outputFileFD);
            exit(EXIT_FAILURE);
        }
    }

    if (readBytes < 0) {
        perror("Error reading from input file");
        close(inputFileFD);
        close(outputFileFD);
        exit(EXIT_FAILURE);
    }

    printf("File copied successfully!\n");

    close(inputFileFD);
    close(outputFileFD);

    return EXIT_SUCCESS;
}
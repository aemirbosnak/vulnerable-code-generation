//Falcon2-11B DATASET v1.0 Category: Basic Unix-like Shell ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    char* command = argv[1];
    char* output_buffer = NULL;
    char* error_buffer = NULL;
    int status = 0;

    // Check if the command is "help"
    if (strcmp(command, "help") == 0) {
        // Print a list of available commands
        printf("Available commands:\n");
        printf("1. ls - list files in the current directory\n");
        printf("2. cat - print the content of a file\n");
        printf("3. pwd - print the current working directory\n");
        printf("4. exit - exit the shell\n");
        printf("5. help - print this help message\n");
        printf("\n");
    } else if (strcmp(command, "ls") == 0) {
        // List files in the current directory
        printf("Listing files in the current directory:\n");
        FILE* fp = popen("ls", "r");
        if (fp == NULL) {
            perror("popen");
            exit(1);
        }
        char line[256];
        while (fgets(line, sizeof(line), fp)!= NULL) {
            printf("%s\n", line);
        }
        pclose(fp);
    } else if (strcmp(command, "cat") == 0) {
        // Print the content of a file
        printf("Printing the content of a file:\n");
        FILE* fp = fopen(argv[2], "r");
        if (fp == NULL) {
            perror("fopen");
            exit(1);
        }
        char line[256];
        while (fgets(line, sizeof(line), fp)!= NULL) {
            printf("%s", line);
        }
        fclose(fp);
    } else if (strcmp(command, "pwd") == 0) {
        // Print the current working directory
        printf("Printing the current working directory:\n");
        printf("%s\n", getcwd(NULL, 0));
    } else if (strcmp(command, "exit") == 0) {
        // Exit the shell
        printf("Exiting the shell.\n");
        exit(0);
    } else if (strcmp(command, "help") == 0) {
        // Print the help message
        printf("Printing the help message:\n");
        printf("Available commands:\n");
        printf("1. ls - list files in the current directory\n");
        printf("2. cat - print the content of a file\n");
        printf("3. pwd - print the current working directory\n");
        printf("4. exit - exit the shell\n");
        printf("5. help - print this help message\n");
        printf("\n");
    } else {
        // Run the command and print the output or error message
        FILE* fp = popen(command, "r");
        if (fp == NULL) {
            perror("popen");
            exit(1);
        }
        char line[256];
        while (fgets(line, sizeof(line), fp)!= NULL) {
            printf("%s", line);
        }
        pclose(fp);
    }

    // Free allocated memory
    free(output_buffer);
    free(error_buffer);

    return 0;
}
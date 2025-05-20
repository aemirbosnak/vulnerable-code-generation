//FormAI DATASET v1.0 Category: System administration ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100 // maximum length of command

void run_command(char* command);

int main() {
    char user_input[MAX_COMMAND_LENGTH];
    while(1) {
        printf("$ ");
        fgets(user_input, MAX_COMMAND_LENGTH, stdin); // get user input
        if(user_input[strlen(user_input) - 1] == '\n') {
            user_input[strlen(user_input) - 1] = '\0'; // remove newline character from user input
        }
        run_command(user_input); // execute user command
    }
    return 0;
}

void run_command(char* command) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE* file_pointer = NULL;
    char buffer[256];

    // execute command as shell command
    if(system(command) != -1) {
        return;
    }

    // read file if command is to read a file
    if(strncmp(command, "read_file", 9) == 0) {
        file_pointer = fopen(command + 11, "r");
        if(file_pointer == NULL) {
            printf("Error: File not found\n");
            return;
        }
        while((read = getline(&line, &len, file_pointer)) != -1) {
            printf("%s", line); // print file content
        }
        fclose(file_pointer);
        return;
    }

    // write file if command is to write to a file
    if(strncmp(command, "write_file", 10) == 0) {
        file_pointer = fopen(command + 12, "w");
        if(file_pointer == NULL) {
            printf("Error: File not writable\n");
            return;
        }
        while(1) {
            fgets(buffer, 256, stdin); // get user input
            if(strcmp(buffer, ".\n") == 0) {
                break; // break when user inputs a single dot on a new line
            }
            fprintf(file_pointer, "%s", buffer); // write to file
        }
        fclose(file_pointer);
        return;
    }

    printf("Error: Unknown command\n");
}
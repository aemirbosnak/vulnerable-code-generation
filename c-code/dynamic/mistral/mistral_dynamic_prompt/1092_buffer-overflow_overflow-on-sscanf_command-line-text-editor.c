#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LINE 256

char buffer[MAX_LINE];
char *commands[] = {"open", "save", "quit"};
int num_commands = sizeof(commands) / sizeof(char *);

void edit() {
    int choice;

    printf("\nCommand Line Editor\n");
    printf("------------------\n");
    printf("1. Open\n");
    printf("2. Save\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");

    if (sscanf(buffer, "%d", &choice) != 1 || choice < 1 || choice > num_commands)
        return;

    printf("You chose: %s\n", commands[choice - 1]);
}

int main(int argc, char *argv[]) {
    char *input;

    while (1) {
        fgets(buffer, MAX_LINE, stdin);
        input = strtok(buffer, " \n");

        if (strcmp(input, "open") == 0)
            edit();
        else if (strcmp(input, "save") == 0)
            printf("Saving...\n");
        else if (strcmp(input, "quit") == 0)
            break;
        else
            printf("Unknown command. Try again.\n");
    }

    return 0;
}

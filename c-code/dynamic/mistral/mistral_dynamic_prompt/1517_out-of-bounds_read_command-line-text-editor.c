#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

void edit(char *buffer) {
    system("clear");
    printf("\nEditor: %s\n\n", buffer);

    char command[BUFFER_SIZE];
    char temp[BUFFER_SIZE];

    while (1) {
        printf("%s> ", "> ");
        fgets(command, BUFFER_SIZE, stdin);
        command[strlen(command) - 1] = '\0';

        if (!strcmp(command, "save")) {
            break;
        } else if (!strcmp(command, "exit")) {
            exit(0);
        } else if (!strcmp(command, "load")) {
            fgets(temp, BUFFER_SIZE, stdin);
            strcat(buffer, temp);
        } else if (!strcmp(command, "insert")) {
            fgets(temp, BUFFER_SIZE, stdin);
            strcat(buffer, temp);
            int index = atoi(command + 6);
            if (index < strlen(buffer))
                strcpy(buffer + index, temp);
        } else if (!strcmp(command, "delete")) {
            int index = atoi(command + 7);
            if (index >= strlen(buffer))
                printf("Error: Invalid index.\n");
            else {
                memmove(buffer + index - 1, buffer + index, strlen(buffer) - index);
            }
        } else {
            printf("Error: Invalid command.\n");
        }

        edit(buffer);
    }
}

int main() {
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);
    edit(buffer);
    return 0;
}

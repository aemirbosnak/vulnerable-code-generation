#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void executeCommand(char command[]) {
    printf("Executing command: %s\n", command);
}

int main() {
    char command[BUFFER_SIZE];

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);
        executeCommand(command);
    }

    return 0;
}

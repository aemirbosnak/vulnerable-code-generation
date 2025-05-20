#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void controlLight(char *command) {
    int state;

    sscanf(command, "%s %*s %d", command, &state);

    if (strcmp(command, "turn on") == 0 && state >= 0 && state <= 1) {
        printf("Light is now on.\n");
    } else if (strcmp(command, "turn off") == 0 && state >= 0 && state <= 1) {
        printf("Light is now off.\n");
    } else {
        printf("Invalid command.\n");
    }
}

int main() {
    char buffer[10];

    while (1) {
        printf("Enter command: ");
        fgets(buffer, sizeof(buffer), stdin);
        controlLight(buffer);
    }

    return 0;
}

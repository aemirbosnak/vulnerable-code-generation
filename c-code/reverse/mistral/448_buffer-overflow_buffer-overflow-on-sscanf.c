#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void controlLight(char *command) {
    if (strcmp(command, "on") == 0) {
        printf("Light is on.\n");
    } else if (strcmp(command, "off") == 0) {
        printf("Light is off.\n");
    } else {
        printf("Invalid command.\n");
    }
}

int main() {
    char buffer[10];
    printf("Enter command (on/off): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%s", buffer);
    controlLight(buffer);
    return 0;
}

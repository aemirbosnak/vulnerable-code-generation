#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 16

void control_lights(char *input) {
    char command[BUFFER_SIZE];
    if (sscanf(input, "%s", command) == 1) {
        if (strcmp(command, "on") == 0) {
            printf("Lights turned on.\n");
        } else if (strcmp(command, "off") == 0) {
            printf("Lights turned off.\n");
        }
    }
}

int main() {
    char input[100];
    printf("Enter command: ");
    fgets(input, sizeof(input), stdin);
    control_lights(input);
    return 0;
}

#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void parse_command(char *input) {
    char command[10];
    int arg;
    if (sscanf(input, "%9s %d", command, &arg) == 2) {
        printf("Command: %s, Argument: %d\n", command, arg);
    } else {
        printf("Invalid input.\n");
    }
}

int main() {
    char input[200];
    while (1) {
        printf("Enter command: ");
        fgets(input, sizeof(input), stdin);
        // Remove newline character
        input[strcspn(input, "\n")] = '\0';
        parse_command(input);
    }
    return 0;
}

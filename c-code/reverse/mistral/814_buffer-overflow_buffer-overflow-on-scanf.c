#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_input(char *input, int size) {
    int i, complexity = 0;
    char command[10];

    for (i = 0; i < strlen(input); i++) {
        if (i > 4 && i < 9) command[i - 5] = input[i];
        if (i == 9) command[i] = '\0';
        if (i > 0 && i < 10 && command[i - 1] == ' ') complexity++;
        if (i == 10) complexity++;
    }

    if (strcmp(command, "turn on") <= 0 && strcmp(command, "turn off") >= 0) {
        printf("Command executed: %s\n", command);
    } else {
        printf("Invalid command. Please try again.\n");
    }
}

int main() {
    char input[100];

    printf("Welcome to Smart Home Automation System\n");
    printf("Enter a command (turn on/off): ");
    scanf("%s", input);
    process_input(input, 100);

    return 0;
}

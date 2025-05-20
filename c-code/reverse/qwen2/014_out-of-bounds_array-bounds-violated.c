#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void parse_command(char *input) {
    char *args[64];
    int i = 0;
    args[i] = strtok(input, " ");
    while (args[i] != NULL && i < 63) {
        i++;
        args[i] = strtok(NULL, " ");
    }
    if (i > 0) {
        execv(args[0], args);
    } else {
        printf("No command provided.\n");
    }
}

int main() {
    char input[256];
    printf("Enter a command: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    parse_command(input);
    return 0;
}

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void exec_command(char *command) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, command);
    system(buffer);
}

int main(int argc, char *argv[]) {
    char input[BUFFER_SIZE];

    printf("Vulnerable Shell: ");
    fgets(input, BUFFER_SIZE, stdin);
    exec_command(input);

    return 0;
}

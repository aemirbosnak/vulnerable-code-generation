#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_input(char *input) {
    char buffer[10];
    int num;

    sscanf(input, "Player %*s %*s %s %n", buffer, &num);
    strcat(buffer, " of the Ancient Kingdom");
    printf("Welcome, %s!\n", buffer);
}

int main() {
    char input[256];
    printf("Enter your name: ");
    fgets(input, sizeof(input), stdin);

    process_input(input);

    return 0;
}

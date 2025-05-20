#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void processInput(char *input) {
    char buffer[5];
    strcpy(buffer, input);
}

int main() {
    char input[100];
    printf("Enter joystick input: ");
    scanf("%s", input);
    processInput(input);
    return 0;
}

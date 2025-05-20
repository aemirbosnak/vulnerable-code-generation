#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void process_input(char *input) {
    char buffer[50];
    strcpy(buffer, input);
}

int main() {
    char input[100];
    printf("Enter joystick input: ");
    scanf("%s", input);
    process_input(input);
    return 0;
}

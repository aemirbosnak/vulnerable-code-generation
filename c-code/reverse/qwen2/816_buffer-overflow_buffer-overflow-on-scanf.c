#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void controlDevice(char* command) {
    char buffer[5];
    strcpy(buffer, command);
}

int main() {
    char input[20];
    printf("Enter device command: ");
    scanf("%s", input);
    controlDevice(input);
    return 0;
}

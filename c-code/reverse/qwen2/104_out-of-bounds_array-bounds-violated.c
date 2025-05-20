#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void process_input(char *buffer) {
    int i = 0;
    while (i < 100) {
        fgets(buffer + i, 100 - i, stdin);
        if (buffer[i] == '\n') break;
        i++;
    }
}

int main() {
    char buffer[100];
    printf("Enter your name: ");
    process_input(buffer);
    printf("Hello, %s\n", buffer);
    return 0;
}

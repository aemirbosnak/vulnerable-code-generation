#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 16

void handle_client(char *data) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, data);
}

int main() {
    char input[256];
    printf("Enter data: ");
    gets(input); // Vulnerable to buffer overflow
    handle_client(input);
    return 0;
}

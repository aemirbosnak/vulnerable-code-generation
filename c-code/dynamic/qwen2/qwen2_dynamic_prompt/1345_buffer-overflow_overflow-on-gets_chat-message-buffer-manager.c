#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

char buffer[BUFFER_SIZE];

void receive_message(const char* message) {
    strcpy(buffer, message);
}

int main() {
    printf("Chat Buffer Manager\n");
    printf("Enter a message: ");
    char input[20];
    fgets(input, sizeof(input), stdin);
    receive_message(input);
    printf("Buffer contains: %s\n", buffer);
    return 0;
}

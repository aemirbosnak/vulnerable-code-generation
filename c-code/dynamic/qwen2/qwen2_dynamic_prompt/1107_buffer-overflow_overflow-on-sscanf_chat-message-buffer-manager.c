#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void process_message(char *message) {
    char buffer[BUFFER_SIZE];
    printf("Received message: %s\n", message);
    sscanf(message, "%[^\n]", buffer); // Vulnerable to buffer overflow
}

int main() {
    char input[200];
    while (1) {
        printf("Enter a message: ");
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'q' || input[0] == 'Q') {
            break;
        }
        process_message(input);
    }
    return 0;
}

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void send_message(char *message) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, message);
    printf("Message sent: %s\n", buffer);
}

int main() {
    char input[1024];
    while (1) {
        printf("Enter a message: ");
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'q' || input[0] == 'Q') {
            break;
        }
        send_message(input);
    }
    return 0;
}

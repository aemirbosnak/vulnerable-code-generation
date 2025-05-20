#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

void display_messages(char *messages[], int num_messages) {
    for (int i = 0; i < num_messages; ++i) {
        printf("%s\n", messages[i]);
    }
}

int main(int argc, char *argv[]) {
    char messages[10][BUFFER_SIZE];
    int num_messages = 0;

    while (1) {
        printf("Enter a chat message (or type 'quit' to exit): ");
        fgets(messages[num_messages], BUFFER_SIZE, stdin);

        if (strcmp(messages[num_messages], "quit\n") == 0) {
            break;
        }

        num_messages++;
    }

    display_messages(messages, num_messages);

    char overflow_buffer[1];
    gets(overflow_buffer); // Vulnerable to buffer overflow

    return 0;
}

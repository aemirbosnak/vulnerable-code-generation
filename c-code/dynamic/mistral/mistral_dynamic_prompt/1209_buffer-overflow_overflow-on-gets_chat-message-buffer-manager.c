#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void read_message(char *buffer) {
    printf("Enter message: ");
    gets(buffer);
}

void print_messages(char messages[][BUFFER_SIZE], int count) {
    for (int i = 0; i < count; ++i) {
        printf("Message %d: %s\n", i + 1, messages[i]);
    }
}

int main() {
    char messages[10][BUFFER_SIZE];
    int count = 0;

    printf("Chat Message Manager\n");

    while (1) {
        read_message(messages[count]);
        ++count;

        if (count == BUFFER_SIZE) {
            printf("Buffer full. Exiting...\n");
            break;
        }
    }

    print_messages(messages, count);

    return 0;
}

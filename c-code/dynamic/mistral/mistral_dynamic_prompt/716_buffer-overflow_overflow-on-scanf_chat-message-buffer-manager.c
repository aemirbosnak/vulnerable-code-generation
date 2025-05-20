#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_MESSAGES 100
#define MAX_MESSAGE_LENGTH 200

char messages[MAX_MESSAGES][MAX_MESSAGE_LENGTH];
int num_messages = 0;

void print_messages() {
    for (int i = 0; i < num_messages; ++i) {
        printf("Message %d: %s\n", i + 1, messages[i]);
    }
}

int main() {
    char input[10];
    printf("Welcome to ChatMessage! Type your name to join.\n");

    scanf("%s", input); // Vulnerable to buffer overflow

    strcpy(messages[num_messages], input);
    num_messages++;

    printf("Hello, %s! You're now part of the ChatMessage community.\n", input);
    print_messages();

    // Simulate an ongoing chat session...
    while (1) {
        printf("\nType your message or type 'quit' to exit.\n");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        strcpy(messages[num_messages], input);
        num_messages++;

        if (num_messages > MAX_MESSAGES) {
            printf("Message queue is full. Cannot save your message.\n");
        } else {
            printf("Your message was saved.\n");
            print_messages();
        }
    }

    return 0;
}

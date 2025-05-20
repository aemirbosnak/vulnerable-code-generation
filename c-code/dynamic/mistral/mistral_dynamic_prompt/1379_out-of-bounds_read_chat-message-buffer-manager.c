#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_MESSAGES 10
#define BUFFER_SIZE 200

char messages[MAX_MESSAGES][BUFFER_SIZE];
int message_count = 0;

void add_message(char* message) {
    if (message_count >= MAX_MESSAGES) {
        printf("No more messages can be stored.\n");
        return;
    }
    strcpy(messages[message_count], message);
    message_count++;
}

void list_messages() {
    for (int i = 0; i < message_count; i++) {
        printf("%d: %s\n", i + 1, messages[i]);
    }
}

int main() {
    char input[BUFFER_SIZE];

    while (1) {
        printf("Enter a message (or type 'list' to see messages):\n");
        scanf("%s", input);

        if (strcmp(input, "list") == 0) {
            list_messages();
            continue;
        }

        add_message(input);
    }

    return 0;
}

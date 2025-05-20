#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_message(char user_input[]) {
    char message[10];
    int age;

    printf("Enter your chat message and age (separated by a space): ");
    sscanf(user_input, "%s %d", message, &age);

    printf("Message received: %s\n", message);
    printf("Your age is: %d\n", age);
}

int main() {
    char input[1024];
    printf("Welcome to Chat-O-Matic 3000! Let's chat and reveal your secrets!\n");

    while (1) {
        printf("Enter your message (or type 'quit' to exit): ");
        fgets(input, sizeof(input), stdin);

        if (!strncmp(input, "quit", 4)) {
            printf("Goodbye!\n");
            break;
        }

        process_message(input);
    }

    return 0;
}

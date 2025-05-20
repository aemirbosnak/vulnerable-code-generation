#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_message(char *message) {
    char name[10];
    char message_from_user[256];
    char message_to_user[256];

    printf("Enter your username (up to 9 characters): ");
    sscanf(message, "%s %s", name, message_from_user);
    strcpy(message_to_user, "Welcome, ");
    strcat(message_to_user, name);
    strcat(message_to_user, "!\n");
    strcat(message_to_user, message_from_user);

    printf("%s\n", message_to_user);
}

int main() {
    char input[4096];

    printf("Chat Message Buffer Manager\n");
    printf("Enter your chat message (max 4095 characters):\n");

    fgets(input, sizeof(input), stdin);

    process_message(input);

    return 0;
}

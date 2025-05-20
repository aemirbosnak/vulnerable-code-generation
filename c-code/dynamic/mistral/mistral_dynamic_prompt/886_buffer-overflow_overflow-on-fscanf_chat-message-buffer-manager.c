#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void chat_manager(char buffer[], int max_length) {
    char user_input[100];
    int i = 0;

    printf("\nWelcome to Chat Manager v1.0\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        printf("\nEnter message (max %d characters): ", max_length);
        fscanf(stdin, "%s", user_input);

        if (strcasecmp(user_input, "exit") == 0) {
            break;
        }

        strcpy(buffer, user_input);
        printf("Your message: %s\n", buffer);
    }
}

int main() {
    char chat_message[50];
    int max_length = 50;

    chat_manager(chat_message, max_length);

    char attacker_input[100];
    printf("\nAttacker's input: ");
    fgets(attacker_input, sizeof(attacker_input), stdin);

    char *attacker_data = malloc(strlen(attacker_input) + 1);
    strcpy(attacker_data, attacker_input);

    char* token = strtok(attacker_data, "\n");
    strncat(chat_message, token, strlen(token) + 1);

    printf("\nChat Message: %s\n", chat_message);

    return 0;
}

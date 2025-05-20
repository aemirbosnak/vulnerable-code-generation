#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 20

void process_message(char *message) {
    char user_name[10];
    strcpy(user_name, message);
    printf("Welcome, %s\n", user_name + sizeof(user_name));
}

int main() {
    char message[100];
    printf("Enter your message:\n");
    fgets(message, sizeof(message), stdin);

    process_message(message);

    return 0;
}

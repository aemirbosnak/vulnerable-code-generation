#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 16
#define MAX_MESSAGE_LENGTH 100

void welcome_message() {
    printf("Welcome to Chatty\n");
    printf("Enter your name (up to 15 characters):\n");
}

void greet_user(char name[]) {
    printf("Hello, %s! Welcome to the chatroom.\n", name);
}

void get_message(char user[], char message[]) {
    printf("%s: ", user);
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
}

void broadcast_message(char user[], char message[]) {
    printf("%s: %s\n", user, message);
}

int main() {
    char name[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    welcome_message();
    scanf("%s", name);

    if (strlen(name) > MAX_NAME_LENGTH) {
        printf("Your name exceeded the maximum length. Program terminated.\n");
        return -1;
    }

    greet_user(name);

    while (1) {
        get_message(name, message);
        broadcast_message(name, message);
    }

    return 0;
}

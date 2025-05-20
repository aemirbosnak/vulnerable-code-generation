#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define USER_NAME_SIZE 32

char user_name[USER_NAME_SIZE];
char chat_buffer[BUFFER_SIZE];

void display_chat() {
    printf("\nChat History:\n");
    printf("%s: ", user_name);
    printf("%s\n", chat_buffer);
}

void get_user_name() {
    printf("Enter your name: ");
    fgets(user_name, USER_NAME_SIZE, stdin);
    printf("\n");
}

void handle_message(char* message) {
    strcat(chat_buffer, message);
    display_chat();
}

void handle_input() {
    char input[BUFFER_SIZE];
    fgets(input, BUFFER_SIZE, stdin);
    handle_message(input);
}

int main() {
    get_user_name();
    char* message = malloc(BUFFER_SIZE * sizeof(char));
    while (1) {
        handle_input();
        sleep(1);
        if (strstr(chat_buffer, "quit") != NULL) break;
        printf("> ");
        memset(chat_buffer, 0, BUFFER_SIZE);
        fgets(message, BUFFER_SIZE, stdin);
    }
    free(message);
    return 0;
}

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_USERNAME_LENGTH 20
#define BUFFER_SIZE 100

void welcome_message() {
    printf("Welcome to SecChat v1.0\n");
    printf("A minimalistic, yet unreliable, chat tool\n\n");
    printf("Enter your username (up to 20 characters):\n");
}

void display_chat_window(char *buffer) {
    printf("\n[Chat window]\n");
    printf("%s\n", buffer);
    printf("> ");
}

void get_user_input(char *username) {
    fgets(username, MAX_USERNAME_LENGTH, stdin);
    username[strcspn(username, "\n")] = '\0'; // Remove newline character
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    char buffer[BUFFER_SIZE];
    welcome_message();
    get_user_input(username);
    printf("Hello, %s!\n", username);

    // Add a deliberate buffer overflow vulnerability on gets call
    gets(buffer);
    // Rest of the program will be affected by the overflow here

    display_chat_window(buffer);

    return 0;
}

//FormAI DATASET v1.0 Category: Text processing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Constants
#define MAX_COMMAND_LENGTH 10
#define MAX_MESSAGE_LENGTH 100

// Struct definitions
typedef struct {
    int id;
    char message[MAX_MESSAGE_LENGTH];
} Message;

// Global variables
Message *messages;
int num_messages = 0;

// Function prototypes
void print_commands();
bool execute_command(char *command);
void send_message();
void view_messages();
void clear_screen();

int main() {
    printf("Welcome to ChatBot!\n");
    printf("Type 'help' to see the list of commands.\n");

    char command[MAX_COMMAND_LENGTH];
    while (true) {
        printf("> ");
        scanf("%s", command);
        if (!execute_command(command)) {
            printf("Invalid command. Type 'help' to see the list of commands.\n");
        }
    }

    return 0;
}

// Print the list of available commands
void print_commands() {
    printf("Available commands:\n");
    printf("send - send a new message\n");
    printf("view - view messages\n");
    printf("clear - clear the screen\n");
    printf("help - display this list of commands\n");
    printf("exit - exit the program\n");
}

// Execute the specified command
bool execute_command(char *command) {
    if (strcmp(command, "send") == 0) {
        send_message();
        return true;
    } else if (strcmp(command, "view") == 0) {
        view_messages();
        return true;
    } else if (strcmp(command, "clear") == 0) {
        clear_screen();
        return true;
    } else if (strcmp(command, "help") == 0) {
        print_commands();
        return true;
    } else if (strcmp(command, "exit") == 0) {
        printf("Goodbye!\n");
        exit(0);
    }
    return false;
}

// Saves the specified message to the message buffer
void send_message() {
    messages = (Message*)realloc(messages, ++num_messages * sizeof(Message));
    Message msg;
    msg.id = num_messages;
    printf("> ");
    scanf(" %[^\n]s", msg.message);
    messages[num_messages - 1] = msg;
    printf("Message sent.\n");
}

// Prints all the messages in the message buffer
void view_messages() {
    printf("Messages:\n");
    for (int i = 0; i < num_messages; i++) {
        printf("%d. %s\n", messages[i].id, messages[i].message);
    }
}

// Clear the screen
void clear_screen() {
    system("clear");
}
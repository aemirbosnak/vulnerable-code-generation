#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256
#define NUM_MESSAGES 10

typedef struct Message {
    char content[BUFFER_SIZE];
    struct Message *next;
} Message;

Message *head = NULL;

void add_message(char *message) {
    Message *new_msg = (Message *)malloc(sizeof(Message));
    strcpy(new_msg->content, message);
    new_msg->next = head;
    head = new_msg;
}

void print_messages() {
    Message *current = head;
    int i = 0;
    while (current != NULL) {
        printf("[%d] %s\n", i++, current->content);
        current = current->next;
    }
}

int main() {
    int option;
    char input[BUFFER_SIZE];
    printf("Welcome to the Simple Chat Manager!\n");

    while (1) {
        printf("\nChoose an option:\n"
               "1. Send a message\n"
               "2. Print messages\n"
               "3. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter your message (up to %d characters):\n", BUFFER_SIZE);
                scanf("%s", input);
                if (strlen(input) >= BUFFER_SIZE) {
                    printf("Message too long. Please limit messages to %d characters.\n", BUFFER_SIZE);
                } else {
                    add_message(input);
                }
                break;
            case 2:
                print_messages();
                break;
            case 3:
                printf("Exiting the Simple Chat Manager...\n");
                exit(0);
            default:
                printf("Invalid option. Please choose 1, 2, or 3.\n");
        }
    }

    return 0;
}

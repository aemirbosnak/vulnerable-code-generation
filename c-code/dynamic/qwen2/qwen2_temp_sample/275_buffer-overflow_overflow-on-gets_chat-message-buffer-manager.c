#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void receive_message(char *buffer, size_t size) {
    printf("Enter your message: ");
    fgets(buffer, size + 2, stdin);
}

int main() {
    char buffer[BUFFER_SIZE];
    int choice;

    while (1) {
        printf("\nChat Message Buffer Manager\n");
        printf("1. Receive message\n");
        printf("2. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 2) {
            break;
        } else if (choice == 1) {
            receive_message(buffer, BUFFER_SIZE);
            printf("Message received: %s\n", buffer);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

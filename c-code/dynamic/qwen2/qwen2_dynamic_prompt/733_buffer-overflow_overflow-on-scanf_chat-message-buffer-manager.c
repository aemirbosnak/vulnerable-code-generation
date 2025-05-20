#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void receiveMessage(char *buffer) {
    printf("Enter your message: ");
    scanf("%s", buffer);
}

int main() {
    char buffer[BUFFER_SIZE];
    int choice;

    while (1) {
        printf("\nChat Buffer Manager\n");
        printf("1. Receive Message\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 2) {
            break;
        } else if (choice == 1) {
            receiveMessage(buffer);
            printf("Buffer contents: %s\n", buffer);
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

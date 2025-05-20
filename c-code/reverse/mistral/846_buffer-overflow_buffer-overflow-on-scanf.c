#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void compose_email(char *buffer, int size) {
    printf("Compose Email:\n");
    printf("Enter recipient: ");
    scanf("%s", buffer);
    printf("Enter subject: ");
    scanf("%s", buffer);
    printf("Enter message (up to %d characters):\n", size);
    scanf("%s", buffer);
}

void display_menu() {
    printf("\nEmail Client Menu:\n");
    printf("1. Compose Email\n");
    printf("2. Send Email\n");
    printf("3. View Inbox\n");
    printf("4. Exit\n");
}

int main() {
    char email[100];
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                compose_email(email, sizeof(email));
                break;
            case 2:
                // Send email implementation
                break;
            case 3:
                // View inbox implementation
                break;
            case 4:
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 256

void compose_email(char *email) {
    printf("Compose your email: ");
    scanf("%255s", email); // Vulnerable to buffer overflow
}

int main() {
    char email[MAX_EMAIL_LENGTH];
    int choice;

    while (1) {
        printf("\nEmail Client Menu\n");
        printf("1. Compose Email\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                compose_email(email);
                break;
            case 2:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

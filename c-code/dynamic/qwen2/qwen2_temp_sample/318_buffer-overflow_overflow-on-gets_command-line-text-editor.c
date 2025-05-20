#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void edit_text() {
    char buffer[128];
    printf("Enter your text (max 127 characters): ");
    gets(buffer);
    printf("Your text: %s\n", buffer);
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Edit Text\n");
        printf("2. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                edit_text();
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

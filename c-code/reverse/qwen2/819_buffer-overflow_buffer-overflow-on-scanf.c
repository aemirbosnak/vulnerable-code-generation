#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int choice;
    while (1) {
        printf("Smart Home System\n");
        printf("1. Control Lights\n");
        printf("2. Control Fan\n");
        printf("3. Control AC Unit\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Control Lights Menu\n");
                // Add light control logic here
                break;
            case 2:
                printf("Control Fan Menu\n");
                // Add fan control logic here
                break;
            case 3:
                printf("Control AC Unit Menu\n");
                // Add AC unit control logic here
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

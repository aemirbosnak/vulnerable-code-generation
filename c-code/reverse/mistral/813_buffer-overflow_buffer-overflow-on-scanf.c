#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void toggleLight() {
    printf("Light is toggled.\n");
}

void toggleFan() {
    printf("Fan is toggled.\n");
}

void toggleAc() {
    printf("AC is toggled.\n");
}

int main() {
    int choice;

    printf("Smart Home System\n");
    printf("1. Toggle Light\n");
    printf("2. Toggle Fan\n");
    printf("3. Toggle AC\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            toggleLight();
            break;
        case 2:
            toggleFan();
            break;
        case 3:
            toggleAc();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}

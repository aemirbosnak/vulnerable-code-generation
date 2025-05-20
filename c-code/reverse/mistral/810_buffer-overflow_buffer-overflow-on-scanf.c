#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void toggleLight() { printf("Light: Toggled\n"); }
void toggleFan() { printf("Fan: Toggled\n"); }
void toggleAc() { printf("AC: Toggled\n"); }

int main() {
    int choice;

    while (1) {
        printf("\nChoose an appliance to toggle (1: Light, 2: Fan, 3: AC, 0: Exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: toggleLight(); break;
            case 2: toggleFan(); break;
            case 3: toggleAc(); break;
            case 0: return 0;
            default: printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

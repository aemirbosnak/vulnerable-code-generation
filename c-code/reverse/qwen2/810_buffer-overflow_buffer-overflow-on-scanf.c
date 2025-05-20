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
        printf("1. Toggle Lights\n");
        printf("2. Toggle Fan\n");
        printf("3. Toggle AC\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Lights Toggled\n");
                break;
            case 2:
                printf("Fan Toggled\n");
                break;
            case 3:
                printf("AC Toggled\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
}

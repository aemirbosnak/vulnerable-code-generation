#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void controlLight(int state) {
    if (state)
        printf("Light is ON\n");
    else
        printf("Light is OFF\n");
}

void controlFan(int state) {
    if (state)
        printf("Fan is ON\n");
    else
        printf("Fan is OFF\n");
}

void controlAc(int state) {
    if (state)
        printf("AC is ON\n");
    else
        printf("AC is OFF\n");
}

int main() {
    int choice, lightState, fanState, acState;

    printf("Welcome to the Smart Home System\n");
    printf("1. Light\n2. Fan\n3. AC\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice != 4) {
        switch (choice) {
            case 1:
                printf("Enter the state of the light (1 for ON, 0 for OFF): ");
                scanf("%d", &lightState);
                controlLight(lightState);
                break;
            case 2:
                printf("Enter the state of the fan (1 for ON, 0 for OFF): ");
                scanf("%d", &fanState);
                controlFan(fanState);
                break;
            case 3:
                printf("Enter the state of the AC (1 for ON, 0 for OFF): ");
                scanf("%d", &acState);
                controlAc(acState);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("1. Light\n2. Fan\n3. AC\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    return 0;
}

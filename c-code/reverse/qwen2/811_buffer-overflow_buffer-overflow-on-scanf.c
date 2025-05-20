#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 10

typedef struct {
    int light;
    int fan;
    int ac;
} SmartHome;

void displayMenu() {
    printf("Smart Home System\n");
    printf("1. Toggle Light\n");
    printf("2. Toggle Fan\n");
    printf("3. Toggle AC\n");
    printf("4. Exit\n");
}

int getUserInput() {
    char input[MAX_INPUT];
    if (fgets(input, sizeof(input), stdin) != NULL) {
        return atoi(input);
    }
    return -1;
}

void toggleLight(SmartHome *home) {
    home->light = !home->light;
    printf("Light is now %s\n", home->light ? "ON" : "OFF");
}

void toggleFan(SmartHome *home) {
    home->fan = !home->fan;
    printf("Fan is now %s\n", home->fan ? "ON" : "OFF");
}

void toggleAC(SmartHome *home) {
    home->ac = !home->ac;
    printf("AC is now %s\n", home->ac ? "ON" : "OFF");
}

int main() {
    SmartHome home = {0};
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        choice = getUserInput();

        switch (choice) {
            case 1:
                toggleLight(&home);
                break;
            case 2:
                toggleFan(&home);
                break;
            case 3:
                toggleAC(&home);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

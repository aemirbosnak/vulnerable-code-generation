//FormAI DATASET v1.0 Category: Smart home light control ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void turnOn(int);
void turnOff(int);
void dim(int, int);

int main() {
    int choice, lightNum, brightness;
    while (1) {
        printf("\nEnter the number of the light (1-10):\n");
        scanf("%d", &lightNum);
        printf("What would you like to do with light number %d?\n", lightNum);
        printf("1. Turn on\n2. Turn off\n3. Dim\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                turnOn(lightNum);
                break;
            case 2:
                turnOff(lightNum);
                break;
            case 3:
                printf("Enter the brightness level (1-10):\n");
                scanf("%d", &brightness);
                dim(lightNum, brightness);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select 1-4.\n");
        }
    }
    return 0;
}

// Function to turn on a specific light
void turnOn(int num) {
    printf("Turning on light %d.\n", num);
}

// Function to turn off a specific light
void turnOff(int num) {
    printf("Turning off light %d.\n", num);
}

// Function to dim a specific light to a specific brightness level
void dim(int num, int level) {
    printf("Dimming light %d to level %d.\n", num, level);
}
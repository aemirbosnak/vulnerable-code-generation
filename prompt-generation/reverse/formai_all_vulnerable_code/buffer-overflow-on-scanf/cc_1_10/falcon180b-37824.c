//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: modular
#include <stdio.h>

// Function prototypes
void setup();
void loop();
void turnOnLight();
void turnOffLight();

int main() {
    setup();
    while (1) {
        loop();
    }
    return 0;
}

void setup() {
    printf("Smart Home Light Control System\n");
    printf("Initializing...\n");
}

void loop() {
    int choice;
    printf("\n");
    printf("1. Turn on light\n");
    printf("2. Turn off light\n");
    printf("3. Exit\n");
    printf("\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            turnOnLight();
            break;
        case 2:
            turnOffLight();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void turnOnLight() {
    printf("Turning on the light...\n");
}

void turnOffLight() {
    printf("Turning off the light...\n");
}
//FormAI DATASET v1.0 Category: Smart home light control ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Cyberpunk Smart Home Light Control System!\n");

    // Generate random numbers (0 or 1)
    srand(time(NULL));
    int livingRoomLight = rand() % 2;
    int kitchenLight = rand() % 2;
    int bedroomLight = rand() % 2;

    // Display current light settings
    printf("Current light settings:\n");
    printf("Living Room: %d\n", livingRoomLight);
    printf("Kitchen: %d\n", kitchenLight);
    printf("Bedroom: %d\n", bedroomLight);

    // Prompt user for input
    printf("Enter 1 to turn a light on or 0 to turn a light off:\n");
    int choice;
    scanf("%d", &choice);

    // Switch statement to determine which light to change
    switch (choice) {
        case 1:
            printf("Which light do you want to turn on?\n");
            printf("1. Living Room\n");
            printf("2. Kitchen\n");
            printf("3. Bedroom\n");
            int lightChoice;
            scanf("%d", &lightChoice);
            switch (lightChoice) {
                case 1:
                    printf("Turning Living Room light on...\n");
                    livingRoomLight = 1;
                    break;
                case 2:
                    printf("Turning Kitchen light on...\n");
                    kitchenLight = 1;
                    break;
                case 3:
                    printf("Turning Bedroom light on...\n");
                    bedroomLight = 1;
                    break;
                default:
                    printf("Invalid choice...\n");
                    break;
            }
            break;
        case 0:
            printf("Which light do you want to turn off?\n");
            printf("1. Living Room\n");
            printf("2. Kitchen\n");
            printf("3. Bedroom\n");
            int lightChoice2;
            scanf("%d", &lightChoice2);
            switch (lightChoice2) {
                case 1:
                    printf("Turning Living Room light off...\n");
                    livingRoomLight = 0;
                    break;
                case 2:
                    printf("Turning Kitchen light off...\n");
                    kitchenLight = 0;
                    break;
                case 3:
                    printf("Turning Bedroom light off...\n");
                    bedroomLight = 0;
                    break;
                default:
                    printf("Invalid choice...\n");
                    break;
            }
            break;
        default:
            printf("Invalid choice...\n");
            break;
    }

    // Display updated light settings
    printf("Updated light settings:\n");
    printf("Living Room: %d\n", livingRoomLight);
    printf("Kitchen: %d\n", kitchenLight);
    printf("Bedroom: %d\n", bedroomLight);

    return 0;
}
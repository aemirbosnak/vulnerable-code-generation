//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: light-weight
#include <stdio.h>

#define LIGHT_ON  1
#define LIGHT_OFF 0

#define LIVING_ROOM_LIGHT  0b00000001 // 1
#define KITCHEN_LIGHT      0b00000010 // 2
#define BEDROOM_LIGHT      0b00000100 // 4
#define BATHROOM_LIGHT     0b00001000 // 8
#define GARAGE_LIGHT       0b00010000 // 16

void printLightStatus(int lights) {
    printf("Light Status:\n");
    printf("Living Room: %s\n", (lights & LIVING_ROOM_LIGHT) ? "ON" : "OFF");
    printf("Kitchen: %s\n", (lights & KITCHEN_LIGHT) ? "ON" : "OFF");
    printf("Bedroom: %s\n", (lights & BEDROOM_LIGHT) ? "ON" : "OFF");
    printf("Bathroom: %s\n", (lights & BATHROOM_LIGHT) ? "ON" : "OFF");
    printf("Garage: %s\n", (lights & GARAGE_LIGHT) ? "ON" : "OFF");
}

int turnOnLight(int lights, int light) {
    return lights | light;
}

int turnOffLight(int lights, int light) {
    return lights & ~light;
}

int toggleLight(int lights, int light) {
    return lights ^ light;
}

int main() {
    int lights = 0; // All lights are OFF initially
    int choice, light;

    while (1) {
        printf("\nLight Control Menu:\n");
        printf("1. Turn ON Light\n");
        printf("2. Turn OFF Light\n");
        printf("3. Toggle Light\n");
        printf("4. Show Light Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Select light to turn ON:\n");
                printf("1. Living Room\n");
                printf("2. Kitchen\n");
                printf("3. Bedroom\n");
                printf("4. Bathroom\n");
                printf("5. Garage\n");
                printf("Enter your choice: ");
                scanf("%d", &light);
                switch (light) {
                    case 1: lights = turnOnLight(lights, LIVING_ROOM_LIGHT); break;
                    case 2: lights = turnOnLight(lights, KITCHEN_LIGHT); break;
                    case 3: lights = turnOnLight(lights, BEDROOM_LIGHT); break;
                    case 4: lights = turnOnLight(lights, BATHROOM_LIGHT); break;
                    case 5: lights = turnOnLight(lights, GARAGE_LIGHT); break;
                    default: printf("Invalid choice!\n"); break;
                }
                break;
                
            case 2:
                printf("Select light to turn OFF:\n");
                printf("1. Living Room\n");
                printf("2. Kitchen\n");
                printf("3. Bedroom\n");
                printf("4. Bathroom\n");
                printf("5. Garage\n");
                printf("Enter your choice: ");
                scanf("%d", &light);
                switch (light) {
                    case 1: lights = turnOffLight(lights, LIVING_ROOM_LIGHT); break;
                    case 2: lights = turnOffLight(lights, KITCHEN_LIGHT); break;
                    case 3: lights = turnOffLight(lights, BEDROOM_LIGHT); break;
                    case 4: lights = turnOffLight(lights, BATHROOM_LIGHT); break;
                    case 5: lights = turnOffLight(lights, GARAGE_LIGHT); break;
                    default: printf("Invalid choice!\n"); break;
                }
                break;
                
            case 3:
                printf("Select light to toggle:\n");
                printf("1. Living Room\n");
                printf("2. Kitchen\n");
                printf("3. Bedroom\n");
                printf("4. Bathroom\n");
                printf("5. Garage\n");
                printf("Enter your choice: ");
                scanf("%d", &light);
                switch (light) {
                    case 1: lights = toggleLight(lights, LIVING_ROOM_LIGHT); break;
                    case 2: lights = toggleLight(lights, KITCHEN_LIGHT); break;
                    case 3: lights = toggleLight(lights, BEDROOM_LIGHT); break;
                    case 4: lights = toggleLight(lights, BATHROOM_LIGHT); break;
                    case 5: lights = toggleLight(lights, GARAGE_LIGHT); break;
                    default: printf("Invalid choice!\n"); break;
                }
                break;

            case 4:
                printLightStatus(lights);
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please enter again.\n");
        }
    }
    return 0;
}
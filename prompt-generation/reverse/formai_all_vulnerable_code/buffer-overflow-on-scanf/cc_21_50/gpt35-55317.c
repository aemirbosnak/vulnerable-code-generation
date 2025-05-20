//FormAI DATASET v1.0 Category: Smart home light control ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10 // maximum number of rooms
#define MAX_LIGHTS 5 // maximum number of lights in each room

typedef struct {
    int room_id;
    int light_id;
    int brightness;
    int status;
} Light;

int main() {
    int num_rooms, num_lights, choice, room_choice, light_choice, i, j;
    Light lights[MAX_ROOMS][MAX_LIGHTS];

    printf("Enter the number of rooms: ");
    scanf("%d", &num_rooms);
    printf("Enter the number of lights in each room: ");
    scanf("%d", &num_lights);

    // initialize all lights to off and brightness to 0
    for (i = 0; i < num_rooms; i++) {
        for (j = 0; j < num_lights; j++) {
            lights[i][j].room_id = i+1;
            lights[i][j].light_id = j+1;
            lights[i][j].status = 0;
            lights[i][j].brightness = 0;
        }
    }

    do {
        // Menu
        printf("\nMAIN MENU\n");
        printf("1. Turn on/off lights\n");
        printf("2. Adjust brightness\n");
        printf("3. Print room status\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Turn on/off lights in a room
                printf("Enter room number (1-%d): ", num_rooms);
                scanf("%d", &room_choice);
                if (room_choice < 1 || room_choice > num_rooms) {
                    printf("Invalid room number.\n");
                    break;
                }
                
                printf("Enter light number (1-%d): ", num_lights);
                scanf("%d", &light_choice);
                if (light_choice < 1 || light_choice > num_lights) {
                    printf("Invalid light number.\n");
                    break;
                }
                
                if (lights[room_choice-1][light_choice-1].status == 0) {
                    lights[room_choice-1][light_choice-1].status = 1;
                    printf("Light turned on.\n");
                }
                else {
                    lights[room_choice-1][light_choice-1].status = 0;
                    printf("Light turned off.\n");
                }
                break;
                
            case 2:
                // Adjust brightness of a light
                printf("Enter room number (1-%d): ", num_rooms);
                scanf("%d", &room_choice);
                if (room_choice < 1 || room_choice > num_rooms) {
                    printf("Invalid room number.\n");
                    break;
                }

                printf("Enter light number (1-%d): ", num_lights);
                scanf("%d", &light_choice);
                if (light_choice < 1 || light_choice > num_lights) {
                    printf("Invalid light number.\n");
                    break;
                }

                printf("Enter brightness level (0-100): ");
                scanf("%d", &lights[room_choice-1][light_choice-1].brightness);
                if (lights[room_choice-1][light_choice-1].brightness < 0 || lights[room_choice-1][light_choice-1].brightness > 100) {
                    printf("Invalid brightness level.\n");
                    break;
                }
                printf("Brightness adjusted to %d.\n", lights[room_choice-1][light_choice-1].brightness);
                break;

            case 3:
                // Print room status
                printf("\nROOM STATUS\n");
                for (i = 0; i < num_rooms; i++) {
                    printf("Room %d: ", i+1);
                    for (j = 0; j < num_lights; j++) {
                        if (lights[i][j].status == 1) {
                            printf("Light %d is on (brightness %d%%) | ", lights[i][j].light_id, lights[i][j].brightness);
                        }
                        else {
                            printf("Light %d is off | ", lights[i][j].light_id);
                        }
                    }
                    printf("\n");
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
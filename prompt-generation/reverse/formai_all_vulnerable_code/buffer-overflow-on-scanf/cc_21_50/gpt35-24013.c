//FormAI DATASET v1.0 Category: Smart home light control ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main() {
    int room1_light = 0, room2_light = 0, room3_light = 0, exit_loop = 0; 
    char user_input;

    printf("Welcome to Smart Home Light Control System!\n");

    while (!exit_loop) {
        printf("Choose a room to control the lights (1, 2, 3) (or type 'E' to exit): ");
        scanf("%c", &user_input);

        switch (user_input) {
            case '1':
                printf("Room 1 light is currently %s. Do you want to turn on or off? (Y/N): ", (room1_light == 0 ? "OFF" : "ON"));
                scanf(" %c", &user_input);

                if (user_input == 'Y' || user_input == 'y') {
                    room1_light = (room1_light == 0 ? 1 : 0);
                    printf("Room 1 light has been turned %s.\n", (room1_light == 1 ? "ON" : "OFF"));
                }
                break;
            case '2':
                printf("Room 2 light is currently %s. Do you want to turn on or off? (Y/N): ", (room2_light == 0 ? "OFF" : "ON"));
                scanf(" %c", &user_input);

                if (user_input == 'Y' || user_input == 'y') {
                    room2_light = (room2_light == 0 ? 1 : 0);
                    printf("Room 2 light has been turned %s.\n", (room2_light == 1 ? "ON" : "OFF"));
                }
                break;
            case '3':
                printf("Room 3 light is currently %s. Do you want to turn on or off? (Y/N): ", (room3_light == 0 ? "OFF" : "ON"));
                scanf(" %c", &user_input);

                if (user_input == 'Y' || user_input == 'y') {
                    room3_light = (room3_light == 0 ? 1 : 0);
                    printf("Room 3 light has been turned %s.\n", (room3_light == 1 ? "ON" : "OFF"));
                }
                break;
            case 'E':
            case 'e':
                exit_loop = 1;
                printf("Exiting Smart Home Light Control System. Thank you!\n");
                break;
            default:
                printf("Invalid input, please try again.\n");
                break;
        }

        fflush(stdin); // clear input buffer
    }

    return 0;
}
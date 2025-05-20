//FormAI DATASET v1.0 Category: Smart home automation ; Style: futuristic
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Initialize smart home devices
    bool living_room_light = false;
    bool kitchen_light = false;
    bool bedroom_light = false;
    int aircon_temp = 23;
    int heater_temp = 22;
    bool door_locked = true;
    bool window_closed = true;
    bool security_system_activated = false;

    // Get user input for desired actions
    char user_input;
    printf("Welcome to your smart home! What would you like to do?\n");
    printf("Press '1' to turn on the living room light\n");
    printf("Press '2' to turn on the kitchen light\n");
    printf("Press '3' to turn on the bedroom light\n");
    printf("Press '4' to adjust the air conditioner temperature\n");
    printf("Press '5' to adjust the heater temperature\n");
    printf("Press '6' to lock/unlock the door\n");
    printf("Press '7' to open/close the window\n");
    printf("Press '8' to activate/deactivate the security system\n");
    scanf("%c", &user_input);

    // Perform desired actions based on user input
    switch(user_input) {
        case '1':
            living_room_light = true;
            printf("Living room light turned on\n");
            break;
        case '2':
            kitchen_light = true;
            printf("Kitchen light turned on\n");
            break;
        case '3':
            bedroom_light = true;
            printf("Bedroom light turned on\n");
            break;
        case '4':
            printf("Enter desired air conditioner temperature: ");
            scanf("%d", &aircon_temp);
            printf("Air conditioner temperature set to %d\n", aircon_temp);
            break;
        case '5':
            printf("Enter desired heater temperature: ");
            scanf("%d", &heater_temp);
            printf("Heater temperature set to %d\n", heater_temp);
            break;
        case '6':
            door_locked = !door_locked;
            if (door_locked) {
                printf("Door locked\n");
            } else {
                printf("Door unlocked\n");
            }
            break;
        case '7':
            window_closed = !window_closed;
            if (window_closed) {
                printf("Window closed\n");
            } else {
                printf("Window opened\n");
            }
            break;
        case '8':
            security_system_activated = !security_system_activated;
            if (security_system_activated) {
                printf("Security system activated\n");
            } else {
                printf("Security system deactivated\n");
            }
            break;
        default:
            printf("Invalid input\n");
    }

    return 0;
}
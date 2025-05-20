//FormAI DATASET v1.0 Category: Smart home light control ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int light_brightness = rand() % 100 + 1; // Generate random brightness level between 1 and 100
    int user_input;
    
    // Display current light brightness level and wait for user input
    printf("Current light brightness level: %d\n", light_brightness);
    printf("Enter a command (1: increase brightness | 2: decrease brightness | 3: turn off light | 4: turn on light): ");
    scanf("%d", &user_input);
    
    // Control the light based on user input
    switch(user_input) {
        case 1:
            printf("Increasing brightness...\n");
            light_brightness += 10;
            if(light_brightness > 100) {
                light_brightness = 100;
                printf("Light is now at maximum brightness.\n");
            }
            else {
                printf("Light brightness level is now %d.\n", light_brightness);
            }
            break;
        case 2:
            printf("Decreasing brightness...\n");
            light_brightness -= 10;
            if(light_brightness < 0) {
                light_brightness = 0;
                printf("Light is now off.\n");
            }
            else {
                printf("Light brightness level is now %d.\n", light_brightness);
            }
            break;
        case 3:
            printf("Turning off light...\n");
            light_brightness = 0;
            printf("Light is now off.\n");
            break;
        case 4:
            printf("Turning on light...\n");
            light_brightness = 50; // Default brightness level when turning on light
            printf("Light is now on with brightness level %d.\n", light_brightness);
            break;
        default:
            printf("Invalid input. Please try again.\n");
            break;
    }
    
    return 0;
}
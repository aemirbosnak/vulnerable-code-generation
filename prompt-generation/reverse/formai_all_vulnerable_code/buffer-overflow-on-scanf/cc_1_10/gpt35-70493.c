//FormAI DATASET v1.0 Category: Smart home light control ; Style: Romeo and Juliet
/* Romeo and Juliet: A Smart Home Light Control */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Declare global variables
int is_light_on = 0;
int current_brightness = 0;

// Function to turn on the light
void turn_on_light() {
    current_brightness = rand() % 10 + 1;
    is_light_on = 1;
    printf("Lady, the light is on with a brightness level of %d/10.\n", current_brightness);
}

// Function to turn off the light
void turn_off_light() {
    current_brightness = 0;
    is_light_on = 0;
    printf("Lady, the light is off.\n");
}

// Main function
int main() {

    srand(time(NULL));

    int hour_of_day;

    printf("Enter the hour of the day (0-23): ");
    scanf("%d", &hour_of_day);

    if (hour_of_day >= 6 && hour_of_day <= 18) {
        // It's daytime, turn off the light
        turn_off_light();
    }
    else {
        // It's nighttime, turn on the light
        turn_on_light();
    }

    char user_input;

    while (1) {
        printf("What would you like to do? Turn the light on (O), turn the light off (F), or quit (Q)? ");
        scanf(" %c", &user_input);

        if (user_input == 'O' || user_input == 'o') {
            if (!is_light_on) {
                turn_on_light();
            }
            else {
                printf("Lady, the light is already on.\n");
            }
        }
        else if (user_input == 'F' || user_input == 'f') {
            if (is_light_on) {
                turn_off_light();
            }
            else {
                printf("Lady, the light is already off.\n");
            }
        }
        else if (user_input == 'Q' || user_input == 'q') {
            printf("Farewell, Lady.\n");
            break;
        }
        else {
            printf("Invalid input, Lady.\n");
        }
    }

    return 0;
}
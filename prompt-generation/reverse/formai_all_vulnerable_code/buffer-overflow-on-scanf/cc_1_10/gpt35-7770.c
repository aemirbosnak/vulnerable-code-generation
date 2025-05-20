//FormAI DATASET v1.0 Category: Smart home light control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* Function declarations */
int get_user_choice();
void print_menu();
void turn_on_lights();
void turn_off_lights();
void dim_lights();
void party_mode();

/* Global state variables */
bool lights_on = false;
int light_intensity = 0;

int main(){
    while(true){
        print_menu();

        int choice = get_user_choice();

        switch(choice){
            case 1:
                turn_on_lights();
                break;
            case 2:
                turn_off_lights();
                break;
            case 3:
                dim_lights();
                break;
            case 4:
                party_mode();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int get_user_choice(){
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void print_menu(){
    printf("--- Smart Home Light Control ---\n");
    printf("1. Turn on lights\n");
    printf("2. Turn off lights\n");
    printf("3. Dim lights\n");
    printf("4. Party mode\n");
    printf("5. Exit\n");
}

void turn_on_lights(){
    if (lights_on){
        printf("Lights are already on.\n");
    } else {
        printf("Turning on lights...\n");
        lights_on = true;
        light_intensity = 100;
        printf("Lights are on at full intensity.\n");
    }
}

void turn_off_lights(){
    if (!lights_on){
        printf("Lights are already off.\n");
    } else {
        printf("Turning off lights...\n");
        lights_on = false;
        light_intensity = 0;
        printf("Lights are off.\n");
    }
}

void dim_lights(){
    if (!lights_on){
        printf("Please turn on lights before dimming.\n");
    } else {
        printf("Enter the desired intensity (0-100): ");
        int desired_intensity;
        scanf("%d", &desired_intensity);

        if (desired_intensity < 0 || desired_intensity > 100){
            printf("Invalid intensity value. Please try again.\n");
        } else {
            printf("Dimming lights...\n");
            light_intensity = desired_intensity;
            printf("Lights are now at %d%% intensity.\n", light_intensity);
        }
    }
}

void party_mode(){
    if (!lights_on){
        printf("Please turn on lights before activating party mode.\n");
    } else {
        printf("Activating party mode...\n");

        srand(time(NULL)); // Seed the random number generator with current time

        for (int i = 0; i < 10; i++){
            int intensity = rand() % 101;
            light_intensity = intensity;
            printf("Lights are now at %d%% intensity.\n", light_intensity);
            sleep(1); // Pause for 1 second
        }

        // Reset to previous state
        light_intensity = 100;
        printf("Party mode ended. Lights are now at full intensity.\n");
    }
}
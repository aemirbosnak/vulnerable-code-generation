//FormAI DATASET v1.0 Category: Smart home light control ; Style: active
#include <stdio.h>
#include <stdbool.h>

#define MAX_LIGHTS 4

bool lights[MAX_LIGHTS] = {false, false, false, false};

void print_lights_status(void);
void switch_on_all_lights(void);
void switch_off_all_lights(void);
void switch_on_one_light(int light_number);
void switch_off_one_light(int light_number);

int main(void) {
    int option, light_number;
    
    printf("Welcome to Smart Home Light Control System!\n");
    print_lights_status();
    
    while (true) {
        printf("\nWhat do you want to do?\n");
        printf("1. Switch on all lights\n");
        printf("2. Switch off all lights\n");
        printf("3. Switch on one light\n");
        printf("4. Switch off one light\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                switch_on_all_lights();
                print_lights_status();
                break;
            case 2:
                switch_off_all_lights();
                print_lights_status();
                break;
            case 3:
                printf("Enter the number of light you want to switch on (1 to %d): ", MAX_LIGHTS);
                scanf("%d", &light_number);
                switch_on_one_light(light_number);
                print_lights_status();
                break;
            case 4:
                printf("Enter the number of light you want to switch off (1 to %d): ", MAX_LIGHTS);
                scanf("%d", &light_number);
                switch_off_one_light(light_number);
                print_lights_status();
                break;
            case 5:
                printf("Thanks for using Smart Home Light Control System!\n");
                return 0;
            default:
                printf("Invalid option!\n");
        }
    }
}

void print_lights_status(void) {
    printf("Current light status: ");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        if (lights[i]) {
            printf("ON ");
        } else {
            printf("OFF ");
        }
    }
    printf("\n");
}

void switch_on_all_lights(void) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i] = true;
    }
}

void switch_off_all_lights(void) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i] = false;
    }
}

void switch_on_one_light(int light_number) {
    if (light_number >= 1 && light_number <= MAX_LIGHTS) {
        lights[light_number-1] = true;
    } else {
        printf("Invalid light number!\n");
    }
}

void switch_off_one_light(int light_number) {
    if (light_number >= 1 && light_number <= MAX_LIGHTS) {
        lights[light_number-1] = false;
    } else {
        printf("Invalid light number!\n");
    }
}
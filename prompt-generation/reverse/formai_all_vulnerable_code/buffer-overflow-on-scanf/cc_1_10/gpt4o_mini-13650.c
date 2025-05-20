//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define LIGHT_COUNT 5

typedef struct {
    int id;
    char name[30];
    int brightness; // 0-100%
    int is_on; // 1 for ON, 0 for OFF
} SmartLight;

SmartLight lights[LIGHT_COUNT];

void init_lights() {
    for (int i = 0; i < LIGHT_COUNT; i++) {
        lights[i].id = i + 1;
        snprintf(lights[i].name, sizeof(lights[i].name), "Light %d", i + 1);
        lights[i].brightness = 0;
        lights[i].is_on = 0; // Initially OFF
    }
}

void display_lights() {
    printf("\nCurrent Smart Lights Status:\n");
    for (int i = 0; i < LIGHT_COUNT; i++) {
        printf("ID: %d, Name: %s, Brightness: %d%%, Status: %s\n",
            lights[i].id, lights[i].name, 
            lights[i].brightness, lights[i].is_on ? "ON" : "OFF");
    }
}

void turn_on(int id) {
    if (id > 0 && id <= LIGHT_COUNT) {
        lights[id - 1].is_on = 1;
        lights[id - 1].brightness = 100; // Defaulting to maximum brightness when turned on
        printf("%s is now turned ON.\n", lights[id - 1].name);
    } else {
        printf("Invalid Light ID.\n");
    }
}

void turn_off(int id) {
    if (id > 0 && id <= LIGHT_COUNT) {
        lights[id - 1].is_on = 0;
        lights[id - 1].brightness = 0; // Turning off sets brightness to 0
        printf("%s is now turned OFF.\n", lights[id - 1].name);
    } else {
        printf("Invalid Light ID.\n");
    }
}

void set_brightness(int id, int brightness) {
    if (id > 0 && id <= LIGHT_COUNT) {
        if (brightness >= 0 && brightness <= 100) {
            lights[id - 1].brightness = brightness;
            printf("Brightness of %s set to %d%%.\n", lights[id - 1].name, brightness);
        } else {
            printf("Brightness must be between 0 and 100.\n");
        }
    } else {
        printf("Invalid Light ID.\n");
    }
}

void simulate_lights() {
    printf("\nStarting light simulation...\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < LIGHT_COUNT; j++) {
            lights[j].is_on = rand() % 2; // Random ON/OFF
            lights[j].brightness = lights[j].is_on ? (rand() % 101) : 0; // Random brightness if ON
        }
        display_lights();
        sleep(2); // Pause for 2 seconds for the simulation 
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    init_lights();

    int choice, id, brightness;
    while (1) {
        printf("\nSmart Home Light Control System\n");
        printf("1. Display Light Status\n");
        printf("2. Turn ON a Light\n");
        printf("3. Turn OFF a Light\n");
        printf("4. Set Brightness of a Light\n");
        printf("5. Simulate Lights\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting the Smart Home system. Goodbye!\n");
                exit(0);
            case 1:
                display_lights();
                break;
            case 2:
                printf("Enter Light ID to turn ON: ");
                scanf("%d", &id);
                turn_on(id);
                break;
            case 3:
                printf("Enter Light ID to turn OFF: ");
                scanf("%d", &id);
                turn_off(id);
                break;
            case 4:
                printf("Enter Light ID to set brightness: ");
                scanf("%d", &id);
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                set_brightness(id, brightness);
                break;
            case 5:
                simulate_lights();
                break;
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    }
    return 0;
}
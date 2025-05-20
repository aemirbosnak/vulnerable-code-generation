//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_LIGHTS 4
#define LIGHT_ON 1
#define LIGHT_OFF 0

enum light_status {
    ON = 1,
    OFF = 0
};

struct light {
    char name[50];
    enum light_status status;
};

void print_light_status(enum light_status status) {
    if (status == ON) {
        printf("Light is ON\n");
    } else {
        printf("Light is OFF\n");
    }
}

int main() {
    struct light lights[NUM_LIGHTS];

    for (int i = 0; i < NUM_LIGHTS; i++) {
        printf("Enter name of light %d: ", i + 1);
        scanf("%s", lights[i].name);
        lights[i].status = OFF;
    }

    int choice;
    while (1) {
        printf("\nSmart Home Light Control\n");
        printf("1. Turn on/off a light\n");
        printf("2. Set a light schedule\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name of light: ");
                scanf("%s", lights[0].name);
                printf("Enter status (0 for OFF, 1 for ON): ");
                scanf("%d", &lights[0].status);
                break;
            case 2:
                printf("Enter name of light: ");
                scanf("%s", lights[0].name);
                printf("Enter schedule (ON/OFF): ");
                char schedule[50];
                scanf("%s", schedule);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
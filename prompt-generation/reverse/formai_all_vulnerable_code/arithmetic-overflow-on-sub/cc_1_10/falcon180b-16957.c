//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_LIGHTS 5

typedef struct {
    char name[20];
    int status;
    int brightness;
} light_t;

light_t lights[NUM_LIGHTS];

void init_lights() {
    for (int i = 0; i < NUM_LIGHTS; i++) {
        strcpy(lights[i].name, "Light ");
        sprintf(&lights[i].name[5], "%d", i + 1);
        lights[i].status = 0;
        lights[i].brightness = 0;
    }
}

void print_lights() {
    printf("Current light settings:\n");
    for (int i = 0; i < NUM_LIGHTS; i++) {
        printf("%s: %s, Brightness: %d\n", lights[i].name, lights[i].status? "On" : "Off", lights[i].brightness);
    }
}

void set_light(int light_num, int status, int brightness) {
    if (light_num >= 0 && light_num < NUM_LIGHTS) {
        lights[light_num].status = status;
        lights[light_num].brightness = brightness;
    } else {
        printf("Invalid light number\n");
    }
}

void increase_brightness(int light_num) {
    if (light_num >= 0 && light_num < NUM_LIGHTS) {
        lights[light_num].brightness++;
        if (lights[light_num].brightness > 100) {
            lights[light_num].brightness = 100;
        }
    } else {
        printf("Invalid light number\n");
    }
}

void decrease_brightness(int light_num) {
    if (light_num >= 0 && light_num < NUM_LIGHTS) {
        lights[light_num].brightness--;
        if (lights[light_num].brightness < 0) {
            lights[light_num].brightness = 0;
        }
    } else {
        printf("Invalid light number\n");
    }
}

int main() {
    init_lights();
    int choice;
    while (1) {
        printf("1. Print light settings\n");
        printf("2. Set light status and brightness\n");
        printf("3. Increase brightness\n");
        printf("4. Decrease brightness\n");
        printf("0. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                print_lights();
                break;
            case 2:
                printf("Enter light number: ");
                int light_num;
                scanf("%d", &light_num);
                printf("Enter status (0=Off, 1=On): ");
                int status;
                scanf("%d", &status);
                printf("Enter brightness (0-100): ");
                int brightness;
                scanf("%d", &brightness);
                set_light(light_num, status, brightness);
                break;
            case 3:
                printf("Enter light number: ");
                int light_num2;
                scanf("%d", &light_num2);
                increase_brightness(light_num2);
                break;
            case 4:
                printf("Enter light number: ");
                int light_num3;
                scanf("%d", &light_num3);
                decrease_brightness(light_num3);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
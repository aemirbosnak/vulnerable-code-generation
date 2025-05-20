//FormAI DATASET v1.0 Category: Smart home light control ; Style: portable
#include <stdio.h>
#include <stdlib.h>

struct Light {
    int brightness;
    int temperature;
    int state; //0: off, 1: on
};

void controlLight(struct Light *light, int option) {
    switch (option) {
        case 1:
            light->brightness = 100;
            light->temperature = 5500;
            light->state = 1;
            printf("Light turn on with brightness %d and temperature %dK\n", light->brightness, light->temperature);
            break;
        case 2:
            light->brightness = 50;
            light->temperature = 4500;
            light->state = 1;
            printf("Light set to half brightness with temperature %dK\n", light->temperature);
            break;
        case 3:
            light->brightness = 10;
            light->temperature = 3500;
            light->state = 1;
            printf("Light set to low brightness with temperature %dK\n", light->temperature);
            break;
        case 4:
            light->state = 0;
            printf("Light turned off\n");
            break;
        default:
            printf("Invalid option\n");
    }
}

int main() {
    struct Light livingRoomLight = {0, 0, 0}; //initialize light attribute to off state

    int option;
    printf("Welcome to Smart Home Light Control\n");
    do {
        printf("Choose an option:\n");
        printf("1. Turn on light with full brightness and natural light temperature\n");
        printf("2. Set light to half brightness with daylight temperature\n");
        printf("3. Set light to low brightness with warm temperature\n");
        printf("4. Turn off light\n");
        printf("5. Exit\n");
        scanf("%d", &option);

        controlLight(&livingRoomLight, option);
    } while (option != 5);

    return 0;
}
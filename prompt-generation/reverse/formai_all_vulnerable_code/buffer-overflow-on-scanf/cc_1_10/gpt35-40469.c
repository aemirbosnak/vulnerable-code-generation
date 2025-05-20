//FormAI DATASET v1.0 Category: Smart home light control ; Style: high level of detail
#include <stdio.h>
#include <unistd.h>

struct Light {
    int status;
    int brightness;
};

void turnOn(struct Light *light) {
    light->status = 1;
    light->brightness = 100;
    printf("The light is turned on with brightness level %d.\n", light->brightness);
}

void turnOff(struct Light *light) {
    light->status = 0;
    light->brightness = 0;
    printf("The light is turned off.\n");
}

void decreaseBrightness(struct Light *light) {
    if (light->brightness > 0) {
        light->brightness -= 10;
        printf("The brightness is decreased to %d.\n", light->brightness);
    }
}

void increaseBrightness(struct Light *light) {
    if (light->brightness < 100) {
        light->brightness += 10;
        printf("The brightness is increased to %d.\n", light->brightness);
    }
}

int main() {
    struct Light livingRoomLight = {0, 0};
    printf("Welcome to Smart Home Light Control.\n");
    while (1) {
        int choice;
        printf("Choose an option:\n");
        printf("1. Turn on the light.\n");
        printf("2. Turn off the light.\n");
        printf("3. Decrease brightness.\n");
        printf("4. Increase brightness.\n");
        printf("5. Exit.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (livingRoomLight.status == 0) {
                    turnOn(&livingRoomLight);
                } else {
                    printf("The light is already turned on.\n");
                }
                break;
            case 2:
                if (livingRoomLight.status == 1) {
                    turnOff(&livingRoomLight);
                } else {
                    printf("The light is already turned off.\n");
                }
                break;
            case 3:
                decreaseBrightness(&livingRoomLight);
                break;
            case 4:
                increaseBrightness(&livingRoomLight);
                break;
            case 5:
                printf("Goodbye.\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
        sleep(1);
    }
    return 0;
}
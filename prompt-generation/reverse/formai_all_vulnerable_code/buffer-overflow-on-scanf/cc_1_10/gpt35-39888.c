//FormAI DATASET v1.0 Category: Smart home light control ; Style: Cyberpunk
#include <stdio.h>
#include <stdbool.h>

#define RED 0xFF0000
#define ORANGE 0xFFA500
#define YELLOW 0xFFFF00
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define PURPLE 0x800080

void turnOnLight(int lightColor);
void turnOffLight(int lightColor);
void changeLightColor(int newColor);
bool isLightOn();

int main() {
    int currentColor = PURPLE;
    bool lightState = false;

    printf("Welcome to Cyberpunk Smart Light Control\n\n");

    while (true) {
        printf("Current Light Color: ");
        switch (currentColor) {
            case RED:
                printf("Red");
                break;
            case ORANGE:
                printf("Orange");
                break;
            case YELLOW:
                printf("Yellow");
                break;
            case GREEN:
                printf("Green");
                break;
            case BLUE:
                printf("Blue");
                break;
            case PURPLE:
                printf("Purple");
                break;
        }
        printf("\n\n");

        printf("What would you like to do?\n");
        printf("1. Turn On/Off the Light\n");
        printf("2. Change the Light Color\n\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isLightOn()) {
                    turnOffLight(currentColor);
                    lightState = false;
                } else {
                    turnOnLight(currentColor);
                    lightState = true;
                }
                break;
            case 2:
                printf("Choose a new Color:\n");
                printf("1. Red\n");
                printf("2. Orange\n");
                printf("3. Yellow\n");
                printf("4. Green\n");
                printf("5. Blue\n");
                printf("6. Purple\n");

                int newColorChoice;
                scanf("%d", &newColorChoice);

                switch (newColorChoice) {
                    case 1:
                        currentColor = RED;
                        break;
                    case 2:
                        currentColor = ORANGE;
                        break;
                    case 3:
                        currentColor = YELLOW;
                        break;
                    case 4:
                        currentColor = GREEN;
                        break;
                    case 5:
                        currentColor = BLUE;
                        break;
                    case 6:
                        currentColor = PURPLE;
                        break;
                }
                if (lightState) {
                    turnOnLight(currentColor);
                }
                break;
        }
        printf("\n");
    }

    return 0;
}

void turnOnLight(int lightColor) {
    printf("Light is now on with Color: ");
    switch (lightColor) {
        case RED:
            printf("Red");
            break;
        case ORANGE:
            printf("Orange");
            break;
        case YELLOW:
            printf("Yellow");
            break;
        case GREEN:
            printf("Green");
            break;
        case BLUE:
            printf("Blue");
            break;
        case PURPLE:
            printf("Purple");
            break;
    }
    printf("\n");
}

void turnOffLight(int lightColor) {
    printf("Light is now off\n");
}

void changeLightColor(int newColor) {
    printf("Light color is changed to: ");
    switch (newColor) {
        case RED:
            printf("Red");
            break;
        case ORANGE:
            printf("Orange");
            break;
        case YELLOW:
            printf("Yellow");
            break;
        case GREEN:
            printf("Green");
            break;
        case BLUE:
            printf("Blue");
            break;
        case PURPLE:
            printf("Purple");
            break;
    }
    printf("\n");
}

bool isLightOn() {
    return true;
}
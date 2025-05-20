//FormAI DATASET v1.0 Category: Smart home light control ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    bool lightOn = false;
    int hour, minute;
    char mode;
    
    printf("Welcome to your smart home light control system!\n");
    printf("Please enter the current time in HH:MM format (24-hour clock): ");
    scanf("%d:%d", &hour, &minute);
    
    printf("Is the light currently on? (y/n): ");
    scanf(" %c", &mode);
    if (mode == 'y') {
        lightOn = true;
    } else if (mode != 'n') {
        printf("Error: Invalid input.\n");
        return 1;
    }
    
    if (hour >= 20 || hour <= 6) {
        printf("Good evening! The sun has set and the night has begun.\n");
        if (lightOn) {
            printf("The light is already on. Would you like to turn it off? (y/n): ");
            scanf(" %c", &mode);
            if (mode == 'y') {
                lightOn = false;
                printf("The light has been turned off.\n");
            } else if (mode != 'n') {
                printf("Error: Invalid input.\n");
                return 1;
            }
        } else {
            printf("The light is off. Would you like to turn it on? (y/n): ");
            scanf(" %c", &mode);
            if (mode == 'y') {
                lightOn = true;
                printf("The light has been turned on.\n");
            } else if (mode != 'n') {
                printf("Error: Invalid input.\n");
                return 1;
            }
        }
    } else {
        printf("Good day! The sun is out and shining.\n");
        if (lightOn) {
            printf("The light is already on. Would you like to turn it off? (y/n): ");
            scanf(" %c", &mode);
            if (mode == 'y') {
                lightOn = false;
                printf("The light has been turned off.\n");
            } else if (mode != 'n') {
                printf("Error: Invalid input.\n");
                return 1;
            }
        } else {
            printf("The light is off. Would you like to turn it on? (y/n): ");
            scanf(" %c", &mode);
            if (mode == 'y') {
                lightOn = true;
                printf("The light has been turned on.\n");
            } else if (mode != 'n') {
                printf("Error: Invalid input.\n");
                return 1;
            }
        }
    }
    
    printf("Thank you for using our smart home light control system!\n");
    return 0;
}
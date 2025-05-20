//FormAI DATASET v1.0 Category: Smart home light control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isLightOn(int light_status) {
    if (light_status == 1) {
        return true;
    } else {
        return false;
    }
}

void turnLightOn(int * light_status) {
    *light_status = 1;
    printf("Light turned on.\n");
}

void turnLightOff(int * light_status) {
    *light_status = 0;
    printf("Light turned off.\n");
}

int main() {
    int light_status = 0;
    int option = 0;
    
    do {
        printf("\n");
        printf("=== SMART HOME LIGHT CONTROL ===\n");
        printf("1. Turn light on\n");
        printf("2. Turn light off\n");
        printf("3. Check light status\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                if (isLightOn(light_status)) {
                    printf("Light is already turned on.\n");
                } else {
                    turnLightOn(&light_status);
                }
                break;
            case 2:
                if (isLightOn(light_status)) {
                    turnLightOff(&light_status);
                } else {
                    printf("Light is already turned off.\n");
                }
                break;
            case 3:
                if (isLightOn(light_status)) {
                    printf("Light status: ON\n");
                } else {
                    printf("Light status: OFF\n");
                }
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }    
    } while (option != 4);
    
    return 0;
}
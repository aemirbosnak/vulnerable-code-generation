//FormAI DATASET v1.0 Category: Smart home light control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LIGHTS 10

bool light_status[MAX_LIGHTS];

void print_menu() {
    printf("\nWelcome to Smart Home Light Control\n");
    printf("1. Turn a Light On\n");
    printf("2. Turn a Light Off\n");
    printf("3. Check Light Status\n");
    printf("4. Exit\n");
}

void turn_light_on(int light_num) {
    if (light_num < 0 || light_num >= MAX_LIGHTS) {
        printf("Invalid Light Number\n");
    } else {
        light_status[light_num] = true;
        printf("Light %d Turned On\n", light_num);
    }
}

void turn_light_off(int light_num) {
    if (light_num < 0 || light_num >= MAX_LIGHTS) {
        printf("Invalid Light Number\n");
    } else {
        light_status[light_num] = false;
        printf("Light %d Turned Off\n", light_num);
    }
}

void check_light_status(int light_num) {
    if (light_num < 0 || light_num >= MAX_LIGHTS) {
        printf("Invalid Light Number\n");
    } else {
        if (light_status[light_num]) {
            printf("Light %d is On\n", light_num);
        } else {
            printf("Light %d is Off\n", light_num);
        }
    }
}

int main() {
    int choice, light_num;
    
    // initially turn off all lights
    for (int i = 0; i < MAX_LIGHTS; i++) {
        light_status[i] = false;
    }
    
    do {
        print_menu();
        printf("Enter Choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter Light Number: ");
                scanf("%d", &light_num);
                turn_light_on(light_num);
                break;
            case 2:
                printf("Enter Light Number: ");
                scanf("%d", &light_num);
                turn_light_off(light_num);
                break;
            case 3:
                printf("Enter Light Number: ");
                scanf("%d", &light_num);
                check_light_status(light_num);
                break;
            case 4:
                printf("Exiting Program\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (choice != 4);
    
    return 0;
}
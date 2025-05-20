//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {

    int red_led = 0, yellow_led = 0, green_led = 0;

    printf("Welcome to the Traffic Light Program\n");

    printf("Enter 1 for Red light, 2 for Yellow light, and 3 for Green light.\n");
    
    printf("Enter 4 to Quit the program.\n\n");

    while(1) {

        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                red_led = 1;
                yellow_led = 0;
                green_led = 0;
                printf("\n\t----> Red light is ON <----\n\n");
                break;

            case 2:
                red_led = 0;
                yellow_led = 1;
                green_led = 0;
                printf("\n\t----> Yellow light is ON <----\n\n");
                break;

            case 3:
                red_led = 0;
                yellow_led = 0;
                green_led = 1;
                printf("\n\t----> Green light is ON <----\n\n");
                break;

            case 4:
                printf("\nShutting down the Traffic Light Controller Program.\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
                break;
        }

        printf("Red LED: %d | Yellow LED: %d | Green LED: %d\n", red_led, yellow_led, green_led);
    }

    return 0;
}
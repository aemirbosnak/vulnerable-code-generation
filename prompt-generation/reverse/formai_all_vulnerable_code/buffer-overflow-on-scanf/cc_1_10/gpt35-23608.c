//FormAI DATASET v1.0 Category: Smart home automation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to turn on/off a light
void toggleLight(bool *lightStatus) {
    *lightStatus = !(*lightStatus);
    if (*lightStatus) {
        printf("Light turned on\n");
    } else {
        printf("Light turned off\n");
    }
}

int main() {
    // Initialize variables
    bool light1 = false, light2 = false, fan = false, ac = false;

    // Ask user for input to control lights, fan, and AC
    int option;
    while(true) {
        printf("\nEnter option:\n");
        printf("1. Turn on/off light 1\n");
        printf("2. Turn on/off light 2\n");
        printf("3. Turn on/off fan\n");
        printf("4. Turn on/off AC\n");
        printf("5. Exit\n");
        scanf("%d", &option);

        // Perform action based on user input
        switch(option) {
            case 1:
                toggleLight(&light1);
                break;
            case 2:
                toggleLight(&light2);
                break;
            case 3:
                fan = !fan;
                if (fan) {
                    printf("Fan turned on\n");
                } else {
                    printf("Fan turned off\n");
                }
                break;
            case 4:
                ac = !ac;
                if (ac) {
                    printf("AC turned on\n");
                } else {
                    printf("AC turned off\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}
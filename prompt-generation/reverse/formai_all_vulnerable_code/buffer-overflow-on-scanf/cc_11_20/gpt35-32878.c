//FormAI DATASET v1.0 Category: Smart home light control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define NUM_LIGHTS 10   // Maximum number of lights in the house

int main() {
    int num_lights, light_choices[NUM_LIGHTS], selected_light;
    char choice;

    printf("Enter the number of lights in the house (max 10): ");
    scanf("%d", &num_lights);

    if(num_lights > NUM_LIGHTS || num_lights < 1) {
        printf("Invalid number of lights\n");
        return 1;
    }

    printf("Enter the numbers of the lights:\n");
    for(int i = 0; i < num_lights; i++) {
        scanf("%d", &light_choices[i]);
    }

    printf("\nWelcome to smart home light control system\n");

    while(1) {
        printf("----------------------------------------------\n");
        printf("Select the light to control:\n");

        for(int i = 0; i < num_lights; i++) {
            printf("%d. Light %d\n", i+1, light_choices[i]);
        }
        
        scanf("%d", &selected_light);

        if(selected_light > num_lights || selected_light < 1) {
            printf("Invalid light choice, please try again.\n");
            continue;
        }

        printf("Selected Light: %d\n", light_choices[selected_light-1]);

        printf("Enter '1' to turn on the light, '0' to turn off the light: ");
        scanf("%s", &choice);

        if(choice == '1') {
            printf("Turning on Light %d\n", light_choices[selected_light-1]);
            // Code for turning on the light
        } else if(choice == '0') {
            printf("Turning off Light %d\n", light_choices[selected_light-1]);
            // Code for turning off the light
        } else {
            printf("Invalid option selected.\n");
            continue;
        }
        
        printf("Press any key to continue, or 'q' to quit: ");
        scanf("%s", &choice);

        if(choice == 'q') {
            printf("Exiting Smart Home Light Control System\n");
            break;
        }
    }

    return 0;
}
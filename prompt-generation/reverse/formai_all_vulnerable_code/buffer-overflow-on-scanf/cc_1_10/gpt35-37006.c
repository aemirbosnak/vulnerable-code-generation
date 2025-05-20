//FormAI DATASET v1.0 Category: Smart home light control ; Style: rigorous
/* Smart home light control example program in C */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIGHTS 50  // Maximum number of lights that can be controlled
#define MAX_NAME_LEN 20  // Maximum length of light name

// Light structure to store details of each light
struct Light {
    char name[MAX_NAME_LEN];
    int status;
};

// Function to turn on a light
void turnLightOn(struct Light* light) {
    light->status = 1;
    printf("%s turned ON\n", light->name);
}

// Function to turn off a light
void turnLightOff(struct Light* light) {
    light->status = 0;
    printf("%s turned OFF\n", light->name);
}

// Function to toggle a light's status
void toggleLightStatus(struct Light* light) {
    if (light->status == 0) {
        turnLightOn(light);
    } else {
        turnLightOff(light);
    }
}

int main() {
    struct Light lights[MAX_LIGHTS];  // Array to store lights

    int numLights;  // Number of lights user wants to control
    printf("How many lights do you want to control? (1-%d) ", MAX_LIGHTS);
    scanf("%d", &numLights);

    // Get details of each light from user
    for (int i = 0; i < numLights; i++) {
        printf("Enter name of light %d (max %d characters): ", i+1, MAX_NAME_LEN);
        scanf("%s", lights[i].name);
        lights[i].status = 0;
    }

    int choice;  // Variable to store user choice
    int selectedLightIndex;  // Variable to store index of light user wants to control

    while (1) {  // Infinite loop to display menu and perform actions
        printf("\nSelect an action:\n");
        printf("1. View current status of lights\n");
        printf("2. Turn ON a light\n");
        printf("3. Turn OFF a light\n");
        printf("4. Toggle the status of a light\n");
        printf("5. Exit the program\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // View current status of lights
                printf("\nCurrent status of lights:\n");
                for (int i = 0; i < numLights; i++) {
                    printf("%d. %s: %s\n", i+1, lights[i].name, lights[i].status ? "ON" : "OFF");
                }
                break;
            case 2:  // Turn ON a light
            case 3:  // Turn OFF a light
            case 4:  // Toggle the status of a light
                printf("\nSelect a light to control:\n");
                for (int i = 0; i < numLights; i++) {
                    printf("%d. %s\n", i+1, lights[i].name);
                }
                printf("Enter your choice (1-%d): ", numLights);
                scanf("%d", &selectedLightIndex);

                if (selectedLightIndex > 0 && selectedLightIndex <= numLights) {
                    struct Light* selectedLight = &lights[selectedLightIndex-1];  // Get pointer to selected light

                    if (choice == 2) {  // Turn ON the light
                        turnLightOn(selectedLight);
                    } else if (choice == 3) {  // Turn OFF the light
                        turnLightOff(selectedLight);
                    } else {  // Toggle the status of the light
                        toggleLightStatus(selectedLight);
                    }
                } else {
                    printf("Invalid choice. Please try again.\n");
                }
                break;
            case 5:  // Exit the program
                exit(0);
            default:  // Invalid choice
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
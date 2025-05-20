//FormAI DATASET v1.0 Category: Smart home light control ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for light status
#define OFF 0
#define ON 1

// Define a struct to represent a light bulb
typedef struct {
    char name[20];
    int status;
} LightBulb;

int main() {
    // Create an array of LightBulb structs to represent all the light bulbs in the house
    LightBulb bulbs[3] = { {"Living Room", OFF}, {"Bedroom", OFF}, {"Kitchen", OFF} };
    
    // Print the current status of all light bulbs
    printf("Current light status:\n");
    for(int i=0; i<3; i++) {
        printf("%s: %s\n", bulbs[i].name, bulbs[i].status == ON ? "ON" : "OFF");
    }
    
    // Prompt user to enter which light bulb to control
    printf("\nEnter the name of the light bulb you want to control: ");
    char input[20];
    scanf("%s", input);
    
    // Find the index of the light bulb with the matching name
    int index = -1;
    for(int i=0; i<3; i++) {
        if(strcmp(input, bulbs[i].name) == 0) {
            index = i;
            break;
        }
    }
    
    // If no matching light bulb was found, print an error message and exit
    if(index == -1) {
        printf("Error: Light bulb not found.\n");
        exit(1);
    }
    
    // Prompt user to enter the desired action
    printf("Enter the action you want to perform (ON/OFF): ");
    scanf("%s", input);
    
    // Update the status of the selected light bulb
    if(strcmp(input, "ON") == 0) {
        bulbs[index].status = ON;
    } else if(strcmp(input, "OFF") == 0) {
        bulbs[index].status = OFF;
    } else {
        printf("Error: Invalid action.\n");
        exit(1);
    }
    
    // Print the updated status of the selected light bulb
    printf("%s is now %s.\n", bulbs[index].name, bulbs[index].status == ON ? "ON" : "OFF");
    
    return 0;
}
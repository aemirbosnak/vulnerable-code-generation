//FormAI DATASET v1.0 Category: Smart home light control ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Structure to represent each light in the smart home.
struct Light {
    char name[20];
    bool isOn;
};

//Function to print the status of all the lights in the smart home
void printLightsStatus(struct Light lights[], int num_lights) {
    printf("Current status of all lights:\n");

    for(int i=0; i<num_lights; i++) {
        printf("%s - %s\n", lights[i].name, lights[i].isOn ? "ON" : "OFF");
    }
}

int main() {
    struct Light lights[5]; //Maximum of 5 lights in the smart home

    //Setting initial status of all lights to OFF
    for(int i=0; i<5; i++) {
        lights[i].isOn = false;
    }

    //Prompting user to enter the name of each light
    printf("Please enter the name of each light:\n");
    for(int i=0; i<5; i++) {
        printf("Light %d: ", i+1);
        scanf("%s", lights[i].name); //Reading input and storing in the name attribute of the appropriate light
    }

    //Printing current status of all the lights
    printLightsStatus(lights, 5);

    //Shifting shape of light 3 from OFF to ON
    lights[2].isOn = true;

    //Printing current status of all the lights after the shape shift
    printLightsStatus(lights, 5);

    //Shifting shape of light 1 from OFF to ON
    lights[0].isOn = true;

    //Printing current status of all the lights after the second shape shift
    printLightsStatus(lights, 5);

    //Shifting shape of light 5 from ON to OFF
    lights[4].isOn = false;

    //Printing current status of all the lights after the third shape shift
    printLightsStatus(lights, 5);

    return 0; //Returning 0 indicates successful execution of program
}
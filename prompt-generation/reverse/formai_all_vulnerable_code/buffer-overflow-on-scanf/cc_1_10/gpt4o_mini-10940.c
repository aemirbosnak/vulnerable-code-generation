//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int isOn;
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int lightCount = 0;

void turnOnLight(int index) {
    lights[index].isOn = 1;
    printf("%s is now ON.\n", lights[index].name);
}

void turnOffLight(int index) {
    lights[index].isOn = 0;
    printf("%s is now OFF.\n", lights[index].name);
}

void displayLights() {
    if (lightCount == 0) {
        printf("No lights in the system.\n");
        return;
    }
    
    printf("Current Lights Status:\n");
    for (int i = 0; i < lightCount; i++) {
        printf("%d: %s - %s\n", i + 1, lights[i].name, lights[i].isOn ? "ON" : "OFF");
    }
}

void addLight() {
    if (lightCount >= MAX_LIGHTS) {
        printf("Cannot add more lights. Maximum limit reached.\n");
        return;
    }
    
    char name[NAME_LENGTH];
    printf("Enter light name: ");
    scanf("%s", name);
    strcpy(lights[lightCount].name, name);
    lights[lightCount].isOn = 0; // Initially off
    lightCount++;
    printf("Added light: %s\n", name);
}

void removeLight() {
    int index;
    displayLights();
    printf("Enter light number to remove: ");
    scanf("%d", &index);

    if (index < 1 || index > lightCount) {
        printf("Invalid light number.\n");
        return;
    }
    
    index--; // Adjust for zero-based index
    printf("Removing light: %s\n", lights[index].name);
    // Shift lights down
    for (int i = index; i < lightCount - 1; i++) {
        lights[i] = lights[i + 1];
    }
    
    lightCount--;
}

void controlLight() {
    int index;
    displayLights();
    printf("Enter light number to control (turn ON/OFF): ");
    scanf("%d", &index);
    
    if (index < 1 || index > lightCount) {
        printf("Invalid light number.\n");
        return;
    }
            
    index--; // Adjust for zero-based index
    if (lights[index].isOn) {
        turnOffLight(index);
    } else {
        turnOnLight(index);
    }
}

int main() {
    int choice;

    do {
        printf("\nSmart Home Light Control System\n");
        printf("1. Add Light\n");
        printf("2. Remove Light\n");
        printf("3. Control Light\n");
        printf("4. Display Lights\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addLight();
                break;
            case 2:
                removeLight();
                break;
            case 3:
                controlLight();
                break;
            case 4:
                displayLights();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
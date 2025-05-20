//FormAI DATASET v1.0 Category: Smart home light control ; Style: all-encompassing
#include <stdio.h>

// function to turn on lights
void turnOnLights() {
    printf("Lights turned ON.\n");
}

// function to turn off lights
void turnOffLights() {
    printf("Lights turned OFF.\n");
}

// function to dim the lights
void dimLights(int dimValue) {
    printf("Lights dimmed to %d%%.\n", dimValue);
}

int main() {
    int choice, dimValue;
    
    printf("Welcome to Smart Home Light Control!\n");
    printf("Select one of the following options:\n");
    printf("1. Turn lights ON\n");
    printf("2. Turn lights OFF\n");
    printf("3. Dim lights\n");
    printf("Enter your choice: ");
    
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            turnOnLights();
            break;
        case 2:
            turnOffLights();
            break;
        case 3:
            printf("Enter the dim value (0-100): ");
            scanf("%d", &dimValue);
            if(dimValue < 0 || dimValue > 100) {
                printf("Invalid dim value.\n");
            }
            else {
                dimLights(dimValue);
            }
            break;
        default:
            printf("Invalid choice.\n");
    }
    
    return 0;
}
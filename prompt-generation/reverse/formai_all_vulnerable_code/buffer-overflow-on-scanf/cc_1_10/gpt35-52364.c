//FormAI DATASET v1.0 Category: Smart home automation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int temperature = 20; // starting temperature
char lights = '0'; // starting light status

int main() {
    printf("Welcome to Smart Home Automation!\n\n");
    
    while (1) { // infinite loop
      
        printf("Current temperature: %d°C\n", temperature);
        printf("Lights are currently turned %s\n\n", (lights == '0') ? "off" : "on");
      
        printf("What would you like to do?\n");
        printf("1. Increase temperature\n");
        printf("2. Decrease temperature\n");
        printf("3. Turn lights on/off\n");
        printf("4. Exit program\n\n");
      
        int choice;
        scanf("%d", &choice);
        printf("\n");
      
        switch (choice) {
            case 1:
                temperature++;
                printf("Temperature increased to %d°C\n", temperature);
                break;
            case 2:
                temperature--;
                printf("Temperature decreased to %d°C\n", temperature);
                break;
            case 3:
                if (lights == '0') {
                    lights = '1';
                    printf("Lights turned on\n");
                } else {
                    lights = '0';
                    printf("Lights turned off\n");
                }
                break;
            case 4:
                printf("Thank you for using Smart Home Automation!");
                exit(0); // exit program
            default:
                printf("Invalid choice, please try again.\n\n");
        }
        
        printf("\n");
    }
    
    return 0;
}
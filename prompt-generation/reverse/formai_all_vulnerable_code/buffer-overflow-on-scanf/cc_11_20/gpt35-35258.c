//FormAI DATASET v1.0 Category: Smart home automation ; Style: happy
#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Initialize the default values for the home appliances
    bool isLightOn = false;
    bool isACOn = false;
    bool isTVOn = false;
    int temp = 25;
    
    printf("Welcome to Happy Home Automation Program!\n\n");
    
    while (true)
    {
        // Display the current status of home appliances
        printf("Current Status:\n");
        printf("Light: %s\n", isLightOn ? "ON" : "OFF");
        printf("Air Conditioner: %s\n", isACOn ? "ON" : "OFF");
        printf("Television: %s\n", isTVOn ? "ON" : "OFF");
        printf("Room Temperature: %d°C\n\n", temp);
        
        // Ask user to enter their preferred action
        printf("What would you like to do?\n");
        printf("1. Turn Light ON/OFF\n");
        printf("2. Turn Air Conditioner ON/OFF\n");
        printf("3. Turn Television ON/OFF\n");
        printf("4. Increase Room Temperature\n");
        printf("5. Decrease Room Temperature\n");
        printf("6. Exit\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1: // Turn Light ON/OFF
                isLightOn = !isLightOn;
                printf("Light is now %s!\n\n", isLightOn ? "ON" : "OFF");
                break;
                
            case 2: // Turn Air Conditioner ON/OFF
                isACOn = !isACOn;
                printf("Air Conditioner is now %s!\n\n", isACOn ? "ON" : "OFF");
                break;
                
            case 3: // Turn Television ON/OFF
                isTVOn = !isTVOn;
                printf("Television is now %s!\n\n", isTVOn ? "ON" : "OFF");
                break;
                
            case 4: // Increase Room Temperature
                temp++;
                printf("Room Temperature increased to %d°C!\n\n", temp);
                break;
                
            case 5: // Decrease Room Temperature
                temp--;
                printf("Room Temperature decreased to %d°C!\n\n", temp);
                break;
                
            case 6: // Exit
                printf("Thank you for using Happy Home Automation Program!\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n\n");
                break;
        }
    }
}
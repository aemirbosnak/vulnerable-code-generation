//FormAI DATASET v1.0 Category: Smart home light control ; Style: surrealist
#include <stdlib.h>
#include <time.h>

int main()
{
    // initialize random number generator
    srand(time(NULL));
    
    int brightness = rand() % 100;
    int temperature = rand() % 100;
    
    printf("Welcome to the Surrealist Smart Home Light Control Program!\n");
    printf("Your light's current brightness is %d percent.\n", brightness);
    printf("Your light's current temperature is %d degrees Kelvin.\n", temperature);
    
    printf("What would you like to do?\n");
    printf("1. Increase brightness\n");
    printf("2. Decrease brightness\n");
    printf("3. Increase temperature\n");
    printf("4. Decrease temperature\n");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            brightness += 10;
            printf("Brightness increased by 10 percent.\n");
            break;
        case 2:
            brightness -= 10;
            printf("Brightness decreased by 10 percent.\n");
            break;
        case 3:
            temperature += 10;
            printf("Temperature increased by 10 degrees Kelvin.\n");
            break;
        case 4:
            temperature -= 10;
            printf("Temperature decreased by 10 degrees Kelvin.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    
    printf("Your light's updated brightness is %d percent.\n", brightness);
    printf("Your light's updated temperature is %d degrees Kelvin.\n", temperature);
    
    return 0;
}
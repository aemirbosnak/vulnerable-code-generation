//FormAI DATASET v1.0 Category: Smart home light control ; Style: protected
#include <stdio.h>
#include <stdbool.h>

/*Function to turn on the lights*/
void turnOnLights(bool *lights, int numberOfLights)
{
    for(int i=0; i<numberOfLights; i++)
    {
        *(lights+i) = true;
    }
}

/*Function to turn off the lights*/
void turnOffLights(bool *lights, int numberOfLights)
{
    for(int i=0; i<numberOfLights; i++)
    {
        *(lights+i) = false;
    }
}

/*Function to toggle the lights*/
void toggleLights(bool *lights, int numberOfLights)
{
    for(int i=0; i<numberOfLights; i++)
    {
        *(lights+i) = !*(lights+i);
    }
}

int main()
{
    int numberOfLights = 5;
    bool lights[numberOfLights];
    
    //Initializing all the lights as turned off
    for(int i=0; i<numberOfLights; i++)
    {
        lights[i] = false;
    }
    
    int choice;
    
    //Menu for the user to select the action
    printf("Welcome to Smart Home light control system!\n");
    do{
        printf("1. Turn on lights\n");
        printf("2. Turn off lights\n");
        printf("3. Toggle lights\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: //case to turn on the lights
                turnOnLights(lights, numberOfLights);
                printf("All the lights are turned on!\n");
                break;
            
            case 2: //case to turn off the lights
                turnOffLights(lights, numberOfLights);
                printf("All the lights are turned off!\n");
                break;
            
            case 3: //case to toggle the lights
                toggleLights(lights, numberOfLights);
                printf("All the lights are toggled!\n");
                break;
            
            case 4: //case to exit the program
                printf("Thank you for using the Smart Home light control system!\n");
                break;
                
            default:
                printf("Invalid choice, please select again.\n");
        }
    
    }while(choice!=4);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Smart home light control ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int choice,bedroom, livingroom,kitchen, exit = 0;
    char operation[5];

    //Initially, all the lights are off
    bedroom = 0;
    livingroom = 0;
    kitchen = 0;

    while(!exit)
    {
        printf("\nEnter your choice:\n1. Turn on/off bedroom light\n2. Turn on/off living room light\n3. Turn on/off kitchen light\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {  
            // For bedroom light
            case 1:
                printf("Enter the operation (on/off) : ");
                scanf("%s",operation);
                if(strcmp(operation,"on") == 0)
                    bedroom = 1;
                else if(strcmp(operation,"off") == 0)
                    bedroom = 0;
                else
                    printf("Invalid operation!\n");
                printf("Bedroom light is %s\n", (bedroom) ? "on" : "off");
                break;
            
            // For living room light
            case 2:
                printf("Enter the operation (on/off) : ");
                scanf("%s",operation);
                if(strcmp(operation,"on") == 0)
                    livingroom = 1;
                else if(strcmp(operation,"off") == 0)
                    livingroom = 0;
                else
                    printf("Invalid operation!\n");
                printf("Living room light is %s\n", (livingroom) ? "on" : "off");
                break;
            
            // For kitchen light
            case 3:
                printf("Enter the operation (on/off) : ");
                scanf("%s",operation);
                if(strcmp(operation,"on") == 0)
                    kitchen = 1;
                else if(strcmp(operation,"off") == 0)
                    kitchen = 0;
                else
                    printf("Invalid operation!\n");
                printf("Kitchen light is %s\n", (kitchen) ? "on" : "off");
                break;
            
            //For exiting the program
            case 4:
                printf("Exiting the application\n");
                exit = 1;
                break;
            
            // If invalid choice is entered
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }

    return 0;
}
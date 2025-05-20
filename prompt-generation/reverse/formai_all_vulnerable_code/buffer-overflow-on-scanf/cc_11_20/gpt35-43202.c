//FormAI DATASET v1.0 Category: Smart home light control ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>

#define MAX_ROOMS 5 //maximum number of rooms in the house
#define MAX_LIGHTS 10 //maximum number of light switches per room

int main()
{
    //initialize 2D array to store the state of the lights in each room
    bool lightState[MAX_ROOMS][MAX_LIGHTS] = {false};

    //initialize variables to store user input
    int roomNumber, lightNumber;
    char userOption;

    while(true)
    {
        //display menu options
        printf("\nWelcome to Smart Home Light Control\n");
        printf("1. Turn on a light\n");
        printf("2. Turn off a light\n");
        printf("3. Display all lights in a room\n");
        printf("4. Exit\n");

        //prompt user for their option
        printf("Enter your option: ");
        scanf(" %c", &userOption);

        switch(userOption)
        {
            case '1':
                //prompt user for room and light switch number
                printf("Enter room number (1-%d): ", MAX_ROOMS);
                scanf("%d", &roomNumber);
                printf("Enter light switch number (1-%d): ", MAX_LIGHTS);
                scanf("%d", &lightNumber);

                //check for valid input
                if(roomNumber < 1 || roomNumber > MAX_ROOMS || lightNumber < 1 || lightNumber > MAX_LIGHTS)
                {
                    printf("Error: Invalid room or light switch number\n");
                    break;
                }

                //turn on the selected light switch
                lightState[roomNumber-1][lightNumber-1] = true;
                printf("Light in Room %d, Switch %d has been turned on\n", roomNumber, lightNumber);
                break;

            case '2':
                //prompt user for room and light switch number
                printf("Enter room number (1-%d): ", MAX_ROOMS);
                scanf("%d", &roomNumber);
                printf("Enter light switch number (1-%d): ", MAX_LIGHTS);
                scanf("%d", &lightNumber);

                //check for valid input
                if(roomNumber < 1 || roomNumber > MAX_ROOMS || lightNumber < 1 || lightNumber > MAX_LIGHTS)
                {
                    printf("Error: Invalid room or light switch number\n");
                    break;
                }

                //turn off the selected light switch
                lightState[roomNumber-1][lightNumber-1] = false;
                printf("Light in Room %d, Switch %d has been turned off\n", roomNumber, lightNumber);
                break;

            case '3':
                //prompt user for room number
                printf("Enter room number (1-%d): ", MAX_ROOMS);
                scanf("%d", &roomNumber);

                //check for valid input
                if(roomNumber < 1 || roomNumber > MAX_ROOMS)
                {
                    printf("Error: Invalid room number\n");
                    break;
                }

                //display the state of all light switches in the selected room
                printf("Lights in Room %d:\n", roomNumber);
                for(int i=0; i<MAX_LIGHTS; i++)
                {
                    printf("Switch %d: %s\n", i+1, lightState[roomNumber-1][i] ? "ON" : "OFF");
                }
                break;

            case '4':
                printf("Exiting Smart Home Light Control...\n");
                return 0;

            default:
                printf("Error: Invalid option\n");
                break;
        }
    }

    return 0;
}
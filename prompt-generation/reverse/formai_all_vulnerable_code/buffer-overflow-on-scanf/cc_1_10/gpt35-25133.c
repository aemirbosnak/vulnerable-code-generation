//FormAI DATASET v1.0 Category: Smart home automation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int players, i, j, timer = 30;
    float temp, humidity;
    srand(time(NULL));

    printf("Welcome to Smart Home Automation: Multiplayer Edition!\n");
    printf("Enter the number of players: ");
    scanf("%d", &players);
    printf("Ready...Set...Go!\n");

    //Gameplay loop
    while (timer > 0)
    {
        //Generate random temperature and humidity values
        temp = (rand() % 100) - 40; //Temperature range: -40 to 60 Celsius
        humidity = (rand() % 100); //Humidity range: 0 to 100 percent

        printf("Current status:\n");
        printf("Temperature: %.1f C\n", temp);
        printf("Humidity: %.1f %%\n", humidity);

        //Players make their decisions
        for (i = 1; i <= players; i++)
        {
            printf("\nPlayer %d, it's your turn:\n", i);

            //Choose an action
            printf("Choose an action:\n");
            printf("1. Turn on/off heater\n");
            printf("2. Turn on/off air conditioner\n");
            printf("3. Set thermostat temperature\n");
            printf("4. Set humidity level\n");

            scanf("%d", &j);

            //Execute the action
            switch (j)
            {
                case 1:
                    printf("Heater turned on/off.\n");
                    break;

                case 2:
                    printf("Air conditioner turned on/off.\n");
                    break;

                case 3:
                    printf("Enter the desired temperature: ");
                    scanf("%f", &temp);
                    printf("Thermostat temperature set to %.1f C.\n", temp);
                    break;

                case 4:
                    printf("Enter the desired humidity level: ");
                    scanf("%f", &humidity);
                    printf("Humidity level set to %.1f %%.\n", humidity);
                    break;

                default:
                    printf("Invalid action.\n");
            }
        }

        timer--;
    }

    printf("Game over!\n");

    return 0;
}
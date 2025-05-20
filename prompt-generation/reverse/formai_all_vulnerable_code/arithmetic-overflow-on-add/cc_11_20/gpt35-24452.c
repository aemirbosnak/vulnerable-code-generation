//FormAI DATASET v1.0 Category: Temperature monitor ; Style: artistic
/*The following program is a unique C Temperature Monitor example program that monitors the temperature, tracks historical data, and alerts the user when the temperature exceeds a certain range.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int current_temperature = 0, max_temperature = 0, min_temperature = 0;
    int historical_temperatures[100], num_of_temperatures = 0;
    int is_alert = 0;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("Welcome to the Temperature Monitor Program!\n\n");
    printf("Today is %d/%d/%d.\n\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    while(1)
    {
        printf("Enter the current temperature: ");
        scanf("%d", &current_temperature);

        if(current_temperature > max_temperature)
        {
            max_temperature = current_temperature;
        }

        if(current_temperature < min_temperature || min_temperature == 0)
        {
            min_temperature = current_temperature;
        }

        historical_temperatures[num_of_temperatures] = current_temperature;
        num_of_temperatures++;

        if(num_of_temperatures > 1)
        {
            printf("\n=== Historical Temperature Data ===\n");
            for(int i = 0; i < num_of_temperatures; i++)
            {
                printf("%d. %d degrees\n", i + 1, historical_temperatures[i]);
            }
            printf("\n");
        }

        if(current_temperature > 30)
        {
            printf("ALERT: Temperature too high! Current temperature is %d degrees.\n", current_temperature);
            is_alert = 1;
        }
        else if(current_temperature < 10)
        {
            printf("ALERT: Temperature too low! Current temperature is %d degrees.\n", current_temperature);
            is_alert = 1;
        }
        else
        {
            is_alert = 0;
        }

        if(is_alert)
        {
            printf("Sending alert message to Administrator...\n\n");
        }

        char choice[10];
        printf("Do you want to continue? (Y/N)");
        fflush(stdin);
        gets(choice);

        if(strcmp(choice, "N") == 0 || strcmp(choice, "n") == 0)
        {
            printf("\n=== Report Summary ===\n");
            printf("Minimum Temperature: %d degrees\n", min_temperature);
            printf("Maximum Temperature: %d degrees\n", max_temperature);
            printf("Number of Temperatures Recorded: %d", num_of_temperatures);
            break;
        }
    }

    return 0;
}
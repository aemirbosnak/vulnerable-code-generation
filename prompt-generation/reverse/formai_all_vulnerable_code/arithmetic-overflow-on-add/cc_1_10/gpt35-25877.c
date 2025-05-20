//FormAI DATASET v1.0 Category: Smart home automation ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function prototypes
void power_off(int);
void lights(char);
void security(int);
void temperature(int);
void water(char);

int main()
{
    int power = 1;
    char light_status = 'O';
    int security_status = 0;
    int temperature_status = 24; // celsius
    char water_status = 'O';

    srand(time(NULL));

    printf("Welcome to the Smart Home Automation System!\n");

    while(power)
    {
        printf("\n1. Turn off power\n");
        printf("2. Toggle lights\n");
        printf("3. Toggle security\n");
        printf("4. Change temperature\n");
        printf("5. Toggle water\n");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: // Turn off power
                power_off(power);
                break;

            case 2: // Toggle lights
                if(light_status == 'O')
                {
                    lights('F');
                    light_status = 'F';
                }
                else
                {
                    lights('O');
                    light_status = 'O';
                }
                break;

            case 3: // Toggle security
                if(security_status == 0)
                {
                    security(1);
                    security_status = 1;
                }
                else
                {
                    security(0);
                    security_status = 0;
                }
                break;

            case 4: // Change temperature
                printf("\nEnter new temperature: ");
                scanf("%d", &temperature_status);
                temperature(temperature_status);
                break;

            case 5: // Toggle water
                if(water_status == 'O')
                {
                    water('F');
                    water_status = 'F';
                }
                else
                {
                    water('O');
                    water_status = 'O';
                }
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }

        // Trigger random events
        int event = rand() % 5;
        switch(event)
        {
            case 1:
                printf("\n--------- BLACKOUT! All power is out! ---------\n");
                power_off(power);
                break;

            case 2:
                printf("\n--------- BURGLAR ALERT! Security system triggered! ---------\n");
                security(1);
                security_status = 1;
                break;

            case 3:
                printf("\n--------- HEAT WAVE! Temperature rising dangerously! ---------\n");
                temperature_status += 10;
                temperature(temperature_status);
                break;

            case 4:
                printf("\n--------- DROUGHT! Water supply has been cut off! ---------\n");
                water('F');
                water_status = 'F';
                break;
        }
    }

    return 0;
}

void power_off(int power)
{
    if(power == 1)
    {
        printf("\n--------- Powering off! Goodbye. ---------\n");
        power = 0;
    }
}

void lights(char status)
{
    if(status == 'O')
    {
        printf("\nTurning off lights...\n");
    }
    else if(status == 'F')
    {
        printf("\nTurning on lights...\n");
    }
}

void security(int status)
{
    if(status == 0)
    {
        printf("\nSecurity system deactivated.\n");
    }
    else if(status == 1)
    {
        printf("\nSecurity system activated.\n");
    }
}

void temperature(int status)
{
    printf("\nNew temperature is %d degrees Celsius.\n", status);
}

void water(char status)
{
    if(status == 'O')
    {
        printf("\nWater supply turned on.\n");
    }
    else if(status == 'F')
    {
        printf("\nWater supply turned off.\n");
    }
}
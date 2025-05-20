//FormAI DATASET v1.0 Category: Temperature monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Function Declarations */
void print_menu(void);
void print_current_status(bool, float);
float get_current_temperature(void);

/* Main Function */
int main()
{
    bool power = false;         // initial status of power
    float temperature = 0.0;    // initial temperature value
    
    printf("Welcome to Temperature Monitor!\n\n");

    while(true)
    {
        print_menu();

        int choice;
        scanf("%d", &choice);
        printf("\n");
        
        switch(choice)
        {
            case 1:     // Power ON
            {
                if(!power)
                {
                    printf("[+] Turning the temperature monitor ON...\n");
                    power = true;
                    printf("Temperature monitor is ON!\n\n");
                }
                else
                {
                    printf("[!] Temperature monitor is already ON!\n\n");
                }
                break;
            }
            
            case 2:     // Power OFF
            {
                if(power)
                {
                    printf("[+] Turning the temperature monitor OFF...\n");
                    power = false;
                    printf("Temperature monitor is OFF!\n\n");
                }
                else
                {
                    printf("[!] Temperature monitor is already OFF!\n\n");
                }
                break;
            }
            
            case 3:     // Get Current Temperature
            {
                if(power)
                {
                    temperature = get_current_temperature();
                    print_current_status(power, temperature);
                }
                else
                {
                    printf("[!] Temperature monitor is OFF! Cannot get current temperature.\n\n");
                }
                break;
            }

            case 4:     // Exit
            {
                printf("\nThank you for using Temperature Monitor!\n");
                exit(0);
            }
            
            default:    // Invalid Choice
            {
                printf("[!] Invalid Choice! Please choose again.\n\n");
                break;
            }
        }
    }

    return 0;
}

/* Function Definitions */

void print_menu(void)
{
    printf("Choose an option:\n");
    printf("1. Turn Power ON\n");
    printf("2. Turn Power OFF\n");
    printf("3. Get Current Temperature\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void print_current_status(bool power, float temperature)
{
    if(power)
    {
        printf("[+] Temperature monitor is ON!\n");
        printf("[+] Current Temperature: %.2f degrees Celsius\n\n", temperature);
    }
    else
    {
        printf("[!] Temperature monitor is OFF!\n");
    }
}

float get_current_temperature(void)
{
    // Code to get current temperature from sensor
    float temp = 25.6;  // Dummy value for demo purposes
    return temp;
}
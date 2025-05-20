//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Sherlock Holmes
//Include required libraries
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

//Function declaration
void display_menu();
void get_temperature();
void display_history();
void exit_program();

//Global variables
float temperature = 0;
int temp_count = 0;
float temp_history[50];

int main()
{
    int choice;
    
    do
    {
        display_menu();
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                get_temperature();
                break;
            case 2:
                display_history();
                break;
            case 3:
                exit_program();
                break;
            default:
                printf("\nInvalid Choice! Please try again.\n");
        }
    } while(choice != 3);
    
    printf("\nThank you for using our Temperature Monitoring System.\n");
    
    return 0;
}

void display_menu()
{
    printf("\n\tTemperature Monitoring System\n");
    printf("----------------------------------------------\n");
    printf("1. Enter Temperature\n");
    printf("2. Display Temperature History\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void get_temperature()
{
    printf("\nEnter Current Temperature in Celsius: ");
    scanf("%f", &temperature);
    
    if(temperature > 0 && temperature <= 100)
    {
        temp_history[temp_count] = temperature;
        temp_count++;
        printf("\nTemperature (%.2f C) recorded Successfully.\n", temperature);
    }
    else
    {
        printf("\nInvalid Temperature! Temperature should be between 0 and 100 Celsius.\n");
    }
}

void display_history()
{
    if(temp_count == 0)
    {
        printf("\nNo Temperature Record Found.\n");
        return;
    }
    
    printf("\nTemperature History\n");
    printf("----------------------------------------------\n");
    for(int i=0; i<temp_count; i++)
    {
        printf("%d. %.2f C\n", i+1, temp_history[i]);
    }
}

void exit_program()
{
    printf("\nDo you really want to Exit? (Y/N): ");
    char confirm;
    scanf(" %c", &confirm);
    if(tolower(confirm) == 'y')
    {
        printf("\nSaving Temperature Record in File...\n");
        //Code to save temperature record in file
    }
    else
    {
        printf("\nExiting Cancelled.\n");
    }
}
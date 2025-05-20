//FormAI DATASET v1.0 Category: Smart home automation ; Style: excited
#include <stdio.h>
#include <stdbool.h> //header file to use 'bool' datatype

//function to toggle a light switch
void toggle_switch(bool* switch_state)
{
    *switch_state = !(*switch_state);
    if(*switch_state)
        printf("The light switch has been turned ON!\n");
    else
        printf("The light switch has been turned OFF!\n");
}

//function to control temperature
void control_temperature(int* temp, int target_temp)
{
    if(*temp > target_temp)
    {
        *temp -= 1;
        printf("The temperature has been reduced to %d\n", *temp);
    }
    else if(*temp < target_temp)
    {
        *temp += 1;
        printf("The temperature has been increased to %d\n", *temp);
    }
    else
        printf("The temperature is already at the target temperature of %d\n", target_temp);
}

int main()
{
    bool light_switch = false;
    int temperature = 25;

    printf("Welcome to the Smart Home Automation system!\n");

    while(true)
    {
        int choice = 0;
        printf("\nWhat would you like to do?\n");
        printf("1. Toggle Light Switch\n");
        printf("2. Control Temperature\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                toggle_switch(&light_switch);
                break;
            
            case 2:
                printf("Enter the target temperature: ");
                int target_temp;
                scanf("%d", &target_temp);
                control_temperature(&temperature, target_temp);
                break;

            case 3:
                printf("Exiting the Smart Home Automation system. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}
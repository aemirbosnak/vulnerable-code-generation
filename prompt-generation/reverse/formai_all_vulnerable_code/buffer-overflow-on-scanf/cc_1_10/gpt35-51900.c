//FormAI DATASET v1.0 Category: Temperature monitor ; Style: introspective
#include<stdio.h>

int current_temp = 0;
int previous_temp = 0;

void display_temperature(int temperature)
{
    printf("The current temperature is %d\n", temperature);
}

void compare_temperature(int current_temp, int previous_temp)
{
    if(current_temp > previous_temp)
    {
        printf("The temperature is increasing\n");
    }
    else if(current_temp < previous_temp)
    {
        printf("The temperature is decreasing\n");
    }
    else
    {
        printf("The temperature is constant\n");
    }
}

int main()
{
    printf("Welcome to the Temperature Monitor\n");
    printf("Please enter the current temperature: ");
    scanf("%d", &current_temp);
    display_temperature(current_temp);
    
    while(1)
    {
        previous_temp = current_temp;
        printf("Please enter the current temperature: ");
        scanf("%d", &current_temp);
        display_temperature(current_temp);
        compare_temperature(current_temp, previous_temp);
        if(current_temp >= 100)
        {
            printf("Warning! The temperature is too high\n");
        }
        if(current_temp <= 0)
        {
            printf("Warning! The temperature is too low\n");
        }
    }
    return 0;
}
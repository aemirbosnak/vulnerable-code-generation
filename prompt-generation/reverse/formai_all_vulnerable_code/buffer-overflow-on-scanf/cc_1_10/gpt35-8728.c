//FormAI DATASET v1.0 Category: Smart home automation ; Style: creative
#include<stdio.h> 
#include<stdlib.h> 

int main() 
{
    //creating variables for home appliances
    int light = 0, ac = 0, tv = 0, fan = 0;
    int choice, on_off;

    //menu for selecting appliances
    printf("Welcome to Smart Home Automation\n");
    printf("\nSelect an appliance: \n");
    printf("\n1. Light\n2. Air Conditioner\n3. TV\n4. Fan\n");

    //asking user for input
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    //switch statement to select appliance
    switch(choice)
    {
        case 1:
            printf("You have selected Light\n");
            printf("Turn on/off the light (1/0): ");
            scanf("%d", &on_off);
            light = on_off;
            break;

        case 2:
            printf("You have selected Air Conditioner\n");
            printf("Turn on/off the AC (1/0): ");
            scanf("%d", &on_off);
            ac = on_off;
            break;

        case 3:
            printf("You have selected TV\n");
            printf("Turn on/off the TV (1/0): ");
            scanf("%d", &on_off);
            tv = on_off;
            break;

        case 4:
            printf("You have selected Fan\n");
            printf("Turn on/off the fan (1/0): ");
            scanf("%d", &on_off);
            fan = on_off;
            break;

        default:
            printf("Invalid choice, please select again\n");
            break;
    }

    //displaying status of appliances
    printf("\nLight status: ");
    if(light == 1)
    {
        printf("ON\n");
    }
    else
    {
        printf("OFF\n");
    }

    printf("Air Conditioner status: ");
    if(ac == 1)
    {
        printf("ON\n");
    }
    else
    {
        printf("OFF\n");
    }

    printf("TV status: ");
    if(tv == 1)
    {
        printf("ON\n");
    }
    else
    {
        printf("OFF\n");
    }

    printf("Fan status: ");
    if(fan == 1)
    {
        printf("ON\n");
    }
    else
    {
        printf("OFF\n");
    }

    return 0;
}
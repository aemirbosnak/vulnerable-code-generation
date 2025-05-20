//FormAI DATASET v1.0 Category: Smart home automation ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int light = 0, fan = 0, ac = 0;
    char choice;

    printf("Welcome to Smart Home Automation System!\n");
    printf("---------------------------------------\n");
    printf("Current Status\n");
    printf("-------------\n");
    printf("Light is currently off.\n");
    printf("Fan is currently off.\n");
    printf("AC is currently off.\n");

    while(1)
    {
        printf("\nEnter your choice:\n");
        printf("------------------\n");
        printf("L/l - Turn ON/OFF the Light\n");
        printf("F/f - Turn ON/OFF the Fan\n");
        printf("A/a - Turn ON/OFF the AC\n");
        printf("X/x - Exit the program\n");

        scanf(" %c", &choice);

        if(choice == 'L' || choice == 'l')
        {
            if(light == 0)
            {
                light = 1;
                printf("Light is now on.\n");
            }
            else
            {
                light = 0;
                printf("Light is now off.\n");
            }
        }
        else if(choice == 'F' || choice == 'f')
        {
            if(fan == 0)
            {
                fan = 1;
                printf("Fan is now on.\n");
            }
            else
            {
                fan = 0;
                printf("Fan is now off.\n");
            }
        }
        else if(choice == 'A' || choice == 'a')
        {
            if(ac == 0)
            {
                ac = 1;
                printf("AC is now on.\n");
            }
            else
            {
                ac = 0;
                printf("AC is now off.\n");
            }
        }
        else if(choice == 'X' || choice == 'x')
        {
            printf("Exiting the program...Thank you for using Smart Home Automation System!\n");
            break;
        }
        else
        {
            printf("Invalid choice! Please enter again.\n");
        }

        printf("Current Status\n");
        printf("-------------\n");
        if(light == 1)
        {
            printf("Light is currently on.\n");
        }
        else
        {
            printf("Light is currently off.\n");
        }

        if(fan == 1)
        {
            printf("Fan is currently on.\n");
        }
        else
        {
            printf("Fan is currently off.\n");
        }

        if(ac == 1)
        {
            printf("AC is currently on.\n");
        }
        else
        {
            printf("AC is currently off.\n");
        }
    }

    return 0;
}
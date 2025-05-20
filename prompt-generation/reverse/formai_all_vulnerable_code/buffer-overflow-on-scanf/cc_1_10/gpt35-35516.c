//FormAI DATASET v1.0 Category: Smart home automation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int temp = 0, light = 0, fan = 0;
    char input;

    printf("Welcome to the Smart Home Automation System!\n\n");

    while(1)
    {
        printf("***MENU***\n");
        printf("1. Set temperature\n");
        printf("2. Set light brightness\n");
        printf("3. Turn fan on/off\n");
        printf("4. Exit system\n\n");

        printf("Enter your choice: ");
        scanf(" %c", &input);

        switch(input)
        {
            case '1':
                printf("Enter temperature (in degrees Celsius): ");
                scanf("%d", &temp);
                printf("Temperature set to %d degrees Celsius.\n", temp);
                break;

            case '2':
                printf("Enter light brightness (0-10): ");
                scanf("%d", &light);
                if(light < 0 || light > 10)
                {
                    printf("Invalid input! Brightness should be between 0 and 10.\n");
                    break;
                }
                printf("Light brightness set to %d.\n", light);
                break;

            case '3':
                if(fan == 0)
                {
                    fan = 1;
                    printf("Fan turned on.\n");
                }
                else
                {
                    fan = 0;
                    printf("Fan turned off.\n");
                }
                break;

            case '4':
                printf("Thank you for using the Smart Home Automation System!\n");
                exit(0);

            default:
                printf("Invalid input! Enter a number between 1 and 4.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}
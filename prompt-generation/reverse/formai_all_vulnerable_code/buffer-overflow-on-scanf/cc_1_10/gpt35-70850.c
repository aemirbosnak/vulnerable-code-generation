//FormAI DATASET v1.0 Category: Smart home light control ; Style: standalone
#include <stdio.h>

#define LIGHT_STATUS_OFF 0
#define LIGHT_STATUS_ON 1

int main()
{
    int light_status = LIGHT_STATUS_OFF;
    int user_choice;

    do
    {
        printf("1. Turn on light\n");
        printf("2. Turn off light\n");
        printf("3. Check light status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &user_choice);

        switch(user_choice)
        {
            case 1:
                if(light_status == LIGHT_STATUS_OFF)
                {
                    printf("Turning on light...\n");
                    light_status = LIGHT_STATUS_ON;
                }
                else
                {
                    printf("Light is already on!\n");
                }
                break;

            case 2:
                if(light_status == LIGHT_STATUS_ON)
                {
                    printf("Turning off light...\n");
                    light_status = LIGHT_STATUS_OFF;
                }
                else
                {
                    printf("Light is already off!\n");
                }
                break;

            case 3:
                if(light_status == LIGHT_STATUS_ON)
                {
                    printf("Light is currently on.\n");
                }
                else
                {
                    printf("Light is currently off.\n");
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("\n");
    }
    while(user_choice != 4);

    return 0;
}
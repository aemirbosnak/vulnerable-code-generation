//FormAI DATASET v1.0 Category: Smart home automation ; Style: mathematical
#include <stdio.h>

#define LIGHT_PIN       8
#define FAN_PIN         9
#define AC_PIN          10
#define DOOR_PIN        2

#define LIGHT_ON        1
#define LIGHT_OFF       0
#define FAN_ON          2
#define FAN_OFF         0
#define AC_ON           3
#define AC_OFF          0
#define DOOR_OPEN       4
#define DOOR_CLOSED     0

int main()
{
    int light_status = LIGHT_OFF;
    int fan_status = FAN_OFF;
    int ac_status = AC_OFF;
    int door_status = DOOR_CLOSED;

    printf("Welcome to Smart Home Automation System\n");

    while(1)
    {
        printf("\nChoose the device you want to control\n");
        printf("1. Lights\n2. Fan\n3. Air conditioner\n4. Door\n5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Choose the action you want to perform for Lights\n");
                printf("1. ON\n2. OFF\n");
                int action;
                scanf("%d", &action);
                switch(action)
                {
                    case 1:
                        light_status = LIGHT_ON;
                        printf("Lights are turned ON\n");
                        break;

                    case 2:
                        light_status = LIGHT_OFF;
                        printf("Lights are turned OFF\n");
                        break;

                    default:
                        printf("Invalid choice\n");
                }
                break;

            case 2:
                printf("Choose the action you want to perform for Fan\n");
                printf("1. ON\n2. OFF\n");
                scanf("%d", &action);
                switch(action)
                {
                    case 1:
                        fan_status = FAN_ON;
                        printf("Fan is turned ON\n");
                        break;

                    case 2:
                        fan_status = FAN_OFF;
                        printf("Fan is turned OFF\n");
                        break;

                    default:
                        printf("Invalid choice\n");
                }
                break;

            case 3:
                printf("Choose the action you want to perform for Air conditioner\n");
                printf("1. ON\n2. OFF\n");
                scanf("%d", &action);
                switch(action)
                {
                    case 1:
                        ac_status = AC_ON;
                        printf("Air conditioner is turned ON\n");
                        break;

                    case 2:
                        ac_status = AC_OFF;
                        printf("Air conditioner is turned OFF\n");
                        break;

                    default:
                        printf("Invalid choice\n");
                }
                break;

            case 4:
                printf("Choose the action you want to perform for Door\n");
                printf("1. OPEN\n2. CLOSE\n");
                scanf("%d", &action);
                switch(action)
                {
                    case 1:
                        door_status = DOOR_OPEN;
                        printf("Door is opened\n");
                        break;

                    case 2:
                        door_status = DOOR_CLOSED;
                        printf("Door is closed\n");
                        break;

                    default:
                        printf("Invalid choice\n");
                }
                break;

            case 5:
                printf("Exiting Smart Home Automation System\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Smart home automation ; Style: medieval
#include<stdio.h>
#include<string.h>

int main()
{
    char password[20];
    int room_num, ignition = 0;

    printf("Enter the password to access the smart home automation system:\n");
    scanf("%s",password);

    if(strcmp(password,"medievalstyle123")==0)
    {
        printf("Access granted!\n");

        printf("Welcome to our medieval style smart home automation system!\n");
        
        while(1)
        {
            printf("\nPlease enter the room number:\n");
            scanf("%d",&room_num);

            switch(room_num)
            {
                case 1: printf("You are in the great hall!\n");

                        printf("Do you want to light the fireplace? (1-Yes, 0-No)\n");
                        scanf("%d",&ignition);

                        if(ignition == 1)
                        {
                            printf("Fireplace is now lit!\n");
                        }
                        else
                        {
                            printf("Fireplace is off!\n");
                        }

                        break;

                case 2: printf("You are in the bedroom!\n");

                        printf("Do you want to turn on the night lamp? (1-Yes, 0-No)\n");
                        scanf("%d",&ignition);

                        if(ignition == 1)
                        {
                            printf("Night lamp is now on!\n");
                        }
                        else
                        {
                            printf("Night lamp is off!\n");
                        }

                        break;

                case 3: printf("You are in the kitchen!\n");

                        printf("Do you want to start the stove? (1-Yes, 0-No)\n");
                        scanf("%d",&ignition);

                        if(ignition == 1)
                        {
                            printf("Stove is now on!\n");
                        }
                        else
                        {
                            printf("Stove is off!\n");
                        }

                        break;

                case 4: printf("You are in the study room!\n");

                        printf("Do you want to turn on the candles? (1-Yes, 0-No)\n");
                        scanf("%d",&ignition);

                        if(ignition == 1)
                        {
                            printf("Candles are now lit!\n");
                        }
                        else
                        {
                            printf("Candles are off!\n");
                        }

                        break;

                case 5: printf("You are in the dungeon!\n");

                        printf("Do you want to open the prison door? (1-Yes, 0-No)\n");
                        scanf("%d",&ignition);

                        if(ignition == 1)
                        {
                            printf("Prison door is now open!\n");
                        }
                        else
                        {
                            printf("Prison door is closed!\n");
                        }

                        break;

                default: printf("Invalid room number!\n");
            }
        }
    }
    else
    {
        printf("Access denied!\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int fuel=100;
    int distance=0;
    int speed=0;
    int choice;
    srand(time(0));

    printf("\n\nWelcome to the Procedural Space Adventure!\n");
    printf("In this game, you are an astronaut traveling to a distant planet.\n");
    printf("You need to manage your fuel and distance traveled to reach the planet.\n");
    printf("Ready to start? Let's go!\n");

    while(distance<5000 && fuel>0)
    {
        printf("\n\nCurrent distance travelled: %dkm\n",distance);
        printf("Current fuel remaining: %d litres\n",fuel);
        printf("Current speed: %dkm/h\n",speed);

        printf("\n\nChoose one of the following options:\n");
        printf("1. Accelerate\n");
        printf("2. Decelerate\n");
        printf("3. Refuel\n");
        printf("4. Travel at Constant Speed\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: 
                    if(speed<1000)
                    {
                        int random_speed=rand()%200+1;
                        speed+=random_speed;
                        printf("\n\nYou accelerated by %dkm/h. Current speed: %dkm/h\n",random_speed,speed);
                    }
                    else
                    {
                        printf("\n\nYou cannot accelerate further!\n");
                    }
                    break;
            case 2: 
                    if(speed>0)
                    {
                        int random_speed=rand()%200+1;
                        speed-=random_speed;
                        printf("\n\nYou decelerated by %dkm/h. Current speed: %dkm/h\n",random_speed,speed);      
                    }
                    else
                    {
                        printf("\n\nYou cannot decelerate further!\n");
                    }
                    break;
            case 3: 
                    {
                        int random_fuel=rand()%51+50;//refueling between 50 to 100 litres
                        fuel+=random_fuel;
                        printf("\n\nYou refueled by %d litres. Current fuel: %d litres\n",random_fuel,fuel);
                    }
                    break;
            case 4: 
                    {
                        int random_travel=rand()%501+500;
                        distance+=random_travel;
                        fuel-=random_travel/10;
                        printf("\n\nYou traveled at a constant speed for %dkm. Current distance travelled: %dkm\n",random_travel,distance);
                        printf("Fuel used: %d litres\n",random_travel/10);
                    }
                    break;
            default: printf("\n\nInvalid Option! Please Try Again.\n");
        }
    }

    if(distance>=5000)
    {
        printf("\n\nCongratulations! You have successfully reached the planet.\n");
    }
    else
    {
        printf("\n\nYou ran out of fuel! Game Over.\n");
    }
    return 0;
}
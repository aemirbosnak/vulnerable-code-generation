//FormAI DATASET v1.0 Category: Smart home automation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int light = 0;
   int temperature = 25;
   int airconditioner = 0;
   int fan = 0;
   
   while(1)
   {
       // display current status
       printf("\n----------CURRENT STATUS----------\n");
       printf("Light is %s\n", (light == 1) ? "ON" : "OFF");
       printf("Temperature is %d°C\n", temperature);
       printf("Air conditioner is %s\n", (airconditioner == 1) ? "ON" : "OFF");
       printf("Fan is %s\n", (fan == 1) ? "ON" : "OFF");
       printf("----------------------------------\n");
       
       // user menu
       printf("\nWhat would you like to do?\n");
       printf("1. Turn light %s\n", (light == 1) ? "OFF" : "ON");
       printf("2. Set temperature\n");
       printf("3. Turn air conditioner %s\n", (airconditioner == 1) ? "OFF" : "ON");
       printf("4. Turn fan %s\n", (fan == 1) ? "OFF" : "ON");
       printf("5. Quit\n");
       printf("Please enter the number of the action you want to perform: ");
       
       int choice;
       scanf("%d", &choice);
       
       switch(choice)
       {
           case 1:
                light = (light == 1) ? 0 : 1;
                break;
           case 2:
                printf("Enter temperature: ");
                scanf("%d", &temperature);
                break;
           case 3:
                airconditioner = (airconditioner == 1) ? 0 : 1;
                if(airconditioner == 1)
                {
                    temperature = 20;
                    printf("Temperature set to 20°C\n");
                }
                break;
           case 4:
                fan = (fan == 1) ? 0 : 1;
                break;
           case 5:
                printf("Goodbye!\n");
                exit(0);
           default:
                printf("Invalid choice, please try again.\n");
                break;
       }
   }
   
   return 0;
}
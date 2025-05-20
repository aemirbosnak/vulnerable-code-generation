//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: sophisticated
#include <stdio.h>

int main() {
   printf("Welcome to C Drone Remote Control\n");
   
   int altitude = 0; //initial altitude is 0
   int distance = 0; //initial distance covered is 0
   int batteryLife = 100; //initial battery life is 100 percent
   
   while(1) { //infinite loop for continuous control of drone
      printf("\n\nDrone Altitude : %d meters\n", altitude);
      printf("Distance covered : %d meters\n", distance);
      printf("Battery Life : %d%%\n", batteryLife);
      printf("\nSelect an option:\n");
      printf("1. Increase altitude by 50 meters\n");
      printf("2. Decrease altitude by 50 meters\n");
      printf("3. Move drone forward by 100 meters\n");
      printf("4. Move drone backward by 100 meters\n");
      printf("5. Turn left\n");
      printf("6. Turn right\n");
      printf("7. Land drone\n");
      printf("8. Exit Remote Control\n");
      
      int option;
      scanf("%d", &option);
      
      switch(option) {
         case 1 :
            altitude += 50;
            batteryLife -= 5; //each increase in altitude reduces battery life by 5%
            printf("\nDrone altitude increased to %d meters\n", altitude);
            break;
         
         case 2 :
            if(altitude>50) { //prevents drone from touching ground
               altitude -= 50;
               batteryLife -= 5; //each decrease in altitude reduces battery life by 5%
               printf("\nDrone altitude decreased to %d meters\n", altitude);
            }
            else {
               printf("\nDrone is already at ground level\n");
            }
            break;
         
         case 3 :
            distance += 100;
            batteryLife -= 2; //each forward movement reduces battery life by 2%
            printf("\nMoved drone forward by 100 meters\n");
            break;
         
         case 4 :
            if(distance>100) { //prevents drone from going beyond the starting point
               distance -= 100;
               batteryLife -= 2; //each backward movement reduces battery life by 2%
               printf("\nMoved drone backward by 100 meters\n");
            }
            else {
               printf("\nDrone is at the starting point\n");
            }
            break;
         
         case 5 :
            printf("\nDrone turned left\n");
            break;
         
         case 6 :
            printf("\nDrone turned right\n");
            break;
         
         case 7 :
            altitude = 0;
            printf("\nDrone landed at ground level\n");
            break;
         
         case 8 :
            printf("\nExiting Remote Control...\n");
            return 0;
         
         default :
            printf("\nIncorrect option selected, Please try again\n");
      }
      
      if(batteryLife<10) { //if battery life is less than 10%, drone automatically lands and remote control ends
         printf("\nBattery Life is low, Drone landing safely...\n");
         altitude = 0;
         return 0;
      }
   }
   return 0;
}
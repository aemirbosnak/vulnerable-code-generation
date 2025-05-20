//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: future-proof
#include<stdio.h>

int main(){
   int fuel, distance, speed, time, flag = 1;

   printf("Enter fuel capacity of the spaceship: ");
   scanf("%d", &fuel);
   if(fuel <= 0){
      printf("Invalid fuel capacity. Program terminated.\n");
      return 0;
   }

   printf("Enter the distance to be covered: ");
   scanf("%d", &distance);
   if(distance <= 0){
      printf("Invalid distance. Program terminated.\n");
      return 0;
   }

   printf("Enter the speed of the spaceship: ");
   scanf("%d", &speed);
   if(speed <= 0){
      printf("Invalid speed. Program terminated.\n");
      return 0;
   }

   time = distance / speed;

   if(time * fuel >= distance){
      printf("The spaceship will reach the destination successfully.\n");
      flag = 0;
   }
   else{
      printf("The spaceship will run out of fuel before reaching the destination.\n");
   }

   while(flag){
      printf("Do you want to refuel? Enter 1 for yes or 0 for no: ");
      int ch;
      scanf("%d", &ch);

      if(ch == 0){
         printf("Program terminated.\n");
         break;
      }

      printf("Enter the amount of fuel to be refueled: ");
      int refuel;
      scanf("%d", &refuel);

      fuel += refuel;

      if(time * fuel >= distance){
         printf("The spaceship will reach the destination successfully.\n");
         flag = 0;
      }
      else{
         printf("The spaceship will run out of fuel before reaching the destination.\n");
      }
   }

   return 0;
}
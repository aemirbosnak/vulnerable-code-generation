//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void time_travel(int);

int main() {
   int year;
   
   printf("Welcome to the Time Travel Simulator!\n\n");
   printf("Enter the year to travel to: ");
   scanf("%d", &year);
   
   time_travel(year);
   
   return 0;
}

void time_travel(int year) {
   int current_year = 2022;
   int i;
   int speed;
   int distance;
   int time_taken;
   int hours, minutes, seconds;
   int random_num;
   
   printf("\n\nCalculating your time travel...\n\n");
  
   if (year > current_year) {
      speed = 1000000000;
      distance = year - current_year;
      
      for (i = 1; i <= distance; i++) {
         printf("Year %d...\n", current_year + i);
         
         if (i < distance) {
            printf("Warping through time...\n");
            printf("Please wait...\n\n");
            srand(time(0));
            random_num = (rand() % 10) + 1;
            time_taken = random_num * 1000 * 1000 * distance / speed;
            hours = time_taken / (60 * 60);
            minutes = (time_taken % (60 * 60)) / 60;
            seconds = time_taken % 60;
            printf("You have arrived in year %d after %d hours, %d minutes and %d seconds!\n\n", current_year + i, hours, minutes, seconds);
         }
      }
   } else {
      speed = -1000000000;
      distance = current_year - year;
      
      for (i = 1; i <= distance; i++) {
         printf("Year %d...\n", current_year - i);
         
         if (i < distance) {
            printf("Warping through time...\n");
            printf("Please wait...\n\n");
            srand(time(0));
            random_num = (rand() % 10) + 1;
            time_taken = random_num * 1000 * 1000 * distance / speed;
            hours = time_taken / (60 * 60);
            minutes = (time_taken % (60 * 60)) / 60;
            seconds = time_taken % 60;
            printf("You have arrived in year %d after %d hours, %d minutes and %d seconds!\n\n", current_year - i, hours, minutes, seconds);
         }
      }
   }
   
   printf("\n\nTime travel complete!\n\n");
   printf("Thank you for using the Time Travel Simulator!\n\n");
}
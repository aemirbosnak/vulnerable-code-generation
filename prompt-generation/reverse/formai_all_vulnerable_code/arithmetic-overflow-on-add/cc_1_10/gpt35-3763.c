//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   time_t t = time(NULL);
   struct tm *tm = localtime(&t);

   printf("Welcome to the Time Travel Simulator!\n\n");

   // Present time
   printf("Present time: %04d-%02d-%02d %02d:%02d:%02d\n",
          tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);

   int option;
   do {
      printf("\nPlease select an option:\n");
      printf("1. Travel to the past\n");
      printf("2. Travel to the future\n");
      printf("3. Exit\n");

      scanf("%d", &option);

      if (option == 1) {
         int years;
         printf("\nHow many years would you like to travel back in time?\n");
         scanf("%d", &years);

         tm->tm_year -= years;
         time_t new_time = mktime(tm);
         struct tm *new_tm = localtime(&new_time);

         printf("You have traveled back %d years.\n", years);
         printf("Time machine date: %04d-%02d-%02d %02d:%02d:%02d\n",
                new_tm->tm_year + 1900, new_tm->tm_mon + 1, new_tm->tm_mday, new_tm->tm_hour, new_tm->tm_min, new_tm->tm_sec);

      } else if (option == 2) {
         int years;
         printf("\nHow many years would you like to travel to the future?\n");
         scanf("%d", &years);

         tm->tm_year += years;
         time_t new_time = mktime(tm);
         struct tm *new_tm = localtime(&new_time);

         printf("You have traveled %d years ahead.\n", years);
         printf("Time machine date: %04d-%02d-%02d %02d:%02d:%02d\n",
                new_tm->tm_year + 1900, new_tm->tm_mon + 1, new_tm->tm_mday, new_tm->tm_hour, new_tm->tm_min, new_tm->tm_sec);

      } else if (option == 3) {
         printf("\nExiting program. Goodbye!\n");

      } else {
         printf("\nInvalid option. Please try again.\n");
      }

   } while (option != 3);

   return 0;
}
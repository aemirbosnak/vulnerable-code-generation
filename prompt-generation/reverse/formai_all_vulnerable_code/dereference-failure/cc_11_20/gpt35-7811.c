//FormAI DATASET v1.0 Category: Date and time ; Style: active
#include <stdio.h>
#include <time.h>

int main() {
   time_t t = time(NULL);
   struct tm tm = *localtime(&t);

   printf("Current Date & Time : %d-%02d-%02d %02d:%02d:%02d\n",
           tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
           tm.tm_hour, tm.tm_min, tm.tm_sec);
           
   int weekday = tm.tm_wday;

   switch (weekday) {
       case 0:
           printf("Today is Sunday\n");
           break;
       case 1:
           printf("Today is Monday\n");
           break;
       case 2:
           printf("Today is Tuesday\n");
           break;
       case 3:
           printf("Today is Wednesday\n");
           break;
       case 4:
           printf("Today is Thursday\n");
           break;
       case 5:
           printf("Today is Friday\n");
           break;
       case 6:
           printf("Today is Saturday\n");
           break;
   }
   
   int hour = tm.tm_hour;
   
   if (hour >= 6 && hour < 12) {
       printf("Good morning!\n");
   } else if (hour >= 12 && hour < 18) {
       printf("Good afternoon!\n");
   } else {
       printf("Good evening!\n");
   }
   
   printf("What is your name?\n");
   char name[20];
   scanf("%s", name);
   printf("Nice to meet you, %s!\n", name);
   
   return 0;
}
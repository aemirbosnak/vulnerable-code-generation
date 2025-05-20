//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

   time_t current_time;
   struct tm * time_info;
   char * time_string;

   /* Get the current time. */
   current_time = time(NULL);

   /* Convert it to local time representation. */
   time_info = localtime(&current_time);

   /* Print it out in a nice format. */
   printf("Current Time: %s\n", asctime(time_info));

   /* Set a time in the future. */
   time_t future_time = current_time + 604800; // 1 week from now

   /* Convert it to local time representation. */
   time_info = localtime(&future_time);

   /* Print it out in a nice format. */
   printf("Future Time: %s\n", asctime(time_info));

   /* Set a time in the past. */
   time_t past_time = current_time - 31536000; // 1 year ago

   /* Convert it to local time representation. */
   time_info = localtime(&past_time);

   /* Print it out in a nice format. */
   printf("Past Time: %s\n", asctime(time_info));

   /* Set a custom time. */
   struct tm custom_time;
   custom_time.tm_year = 2030 - 1900; // year 2030
   custom_time.tm_mon = 10; // November
   custom_time.tm_mday = 15; // 15th day of the month
   custom_time.tm_hour = 12; // 12:00 noon
   custom_time.tm_min = 30; // 30 minutes past the hour
   custom_time.tm_sec = 0; // 0 seconds

   /* Convert it to time_t format. */
   time_t custom_time_t = mktime(&custom_time);

   /* Convert it to local time representation. */
   time_info = localtime(&custom_time_t);

   /* Print it out in a nice format. */
   printf("Custom Time: %s\n", asctime(time_info));

   return 0;
}
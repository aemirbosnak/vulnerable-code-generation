#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <time.h>

int main() {
  time_t t, now, then, duration;
  int year, month, day, hour, minute, zone, offset;

  // Get current time
  now = time(NULL);
  struct tm *now_tm = localtime(&now);

  // Get user input
  printf("Enter the current date (YYYY-MM-DD): ");
  scanf("%d-%d-%d", &year, &month, &day);

  printf("Enter the current time (HH:MM): ");
  scanf("%d:%d", &hour, &minute);

  printf("Enter the time travel duration (HH:MM): ");
  scanf("%d:%d", &duration, &offset);

  // Calculate the resulting time
  then = now + duration * 3600 + offset * 3600;
  struct tm *then_tm = localtime( &then );

  // Display the resulting time
  printf("The date and time after time travel is: ");
  printf("%d-%d-%d %d:%d", then_tm->tm_year, then_tm->tm_mon, then_tm->tm_mday, then_tm->tm_hour, then_tm->tm_min);

  return 0;
}

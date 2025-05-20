#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <time.h>

int main() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);

  int year, month, day, hour, minute, second, duration, zone_offset;
  printf("Enter the current date (YYYY-MM-DD): ");
  scanf("%d-%d-%d", &year, &month, &day);

  printf("Enter the current time (HH:MM:SS): ");
  scanf("%d:%d:%d", &hour, &minute, &second);

  printf("Enter the time travel duration (in seconds): ");
  scanf("%d", &duration);

  printf("Enter the time zone offset (in hours): ");
  scanf("%d", &zone_offset);

  // Calculate the resulting date and time
  time_t result_t = t + duration * 3600 + zone_offset * 3600;
  struct tm *result_tm = localtime(result_t);

  // Print the resulting date and time
  printf("The resulting date and time is: ");
  printf("%d-%d-%d %d:%d:%d", result_tm->tm_year, result_tm->tm_mon, result_tm->tm_mday, result_tm->tm_hour, result_tm->tm_min, result_tm->tm_sec);

  return 0;
}

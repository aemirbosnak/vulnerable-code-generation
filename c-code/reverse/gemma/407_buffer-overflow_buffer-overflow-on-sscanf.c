#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char date_time_str[100];
  time_t timestamp;
  struct tm *tm_ptr;

  printf("Enter a date and time (YYYY-MM-DD HH:MM:SS): ");
  scanf("%s", date_time_str);

  if (sscanf(date_time_str, "%d-%d-%d %d:%d:%d", &timestamp, &tm_ptr) != 6) {
    printf("Invalid date/time format. Please try again.\n");
    return 1;
  }

  if (mktime(tm_ptr) == -1) {
    printf("Error converting date/time to timestamp. Please try again.\n");
    return 1;
  }

  printf("Your chosen timestamp is: %s", asctime(tm_ptr));

  return 0;
}

#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char datetime[100];
  printf("Enter the date and time in DD/MM/YYYY HH:MM AM/PM Timezone:");
  scanf("%s", datetime);

  int year, month, day, hour, minute;
  sscanf(datetime, "%d/%d/%d %d:%d %s", &day, &month, &year, &hour, &minute, NULL);

  int timestamp = (year * 1000000) + (month * 10000) + (day * 100) + (hour * 60) + minute;

  printf("Your timestamp is: %d", timestamp);

  return 0;
}

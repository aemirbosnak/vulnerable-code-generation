#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char date_time[100];
  printf("Enter the date and time in DD/MM/YYYY HH:MM AM/PM Timezone format:");
  scanf("%s", date_time);

  int year, month, day, hour, minute;
  sscanf(date_time, "%d/%d/%d %d:%d %s", &day, &month, &year, &hour, &minute, NULL);

  if (year < 1900 || year > 2100) {
    printf("Invalid year.\n");
  } else if (month < 1 || month > 12) {
    printf("Invalid month.\n");
  } else if (day < 1 || day > 31) {
    printf("Invalid day.\n");
  } else if (hour < 0 || hour > 23) {
    printf("Invalid hour.\n");
  } else if (minute < 0 || minute > 59) {
    printf("Invalid minute.\n");
  } else {
    printf("Time travel successful!\n");
  }

  return 0;
}

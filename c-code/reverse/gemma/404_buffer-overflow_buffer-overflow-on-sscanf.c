#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char date[10];
  scanf("%s", date);
  int year = atoi(date);
  int month = atoi(date + 3);
  int day = atoi(date + 6);

  if (year < 1000 || year > 2023) {
    printf("Invalid date");
  } else if (month < 1 || month > 12) {
    printf("Invalid month");
  } else if (day < 1 || day > 31) {
    printf("Invalid day");
  } else {
    printf("Time travel successful");
  }

  return 0;
}

//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SIMS 100

int main() {
  srand(time(NULL));

  for (int i = 0; i < NUM_SIMS; i++) {
    int year = rand() % 100 + 1900;
    int month = rand() % 12 + 1;
    int day = rand() % 31 + 1;

    char month_str[3];
    switch (month) {
      case 1:
        strcpy(month_str, "Jan");
        break;
      case 2:
        strcpy(month_str, "Feb");
        break;
      case 3:
        strcpy(month_str, "Mar");
        break;
      case 4:
        strcpy(month_str, "Apr");
        break;
      case 5:
        strcpy(month_str, "May");
        break;
      case 6:
        strcpy(month_str, "Jun");
        break;
      case 7:
        strcpy(month_str, "Jul");
        break;
      case 8:
        strcpy(month_str, "Aug");
        break;
      case 9:
        strcpy(month_str, "Sep");
        break;
      case 10:
        strcpy(month_str, "Oct");
        break;
      case 11:
        strcpy(month_str, "Nov");
        break;
      case 12:
        strcpy(month_str, "Dec");
        break;
    }

    printf("Date: %d %s %d, %d\n", day, month_str, year);
  }

  return 0;
}
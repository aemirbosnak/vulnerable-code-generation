//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main() {
  char month[10], day[5], year[5];
  int month_num, day_num, year_num;

  printf("\nOh Romeo! What date is it today?\n");
  printf("\nIn what month are we? (e.g. January)\n");
  scanf("%s", month);

  //Converting month to month number
  if (strcmp(month, "January") == 0) {
    month_num = 1;
  }
  else if (strcmp(month, "February") == 0) {
    month_num = 2;
  }
  else if (strcmp(month, "March") == 0) {
    month_num = 3;
  }
  else if (strcmp(month, "April") == 0) {
    month_num = 4;
  }
  else if (strcmp(month, "May") == 0) {
    month_num = 5;
  }
  else if (strcmp(month, "June") == 0) {
    month_num = 6;
  }
  else if (strcmp(month, "July") == 0) {
    month_num = 7;
  }
  else if (strcmp(month, "August") == 0) {
    month_num = 8;
  }
  else if (strcmp(month, "September") == 0) {
    month_num = 9;
  }
  else if (strcmp(month, "October") == 0) {
    month_num = 10;
  }
  else if (strcmp(month, "November") == 0) {
    month_num = 11;
  }
  else if (strcmp(month, "December") == 0) {
    month_num = 12;
  }
  else {
    printf("\nOh no! That's an invalid month. Please try again.\n");
    return 0;
  }

  printf("What day is it in %s, my dear Romeo? (e.g. 14)\n", month);
  scanf("%s", day);
  //Converting day to day number
  day_num = atoi(day);

  printf("In what year are we, my Juliet? (e.g. 1595)\n");
  scanf("%s", year);
  //Converting year to year number
  year_num = atoi(year);

  printf("\nGreat news, my love! The date you requested is %d/%d/%d\n", month_num, day_num, year_num);

  return 0;
}
//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
  int year, month, day;
  char input[20];
  char *token;
  int count = 0;
  int flag = 0;
  int length = 0;
  char *month_str = "January February March April May June July August September October November December";
  char *week_str = "Sunday Monday Tuesday Wednesday Thursday Friday Saturday";
  char *day_str = "st nd rd th";

  printf("Enter a date in natural language format (e.g. 'January 1st, 2022'): ");
  fgets(input, 20, stdin);

  token = strtok(input, " ");
  while (token!= NULL) {
    if (flag == 0) {
      if (isdigit(token[0])) {
        year = atoi(token);
        flag = 1;
      } else {
        for (int i = 0; i < strlen(month_str); i++) {
          if (strcmp(token, month_str + i) == 0) {
            month = i + 1;
            flag = 1;
            break;
          }
        }
      }
    } else if (flag == 1) {
      if (isdigit(token[0])) {
        day = atoi(token);
        flag = 2;
      } else {
        for (int i = 0; i < strlen(week_str); i++) {
          if (strcmp(token, week_str + i) == 0) {
            count = i + 1;
            flag = 2;
            break;
          }
        }
      }
    } else if (flag == 2) {
      if (isdigit(token[0])) {
        day = atoi(token);
        flag = 3;
      } else {
        for (int i = 0; i < strlen(day_str); i++) {
          if (strcmp(token, day_str + i) == 0) {
            length = i + 1;
            flag = 3;
            break;
          }
        }
      }
    }
    token = strtok(NULL, " ");
  }

  if (flag == 3) {
    printf("The date %s %d, %d is a %s.\n", week_str[count - 1], day, year, day_str[length - 1]);
  } else {
    printf("Invalid date format.\n");
  }

  return 0;
}
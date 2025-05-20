//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LEN 20
#define DATE_FORMAT_LEN 10

typedef struct Date {
  int year;
  int month;
  int day;
} Date;

int validate_date(char *date_str) {
  int year, month, day;
  char ch;

  if (!date_str) {
    return -1;
  }

  year = month = day = -1;

  ch = *date_str;
  while (ch) {
    if (isdigit(ch)) {
      switch (ch - '0') {
        case 0:
          year = 2000 + year * 10 + ch - '0';
          break;
        case 1:
          year = 2000 + year * 10 + ch - '0';
          break;
        case 2:
          month = ch - '0';
          break;
        case 3:
          month = ch - '0';
          break;
        case 4:
          day = ch - '0';
          break;
        case 5:
          day = ch - '0';
          break;
      }
    }
    ch++;
  }

  if (year < 1900 || year > 2023) {
    return -1;
  }

  if (month < 1 || month > 12) {
    return -1;
  }

  if (day < 1 || day > 31) {
    return -1;
  }

  return 0;
}

Date convert_date(char *date_str) {
  Date date;
  int valid_date = validate_date(date_str);

  if (valid_date == -1) {
    date.year = date.month = date.day = -1;
  } else {
    date.year = valid_date / 1000;
    date.month = (valid_date % 1000) / 100;
    date.day = valid_date % 100;
  }

  return date;
}

int main() {
  char date_str[] = "2023-04-01";
  Date date = convert_date(date_str);

  if (date.year != -1) {
    printf("Year: %d\n", date.year);
  }

  if (date.month != -1) {
    printf("Month: %d\n", date.month);
  }

  if (date.day != -1) {
    printf("Day: %d\n", date.day);
  }

  return 0;
}
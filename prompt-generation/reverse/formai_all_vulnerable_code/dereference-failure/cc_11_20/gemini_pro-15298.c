//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s date_string\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *date_string = argv[1];

  // Validate the date string.

  if (strlen(date_string) != 10) {
    fprintf(stderr, "invalid date string: %s\n", date_string);
    return EXIT_FAILURE;
  }

  for (int i = 0; i < 10; i++) {
    if (!isdigit(date_string[i])) {
      fprintf(stderr, "invalid date string: %s\n", date_string);
      return EXIT_FAILURE;
    }
  }

  // Convert the date string to a time_t value.

  int year = atoi(date_string + 0);
  int month = atoi(date_string + 2);
  int day = atoi(date_string + 4);

  if (year < 1900 || year > 2099) {
    fprintf(stderr, "invalid year: %d\n", year);
    return EXIT_FAILURE;
  }

  if (month < 1 || month > 12) {
    fprintf(stderr, "invalid month: %d\n", month);
    return EXIT_FAILURE;
  }

  if (day < 1 || day > 31) {
    fprintf(stderr, "invalid day: %d\n", day);
    return EXIT_FAILURE;
  }

  struct tm tm = {0};
  tm.tm_year = year - 1900;
  tm.tm_mon = month - 1;
  tm.tm_mday = day;

  time_t time_t_value = mktime(&tm);

  if (time_t_value == -1) {
    fprintf(stderr, "invalid date: %s\n", date_string);
    return EXIT_FAILURE;
  }

  // Print the converted time in various formats.

  printf("time_t value: %ld\n", time_t_value);

  char *ctime_string = ctime(&time_t_value);
  printf("ctime string: %s", ctime_string);

  char *asctime_string = asctime(&tm);
  printf("asctime string: %s", asctime_string);

  char strftime_buffer[MAX_LINE_LENGTH];
  strftime(strftime_buffer, MAX_LINE_LENGTH, "%c", &tm);
  printf("strftime string: %s", strftime_buffer);

  return EXIT_SUCCESS;
}
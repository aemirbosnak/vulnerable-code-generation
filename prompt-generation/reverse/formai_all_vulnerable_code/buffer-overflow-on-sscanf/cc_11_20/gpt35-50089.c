//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: statistical
#include <stdio.h>
#include <string.h>

int main() {
  char date[20];
  char year[5], month[3], day[3];
  int d, m, y;
  
  printf("Enter a date in natural language (ex. January 20, 2022): ");
  fgets(date, sizeof(date), stdin);
  
  // Get year
  sscanf(date, "%*s %s", year);
  y = atoi(year);
  
  // Get month
  sscanf(date, "%s", month);
  if (strcmp(month, "January") == 0) {
    m = 1;
  } else if (strcmp(month, "February") == 0) {
    m = 2;
  } else if (strcmp(month, "March") == 0) {
    m = 3;
  } else if (strcmp(month, "April") == 0) {
    m = 4;
  } else if (strcmp(month, "May") == 0) {
    m = 5;
  } else if (strcmp(month, "June") == 0) {
    m = 6;
  } else if (strcmp(month, "July") == 0) {
    m = 7;
  } else if (strcmp(month, "August") == 0) {
    m = 8;
  } else if (strcmp(month, "September") == 0) {
    m = 9;
  } else if (strcmp(month, "October") == 0) {
    m = 10;
  } else if (strcmp(month, "November") == 0) {
    m = 11;
  } else if (strcmp(month, "December") == 0) {
    m = 12;
  } else {
    printf("Invalid month entered.\n");
    return 1;
  }
  
  // Get day
  sscanf(date, "%*s %*s %d,", &d);
  
  printf("%d/%d/%d\n", m, d, y);
  
  return 0;
}
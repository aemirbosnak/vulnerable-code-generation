//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: invasive
#include <stdio.h>

int main() {
  printf("Welcome to the C Natural Language Date Converter!\n");
  printf("Please enter a date in natural language form (e.g. January 1st, 2022): ");
  
  char month[20], suffix[3];
  int day, year;
  
  scanf("%s %d%s %d", month, &day, suffix, &year);
  
  // Remove suffix 
  if (suffix[0] == 's') {
    suffix[1] = suffix[0];
    suffix[0] = '\0';
  }
  
  // Convert month to number
  int monthNum;
  if (strcmp(month, "January") == 0) { 
    monthNum = 1;
  } else if (strcmp(month, "February") == 0) {
    monthNum = 2;
  } else if (strcmp(month, "March") == 0) {
    monthNum = 3;
  } else if (strcmp(month, "April") == 0) {
    monthNum = 4;
  } else if (strcmp(month, "May") == 0) {
    monthNum = 5;
  } else if (strcmp(month, "June") == 0) {
    monthNum = 6;
  } else if (strcmp(month, "July") == 0) {
    monthNum = 7;
  } else if (strcmp(month, "August") == 0) {
    monthNum = 8;
  } else if (strcmp(month, "September") == 0) {
    monthNum = 9;
  } else if (strcmp(month, "October") == 0) {
    monthNum = 10;
  } else if (strcmp(month, "November") == 0) {
    monthNum = 11;
  } else if (strcmp(month, "December") == 0) {
    monthNum = 12;
  }
  
  // Check for invalid date entries
  if (day < 1 || day > 31) {
    printf("Invalid day entered.\n");
    return 1;
  }
  
  if (monthNum < 1 || monthNum > 12) {
    printf("Invalid month entered.\n");
    return 1;
  }
  
  if (year < 0) {
    printf("Invalid year entered.\n");
    return 1;
  }
  
  // Add suffix to day if necessary
  if (suffix[0] != '\0') {
    if (suffix[0] == 't' && suffix[1] == 'h') {
      if (day == 1 || day == 21 || day == 31) {
        printf("Invalid suffix entered with day.\n");
        return 1;
      } else {
        printf("Date entered: %d/%d/%d\n", monthNum, day, year);
      }
    } else if (suffix[0] == 's' && suffix[1] == 't') {
      printf("Invalid suffix entered with day.\n");
      return 1;
    } else {
      printf("Date entered: %d/%d/%d\n", monthNum, day, year);
    }
  } else {
    printf("Date entered: %d/%d/%d\n", monthNum, day, year);
  }
  
  return 0;
}
//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* c_natlang_date_converter(char* input_date) {
  char* output_date = (char*)malloc(sizeof(char)*20);
  char* month = (char*)malloc(sizeof(char)*10);
  char* day = (char*)malloc(sizeof(char)*3);
  char* year = (char*)malloc(sizeof(char)*5);

  if (strlen(input_date) < 6 || strlen(input_date) > 18) { // Input date must have minimum length of 6 (ex. 1/1/20) and maximum length of 18 (ex. January 1, 2020)
    strcpy(output_date, "Invalid date format!");
    return output_date;
  }

  int num_slashes = 0;
  int num_commas = 0;
  int num_spaces = 0;
  for (int i = 0; i < strlen(input_date); i++) {
    if (input_date[i] == '/') {
      num_slashes++;
    } else if (input_date[i] == ',') {
      num_commas++;
    } else if (input_date[i] == ' ') {
      num_spaces++;
    }
  }

  if (num_slashes == 2 && num_commas == 0 && num_spaces == 0) { // Input date is in format of MM/DD/YY or MM/DD/YYYY
    sscanf(input_date, "%[^/]/%[^/]/%[^/]", month, day, year);
    if (strlen(year) == 2) { // Add 2000 to year if year is given in two digits
      strcat(year, "20");
    }
  } else if (num_slashes == 0 && num_commas == 1 && num_spaces == 1) { // Input date is in format of Month Day, Year
    sscanf(input_date, "%[^,], %[^ ] %[^,]", month, day, year);
  } else {
    strcpy(output_date, "Invalid date format!");
    return output_date;
  }

  int int_month = 0;
  if (sscanf(month, "%d", &int_month) != 1) { // Convert month from string to integer (ex. January -> 1)
    if (strncmp(month, "January", 3) == 0) {
      int_month = 1;
    } else if (strncmp(month, "February", 3) == 0) {
      int_month = 2;
    } else if (strncmp(month, "March", 3) == 0) {
      int_month = 3;
    } else if (strncmp(month, "April", 3) == 0) {
      int_month = 4;
    } else if (strncmp(month, "May", 3) == 0) {
      int_month = 5;
    } else if (strncmp(month, "June", 3) == 0) {
      int_month = 6;
    } else if (strncmp(month, "July", 3) == 0) {
      int_month = 7;
    } else if (strncmp(month, "August", 3) == 0) {
      int_month = 8;
    } else if (strncmp(month, "September", 3) == 0) {
      int_month = 9;
    } else if (strncmp(month, "October", 3) == 0) {
      int_month = 10;
    } else if (strncmp(month, "November", 3) == 0) {
      int_month = 11;
    } else if (strncmp(month, "December", 3) == 0) {
      int_month = 12;
    } else {
      strcpy(output_date, "Invalid month!");
      return output_date;
    }
  }

  int int_day = atoi(day);
  int int_year = atoi(year);

  if (int_month < 1 || int_month > 12) {
    strcpy(output_date, "Invalid month!");
    return output_date;
  } else if (int_day < 1 || int_day > 31) { // This program does not handle leap years and months with fewer days
    strcpy(output_date, "Invalid day!");
    return output_date;
  } else if (int_year < 1000 || int_year > 9999) {
    strcpy(output_date, "Invalid year!");
    return output_date;
  }

  sprintf(output_date, "%d-%02d-%02d", int_year, int_month, int_day); // Output date in format of YYYY-MM-DD

  free(month);
  free(day);
  free(year);
  return output_date;
}

int main() {
  char* input_date_1 = "1/1/20";
  char* input_date_2 = "January 1, 2020";
  char* input_date_3 = "2/29/2021"; // Invalid date since 2021 is not a leap year
  char* input_date_4 = "Feb 29, 2024"; // Valid leap year date

  char* output_date_1 = c_natlang_date_converter(input_date_1);
  printf("%s -> %s\n", input_date_1, output_date_1);

  char* output_date_2 = c_natlang_date_converter(input_date_2);
  printf("%s -> %s\n", input_date_2, output_date_2);

  char* output_date_3 = c_natlang_date_converter(input_date_3);
  printf("%s -> %s\n", input_date_3, output_date_3);

  char* output_date_4 = c_natlang_date_converter(input_date_4);
  printf("%s -> %s\n", input_date_4, output_date_4);

  free(output_date_1);
  free(output_date_2);
  free(output_date_3);
  free(output_date_4);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the supported date formats
#define DATE_FORMAT_YYYYMMDD "YYYY-MM-DD"
#define DATE_FORMAT_DDMMYYYY "DD-MM-YYYY"
#define DATE_FORMAT_MMDDYYYY "MM-DD-YYYY"

// Define the supported date separators
#define DATE_SEPARATOR_HYPHEN "-"
#define DATE_SEPARATOR_SLASH "/"
#define DATE_SEPARATOR_DOT "."

// Define the supported date parts
#define DATE_PART_YEAR 0
#define DATE_PART_MONTH 1
#define DATE_PART_DAY 2

// Define the maximum length of a date string
#define DATE_STRING_MAX_LENGTH 10

// Define the error codes
#define ERROR_INVALID_DATE_FORMAT 1
#define ERROR_INVALID_DATE_SEPARATOR 2
#define ERROR_INVALID_DATE_PARTS 3
#define ERROR_INVALID_DATE_VALUE 4

// Convert a string to an integer
int string_to_int(char *string) {
  int integer = 0;
  int length = strlen(string);
  for (int i = 0; i < length; i++) {
    integer *= 10;
    integer += string[i] - '0';
  }
  return integer;
}

// Check if a string is a valid date format
int is_valid_date_format(char *string) {
  return strcmp(string, DATE_FORMAT_YYYYMMDD) == 0 || strcmp(string, DATE_FORMAT_DDMMYYYY) == 0 || strcmp(string, DATE_FORMAT_MMDDYYYY) == 0;
}

// Check if a string is a valid date separator
int is_valid_date_separator(char *string) {
  return strcmp(string, DATE_SEPARATOR_HYPHEN) == 0 || strcmp(string, DATE_SEPARATOR_SLASH) == 0 || strcmp(string, DATE_SEPARATOR_DOT) == 0;
}

// Check if a string is a valid date value
int is_valid_date_value(char *string) {
  int year = string_to_int(string);
  int month = string_to_int(string + 4);
  int day = string_to_int(string + 7);
  return year >= 1900 && year <= 2100 && month >= 1 && month <= 12 && day >= 1 && day <= 31;
} 

// Convert a date string to a date object
int date_string_to_date_object(char *string, int *year, int *month, int *day) {
  char *parts[3];
  char *separator = NULL;
  int i = 0;
  int j = 0;
  
  // Split the date string into parts
  while (string[i] != '\0') {
    if (string[i] == DATE_SEPARATOR_HYPHEN || string[i] == DATE_SEPARATOR_SLASH || string[i] == DATE_SEPARATOR_DOT) {
      separator = string + i;
      parts[j++] = string;
      i++;
    } else {
      i++;
    }
  }
  parts[j] = separator + 1;

  // Check if the date string is valid
  if (!is_valid_date_format(string)) {
    return ERROR_INVALID_DATE_FORMAT;
  }
  if (!is_valid_date_separator(separator)) {
    return ERROR_INVALID_DATE_SEPARATOR;
  }
  if (!is_valid_date_value(parts[0]) || !is_valid_date_value(parts[1]) || !is_valid_date_value(parts[2])) {
    return ERROR_INVALID_DATE_VALUE;
  }

  // Convert the date parts to integers
  *year = string_to_int(parts[DATE_PART_YEAR]);
  *month = string_to_int(parts[DATE_PART_MONTH]);
  *day = string_to_int(parts[DATE_PART_DAY]);

  return 0;
}

// Convert a date object to a string
char *date_object_to_date_string(int year, int month, int day) {
  char *string = malloc(DATE_STRING_MAX_LENGTH);
  sprintf(string, "%04d-%02d-%02d", year, month, day);
  return string;
}

int main() {
  // Get the input date string
  char *date_string = malloc(DATE_STRING_MAX_LENGTH);
  printf("Enter the date string: ");
  scanf("%s", date_string);

  // Convert the date string to a date object
  int year, month, day;
  int error_code = date_string_to_date_object(date_string, &year, &month, &day);

  // Check if the date string is valid
  if (error_code != 0) {
    printf("Error: Invalid date string.\n");
    return error_code;
  }

  // Convert the date object to a string
  char *output_date_string = date_object_to_date_string(year, month, day);

  // Print the output date string
  printf("The date string is: %s\n", output_date_string);

  // Free the allocated memory
  free(date_string);
  free(output_date_string);

  return 0;
}
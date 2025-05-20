#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char date_buffer[50];
  printf("Enter a date (format: YYYY-MM-DD): ");
  scanf("%s", date_buffer);

  // Malicious input exceeding the buffer size
  date_buffer[49] = 'a';

  // Attempt to parse the date
  int year, month, day;
  sscanf(date_buffer, "%d-%d-%d", &year, &month, &day);

  // Display the parsed date
  printf("Year: %d, Month: %d, Day: %d", year, month, day);

  return 0;
}

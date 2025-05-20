//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to convert a given date from natural language to computer-understandable format
void convertDate(char* naturalDate) {
  char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

  // Initialize variables
  int day, year, month = -1;
  char monthName[10];

  // Find day and year
  sscanf(naturalDate, "%d, %d", &day, &year);

  // Parse month name
  sscanf(naturalDate, "%*[^ ] %s", monthName);

  // Look for month in array
  for (int i = 0; i < 12; i++) {
    if (strcmp(monthName, months[i]) == 0) {
      month = i + 1;
      break;
    }
  }

  // Print results
  if (month == -1) {
    printf("Error: Invalid month\n");
  }
  else {
    printf("Date in computer-understandable format: %02d/%02d/%d\n", month, day, year);
  }
}

// Main function
int main() {
  char naturalDate[20];
  
  // Get date from user
  printf("Enter date in natural language format (e.g. January 1, 2022): ");
  fgets(naturalDate, 20, stdin);

  // Remove newline character from input
  naturalDate[strcspn(naturalDate, "\n")] = 0;

  // Call function to convert date
  convertDate(naturalDate);

  return 0;
}
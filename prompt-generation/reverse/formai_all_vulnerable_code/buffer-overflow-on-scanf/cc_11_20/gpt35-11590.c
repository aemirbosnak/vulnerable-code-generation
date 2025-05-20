//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int destination_year, current_year, i;
  time_t current_time;
  struct tm* current_date;
  
  srand(time(0));
  
  printf("Welcome to the Time Travel Simulator!\n");
  
  // Get the current year and display it to the user
  current_time = time(NULL);
  current_date = localtime(&current_time);
  current_year = current_date->tm_year + 1900;
  printf("The current year is %d.\n", current_year);
  
  // Prompt the user to enter a destination year
  printf("What year would you like to travel to? ");
  scanf("%d", &destination_year);
  
  // Determine if the destination year is in the past or future
  if (destination_year < current_year)
  {
    printf("You want to travel back in time... this could be dangerous!\n");
  }
  else if (destination_year == current_year)
  {
    printf("You are already in the current year... there's nowhere to go!\n");
    return 0;
  }
  else
  {
    printf("You want to travel to the future... are you sure you're ready?\n");
  }
  
  printf("Preparing to travel through time...\n");
  
  // Simulate the time travel process
  for (i = 5; i >= 1; i--)
  {
    printf("%d...\n", i);
    sleep(1);
  }
  
  // Display the final destination year to the user
  printf("Welcome to the year %d!\n", destination_year);
  
  // Determine if the user made any historical mistakes
  if (destination_year < 1914)
  {
    printf("You have arrived before the start of World War I. Be careful not to get involved!\n");
  }
  else if (destination_year < 1939)
  {
    printf("You have arrived in the period between World War I and World War II. Stay alert!\n");
  }
  else if (destination_year < 1945)
  {
    printf("You have arrived during World War II. Keep your head down and stay out of trouble!\n");
  }
  else if (destination_year < 1969)
  {
    printf("You have arrived in the post-World War II era. Enjoy the prosperity!\n");
  }
  else if (destination_year < 1990)
  {
    printf("You have arrived during the Cold War. Be careful not to cause an international incident!\n");
  }
  else if (destination_year < 2001)
  {
    printf("You have arrived in the pre-9/11 era. Take advantage of the relative peace!\n");
  }
  else if (destination_year < 2021)
  {
    printf("You have arrived in the early 2000s. Enjoy the rise of technology, but watch out for the financial crisis!\n");
  }
  else
  {
    printf("You have arrived in the present day. Welcome to the future!\n");
  }
  
  return 0;
}
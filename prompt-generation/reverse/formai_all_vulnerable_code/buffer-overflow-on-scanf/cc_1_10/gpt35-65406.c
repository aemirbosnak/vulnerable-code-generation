//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // welcome message
  printf("Welcome to the Time Travel Simulator!\n\n");
  
  // get current time
  time_t now = time(NULL);
  struct tm current_time = *localtime(&now);
  
  // display current time
  printf("The current time is %02d:%02d:%02d on %02d/%02d/%04d\n\n", current_time.tm_hour, current_time.tm_min, current_time.tm_sec, current_time.tm_mday, current_time.tm_mon + 1, current_time.tm_year + 1900);
  
  // ask user for time travel destination
  char choice;
  printf("Where would you like to go? Please enter:\n");
  printf("a. The future\n");
  printf("b. The past\n");
  printf("c. Random time\n");
  printf("Your choice (a/b/c): ");
  scanf(" %c", &choice);
  
  // time travel based on user's choice
  switch (choice) {
    case 'a':
      {
        int years;
        printf("\nHow many years into the future would you like to travel? ");
        scanf("%d", &years);
        
        // calculate future year
        int future_year = current_time.tm_year + years;
        struct tm future_time = current_time;
        future_time.tm_year = future_year - 1900;
        mktime(&future_time);
        
        // display future time
        printf("\nYou have arrived in the future on %02d/%02d/%04d at %02d:%02d:%02d!\n\n", future_time.tm_mday, future_time.tm_mon + 1, future_time.tm_year + 1900, future_time.tm_hour, future_time.tm_min, future_time.tm_sec);
        break;
      }
      
    case 'b':
      {
        int years;
        printf("\nHow many years into the past would you like to travel? ");
        scanf("%d", &years);
        
        // calculate past year
        int past_year = current_time.tm_year - years;
        struct tm past_time = current_time;
        past_time.tm_year = past_year - 1900;
        mktime(&past_time);
        
        // display past time
        printf("\nYou have arrived in the past on %02d/%02d/%04d at %02d:%02d:%02d!\n\n", past_time.tm_mday, past_time.tm_mon + 1, past_time.tm_year + 1900, past_time.tm_hour, past_time.tm_min, past_time.tm_sec);
        break;
      }
      
    case 'c':
      {
        // generate random time
        struct tm random_time;
        random_time.tm_sec = rand() % 60;
        random_time.tm_min = rand() % 60;
        random_time.tm_hour = rand() % 24;
        random_time.tm_mday = rand() % 28 + 1;
        random_time.tm_mon = rand() % 12;
        random_time.tm_year = rand() % 201 + 1900;
        mktime(&random_time);
        
        // display random time
        printf("\nYou have arrived in a random time on %02d/%02d/%04d at %02d:%02d:%02d!\n\n", random_time.tm_mday, random_time.tm_mon + 1, random_time.tm_year, random_time.tm_hour, random_time.tm_min, random_time.tm_sec);
        break;
      }
      
    default:
      printf("\nInvalid choice! Please try again.\n\n");
      break;
  }
  
  // goodbye message
  printf("Thank you for using the Time Travel Simulator, have a great day!\n");
  
  return 0;
}
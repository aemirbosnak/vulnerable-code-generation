//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: paranoid
#include <stdio.h>
#include <time.h>

int main() {
  time_t currentTime;
  struct tm * dateTime;
  
  time(&currentTime);
  dateTime = gmtime(&currentTime);
  
  printf("You have entered a Time Travel Simulator program\n");
  printf("But remember, altering the past could result in catastrophic consequences.\n");
  printf("Do you wish to proceed? (Y/N)\n");
  
  char answer;
  scanf("%c", &answer);
  
  if (answer == 'Y') {
    printf("Please enter a year to time travel to:\n");
    int inputYear;
    scanf("%d", &inputYear);
    
    if (inputYear > dateTime->tm_year + 1900) {
      printf("You are attempting to travel to the future. Are you sure? (Y/N)\n");
      scanf(" %c", &answer);
      
      if (answer == 'Y') {
        printf("Calculating warp trajectory to year %d...\n", inputYear);
        
        for (int i = 0; i < 5; i++) {
          printf("WARNING: Chrono-distortion detected.\n");
          printf("Systems failing. Re-routing auxilliary power.\n");
        }
        
        printf("Destination reached. Welcome to the year %d.\n", inputYear);
      } else {
        printf("Exiting Time Travel Simulator.\n");
      }
    } else {
      printf("Calculating temporal shift to year %d...\n", inputYear);
      
      for (int i = 0; i < 3; i++) {
        printf("WARNING: Temporal stability predicted to be low.\n");
        printf("Engaging protective systems.\n");
      }
      
      printf("Shift complete. Greetings from the year %d.\n", inputYear);
    }
  } else {
    printf("Exiting Time Travel Simulator.\n");
  }
  
  return 0;
}
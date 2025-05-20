//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: intelligent
#include<stdio.h>
#include<string.h>

void alert(char *msg) {
  // Replace this with your desired alert system (email, text, etc.)
  printf("ALERT: %s\n", msg);
}

int main() {
  char userInput[256]; // buffer for user input
  int attempts = 0; // number of failed login attempts
  int maxAttempts = 3; // maximum allowed login attempts

  // security log
  FILE *securityLog;
  securityLog = fopen("security.log", "w");

  // loop to prompt for user input
  while(1) {
    printf("Enter your username and password:\n");
    fgets(userInput, 256, stdin);

    // check for null character (end of user input)
    if(userInput[strlen(userInput)-1] == '\n') {
      userInput[strlen(userInput)-1] = '\0'; // replace newline with null
    }

    // log user input
    fprintf(securityLog, "%s\n", userInput);

    // check for correct password
    if(strcmp(userInput, "admin:password123") == 0) {
      printf("Login successful!\n");
      break; // exit loop
    }
    else {
      attempts++;
      if(attempts == maxAttempts) {
        alert("Too many failed login attempts!");
        break; // exit loop
      }
      else {
        printf("Login failed. Please try again.\n");
      }
    }
  }

  // close security log
  fclose(securityLog);

  return 0;
}
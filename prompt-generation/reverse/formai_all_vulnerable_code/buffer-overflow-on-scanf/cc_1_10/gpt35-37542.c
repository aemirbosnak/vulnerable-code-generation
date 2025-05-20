//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Romeo and Juliet
/* Romeo and Juliet: An Intrusion Detection System */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function declarations */
void alert(char *message);
void log_event(char *event);

/* Constants */
#define MAX_FAILED_LOGINS 5

/* Global variables */
int failed_logins = 0;

int main() {

  char username[50], password[50];
  printf("Welcome to the Intrusion Detection System!\n");

  while (1) {
  
    /* Prompt user for username and password */
    printf("Please enter your username: ");
    scanf("%s", username);
    printf("Please enter your password: ");
    scanf("%s", password);
  
    /* Check if the credentials are correct */
    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
      log_event("User successfully logged in as admin.");
      printf("Welcome, admin!\n");
      
      /* Reset failed login attempts count */
      failed_logins = 0;
      break;
    }
    else {
      /* Increment the failed login attempts count */
      failed_logins++;
      if (failed_logins >= MAX_FAILED_LOGINS) {
        char message[100];
        sprintf(message, "ALERT: Maximum failed login attempts (%d) reached!", MAX_FAILED_LOGINS);
        alert(message);
        break;
      }
      else {
        char message[100];
        sprintf(message, "Invalid login attempt with username: %s, password: %s", username, password);
        log_event(message);
        printf("Invalid username or password. Please try again.\n");
      }
    }
  }
  
  return 0;
}

void alert(char *message) {
  printf("ALERT! %s\n", message);
}

void log_event(char *event) {
  printf("LOG: %s\n", event);
}
//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of intrusion attempts we're willing to tolerate
#define MAX_INTRUSION_ATTEMPTS 5

// Define the maximum number of characters in a username
#define MAX_USERNAME_LEN 32

// Define the maximum number of characters in a password
#define MAX_PASSWORD_LEN 32

// Define the number of seconds until the intrusion counter is reset
#define RESET_INTERVAL 600

// Define the file where we'll log intrusion attempts
#define LOG_FILE "intrusion_log.txt"

// Function to check if a username and password are valid
int check_credentials(char *username, char *password) {
  // Check if the username and password are empty
  if (strlen(username) == 0 || strlen(password) == 0) {
    return 0;
  }

  // Check if the username and password are too long
  if (strlen(username) > MAX_USERNAME_LEN || strlen(password) > MAX_PASSWORD_LEN) {
    return 0;
  }

  // Check if the username and password contain any invalid characters
  for (int i = 0; i < strlen(username); i++) {
    if (!isalnum(username[i])) {
      return 0;
    }
  }
  for (int i = 0; i < strlen(password); i++) {
    if (!isalnum(password[i])) {
      return 0;
    }
  }

  // Check if the username and password are correct
  if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
    return 1;
  }

  return 0;
}

// Function to log an intrusion attempt
void log_intrusion_attempt(char *username, char *password, time_t timestamp) {
  // Open the log file
  FILE *fp = fopen(LOG_FILE, "a");
  if (fp == NULL) {
    return;
  }

  // Write the intrusion attempt to the log file
  fprintf(fp, "%s %s %ld\n", username, password, timestamp);

  // Close the log file
  fclose(fp);
}

// Function to reset the intrusion counter
void reset_intrusion_counter() {
  // Open the log file
  FILE *fp = fopen(LOG_FILE, "w");
  if (fp == NULL) {
    return;
  }

  // Write the empty log file
  fprintf(fp, "");

  // Close the log file
  fclose(fp);
}

// Main function
int main() {
  // Initialize the intrusion counter
  int intrusion_counter = 0;

  // Initialize the last intrusion timestamp
  time_t last_intrusion_timestamp = 0;

  // Get the current time
  time_t current_time = time(NULL);

  // Loop until the user enters the correct username and password
  while (1) {
    // Prompt the user for their username
    printf("Enter your username: ");
    char username[MAX_USERNAME_LEN + 1];
    scanf("%s", username);

    // Prompt the user for their password
    printf("Enter your password: ");
    char password[MAX_PASSWORD_LEN + 1];
    scanf("%s", password);

    // Check if the username and password are valid
    if (check_credentials(username, password)) {
      // The user entered the correct username and password, so reset the intrusion counter and the last intrusion timestamp
      intrusion_counter = 0;
      last_intrusion_timestamp = 0;

      // Print a welcome message
      printf("Welcome, %s!\n", username);

      // Exit the loop
      break;
    } else {
      // The user entered the incorrect username and password, so increment the intrusion counter and log the intrusion attempt
      intrusion_counter++;
      log_intrusion_attempt(username, password, current_time);

      // Check if the intrusion counter has exceeded the maximum number of allowed attempts
      if (intrusion_counter >= MAX_INTRUSION_ATTEMPTS) {
        // The user has exceeded the maximum number of allowed attempts, so reset the intrusion counter and the last intrusion timestamp
        intrusion_counter = 0;
        last_intrusion_timestamp = 0;

        // Print a warning message
        printf("Warning: You have exceeded the maximum number of allowed intrusion attempts.\n");
      } else {
        // The user has not yet exceeded the maximum number of allowed attempts, so print a warning message
        printf("Warning: You have %d intrusion attempts remaining.\n", MAX_INTRUSION_ATTEMPTS - intrusion_counter);
      }
    }

    // Check if the last intrusion attempt was within the last RESET_INTERVAL seconds
    if (current_time - last_intrusion_timestamp > RESET_INTERVAL) {
      // The last intrusion attempt was more than RESET_INTERVAL seconds ago, so reset the intrusion counter and the last intrusion timestamp
      intrusion_counter = 0;
      last_intrusion_timestamp = 0;
    }

    // Get the current time
    current_time = time(NULL);
  }

  return 0;
}
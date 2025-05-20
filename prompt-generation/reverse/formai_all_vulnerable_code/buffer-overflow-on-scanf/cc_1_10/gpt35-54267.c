//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Welcome User!
  printf("Welcome to the Intrusion Detection System!\n");
  
  // Declare Variables
  char* username = (char*) malloc(20);
  char* password = (char*) malloc(20);
  
  // Prompt for Username
  printf("Please enter your username: ");
  scanf("%s", username);
  
  // Prompt for Password
  printf("Please enter your password: ");
  scanf("%s", password);
  
  // Check Credentials
  if(strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0) {
    printf("Success! You are now logged in.\n");
  }
  else {
    printf("Username or Password is incorrect. Please try again.\n");
    return 1;
  }
  
  // Declare More Variables
  char* log = (char*) malloc(50);
  char* ip = (char*) malloc(20);
  char* date = (char*) malloc(20);
  char* time = (char*) malloc(20);
  char* action = (char*) malloc(20);
  
  // Enter Log Data
  printf("Please enter the Log IP Address: ");
  scanf("%s", ip);
  printf("Please enter the Log Date (MM/DD/YYYY): ");
  scanf("%s", date);
  printf("Please enter the Log Time (HH:MM:SS): ");
  scanf("%s", time);
  printf("Please enter the Log Action: ");
  scanf("%s", action);
  
  // Display Log Data
  sprintf(log, "IP: %s\nDate: %s\nTime: %s\nAction: %s\n", ip, date, time, action);
  printf("Log Entry:\n%s", log);
  
  // Notify User of Intrusion
  printf("An Intrusion has been detected!\n");
  
  // Free Memory
  free(username);
  free(password);
  free(log);
  free(ip);
  free(date);
  free(time);
  free(action);
  
  return 0;
}
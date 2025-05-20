#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char message[100];
  int advertising_count = 0, winning_count = 0, watches_count = 0, free_count = 0;

  printf("Enter a message: ");
  gets(message);

  // Analyze the message for specific spam keywords
  if (strstr(message, "advertising") != NULL) {
    advertising_count++;
  }
  if (strstr(message, "winning") != NULL) {
    winning_count++;
  }
  if (strstr(message, "watches") != NULL) {
    watches_count++;
  }
  if (strstr(message, "free") != NULL) {
    free_count++;
  }

  // Output a warning if any keywords are found
  if (advertising_count > 0) {
    printf("Warning: Advertising keyword found.\n");
  }
  if (winning_count > 0) {
    printf("Warning: Winning keyword found.\n");
  }
  if (watches_count > 0) {
    printf("Warning: Watches keyword found.\n");
  }
  if (free_count > 0) {
    printf("Warning: Free keyword found.\n");
  }

  return 0;
}

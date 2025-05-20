//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIGNAL_STRENGTH 100

void scan_wifi_signal_strength() {
  int signal_strength = rand() % MAX_SIGNAL_STRENGTH;

  printf("\nScanning WiFi signal strength...\n");
  printf("Signal Strength: %d%%\n", signal_strength);
}

void display_menu() {
  printf("\n====== WiFi Analyzer ======\n\n");
  printf("1. Scan Signal Strength\n");
  printf("2. Exit\n");
  printf("\nEnter your choice (1-2): ");
}

int main() {
  int choice;

  srand(time(NULL));

  printf("Welcome to WiFi Analyzer!\n");

  while (1) {
    display_menu();

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        scan_wifi_signal_strength();
        break;
      case 2:
        printf("\nGoodbye!\n");
        exit(0);
      default:
        printf("\nInvalid choice! Please enter a number between 1 and 2.\n");
        break;
    }

    // Sleep for 2 seconds before displaying menu again
    sleep(2);
  }

  return 0;
}
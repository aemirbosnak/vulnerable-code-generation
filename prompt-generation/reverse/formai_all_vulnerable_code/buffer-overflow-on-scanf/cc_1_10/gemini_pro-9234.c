//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Colors for the CLI
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

// Function to get the signal strength of a Wi-Fi network
int getSignalStrength(char *interface, char *ssid) {
  // Open the file containing the Wi-Fi information
  FILE *fp = fopen("/proc/net/wireless", "r");
  if (fp == NULL) {
    perror("fopen");
    return -1;
  }

  // Skip the header line
  char line[256];
  fgets(line, sizeof(line), fp);

  // Read the Wi-Fi information line by line
  while (fgets(line, sizeof(line), fp)) {
    // Check if the line contains the specified interface and SSID
    if (strstr(line, interface) != NULL && strstr(line, ssid) != NULL) {
      // Extract the signal strength from the line
      char *ptr = strstr(line, "signal:");
      if (ptr != NULL) {
        ptr += strlen("signal:");
        while (*ptr == ' ') ptr++;
        return atoi(ptr);
      }
    }
  }

  // Signal strength not found
  return -1;
}

int main() {
  // Get the interface name and SSID from the user
  char interface[32];
  char ssid[32];
  printf("Enter the interface name: ");
  scanf("%s", interface);
  printf("Enter the SSID: ");
  scanf("%s", ssid);

  // Get the signal strength
  int signalStrength = getSignalStrength(interface, ssid);

  // Print the signal strength
  if (signalStrength < -100) {
    printf(RED "Signal strength: Very Weak\n" RESET);
  } else if (signalStrength < -80) {
    printf(RED "Signal strength: Weak\n" RESET);
  } else if (signalStrength < -60) {
    printf(YELLOW "Signal strength: Fair\n" RESET);
  } else if (signalStrength < -40) {
    printf(YELLOW "Signal strength: Good\n" RESET);
  } else {
    printf(GREEN "Signal strength: Excellent\n" RESET);
  }

  return 0;
}
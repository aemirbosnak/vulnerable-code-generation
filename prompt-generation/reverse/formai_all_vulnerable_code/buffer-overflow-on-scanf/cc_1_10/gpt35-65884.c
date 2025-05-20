//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DEVICES 50
#define MIN_STRENGTH 5

int main() {
  int i, n;
  int strength[MAX_DEVICES];
  bool connected[MAX_DEVICES];

  printf("Enter the number of devices to analyze: ");
  scanf("%d", &n);

  if (n < 1 || n > MAX_DEVICES) {
    printf("Invalid number of devices. Please try again.");
    exit(0);
  }

  printf("\n");

  for (i = 0; i < n; i++) {
    printf("Enter the signal strength (0-100%%) of device %d: ", i + 1);
    scanf("%d", &strength[i]);

    if (strength[i] < 0 || strength[i] > 100) {
      printf("Invalid strength value. Please try again.");
      i--;
    }
    else {
      connected[i] = strength[i] >= MIN_STRENGTH;
    }

    printf("\n");
  }

  printf("==============================\n");
  printf("Device No.\tSignal Strength\tConnection Status\n");
  printf("==============================\n");

  for (i = 0; i < n; i++) {
    printf("%d\t\t%d%%\t\t", i + 1, strength[i]);

    if (connected[i]) {
      printf("Connected\n");
    }
    else {
      printf("Disconnected\n");
    }
  }

  printf("==============================\n");

  return 0;
}
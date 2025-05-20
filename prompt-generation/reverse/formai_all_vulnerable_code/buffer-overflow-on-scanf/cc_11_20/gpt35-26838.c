//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>

void main() {
  int strength, quality;
  
  printf("Enter Wi-Fi signal strength (in dBm): ");
  
  scanf("%d", &strength);

  if (strength <= -90) {
    quality = 0;
  } else if (strength <= -80) {
    quality = 1;
  } else if (strength <= -70) {
    quality = 2;
  } else if (strength <= -60) {
    quality = 3;
  } else if (strength <= -50) {
    quality = 4;
  } else if (strength > -50) {
    quality = 5;
  } 

  printf("The Wi-Fi signal strength is %d dBm which means the signal quality is ", strength);
  
  switch (quality) {
    case 0:
      printf("poor.\n");
      break;
    case 1:
      printf("fair.\n");
      break;
    case 2:
      printf("good.\n");
      break;
    case 3:
      printf("very good.\n");
      break;
    case 4:
      printf("excellent.\n");
      break;
    case 5:
      printf("outstanding!\n");
      break;
    default:
      printf("invalid.\n");
      break;
  }
}
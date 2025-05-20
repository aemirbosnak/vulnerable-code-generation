//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int quality;
  printf("Welcome to the Network Quality of Service (QoS) monitor!\n");
  usleep(2000000); // delay for dramatic effect
  printf("The surrealistic journey begins...\n");
  usleep(2500000); // delay for dramatic effect
  printf("Please enter a quality score (between 0-10): ");
  scanf("%d", &quality);
  printf("You entered: %d\n", quality);
  usleep(2000000); // delay for dramatic effect
  
  if (quality < 0 || quality > 10) {
    printf("Invalid quality score. Exiting program...\n");
    exit(0);
  }
  
  printf("Initiating QoS monitoring...\n");
  usleep(2500000); // delay for dramatic effect
  
  printf("Monitoring network traffic...\n");
  usleep(3000000); // delay for dramatic effect
  
  printf("Analyzing network performance...\n");
  usleep(3500000); // delay for dramatic effect
  
  printf("Calculating QoS score...\n");
  usleep(4000000); // delay for dramatic effect
  
  double score = quality * 0.1;
  printf("QoS score: %f\n", score);
  usleep(2000000); // delay for dramatic effect
  
  if (score >= 0.8) {
    printf("Excellent network performance!\n");
  } else if (score >= 0.6) {
    printf("Good network performance!\n");
  } else if (score >= 0.4) {
    printf("Fair network performance...\n");
  } else {
    printf("Poor network performance. Consider upgrading your network...\n");
  }
  usleep(2000000); // delay for dramatic effect
  
  printf("Thank you for using the surrealistic Network Quality of Service (QoS) monitor!\n");
  usleep(3000000); // delay for dramatic effect
  return 0;
}
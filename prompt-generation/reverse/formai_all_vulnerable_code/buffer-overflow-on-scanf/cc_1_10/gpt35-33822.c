//FormAI DATASET v1.0 Category: Smart home automation ; Style: irregular
#include <stdio.h>

int main() {
  printf("Welcome to your customized Smart Home!\n");
  printf("Please input today's high temperature in Fahrenheit: ");
  float temperature;
  scanf("%f", &temperature);

  if (temperature > 80) {
    printf("It's going to be a hot day! Turning on air conditioning...\n");
  } else if (temperature < 60) {
    printf("It's a bit chilly today! Turning on the heater...\n");
  } else {
    printf("The temperature is just right today! No need for temperature control...\n");
  }

  printf("Please specify the time for your lights to turn on in 24-hour format (e.g. 16:30): ");
  char lightTime[6];
  scanf("%s", lightTime);

  printf("Setting your lights to turn on at %s...\n", lightTime);

  printf("Please input any mood you'd like to set for tonight (e.g. 'romantic', 'movie', 'party'): ");
  char moodType[10];
  scanf("%s", moodType);

  if (strcmp(moodType, "romantic") == 0) {
    printf("Set the mood to 'romantic' with dimmed lighting and soft music...\n");
  } else if (strcmp(moodType, "movie") == 0) {
    printf("Set the mood to 'movie' with dimmed lighting and full volume sound...\n");
  } else if (strcmp(moodType, "party") == 0) {
    printf("Set the mood to 'party' with flashing lights and loud music...\n");
  } else {
    printf("Sorry, the mood '%s' is not recognized...\n", moodType);
  }

  printf("Please input your desired security level (1-3 where 1 is low and 3 is high): ");
  int securityLevel;
  scanf("%d", &securityLevel);

  if (securityLevel == 1) {
    printf("Set security level to 'low' with only door and window sensors enabled...\n");
  } else if (securityLevel == 2) {
    printf("Set security level to 'medium' with door, window, and motion sensors enabled...\n");
  } else if (securityLevel == 3) {
    printf("Set security level to 'high' with door, window, motion sensors enabled, and security camera surveillance...\n");
  } else {
    printf("Sorry, the security level '%d' is not recognized...\n", securityLevel);
  }

  printf("Thank you for using our Smart Home system!\n");

  return 0;
}
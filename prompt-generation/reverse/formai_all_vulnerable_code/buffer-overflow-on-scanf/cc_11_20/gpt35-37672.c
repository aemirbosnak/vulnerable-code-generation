//FormAI DATASET v1.0 Category: Smart home automation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  int lights, ac, tv, fp, temp;
  int time;
  printf("Welcome to the wackiest smart home automation system!\n");
  printf("How many lights do you want to control today? ");
  scanf("%d", &lights);
  printf("How many air conditioners do you want to control? ");
  scanf("%d", &ac);
  printf("How many TVs do you want to control? ");
  scanf("%d", &tv);
  printf("How many fans and projectors do you want to control? ");
  scanf("%d", &fp);

  printf("Enter the room temperature: ");
  scanf("%d", &temp);

  if (temp > 30) {
    printf("The room temperature is too hot. Turning on all %d air conditioners...\n", ac);
    for (int i = 0; i < ac; i++) {
      printf("Air conditioner %d turned on.\n", i+1);
    }
  } else {
    printf("The room temperature is perfect. No need for air conditioning.\n");
  }

  printf("What time is it now (in 24-hour format)? ");
  scanf("%d", &time);

  if (time >= 0 && time <= 6) {
    printf("It's pretty late. Turning off all %d lights...\n", lights);
    for (int i = 0; i < lights; i++) {
      printf("Light %d turned off.\n", i+1);
    }
  } else if (time >= 6 && time <= 12) {
    printf("Good morning! Turning on %d lights...\n", lights);
    for (int i = 0; i < lights; i++) {
      printf("Light %d turned on.\n", i+1);
    }
  } else if (time >= 12 && time <= 18) {
    printf("Good afternoon! Turning on %d lights and TV...\n", lights);
    for (int i = 0; i < lights; i++) {
      printf("Light %d turned on.\n", i+1);
    }
    for (int i = 0; i < tv; i++) {
      printf("TV %d turned on.\n", i+1);
    }
  } else if (time >= 18 && time <= 24) {
    printf("Good evening! Turning on %d lights, TV, and %d fans/projectors...\n", lights, fp);
    for (int i = 0; i < lights; i++) {
      printf("Light %d turned on.\n", i+1);
    }
    for (int i = 0; i < tv; i++) {
      printf("TV %d turned on.\n", i+1);
    }
    for (int i = 0; i < fp; i++) {
      printf("Fan/Projector %d turned on.\n", i+1);
    }
  } else {
    printf("Invalid time input.\n");
    exit(0);
  }

  printf("Thanks for choosing our wacky smart home automation system!\n");
  return 0;
}
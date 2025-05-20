//LLAMA2-13B DATASET v1.0 Category: Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100
#define MAGIC_NUMBER 42

int main() {
  char name[MAX_LENGTH];
  int age;
  int height;
  float weight;
  int happy = 0;

  // Ask the user for their name, age, height, and weight
  printf("Hello there! My name is %s, and I'm here to bring you joy! \n", name);
  printf("What's your name? ");
  scanf("%s", name);
  printf("And how old are you? ");
  scanf("%d", &age);
  printf("How tall are you? ");
  scanf("%d", &height);
  printf("And how much do you weigh? ");
  scanf("%f", &weight);

  // Calculate the BMI (Body Mass Index)
  weight /= (height * height);
  weight /= 100;

  // Check if the user is within the healthy weight range
  if (weight >= 18.5 && weight <= 24.9) {
    happy = 1;
    printf("You're within the healthy weight range! Congratulations! \n");
  } else if (weight > 24.9 && weight < 29.9) {
    happy = 2;
    printf("You're a little overweight, but still within the healthy range! Keep it up! \n");
  } else if (weight >= 30 && weight < 39.9) {
    happy = 3;
    printf("You're obese, but don't worry! You can still be healthy and happy! \n");
  } else {
    happy = 4;
    printf("You're morbidly obese, but that's okay! You're still a beautiful person inside and out! \n");
  }

  // Print out a funny and happy message based on the user's BMI
  switch (happy) {
    case 1:
      printf("You're a healthy and happy bunny! Keep up the good work! \n");
      break;
    case 2:
      printf("You're a little chubby, but who cares? You're still adorable! \n");
      break;
    case 3:
      printf("You're a big ol' bear! But don't worry, you're still cuddly and lovable! \n");
      break;
    case 4:
      printf("You're a giant, fluffy sloth! And that's totally awesome! \n");
      break;
    default:
      printf("I don't know what to say... Maybe try eating more veggies and exercising? Just kidding! You're perfect just the way you are! \n");
      break;
  }

  // Print out a happy message with the user's name and age
  printf("Hello, %s! You're %d years young today! \n", name, age);

  // Print out a funny and happy message with the user's height and weight
  printf("You're %d cm tall and weigh %f kg. That's like, totally average! \n", height, weight);

  // Print out a funny and happy message with the user's BMI and height
  printf("Your BMI is %f, which is like, totally normal for someone who's %d cm tall! \n", weight / (height * height), height);

  // Print out a happy and funny message with the user's name, age, and BMI
  printf("You're %s, %d years old, and have a BMI of %f. That's like, totally amazing! \n", name, age, weight / (height * height));

  return 0;
}
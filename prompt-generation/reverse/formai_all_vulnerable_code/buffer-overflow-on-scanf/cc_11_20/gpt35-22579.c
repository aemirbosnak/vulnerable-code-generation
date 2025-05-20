//FormAI DATASET v1.0 Category: Data validation ; Style: surprised
#include <stdio.h>

int main() {
  printf("Welcome to the Data Validation Program!\n");

  float number;
  printf("Please enter a float number: ");
  scanf("%f", &number);

  if (number >= 0) {
    if (number <= 100) {
      printf("The number %.2f is valid!\n", number);
    } else {
      printf("Oh my goodness! The number %.2f is too big!\n", number);
    }
  } else {
    printf("Holy guacamole! The number %.2f is too small!\n", number);
  }

  int age;
  printf("Please enter an integer age: ");
  scanf("%d", &age);

  if (age >= 18) {
    printf("Congratulations! You are old enough to vote.\n");
  } else {
    printf("Yikes! You are not old enough to vote.\n");
  }

  char letter;
  printf("Please enter a lowercase letter: ");
  scanf(" %c", &letter); // notice the space before %c to consume any leading white space

  if (letter >= 'a' && letter <= 'z') {
    printf("Great! The letter %c is lowercase.\n", letter);
  } else {
    printf("Say what?! The letter %c is not lowercase!\n", letter);
  }

  int number2;
  printf("Please enter an integer between 1 and 10: ");
  scanf("%d", &number2);

  switch(number2) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
      printf("Wow! The number %d is between 1 and 10.\n", number2);
      break;
    default:
      printf("Oh no! The number %d is not between 1 and 10.\n", number2);
  }

  printf("Thank you for using the Data Validation Program!\n");

  return 0;
}
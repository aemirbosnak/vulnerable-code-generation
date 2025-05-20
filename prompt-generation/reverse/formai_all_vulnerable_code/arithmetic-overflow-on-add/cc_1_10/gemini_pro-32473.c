//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A grand adventure awaits you, young traveler! Let us embark on a mystical journey through the treacherous realm of numbers.

int main()
{
  // First, we summon a mystical force to guide our path - the random number generator.
  srand(time(NULL));

  // Now, let us create a mystical realm of numbers, filled with both positive and negative forces.
  int realm[100];
  for (int i = 0; i < 100; i++)
    realm[i] = rand() % 201 - 100;

  // As we traverse this realm, we shall encounter a wise old sage who possesses the power of arithmetic.
  printf("Greetings, young traveler! May I offer you some wisdom from my mystical tome of arithmetic?\n");

  // The sage greets us with a series of riddles, testing our knowledge of addition and subtraction.
  int answer;
  printf("First riddle: What is the sum of the first and last numbers in our realm?\n");
  scanf("%d", &answer);
  if (answer == realm[0] + realm[99])
    printf("Well done, young traveler! Your arithmetic prowess is commendable.\n");
  else
    printf("Alas, young traveler, your answer is incorrect. The sum is %d.\n", realm[0] + realm[99]);

  printf("Second riddle: What is the difference between the largest and smallest numbers in our realm?\n");
  scanf("%d", &answer);
  if (answer == realm[99] - realm[0])
    printf("Well done, young traveler! Your understanding of subtraction is impeccable.\n");
  else
    printf("Alas, young traveler, your answer is incorrect. The difference is %d.\n", realm[99] - realm[0]);

  // As we marvel at the sage's wisdom, we realize that we have neglected our own magical abilities.
  printf("Now, young traveler, it is time for you to demonstrate your own arithmetic powers.\n");

  // The sage challenges us to manipulate the numbers within the realm using our newfound understanding.
  int num1, num2;
  printf("First challenge: Add two numbers of your choice from our realm.\n");
  scanf("%d %d", &num1, &num2);
  printf("The sum of %d and %d is %d.\n", num1, num2, num1 + num2);

  printf("Second challenge: Subtract one number from another number of your choice from our realm.\n");
  scanf("%d %d", &num1, &num2);
  printf("The difference between %d and %d is %d.\n", num1, num2, num1 - num2);

  // As we bid farewell to the sage, we reflect on the lessons we have learned and the adventures that lie ahead.
  printf("Thank you, wise sage, for sharing your wisdom with me. I shall forever cherish the lessons I have learned here.\n");
  printf("Now, young traveler, your journey continues. May your path be filled with both wonder and enlightenment.\n");

  return 0;
}
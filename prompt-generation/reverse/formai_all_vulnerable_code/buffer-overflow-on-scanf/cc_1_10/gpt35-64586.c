//FormAI DATASET v1.0 Category: Math exercise ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // random number generator based on current time
  srand((unsigned int) time(NULL));

  // randomly select two shapes from list
  char* shapes[] = {"circle", "square", "rectangle", "triangle"};
  int shape1_index = rand() % 4;
  int shape2_index = rand() % 4;
  char* shape1 = shapes[shape1_index];
  char* shape2 = shapes[shape2_index];

  // generate unique math exercise based on shapes
  int result;
  if (shape1_index == 0) {  // circle
    int radius = rand() % 10 + 1;
    printf("Calculate the circumference of a %s with radius %d.\n", shape1, radius);
    result = 2 * 3.14 * radius;
  } else if (shape1_index == 1) {  // square
    int side = rand() % 10 + 1;
    printf("Calculate the area of a %s with side length %d.\n", shape1, side);
    result = side * side;
  } else if (shape1_index == 2) {  // rectangle
    int length = rand() % 10 + 1;
    int width = rand() % 10 + 1;
    printf("Calculate the perimeter of a %s with length %d and width %d.\n", shape1, length, width);
    result = 2 * (length + width);
  } else {  // triangle
    int base = rand() % 10 + 1;
    int height = rand() % 10 + 1;
    printf("Calculate the area of a %s with base %d and height %d.\n", shape1, base, height);
    result = base * height;
  }

  // ask user to solve math exercise
  int user_answer;
  printf("Type your answer here: ");
  scanf("%d", &user_answer);

  // check if user answer is correct
  if (user_answer == result) {
    printf("Congratulations! Your answer is correct.\n");
  } else {
    printf("Sorry, your answer is incorrect. The correct answer is %d.\n", result);
  }

  // shape shifting message to spice things up
  printf("Now let's switch things up and do a math exercise about a %s.\n", shape2);

  // generate new unique math exercise based on new shape
  if (shape2_index == 0) {  // circle
    int radius = rand() % 10 + 1;
    printf("Calculate the area of a %s with radius %d.\n", shape2, radius);
    result = 3.14 * radius * radius;
  } else if (shape2_index == 1) {  // square
    int side = rand() % 10 + 1;
    printf("Calculate the perimeter of a %s with side length %d.\n", shape2, side);
    result = 4 * side;
  } else if (shape2_index == 2) {  // rectangle
    int length = rand() % 10 + 1;
    int width = rand() % 10 + 1;
    printf("Calculate the area of a %s with length %d and width %d.\n", shape2, length, width);
    result = length * width;
  } else {  // triangle
    int base = rand() % 10 + 1;
    int height = rand() % 10 + 1;
    printf("Calculate the hypotenuse of a %s with base %d and height %d.\n", shape2, base, height);
    result = sqrt(base * base + height * height);
  }

  // ask user to solve math exercise
  printf("Type your answer here: ");
  scanf("%d", &user_answer);

  // check if user answer is correct
  if (user_answer == result) {
    printf("Congratulations! Your answer is correct.\n");
  } else {
    printf("Sorry, your answer is incorrect. The correct answer is %d.\n", result);
  }

  return 0;
}
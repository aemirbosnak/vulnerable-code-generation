//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num_questions = 10; // number of questions in the quiz
  int score = 0; // user's score
  int i;
  char answer[3]; // user's answer (up to 2 characters)
  char correct_answer[3]; // correct answer (up to 2 characters)

  // seed the random number generator with the current time
  srand(time(NULL));

  // ask the user how many questions they want in the quiz
  printf("How many questions do you want in the quiz? ");
  scanf("%d", &num_questions);

  // loop through the quiz questions
  for (i = 0; i < num_questions; i++) {
    // generate a random element symbol
    int element_num = rand() % 118;
    char element_symbol[3] = { 'A', 'a' + element_num, '\0' };

    // generate a random property of the element
    int property_num = rand() % 4;
    char property_str[50];
    switch (property_num) {
      case 0:
        sprintf(property_str, "Atomic number: %d", element_num + 1);
        break;
      case 1:
        sprintf(property_str, "Atomic weight: %.2f", (float) element_num / 10.0);
        break;
      case 2:
        sprintf(property_str, "Element category: %c-block", 'A' + (element_num / 10) % 8);
        break;
      case 3:
        sprintf(property_str, "Electron configuration: %s", "unknown");
        break;
    }

    // ask the user the question
    printf("Question %d: What is the %s of %s? ", i+1, property_str, element_symbol);
    scanf("%s", answer);

    // check if the user's answer is correct
    if (strcmp(answer, property_str) == 0) {
      printf("Correct!\n");
      score++;
    } else {
      printf("Incorrect. The correct answer is %s.\n", property_str);
    }
  }

  // print the user's score
  printf("You got %d out of %d questions correct.\n", score, num_questions);

  return 0;
}
//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));      // seed random number generator
  
  int correct = 0;     // number of correct answers
  int incorrect = 0;   // number of incorrect answers
  int question_num = 1;  // initialize the question number
  
  printf("Welcome to the C Periodic Table Quiz!\n");
  printf("You will be given 10 questions to answer. Good luck!\n\n");

  while (question_num <= 10) {   // loop through 10 questions
    
    int element_num = rand() % 118 + 1;   // generate random element number
    char element[3];   // initialize array to store element symbol
    
    // assign the element symbol based on its atomic number
    switch(element_num) {
      case 1:
        sprintf(element, "H");
        break;
      case 2:
        sprintf(element, "He");
        break;
      case 3:
        sprintf(element, "Li");
        break;
      case 4:
        sprintf(element, "Be");
        break;
      case 5:
        sprintf(element, "B");
        break;
      case 6:
        sprintf(element, "C");
        break;
      case 7:
        sprintf(element, "N");
        break;
      case 8:
        sprintf(element, "O");
        break;
      case 9:
        sprintf(element, "F");
        break;
      case 10:
        sprintf(element, "Ne");
        break;
      case 11:
        sprintf(element, "Na");
        break;
      case 12:
        sprintf(element, "Mg");
        break;
      // continue for each element up to atomic number 118
    }
    
    printf("Question %d: What is the atomic number of %s?\n", question_num, element);
    int answer;  // initialize variable for user's answer
    scanf("%d", &answer);  // get user's answer
    
    if (answer == element_num) {
      printf("Correct!\n");
      correct++;
    } else {
      printf("Incorrect. The correct answer is %d.\n", element_num);
      incorrect++;
    }
    
    question_num++;   // increment question number
  }
  
  printf("\nQuiz complete!\n");
  printf("You got %d questions correct and %d questions incorrect.\n", correct, incorrect);
  
  return 0;
}
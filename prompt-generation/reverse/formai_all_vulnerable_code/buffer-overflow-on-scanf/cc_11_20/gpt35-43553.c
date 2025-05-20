//FormAI DATASET v1.0 Category: Online Examination System ; Style: excited
#include <stdio.h>

int main() {
  printf("Welcome to the Online Examination System!\n");
  printf("Please enter your name: ");

  char name[50];
  scanf("%s", name);
  
  printf("\nHi, %s! Let's get started.\n", name);
  printf("You will be given 10 questions to answer.\n");
  printf("Each correct answer is worth 10 points.\n");
  printf("Press enter to begin the exam.\n");
  
  char start;
  scanf("%c", &start); // clear the input buffer
  scanf("%c", &start); // wait for enter key
  
  int score = 0;
  
  // Question 1
  printf("\nQuestion 1: 1 + 1 = ?\n");
  printf("A. 1\t B. 2\t C. 3\t D. 4\n");
  
  char answer;
  scanf("%c", &answer); // clear the input buffer
  scanf("%c", &answer); // read answer from user
  
  if (answer == 'B') {
    printf("Correct answer! You get 10 points.\n");
    score += 10;
  } else {
    printf("Sorry, that's the wrong answer. The correct answer is B.\n");
  }
  
  // Question 2
  printf("\nQuestion 2: What is the capital of Canada?\n");
  printf("A. Toronto\t B. Vancouver\t C. Ottawa\t D. Montreal\n");
  
  scanf("%c", &answer); // clear the input buffer
  scanf("%c", &answer); // read answer from user
  
  if (answer == 'C') {
    printf("Correct answer! You get 10 points.\n");
    score += 10;
  } else {
    printf("Sorry, that's the wrong answer. The correct answer is C.\n");
  }
  
  // Question 3
  printf("\nQuestion 3: Who is the CEO of Tesla?\n");
  printf("A. Steve Jobs\t B. Jeff Bezos\t C. Elon Musk\t D. Mark Zuckerberg\n");
  
  scanf("%c", &answer); // clear the input buffer
  scanf("%c", &answer); // read answer from user
  
  if (answer == 'C') {
    printf("Correct answer! You get 10 points.\n");
    score += 10;
  } else {
    printf("Sorry, that's the wrong answer. The correct answer is C.\n");
  }
  
  // Question 4
  printf("\nQuestion 4: What is the main component of sand?\n");
  printf("A. Silica\t B. Carbon\t C. Calcium\t D. Iron\n");
  
  scanf("%c", &answer); // clear the input buffer
  scanf("%c", &answer); // read answer from user
  
  if (answer == 'A') {
    printf("Correct answer! You get 10 points.\n");
    score += 10;
  } else {
    printf("Sorry, that's the wrong answer. The correct answer is A.\n");
  }
  
  // Question 5
  printf("\nQuestion 5: Which year did World War II end?\n");
  printf("A. 1943\t B. 1945\t C. 1947\t D. 1950\n");
  
  scanf("%c", &answer); // clear the input buffer
  scanf("%c", &answer); // read answer from user
  
  if (answer == 'B') {
    printf("Correct answer! You get 10 points.\n");
    score += 10;
  } else {
    printf("Sorry, that's the wrong answer. The correct answer is B.\n");
  }
  
  // Question 6
  printf("\nQuestion 6: Who is the author of the Harry Potter series?\n");
  printf("A. Stephenie Meyer\t B. J.K. Rowling\t C. George R.R. Martin\t D. Suzanne Collins\n");
  
  scanf("%c", &answer); // clear the input buffer
  scanf("%c", &answer); // read answer from user
  
  if (answer == 'B') {
    printf("Correct answer! You get 10 points.\n");
    score += 10;
  } else {
    printf("Sorry, that's the wrong answer. The correct answer is B.\n");
  }
  
  // Question 7
  printf("\nQuestion 7: What is the largest planet in our solar system?\n");
  printf("A. Earth\t B. Jupiter\t C. Mars\t D. Venus\n");
  
  scanf("%c", &answer); // clear the input buffer
  scanf("%c", &answer); // read answer from user
  
  if (answer == 'B') {
    printf("Correct answer! You get 10 points.\n");
    score += 10;
  } else {
    printf("Sorry, that's the wrong answer. The correct answer is B.\n");
  }
  
  // Question 8
  printf("\nQuestion 8: Who painted the famous artwork called Mona Lisa?\n");
  printf("A. Vincent van Gogh\t B. Pablo Picasso\t C. Leonardo da Vinci\t D. Michelangelo\n");
  
  scanf("%c", &answer); // clear the input buffer
  scanf("%c", &answer); // read answer from user
  
  if (answer == 'C') {
    printf("Correct answer! You get 10 points.\n");
    score += 10;
  } else {
    printf("Sorry, that's the wrong answer. The correct answer is C.\n");
  }
  
  // Question 9
  printf("\nQuestion 9: What is the smallest country in the world?\n");
  printf("A. Monaco\t B. Vatican City\t C. Singapore\t D. Liechtenstein\n");
  
  scanf("%c", &answer); // clear the input buffer
  scanf("%c", &answer); // read answer from user
  
  if (answer == 'B') {
    printf("Correct answer! You get 10 points.\n");
    score += 10;
  } else {
    printf("Sorry, that's the wrong answer. The correct answer is B.\n");
  }
  
  // Question 10
  printf("\nQuestion 10: What is the name of the world's largest ocean?\n");
  printf("A. Atlantic Ocean\t B. Indian Ocean\t C. Arctic Ocean\t D. Pacific Ocean\n");
  
  scanf("%c", &answer); // clear the input buffer
  scanf("%c", &answer); // read answer from user
  
  if (answer == 'D') {
    printf("Correct answer! You get 10 points.\n");
    score += 10;
  } else {
    printf("Sorry, that's the wrong answer. The correct answer is D.\n");
  }
  
  printf("\nCongratulations, %s! You have completed the exam.\n", name);
  printf("Your final score is %d out of 100.\n", score);
  return 0;
}
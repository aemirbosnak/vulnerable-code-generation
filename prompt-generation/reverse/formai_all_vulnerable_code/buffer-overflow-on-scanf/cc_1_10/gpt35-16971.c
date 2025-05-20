//FormAI DATASET v1.0 Category: Game ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

  printf("Welcome to the Trivia Game!\n");
  printf("********************************\n");
  printf("Answer the following 10 questions correctly to win the game.\n");
  printf("********************************\n\n");

  //initialize variables
  int score = 0;
  srand(time(0));

  //create array with 10 questions and their corresponding answers
  char questions[10][200] = {
    "How many months are in a year?\n",
    "What is the capital of France?\n",
    "Who painted the Mona Lisa?\n",
    "What is the largest continent in the world?\n",
    "What is the name of the world's biggest ocean?\n",
    "What is the smallest planet in our solar system?\n",
    "What is the first element on the periodic table?\n",
    "What is the largest animal in the world?\n",
    "Who created Facebook?\n",
    "What is the tallest mammal in the world?\n"
  };
  char answers[10][50] = {
    "12",
    "Paris",
    "Leonardo da Vinci",
    "Asia",
    "Pacific",
    "Mercury",
    "Hydrogen",
    "Blue Whale",
    "Mark Zuckerberg",
    "Giraffe"
  };

  //loop through questions, ask user and check their answer
  for(int i=0; i<10; i++) {

    printf("%d) %s", i+1, questions[i]);
    char userAnswer[50];
    scanf("%s", userAnswer);

    if(strcmp(userAnswer, answers[i]) == 0) {
      printf("Correct!\n");
      score++;
    }
    else {
      printf("Incorrect. The correct answer is %s.\n", answers[i]);
    }
  }

  //display final score and winner message
  printf("\n********************************\n");
  printf("Your final score is %d out of 10.\n", score);
  if(score == 10) {
    printf("Congratulations! You are a trivia master!\n");
  }
  else {
    printf("Better luck next time!\n");
  }

  return 0;
}
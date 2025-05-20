//FormAI DATASET v1.0 Category: Online Examination System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int questions[5][5] = {{1,2,3,4,5},
                       {2,3,4,5,1},
                       {3,4,5,1,2},
                       {4,5,1,2,3},
                       {5,1,2,3,4}};

char answers[5][6] = {{'A','B','C','D','E'},
                      {'B','C','D','E','A'},
                      {'C','D','E','A','B'},
                      {'D','E','A','B','C'},
                      {'E','A','B','C','D'}};

int main() {
  int choice, count, answer;
  char selectedAnswer, correctAnswer;
  count = 0;

  printf("\n------------ Welcome to C Examination ------------\n\n");
  printf("Instructions:\n");
  printf("\t- There are 5 questions in this test.\n");
  printf("\t- Each question has 5 choices (A, B, C, D, E).\n");
  printf("\t- Choose the correct answer by entering the corresponding letter.\n\n");

  for (int i = 0; i < 5; i++) {
    printf("Question %d: What is %d + %d?\n", i+1, i, i+1);
    printf("\tA. %d\n", questions[i][0]);
    printf("\tB. %d\n", questions[i][1]);
    printf("\tC. %d\n", questions[i][2]);
    printf("\tD. %d\n", questions[i][3]);
    printf("\tE. %d\n", questions[i][4]);
    printf("Enter your answer (A, B, C, D, or E): ");
    scanf(" %c", &selectedAnswer);
    answer = selectedAnswer - 65;
    if (answer < 0 || answer > 4) {
      printf("Invalid response. Please enter A, B, C, D, or E.\n");
      i--;
      continue;
    }
    correctAnswer = answers[i][answer];
    if (selectedAnswer == correctAnswer) {
      printf("Correct!\n");
      count++;
    } else {
      printf("Incorrect. The correct answer is %c.\n", correctAnswer);
    }
    printf("\n");
  }

  printf("------------ Results ------------\n\n");
  printf("You answered %d out of 5 questions correctly!\n", count);
  if (count == 5) {
    printf("Excellent!\n");
  } else if (count >= 3) {
    printf("Good job!\n");
  } else {
    printf("Better luck next time.\n");
  }

  printf("\n");
  return 0;
}
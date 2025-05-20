//FormAI DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int num_of_questions = 5; // change this value to adjust size of exam
  int num_of_options = 4; // change this value to adjust number of options per question
  int score = 0; // initialize score to 0
  int i, j; // loop counters

  // store answers to questions
  char *answers[num_of_questions];
  answers[0] = "a";
  answers[1] = "b";
  answers[2] = "c";
  answers[3] = "d";
  answers[4] = "a";

  // store questions and options
  char *questions[num_of_questions]; 
  char *options[num_of_questions][num_of_options];
  questions[0] = "What is the capital of France?";
  options[0][0] = "a. London";
  options[0][1] = "b. Paris";
  options[0][2] = "c. Madrid";
  options[0][3] = "d. Rome";

  questions[1] = "What is the largest continent in the world?";
  options[1][0] = "a. Australia";
  options[1][1] = "b. North America";
  options[1][2] = "c. Asia";
  options[1][3] = "d. Africa";

  questions[2] = "What is the capital of Australia?";
  options[2][0] = "a. Melbourne";
  options[2][1] = "b. Sydney";
  options[2][2] = "c. Canberra";
  options[2][3] = "d. Perth";

  questions[3] = "What is the smallest country in the world?";
  options[3][0] = "a. Vatican City";
  options[3][1] = "b. Monaco";
  options[3][2] = "c. San Marino";
  options[3][3] = "d. Liechtenstein";

  questions[4] = "What is the highest mountain in the world?";
  options[4][0] = "a. Kilimanjaro";
  options[4][1] = "b. Mount Everest";
  options[4][2] = "c. Mount Fuji";
  options[4][3] = "d. Mount Kilimanjaro";

  // ask questions one by one and get user input
  for(i=0; i<num_of_questions; i++) {
    printf("%d. %s\n", i+1, questions[i]);
    for(j=0; j<num_of_options; j++) {
      printf("%s\n", options[i][j]);
    }

    char user_input;
    printf("Enter your answer: ");
    scanf(" %c", &user_input);
    if(tolower(user_input) == answers[i][0]) {
      printf("Correct!\n\n");
      score++; // increment score if answer is correct
    }
    else {
      printf("Wrong. The correct answer is %s\n\n", answers[i]);
    }
  }

  // display final score
  printf("Your final score is %d/%d\n\n", score, num_of_questions);

  return 0;
}
//FormAI DATASET v1.0 Category: Online Examination System ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct question {
  char question[100];
  char options[4][25];
  int answer;
}Question;

int main() {
  int n;
  printf("Enter number of questions: ");
  scanf("%d", &n);

  Question* questions = (Question*) malloc(n * sizeof(Question));

  // Adding questions
  for(int i = 0; i < n; i++) {
    printf("Enter question %d: ", i+1);
    scanf("%s", questions[i].question);

    for(int j = 0; j < 4; j++) {
      printf("Enter option %d: ", j+1);
      scanf("%s", questions[i].options[j]);
    }

    printf("Enter answer (1-4): ");
    scanf("%d", &questions[i].answer);
  }

  int score = 0;

  // Displaying questions and checking answers
  for(int i = 0; i < n; i++) {
    printf("Question %d: %s\n", i+1, questions[i].question);
    for(int j = 0; j < 4; j++) {
      printf("%d.  %s\n", j+1, questions[i].options[j]);
    }
    int userAnswer;
    printf("Enter your answer (1-4): ");
    scanf("%d", &userAnswer);

    if(userAnswer == questions[i].answer) {
      printf("Correct answer!\n");
      score++;
    } else {
      printf("Wrong answer! The correct answer is %d\n", questions[i].answer);
    }
  }

  printf("Your score is %d/%d\n", score, n);

  return 0;
}
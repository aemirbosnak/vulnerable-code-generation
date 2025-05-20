//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10

struct Question {
  char question[255];
  char answer[255];
  int marks;
  int difficulty;
};

void main() {
  struct Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", "A person who starts and manages their own business venture", 5, 3},
    {"Which scientist invented the theory of relativity?", "Albert Einstein", 4, 2},
    {"Which country has the largest population?", "China", 3, 1},
    {"What is the capital of France?", "Paris", 4, 2},
    {"Who wrote the novel 'The Lord of the Flies'?", "William Golding", 3, 1},
    {"Which animal is known for its sharp claws and quick reflexes?", "Tiger", 5, 3},
    {"What is the meaning of the word 'entrepreneur'?", "A person who starts and manages their own business venture", 5, 3},
    {"Which scientist invented the theory of relativity?", "Albert Einstein", 4, 2},
    {"Which country has the largest population?", "China", 3, 1},
    {"What is the capital of France?", "Paris", 4, 2}
  };

  int totalMarks = 0;
  for (int i = 0; i < MAX_QUESTIONS; i++) {
    printf("Question %d: %s", i + 1, questions[i].question);
    printf("\n");
    printf("Enter your answer: ");
    char answer[255];
    scanf("%s", answer);

    if (strcmp(answer, questions[i].answer) == 0) {
      printf("Correct!");
      questions[i].marks += 1;
    } else {
      printf("Incorrect. The answer is: %s", questions[i].answer);
    }

    printf("\n");
    totalMarks += questions[i].marks;
  }

  printf("Total marks: %d", totalMarks);
  printf("\n");
  printf("Your final grade: %c", (totalMarks / MAX_QUESTIONS) >= 5 ? 'A' : 'F');
}
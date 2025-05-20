//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

typedef struct Question {
  char question[256];
  char answer[256];
  int marks;
} Question;

Question questions[MAX_QUESTIONS] = {
  {"What is the meaning of the word entropy?", "A measure of disorder", 20},
  {"Who invented the telephone?", "Alexander Graham Bell", 20},
  {"What is the capital of France?", "Paris", 20},
  {"What is the sound of one hand clapping?", "Silence", 10},
  {"What is the square of 5?", "25", 10},
  {"Who was the first president of the United States?", "George Washington", 20},
  {"What is the meaning of the word polymorphism?", "The ability of a single object to take on many forms", 20},
  {"What is the capital of Australia?", "Canberra", 20},
  {"What is the chemical symbol for gold?", "Au", 20},
  {"What is the meaning of the word equilibrium?", "A state of balance", 20}
};

int main() {
  int i, score = 0;
  char answer[256];

  // Display questions
  for (i = 0; i < MAX_QUESTIONS; i++) {
    printf("%s\n", questions[i].question);
  }

  // Get user answers
  for (i = 0; i < MAX_QUESTIONS; i++) {
    printf("Enter your answer: ");
    scanf("%s", answer);

    // Check if the answer is correct
    if (strcmp(answer, questions[i].answer) == 0) {
      score += questions[i].marks;
    }
  }

  // Display the final score
  printf("Your final score is: %d\n", score);

  return 0;
}
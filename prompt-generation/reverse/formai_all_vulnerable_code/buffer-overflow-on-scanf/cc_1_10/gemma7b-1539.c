//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10

typedef struct Question {
  char question[255];
  char answer[255];
  int marks;
} Question;

Question questions[MAX_QUESTIONS] = {
  {"What is the meaning of the word 'entrepreneur'?", "a) A person who owns and operates a business", 10},
  {"Which planet is the largest?", "b) Mars", 8},
  {"What is the capital of France?", "c) Paris", 9},
  {"Which scientist invented the theory of relativity?", "d) Albert Einstein", 12},
  {"What is the sound of one hand clapping?", "e) Silence", 7},
  {"Which animal is known for its intelligence?", "f) Humans", 11},
  {"What is the meaning of the word 'entrepreneur'?", "g) A person who is always getting ahead", 9},
  {"Which country is the largest exporter of oil?", "h) Saudi Arabia", 10},
  {"What is the meaning of the word 'entrepreneur'?", "i) A person who is willing to take risks", 8},
  {"Which city is the largest in the world?", "j) Tokyo", 9}
};

int main() {
  time_t start_time = time(NULL);
  int score = 0;
  int current_question = 0;

  system("clear");
  printf("Welcome to the Future Exam System!\n");
  printf("-----------------------\n");

  while (current_question < MAX_QUESTIONS) {
    printf("Question %d: %s\n", current_question + 1, questions[current_question].question);

    char answer[255];
    printf("Enter your answer: ");
    scanf("%s", answer);

    if (strcmp(answer, questions[current_question].answer) == 0) {
      score += questions[current_question].marks;
      printf("Correct!\n");
    } else {
      printf("Incorrect. The answer is: %s\n", questions[current_question].answer);
    }

    current_question++;
  }

  time_t end_time = time(NULL);
  int time_taken = (end_time - start_time) * 60;

  printf("Your total score is: %d\n", score);
  printf("Time taken: %d minutes\n", time_taken);

  return 0;
}
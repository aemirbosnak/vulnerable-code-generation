//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10

typedef struct Question {
  char question[256];
  char answer[256];
  int marks;
} Question;

Question questions[MAX_QUESTIONS] = {
  {"What is the meaning of the word 'entrepreneur'?", "Someone who starts and manages their own business", 5},
  {"Which scientist invented the theory of relativity?", "Albert Einstein", 4},
  {"What is the chemical symbol for gold?", "Au", 3},
  {"Which president of the United States was assassinated in 1963?", "President Kennedy", 4},
  {"What is the capital of Australia?", "Canberra", 3},
  {"Which planet is the largest?", "Jupiter", 4},
  {"What is the meaning of the word 'entrepreneur' in French?", "Un entrepreneur", 5},
  {"Which scientist invented the theory of quantum mechanics?", "Max Planck", 4},
  {"What is the chemical symbol for silver?", "Ag", 3},
  {"Which president of the United States was the first to live in the White House?", "George Washington", 4}
};

int main() {
  int i, score = 0, total_marks = 0;
  time_t start_time, end_time;

  // Start the timer
  start_time = time(NULL);

  // Display the questions
  for (i = 0; i < MAX_QUESTIONS; i++) {
    printf("%d. %s\n", i + 1, questions[i].question);
  }

  // Get the student's answer for each question
  for (i = 0; i < MAX_QUESTIONS; i++) {
    char answer[256];
    printf("Enter your answer for question %d: ", i + 1);
    scanf("%s", answer);

    // Check if the answer is correct
    if (strcmp(answer, questions[i].answer) == 0) {
      score++;
    }

    total_marks += questions[i].marks;
  }

  // End the timer
  end_time = time(NULL);

  // Calculate the time taken
  int time_taken = (int) (end_time - start_time);

  // Display the results
  printf("Your total score is: %d\n", score);
  printf("Your total marks are: %d\n", total_marks);
  printf("Time taken: %d minutes", time_taken);

  return 0;
}
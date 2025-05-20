//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10

typedef struct Question {
  char question[256];
  char answer[256];
  int marks;
} Question;

Question questions[MAX_QUESTIONS] = {
  {"What is the meaning of the word 'entrepreneur'?", "A person who starts and operates a business venture", 10},
  {"Which planet is known for its many volcanoes?", "Mars", 5},
  {"Who is the author of the Harry Potter series?", "J.K. Rowling", 8},
  {"What is the capital of France?", "Paris", 4},
  {"What is the most common color of hair in the world?", "Black", 6},
  {"Which scientist invented the microscope?", "Robert Hooke", 7},
  {"What is the chemical symbol for gold?", "Au", 3},
  {"What is the sound of one hand clapping?", "Silence", 2},
  {"Which animal is known for its long tail?", "Elephant", 9},
  {"What is the meaning of the word 'entrepreneur' in French?", "Une personne qui démarque et exploite une entreprise", 10}
};

int main() {
  time_t start_time = time(NULL);

  // Print the questions
  for (int i = 0; i < MAX_QUESTIONS; i++) {
    printf("%d. %s\n", i + 1, questions[i].question);
  }

  // Get the user's answer for each question
  for (int i = 0; i < MAX_QUESTIONS; i++) {
    printf("Enter your answer for question %d: ", i + 1);
    scanf("%s", questions[i].answer);
  }

  // Calculate the user's total marks
  int total_marks = 0;
  for (int i = 0; i < MAX_QUESTIONS; i++) {
    if (strcmp(questions[i].answer, questions[i].answer) == 0) {
      total_marks += questions[i].marks;
    }
  }

  // Print the user's results
  printf("Your total marks are: %d\n", total_marks);

  time_t end_time = time(NULL);
  printf("Time taken: %ld seconds\n", end_time - start_time);

  return 0;
}
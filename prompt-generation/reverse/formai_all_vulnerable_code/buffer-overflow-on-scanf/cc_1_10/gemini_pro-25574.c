//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
  char question[256];
  char options[4][64];
  int correct_answer;
};

struct Student {
  char name[64];
  int score;
};

int main() {
  // Define questions and answers
  struct Question questions[] = {
    {"What is the capital of France?", {"Paris", "London", "Rome", "Madrid"}, 0},
    {"Who painted the Mona Lisa?", {"Leonardo da Vinci", "Michelangelo", "Raphael", "Rembrandt"}, 0},
    {"What is the chemical symbol for gold?", {"Au", "Ag", "Cu", "Fe"}, 0},
    {"What is the largest ocean in the world?", {"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"}, 0},
    {"Who wrote the novel 'To Kill a Mockingbird'?", {"Harper Lee", "Mark Twain", "J.D. Salinger", "Jane Austen"}, 0}
  };

  // Welcome message
  printf("Welcome to the Online Examination System!\n");
  printf("Please enter your name: ");
  char name[64];
  scanf("%s", name);

  // Create student struct
  struct Student student;
  strcpy(student.name, name);
  student.score = 0;

  // Loop through questions and display them
  for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
    printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
    for (int j = 0; j < 4; j++) {
      printf("  %c) %s\n", 'A' + j, questions[i].options[j]);
    }

    // Get user input
    char answer;
    printf("Enter your answer (A, B, C, or D): ");
    scanf(" %c", &answer);

    // Check if answer is correct
    if (answer - 'A' == questions[i].correct_answer) {
      printf("Correct!\n");
      student.score++;
    } else {
      printf("Incorrect.\n");
    }
  }

  // Display results
  printf("\nYour score is %d out of 5.\n", student.score);
  if (student.score >= 3) {
    printf("Congratulations, %s! You passed the exam.\n", student.name);
  } else {
    printf("Sorry, %s. You failed the exam.\n", student.name);
  }

  return 0;
}
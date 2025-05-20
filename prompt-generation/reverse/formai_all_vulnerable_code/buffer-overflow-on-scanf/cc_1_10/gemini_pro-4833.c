//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define NUM_QUESTIONS 10
#define NUM_CHOICES 4

struct question {
  char *question;
  char *choices[NUM_CHOICES];
  int answer;
};

struct question questions[] = {
  {
    "What is the atomic number of hydrogen?",
    {"1", "2", "3", "4"},
    1
  },
  {
    "What is the symbol for gold?",
    {"Au", "Ag", "Fe", "Cu"},
    1
  },
  {
    "What is the atomic mass of oxygen?",
    {"16", "32", "48", "64"},
    1
  },
  {
    "What is the name of the element with the atomic number 17?",
    {"Chlorine", "Fluorine", "Bromine", "Iodine"},
    1
  },
  {
    "What is the symbol for sodium?",
    {"Na", "K", "Li", "Rb"},
    1
  },
  {
    "What is the atomic number of carbon?",
    {"6", "12", "18", "24"},
    1
  },
  {
    "What is the symbol for iron?",
    {"Fe", "Ni", "Co", "Zn"},
    1
  },
  {
    "What is the atomic mass of nitrogen?",
    {"14", "28", "42", "56"},
    1
  },
  {
    "What is the name of the element with the atomic number 3?",
    {"Lithium", "Sodium", "Potassium", "Rubidium"},
    1
  },
  {
    "What is the symbol for aluminum?",
    {"Al", "Zn", "Cd", "Hg"},
    1
  }
};

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Shuffle the questions
  for (int i = 0; i < NUM_QUESTIONS; i++) {
    int j = rand() % NUM_QUESTIONS;
    struct question temp = questions[i];
    questions[i] = questions[j];
    questions[j] = temp;
  }

  // Ask the user each question and get their answer
  int score = 0;
  for (int i = 0; i < NUM_QUESTIONS; i++) {
    printf("%s\n", questions[i].question);
    for (int j = 0; j < NUM_CHOICES; j++) {
      printf("%d. %s\n", j + 1, questions[i].choices[j]);
    }
    int answer;
    scanf("%d", &answer);
    if (answer == questions[i].answer) {
      printf("Correct!\n");
      score++;
    } else {
      printf("Incorrect. The correct answer is %d.\n", questions[i].answer);
    }
  }

  // Print the user's score
  printf("Your score is %d out of %d.\n", score, NUM_QUESTIONS);

  return 0;
}
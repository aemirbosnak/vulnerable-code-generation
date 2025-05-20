//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_QUESTIONS 10
#define MAX_OPTIONS 4

typedef struct {
  char question[100];
  char options[MAX_OPTIONS][100];
  char answer;
} Question;

Question questions[NUM_QUESTIONS] = {
  {
    "What is the capital of France?",
    {
      "Paris",
      "London",
      "Berlin",
      "Rome"
    },
    'A'
  },
  {
    "What is the smallest planet in our solar system?",
    {
      "Earth",
      "Venus",
      "Mars",
      "Mercury"
    },
    'C'
  },
  {
    "What is the largest living species of lizard?",
    {
      "Snakes",
      "Lizards",
      "Turtles",
      "Frogs"
    },
    'B'
  },
  {
    "What is the largest mammal on Earth?",
    {
      "Elephant",
      "Whale",
      "Giraffe",
      "Rhino"
    },
    'A'
  },
  {
    "What is the largest species of fish in the ocean?",
    {
      "Shark",
      "Swordfish",
      "Barracuda",
      "Tuna"
    },
    'A'
  },
  {
    "What is the largest bird in the world?",
    {
      "Eagle",
      "Vulture",
      "Ostrich",
      "Penguin"
    },
    'C'
  },
  {
    "What is the largest insect in the world?",
    {
      "Bee",
      "Butterfly",
      "Ant",
      "Grasshopper"
    },
    'B'
  },
  {
    "What is the largest reptile in the world?",
    {
      "Crocodile",
      "Snake",
      "Lizard",
      "Turtle"
    },
    'A'
  },
  {
    "What is the largest amphibian in the world?",
    {
      "Frog",
      "Toad",
      "Newt",
      "Salamander"
    },
    'B'
  },
  {
    "What is the largest bird in the world?",
    {
      "Eagle",
      "Vulture",
      "Ostrich",
      "Penguin"
    },
    'C'
  }
};

int main() {
  int i, j, score = 0;
  char choice;

  // Shuffle the questions
  srand(time(NULL));
  for (i = 0; i < NUM_QUESTIONS; i++) {
    int r = rand() % (NUM_QUESTIONS - i) + i;
    Question temp = questions[i];
    questions[i] = questions[r];
    questions[r] = temp;
  }

  // Ask the questions
  for (i = 0; i < NUM_QUESTIONS; i++) {
    printf("%s\n", questions[i].question);
    for (j = 0; j < MAX_OPTIONS; j++) {
      printf("%c) %s\n", 'A' + j, questions[i].options[j]);
    }
    scanf("%c", &choice);

    // Check if the answer is correct
    if (choice == questions[i].answer) {
      score++;
      printf("Correct!\n");
    } else {
      printf("Wrong. The correct answer is %c.\n", questions[i].answer);
    }
  }

  // Print the final score
  printf("Your score is %d out of %d.\n", score, NUM_QUESTIONS);

  return 0;
}
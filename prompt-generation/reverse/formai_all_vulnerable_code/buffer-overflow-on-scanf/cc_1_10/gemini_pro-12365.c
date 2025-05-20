//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store question and answer
struct Question {
  char question[256];
  char options[4][64];
  int correctAnswer;
};

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
  srand(time(NULL));
  return rand() % (max - min + 1) + min;
}

// Function to display the question and options
void displayQuestion(struct Question question) {
  printf("\n%s\n", question.question);
  for (int i = 0; i < 4; i++) {
    printf("%d. %s\n", i + 1, question.options[i]);
  }
}

// Function to get the user's answer
int getAnswer() {
  int answer;
  printf("Enter your answer (1-4): ");
  scanf("%d", &answer);
  return answer;
}

// Function to check if the answer is correct
int isCorrectAnswer(struct Question question, int answer) {
  return question.correctAnswer == answer;
}

// Main function
int main() {
  // Array of questions
  struct Question questions[] = {
    {
      "What is the capital of France?",
      {"Paris", "London", "Rome", "Madrid"},
      1
    },
    {
      "Who is the author of the Harry Potter series?",
      {"J.K. Rowling", "Stephenie Meyer", "Suzanne Collins", "Veronica Roth"},
      1
    },
    {
      "What is the largest ocean in the world?",
      {"Atlantic Ocean", "Pacific Ocean", "Indian Ocean", "Arctic Ocean"},
      2
    },
    {
      "What is the chemical symbol for gold?",
      {"Au", "Ag", "Cu", "Fe"},
      1
    },
    {
      "Who is the current president of the United States?",
      {"Joe Biden", "Donald Trump", "Barack Obama", "George W. Bush"},
      1
    }
  };

  // Number of questions
  int numQuestions = sizeof(questions) / sizeof(questions[0]);

  // Generate a random order of questions
  int randomOrder[numQuestions];
  for (int i = 0; i < numQuestions; i++) {
    randomOrder[i] = generateRandomNumber(0, numQuestions - 1);
  }

  // Keep track of the user's score
  int score = 0;

  // Loop through the questions
  for (int i = 0; i < numQuestions; i++) {
    // Get the next question
    struct Question question = questions[randomOrder[i]];

    // Display the question and options
    displayQuestion(question);

    // Get the user's answer
    int answer = getAnswer();

    // Check if the answer is correct
    if (isCorrectAnswer(question, answer)) {
      printf("Correct! :)\n");
      score++;
    } else {
      printf("Wrong! :(\n");
    }
  }

  // Display the final score
  printf("\nYour final score is %d out of %d.\n", score, numQuestions);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

// The questions
char *questions[] = {
  "What is the capital of France?",
  "Who is the current president of the United States?",
  "What is the chemical symbol for gold?",
  "What is the boiling point of water?",
  "What is the speed of light?"
};

// The answers
char *answers[] = {
  "Paris",
  "Joe Biden",
  "Au",
  "100 degrees Celsius",
  "299,792,458 meters per second"
};

// The number of questions
int num_questions = sizeof(questions) / sizeof(char *);

// The user's score
int score = 0;

// The timer
int timer = 60;

// The main function
int main() {
  // Start the timer
  alarm(timer);

  // Loop through the questions
  for (int i = 0; i < num_questions; i++) {
    // Print the question
    printf("%s\n", questions[i]);

    // Get the user's answer
    char answer[100];
    scanf("%s", answer);

    // Check if the answer is correct
    if (strcmp(answer, answers[i]) == 0) {
      // The answer is correct, so increment the score
      score++;
    }
  }

  // Print the score
  printf("Your score is %d\n", score);

  return 0;
}
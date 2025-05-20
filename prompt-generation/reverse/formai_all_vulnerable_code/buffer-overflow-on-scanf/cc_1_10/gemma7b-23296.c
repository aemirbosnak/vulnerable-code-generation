//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10

typedef struct Question {
  char *question;
  char *options[4];
  int answer;
} Question;

Question questions[MAX_QUESTIONS] = {
  {"What is the meaning of the word 'entrepreneur'?", {"a. A person who owns a business", "b. A person who is good at math", "c. A person who is creative", "d. A person who is smart"}, 1},
  {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 0},
  {"What is the capital of France?", {"a. Paris", "b. Lyon", "c. Rome", "d. Berlin"}, 2},
  // Add more questions here...
};

int main() {
  int i, score = 0, time_left = 60;
  char answer;

  // Display the questions
  for (i = 0; i < MAX_QUESTIONS; i++) {
    printf("%s\n", questions[i].question);

    // Display the options
    for (int j = 0; j < 4; j++) {
      printf("  %s\n", questions[i].options[j]);
    }

    // Get the user's answer
    printf("Enter your answer: ");
    scanf(" %c", &answer);

    // Check if the answer is correct
    if (answer == questions[i].answer) {
      score++;
    }

    // Time left
    time_left--;
  }

  // Display the results
  printf("Your score: %d out of %d\n", score, MAX_QUESTIONS);
  printf("Time left: %d seconds\n", time_left);

  return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PI 3.14159

int main() {
  int curiosity_level = 5; // Set curiosity level to 5 (out of 10)
  int correct_answers = 0; // Initialize correct answer count to 0
  int total_questions = 10; // Total number of questions to ask
  int current_question = 0; // Current question number

  // Define a struct to store question and answer pairs
  struct question {
    char question[50]; // Question text
    char answer[50]; // Answer text
  };
  struct question questions[] = {
    {"What is the capital of France?", "Paris"},
    {"What is the smallest prime number?", "2"},
    {"What is the value of Pi?", "3.14159"},
    {"What is the largest planet in our solar system?", "Jupiter"},
    {"What is the smallest letter in the alphabet?", "a"},
    {"What is the largest letter in the alphabet?", "Z"},
    {"What is the temperature in Celsius that water freezes at?", "32"},
    {"What is the boiling point of water in Celsius?", "100"},
    {"What is the number of sides of a hexagon?", "6"},
    {"What is the number of edges of a cube?", "12"}
  };

  // Generate a random question from the array
  int random_question_index = rand() % (sizeof(questions) / sizeof(questions[0]));
  struct question *random_question = questions + random_question_index;

  // Print the current question and ask the user to answer
  printf("Curiosity level: %d\n", curiosity_level);
  printf("Current question: %s\n", random_question->question);
  printf("Please enter your answer: ");

  // Read the user's answer and check if it's correct
  char user_answer[50];
  scanf("%s", user_answer);
  if (strcmp(random_question->answer, user_answer) == 0) {
    correct_answers++;
    printf("Correct! The answer is %s.\n", random_question->answer);
  } else {
    printf("Incorrect. The correct answer is %s.\n", random_question->answer);
  }

  // Increment the current question number and check if we've reached the end
  current_question++;
  if (current_question >= total_questions) {
    printf("You have reached the end of the curiosity test! You answered %d out of %d questions correctly.\n", correct_answers, total_questions);
    return 0;
  }

  // Generate the next question and repeat the process
  random_question_index = rand() % (sizeof(questions) / sizeof(questions[0]));
  random_question = questions + random_question_index;

  // Print the next question and continue
  printf("Next question: %s\n", random_question->question);

  return 0;
}
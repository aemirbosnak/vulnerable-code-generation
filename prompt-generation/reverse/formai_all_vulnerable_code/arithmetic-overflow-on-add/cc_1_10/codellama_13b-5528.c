//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for a question
typedef struct {
  char* question;
  char* answer;
  int points;
} Question;

// Structure for a student's answer
typedef struct {
  char* answer;
  int points;
} StudentAnswer;

// Structure for a student's results
typedef struct {
  int score;
  int total_points;
} StudentResults;

// Function to generate a random question
void generate_question(Question* question) {
  // Generate a random number for the question
  int question_num = rand() % 10 + 1;
  // Set the question and answer based on the random number
  switch (question_num) {
    case 1:
      question->question = "What is the capital of France?";
      question->answer = "Paris";
      question->points = 10;
      break;
    case 2:
      question->question = "What is the largest planet in our solar system?";
      question->answer = "Jupiter";
      question->points = 10;
      break;
    case 3:
      question->question = "What is the smallest country in the world?";
      question->answer = "Vatican City";
      question->points = 10;
      break;
    case 4:
      question->question = "What is the largest living species of lizard?";
      question->answer = "Salomon Island giant tortoise";
      question->points = 10;
      break;
    case 5:
      question->question = "What is the largest waterfall in the world?";
      question->answer = "Victoria Falls";
      question->points = 10;
      break;
    case 6:
      question->question = "What is the largest living species of jellyfish?";
      question->answer = "Titanoboa";
      question->points = 10;
      break;
    case 7:
      question->question = "What is the largest mammal that ever lived?";
      question->answer = "Blue whale";
      question->points = 10;
      break;
    case 8:
      question->question = "What is the largest bird in the world?";
      question->answer = "Emu";
      question->points = 10;
      break;
    case 9:
      question->question = "What is the largest fish in the world?";
      question->answer = "Whale shark";
      question->points = 10;
      break;
    case 10:
      question->question = "What is the largest reptile in the world?";
      question->answer = "Gharial";
      question->points = 10;
      break;
    default:
      question->question = "Unknown question";
      question->answer = "Unknown answer";
      question->points = 0;
      break;
  }
}

// Function to check if a student's answer is correct
void check_answer(Question* question, StudentAnswer* answer, StudentResults* results) {
  if (strcmp(answer->answer, question->answer) == 0) {
    results->score += question->points;
    results->total_points += question->points;
  } else {
    results->total_points += question->points;
  }
}

int main() {
  // Set the random seed
  srand(time(NULL));

  // Initialize the question and answer structures
  Question question;
  StudentAnswer answer;
  StudentResults results;

  // Generate a random question
  generate_question(&question);

  // Print the question
  printf("%s\n", question.question);

  // Get the student's answer
  printf("Enter your answer: ");
  scanf("%s", answer.answer);

  // Check the answer
  check_answer(&question, &answer, &results);

  // Print the results
  printf("Your score is: %d\n", results.score);

  return 0;
}
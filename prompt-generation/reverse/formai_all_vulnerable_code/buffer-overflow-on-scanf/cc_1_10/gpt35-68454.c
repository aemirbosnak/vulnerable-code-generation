//FormAI DATASET v1.0 Category: Online Examination System ; Style: Linus Torvalds
/*
  * C Online Examination System
  * Written in a Linus Torvalds style
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 20

void clear_screen()
{
  system("clear || cls"); // Linux or Windows
}

void print_question(int question_number, char* question)
{
  printf("Question %d: %s\n", question_number, question);
}

int get_answer()
{
  char input[10];
  scanf("%s", input);
  int answer = atoi(input);
  return answer;
}

void evaluate(int correct_answers)
{
  clear_screen();
  printf("You answered %d out of %d questions correctly.\n", correct_answers, MAX_QUESTIONS);

  if (correct_answers >= 15)
  {
    printf("Congratulations, you passed the exam!\n");
  }
  else
  {
    printf("Sorry, you did not pass the exam.\n");
  }
}

int main()
{
  char* questions[MAX_QUESTIONS] = {
    "What is the capital of France?",
    "What is the largest country in the world?",
    "What is the smallest country in the world?",
    "Who wrote the Harry Potter series?",
    "What is the largest organ in the human body?",
    "What is the only continent with no active volcanoes?",
    "What is the smallest ocean in the world?",
    "What is the name of the largest desert in the world?",
    "What is the name of the currency used in Japan?",
    "What is the largest planet in the solar system?",
    "What is the only metal that is liquid at room temperature?",
    "What is the main language spoken in Brazil?",
    "What is the name of the tallest mountain in Africa?",
    "What is the name of the process by which plants convert sunlight into food?",
    "What is the speed of light in a vacuum?",
    "Who was the first man to step on the moon?",
    "What is the chemical symbol for gold?",
    "What is the name of the first element on the periodic table?",
    "What is the name of the largest lake in Africa?",
    "Who painted the Mona Lisa?"
  };

  int answers[MAX_QUESTIONS] = {2, 1, 3, 2, 1, 4, 2, 1, 2, 5, 4, 2, 1, 3, 300000000, 1, 79, 1, 1, 3};

  int correct_answers = 0;

  clear_screen();
  printf("Welcome to the C Online Examination System!\n\n");

  for (int i = 0; i < MAX_QUESTIONS; i++)
  {
    print_question(i + 1, questions[i]);
    int answer = get_answer();
    if (answer == answers[i])
    {
      correct_answers++;
      printf("Correct!\n\n");
    }
    else
    {
      printf("Incorrect. The correct answer is %d.\n\n", answers[i]);
    }
  }

  evaluate(correct_answers);

  return 0;
}
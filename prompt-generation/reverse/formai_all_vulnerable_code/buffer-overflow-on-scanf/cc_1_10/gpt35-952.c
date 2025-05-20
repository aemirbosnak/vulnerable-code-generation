//FormAI DATASET v1.0 Category: Online Examination System ; Style: rigorous
#include <stdio.h>
#include <string.h>

int main()
{
  char username[10], password[10];
  int attempt = 0, i, count = 0;

  // Set a correct username and password
  char correct_username[10] = "user";
  char correct_password[10] = "pass";

  while (attempt < 3)
  {
    // Request and scan for user input
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Compare input with correct login credentials
    if (strcmp(username, correct_username) == 0 && strcmp(password, correct_password) == 0)
    {
      printf("\nWelcome to the Online Examination System!\n");
      break;
    }
    else
    {
      attempt++;
      printf("\nInvalid login credentials. Please try again.\n");
      printf("You have %d attempts remaining.\n", 3 - attempt);
    }
  }

  if (attempt == 3)
  {
    printf("\nYou have reached the maximum number of attempts. Please try again later.\n");
    return 0;
  }

  // Set exam questions and answers
  char questions[5][100] = {
      "What is the capital city of France?",
      "What is the largest planet in our solar system?",
      "Which is the highest mountain in the world?",
      "Who wrote the famous novel 'To Kill a Mockingbird?'",
      "What is the smallest continent in the world?",
  };
  char answers[5][50] = {
      "Paris",
      "Jupiter",
      "Mount Everest",
      "Harper Lee",
      "Australia",
  };

  // Ask exam questions and evaluate answers
  printf("\nExam started.\n");
  for (i = 0; i < 5; i++)
  {
    printf("\n%s\n", questions[i]);
    printf("Enter your answer: ");
    char user_answer[50];
    scanf("%s", user_answer);
    if (strcmp(user_answer, answers[i]) == 0)
    {
      printf("Correct answer!\n");
      count++;
    }
    else
    {
      printf("Incorrect answer. The correct answer is: %s\n", answers[i]);
    }
  }

  // Calculate and output exam result
  float percentage = count / 5.0 * 100.0;
  printf("\nExam completed!\n");
  printf("Your score is: %d/5\n", count);
  printf("You got %.2f%% of the questions correct.\n", percentage);

  return 0;
}
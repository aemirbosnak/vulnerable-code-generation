//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: funny
#include<stdio.h>

int main() {
  printf("Welcome to the Online Examination System!");
  printf("This program is so funny!\n");

  int marks = 0;
  int totalMarks = 100;
  int attempts = 0;
  int correctAnswers = 0;
  int wrongAnswers = 0;

  while (marks < totalMarks && attempts < 5) {
    int questionNumber = rand() % 10 + 1;
    int option1 = rand() % 10 + 1;
    int option2 = rand() % 10 + 1;
    int option3 = rand() % 10 + 1;
    int option4 = rand() % 10 + 1;

    printf("Question %d: ", questionNumber);
    printf("What is the answer to the following question?\n");
    printf("A) %d\n", option1);
    printf("B) %d\n", option2);
    printf("C) %d\n", option3);
    printf("D) %d\n", option4);

    int choice;
    scanf("%d", &choice);

    if (choice == option1) {
      correctAnswers++;
    } else if (choice == option2) {
      wrongAnswers++;
    } else if (choice == option3) {
      wrongAnswers++;
    } else if (choice == option4) {
      correctAnswers++;
    } else {
      printf("Invalid choice. Please try again.\n");
      wrongAnswers++;
    }

    attempts++;
  }

  if (correctAnswers == totalMarks) {
    printf("Congratulations! You have passed the online examination.\n");
  } else {
    printf("Sorry, you have failed the online examination.\n");
  }

  return 0;
}
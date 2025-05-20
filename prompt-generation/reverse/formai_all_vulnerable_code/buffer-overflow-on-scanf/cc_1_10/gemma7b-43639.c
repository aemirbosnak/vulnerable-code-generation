//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main() {
  system("clear");
  system("figlet -f Pixel -c 'Online Examination System'");
  printf("__________________________________\n");
  printf("Welcome to the Online Examination System!\n");
  printf("__________________________________\n");

  // Student Information
  char student_name[50];
  printf("Enter your full name: ");
  scanf("%s", student_name);

  // Exam Information
  char exam_name[50];
  printf("Enter the name of the exam: ");
  scanf("%s", exam_name);

  // Start Time
  time_t start_time = time(NULL);

  // Question Bank
  char questions[1000];
  questions[0] = "What is the meaning of the word 'entrepreneur'?\n";
  questions[1] = "Explain the concept of polymorphism in OOP.\n";
  questions[2] = "Write a short story about a young programmer named John.\n";

  // Exam Questions
  int num_questions = 3;
  for (int i = 0; i < num_questions; i++) {
    printf("%d. %s", i + 1, questions[i]);
  }

  // Answer Submission
  char answer[2000];
  printf("\nEnter your answer for each question, separated by commas: ");
  scanf("%s", answer);

  // End Time
  time_t end_time = time(NULL);

  // Time Taken
  int time_taken = (int) (end_time - start_time) / 60;

  // Result
  int result = 0;
  for (int i = 0; i < num_questions; i++) {
    if (strcmp(answer[i], questions[i]) == 0) {
      result++;
    }
  }

  // Grade
  char grade = 'F';
  if (result >= 80) {
    grade = 'A';
  } else if (result >= 60) {
    grade = 'B';
  } else if (result >= 40) {
    grade = 'C';
  }

  // Conclusion
  printf("\nCongratulations, %s! You have completed the %s exam.\n", student_name, exam_name);
  printf("Your total time taken was %d minutes.\n", time_taken);
  printf("Your grade is: %c\n", grade);

  system("pause");
}
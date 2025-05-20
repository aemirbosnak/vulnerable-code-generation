//FormAI DATASET v1.0 Category: Online Examination System ; Style: happy
#include <stdio.h>

// Function to display the welcome message
void welcomeMessage() {
  printf("Welcome to the Online Examination System!\n");
  printf("******************************************************\n\n");
}

// Function to display the list of available subjects
void subjectList() {
  printf("What subject would you like to take the exam for?\n");
  printf("1. Mathematics\n");
  printf("2. Science\n");
  printf("3. English\n");
  printf("4. History\n");
}

// Function to display the instructions before starting the exam
void examInstructions() {
  printf("\n\nRead the following instructions carefully before starting the exam:\n");
  printf("1. You have 1 hour to complete the exam.\n");
  printf("2. The exam consists of 50 multiple choice questions.\n");
  printf("3. Each question carries 2 marks.\n");
  printf("4. There is no negative marking.\n");
  printf("******************************************************\n\n");
}

// Function to take the user's choice of subject
int takeSubjectChoice() {
  int choice;
  printf("Enter the subject choice (1-4): ");
  scanf("%d", &choice);
  return choice;
}

// Function to display the questions and get the user's answers
void takeExam(int subjectChoice) {
  int marks = 0;
  if (subjectChoice == 1) {
    printf("Mathematics Exam:\n");
    printf("1. What is the value of pi?\n");
    printf("a. 3.14\nb. 2.71\nc. 1.23\nd. 4.56\n");
    char answer;
    printf("Enter your answer (a/b/c/d): ");
    scanf(" %c", &answer);
    if (answer == 'a') {
      marks += 2;
    }
    printf("\n2. What is the formula for finding the area of a circle?\n");
    printf("a. 2 * pi * r\nb. pi * r^2\nc. 2 * r^2\nd. pi * r\n");
    printf("Enter your answer (a/b/c/d): ");
    scanf(" %c", &answer);
    if (answer == 'b') {
      marks += 2;
    }
  }
  else if (subjectChoice == 2) {
    printf("Science Exam:\n");
    printf("1. What is the fundamental force that holds the nucleus of an atom together?\n");
    printf("a. Gravity\nb. Strong Force\nc. Weak Force\nd. Electromagnetic Force\n");
    char answer;
    printf("Enter your answer (a/b/c/d): ");
    scanf(" %c", &answer);
    if (answer == 'b') {
      marks += 2;
    }
    printf("\n2. Which of the following is a noble gas?\n");
    printf("a. Oxygen\nb. Nitrogen\nc. Helium\nd. Hydrogen\n");
    printf("Enter your answer (a/b/c/d): ");
    scanf(" %c", &answer);
    if (answer == 'c') {
      marks += 2;
    }
  }
  else if (subjectChoice == 3) {
    printf("English Exam:\n");
    printf("1. Identify the sentence that is written in active voice.\n");
    printf("a. The cake was baked by my grandma.\nb. The boy was bitten by the dog.\n");
    printf("c. The teacher was impressed by the student's essay.\nd. The storm was witnessed by everyone.\n");
    char answer;
    printf("Enter your answer (a/b/c/d): ");
    scanf(" %c", &answer);
    if (answer == 'c') {
      marks += 2;
    }
    printf("\n2. Which of the following is a synonym for 'beautiful'?\n");
    printf("a. Ugly\nb. Pretty\nc. Innocent\nd. Creative\n");
    printf("Enter your answer (a/b/c/d): ");
    scanf(" %c", &answer);
    if (answer == 'b') {
      marks += 2;
    }
  }
  else if (subjectChoice == 4) {
    printf("History Exam:\n");
    printf("1. Who was the first president of the United States?\n");
    printf("a. George Washington\nb. Thomas Jefferson\nc. John Adams\nd. Abraham Lincoln\n");
    char answer;
    printf("Enter your answer (a/b/c/d): ");
    scanf(" %c", &answer);
    if (answer == 'a') {
      marks += 2;
    }
    printf("\n2. When did World War II end?\n");
    printf("a. 1945\nb. 1939\nc. 1941\nd. 1940\n");
    printf("Enter your answer (a/b/c/d): ");
    scanf(" %c", &answer);
    if (answer == 'a') {
      marks += 2;
    }
  }
  else {
    printf("Invalid subject choice!\n");
    return;
  }
  printf("\n\nCongratulations on completing the exam!\n");
  printf("Your total marks for the exam is %d out of 10.\n", marks);
}

int main() {
  welcomeMessage();
  subjectList();
  int subjectChoice = takeSubjectChoice();
  examInstructions();
  takeExam(subjectChoice);
  return 0;
}
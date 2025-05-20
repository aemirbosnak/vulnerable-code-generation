//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[20];
  int score;
} Student;

int main() {
  // Welcome message
  printf("Welcome to the Super Duper C Online Examination System!\n");
  printf("Prepare to be amazed by our cutting-edge technology and mind-boggling questions!\n");
  printf("Are you ready to unleash your inner genius? (Y/N)\n");

  // Get user input
  char input[2];
  scanf("%s", input);

  // Check if user is ready
  if (strcmp(input, "Y") != 0) {
    printf("Come on, don't be shy! We're not biting... or maybe we are, who knows!\n");
    return 0;
  }

  // Initialize student array
  Student students[10];

  // Get student names and scores
  for (int i = 0; i < 10; i++) {
    printf("Enter student %d's name: ", i + 1);
    scanf("%s", students[i].name);
    printf("Enter student %d's score: ", i + 1);
    scanf("%d", &students[i].score);
  }

  // Print student names and scores
  printf("\nHere are the results:\n");
  for (int i = 0; i < 10; i++) {
    printf("%s: %d\n", students[i].name, students[i].score);
    if (students[i].score >= 90) {
      printf("Excellent work, %s! You're a true coding ninja!\n", students[i].name);
    } else if (students[i].score >= 70) {
      printf("Good job, %s! Keep up the good work!\n", students[i].name);
    } else if (students[i].score >= 50) {
      printf("Well done, %s! You're on the right track!\n", students[i].name);
    } else {
      printf("Don't worry, %s! Practice makes perfect.\n", students[i].name);
    }
  }

  // Farewell message
  printf("\nThank you for taking our Super Duper C Online Examination System!\n");
  printf("We hope you enjoyed the challenge and learned a lot along the way.\n");
  printf("Remember, the true measure of your success is not the score you get, but the knowledge you gain.\n");
  printf("Keep coding, keep learning, and keep rocking the world!\n");

  return 0;
}
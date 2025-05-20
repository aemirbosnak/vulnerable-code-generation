//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: inquisitive
#include <stdio.h>

int main() {
  char answer1, answer2, answer3;

  // Introduction
  printf("Welcome to the Inquisitive Adventure Game!\n");
  printf("You will be asked a series of questions.\n");
  printf("Please answer truthfully.\n\n");
  
  // First Question
  printf("Question 1: Do you prefer cats or dogs? (c/d)\n");
  scanf(" %c", &answer1);

  if (answer1 == 'c') {
    printf("Interesting choice. On to the next question.\n\n");
  } else if (answer1 == 'd') {
    printf("Great choice! Dogs are the best.\n\n");
  } else {
    printf("Invalid answer. Please try again.\n\n");
    return 0;
  }

  // Second Question
  printf("Question 2: Would you rather live in a big city or a small town? (c/t)\n");
  scanf(" %c", &answer2);

  if (answer2 == 'c') {
    printf("City life, huh? Alright.\n\n");
  } else if (answer2 == 't') {
    printf("Small town living, I see. Interesting.\n\n");
  } else {
    printf("Invalid answer. Please try again.\n\n");
    return 0;
  }

  // Third Question
  printf("Question 3: What is your favorite color? (b/g/r)\n");
  scanf(" %c", &answer3);

  switch (answer3) {
    case 'b':
      printf("Blue is a nice color.\n\n");
      break;
    case 'g':
      printf("Green is a great color!\n\n");
      break;
    case 'r':
      printf("Red is a bold choice.\n\n");
      break;
    default:
      printf("Invalid answer. Please try again.\n\n");
      return 0;
  }

  // Conclusion
  printf("Thanks for playing the Inquisitive Adventure Game!\n");
  
  return 0;
}
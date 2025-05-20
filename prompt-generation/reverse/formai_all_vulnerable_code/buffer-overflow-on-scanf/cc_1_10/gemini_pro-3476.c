//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Welcome banner
void welcome() {
  printf("********************************************************************************\n");
  printf("*                                                                              *\n");
  printf("*                                                                              *\n");
  printf("*                 Welcome to the Ultimate Typing Speed Test!                      *\n");
  printf("*                                                                              *\n");
  printf("*                 Get ready to put your fingers to the test!                    *\n");
  printf("*                                                                              *\n");
  printf("*                                                                              *\n");
  printf("********************************************************************************\n");
}

// Instructions
void instructions() {
  printf("********************************************************************************\n");
  printf("*                                                                              *\n");
  printf("*                                                                              *\n");
  printf("*                                Instructions                                 *\n");
  printf("*                                                                              *\n");
  printf("* - Type the text that appears on the screen as quickly and accurately as possible. *\n");
  printf("* - The test will last for 30 seconds.                                       *\n");
  printf("* - You will be scored on speed (characters per minute) and accuracy (percentage). *\n");
  printf("* - Press any key to start the test.                                         *\n");
  printf("*                                                                              *\n");
  printf("*                                                                              *\n");
  printf("********************************************************************************\n");
}

// Generate random text
char* generateText(int length) {
  char* text = (char*)malloc(length + 1);
  for (int i = 0; i < length; i++) {
    text[i] = (rand() % 26) + 'a';
  }
  text[length] = '\0';
  return text;
}

// Get user input
char* getUserInput() {
  char* input = (char*)malloc(1000);
  printf("Type the following text: ");
  scanf("%s", input);
  return input;
}

// Calculate speed
int calculateSpeed(int length, double time) {
  return (int)((double)length / time * 60);
}

// Calculate accuracy
int calculateAccuracy(char* text, char* input) {
  int length = strlen(text);
  int errors = 0;
  for (int i = 0; i < length; i++) {
    if (text[i] != input[i]) {
      errors++;
    }
  }
  return (int)(((double)(length - errors) / length) * 100);
}

// Display results
void displayResults(int speed, int accuracy) {
  printf("********************************************************************************\n");
  printf("*                                                                              *\n");
  printf("*                                                                              *\n");
  printf("*                                Results                                  *\n");
  printf("*                                                                              *\n");
  printf("* - Speed: %d characters per minute                                     *\n", speed);
  printf("* - Accuracy: %d%%                                                        *\n");
  printf("*                                                                              *\n");
  printf("*                                                                              *\n");
  printf("********************************************************************************\n");
}

// Main function
int main() {
  // Welcome the user
  welcome();
  
  // Display instructions
  instructions();
  
  // Get user input
  char* input = getUserInput();
  
  // Calculate speed and accuracy
  int speed = calculateSpeed(strlen(input), 30);
  int accuracy = calculateAccuracy(input, input);
  
  // Display results
  displayResults(speed, accuracy);
  
  return 0;
}
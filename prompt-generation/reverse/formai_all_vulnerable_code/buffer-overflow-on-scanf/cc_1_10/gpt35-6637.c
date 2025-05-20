//FormAI DATASET v1.0 Category: Image Classification system ; Style: happy
#include <stdio.h>

// Welcome message
void printWelcome() {
  printf("Hello there! I am a happy image classification system program.\n");
}

// Ask for user input
void askForInput(char *prompt) {
  printf("%s", prompt);
}

// Check if input is valid
int isValidInput(int input) {
  if (input >= 0 && input <= 3) {
    return 1;
  } else {
    return 0;
  }
}

// Perform image classification
void classifyImage(int input) {
  switch (input) {
    case 0:
      printf("This is a picture of a cute puppy!\n");
      break;
    case 1:
      printf("This is a picture of a beautiful flower!\n");
      break;
    case 2:
      printf("This is a picture of a delicious pizza!\n");
      break;
    case 3:
      printf("This is a picture of a stunning sunset!\n");
      break;
    default:
      printf("I'm sorry, I couldn't classify this image.\n");
  }
}

// Main function
int main() {
  // Variables
  int input;
  char prompt[] = "Enter the type of image (0 = puppy, 1 = flower, 2 = pizza, 3 = sunset): ";
  
  // Start program
  printWelcome();
  
  while (1) {
    // Ask for input and validate
    askForInput(prompt);
    scanf("%d", &input);
    
    if (!isValidInput(input)) {
      printf("Invalid input. Please try again.\n");
      continue;
    }
    
    // Classify image
    classifyImage(input);
  }
  
  return 0;
}
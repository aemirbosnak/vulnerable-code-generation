//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: excited
#include <stdio.h>

// Function to print the instructions
void print_instructions() {
  printf("************************************************************************************************************\n");
  printf("*                                      WELCOME TO THE TOWER OF HANOI                                         *\n");
  printf("************************************************************************************************************\n\n");

  printf("Objective: Move all the disks from the source pole to the destination pole, following these rules:\n");
  printf("1. Only one disk can be moved at a time.\n");
  printf("2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack.\n");
  printf("3. No disk may be placed on top of a smaller disk.\n\n");

  printf("Here are the steps to play the game:\n");
  printf("1. Enter the number of disks you want to use (minimum 3).\n");
  printf("2. Enter the source pole (A, B, or C).\n");
  printf("3. Enter the destination pole (A, B, or C).\n");
  printf("4. Enter the number of moves you want to make (minimum 1).\n\n");
}

// Function to get the user input
void get_user_input(int *num_disks, char *source_pole, char *destination_pole, int *num_moves) {
  // Get the number of disks
  printf("Enter the number of disks (minimum 3): ");
  scanf("%d", num_disks);

  // Get the source pole
  printf("Enter the source pole (A, B, or C): ");
  scanf(" %c", source_pole);

  // Get the destination pole
  printf("Enter the destination pole (A, B, or C): ");
  scanf(" %c", destination_pole);

  // Get the number of moves
  printf("Enter the number of moves (minimum 1): ");
  scanf("%d", num_moves);
}

// Function to check if the input is valid
int is_valid_input(int num_disks, char source_pole, char destination_pole, int num_moves) {
  // Check if the number of disks is valid
  if (num_disks < 3) {
    printf("Error: The number of disks must be at least 3.\n");
    return 0;
  }

  // Check if the source pole is valid
  if (source_pole != 'A' && source_pole != 'B' && source_pole != 'C') {
    printf("Error: The source pole must be A, B, or C.\n");
    return 0;
  }

  // Check if the destination pole is valid
  if (destination_pole != 'A' && destination_pole != 'B' && destination_pole != 'C') {
    printf("Error: The destination pole must be A, B, or C.\n");
    return 0;
  }

  // Check if the number of moves is valid
  if (num_moves < 1) {
    printf("Error: The number of moves must be at least 1.\n");
    return 0;
  }

  return 1;
}

// Function to move the disks
void move_disks(int num_disks, char source_pole, char destination_pole, char temp_pole) {
  // Base case: If there is only one disk, move it to the destination pole
  if (num_disks == 1) {
    printf("Move disk 1 from pole %c to pole %c.\n", source_pole, destination_pole);
    return;
  }

  // Recursive case: Move the top num_disks - 1 disks from the source pole to the temp pole
  move_disks(num_disks - 1, source_pole, temp_pole, destination_pole);

  // Move the bottom disk from the source pole to the destination pole
  printf("Move disk %d from pole %c to pole %c.\n", num_disks, source_pole, destination_pole);

  // Recursive case: Move the num_disks - 1 disks from the temp pole to the destination pole
  move_disks(num_disks - 1, temp_pole, destination_pole, source_pole);
}

// Main function
int main() {
  // Print the instructions
  print_instructions();

  // Get the user input
  int num_disks;
  char source_pole;
  char destination_pole;
  int num_moves;
  get_user_input(&num_disks, &source_pole, &destination_pole, &num_moves);

  // Check if the input is valid
  if (!is_valid_input(num_disks, source_pole, destination_pole, num_moves)) {
    return 1;
  }

  // Move the disks
  move_disks(num_disks, source_pole, destination_pole, 'A' + 3 - source_pole - destination_pole);

  return 0;
}
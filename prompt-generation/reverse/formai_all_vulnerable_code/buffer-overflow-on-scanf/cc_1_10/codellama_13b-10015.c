//Code Llama-13B DATASET v1.0 Category: Electronic Voting System ; Style: happy
// Happy EVS Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Function to display the welcome message
void display_welcome() {
  printf("Welcome to the Happy EVS System\n");
  printf("Please enter your name: ");
  char name[20];
  scanf("%s", name);
  printf("Hello %s!\n", name);
}

// Function to display the election options
void display_options() {
  printf("Select your preferred candidate:\n");
  printf("1. Candidate 1\n");
  printf("2. Candidate 2\n");
  printf("3. Candidate 3\n");
}

// Function to display the results
void display_results(int votes[3]) {
  printf("The results are in!\n");
  printf("Candidate 1: %d votes\n", votes[0]);
  printf("Candidate 2: %d votes\n", votes[1]);
  printf("Candidate 3: %d votes\n", votes[2]);
}

// Function to calculate the winner
void calculate_winner(int votes[3]) {
  int winner = 0;
  for (int i = 1; i < 3; i++) {
    if (votes[i] > votes[winner]) {
      winner = i;
    }
  }
  printf("The winner is Candidate %d!\n", winner + 1);
}

// Function to display the menu
void display_menu() {
  printf("1. Cast your vote\n");
  printf("2. Display results\n");
  printf("3. Exit\n");
}

// Function to handle the user input
void handle_input(int *vote, int votes[3]) {
  int choice;
  scanf("%d", &choice);
  switch (choice) {
    case 1:
      printf("You have chosen to cast your vote\n");
      printf("Please select your preferred candidate:\n");
      printf("1. Candidate 1\n");
      printf("2. Candidate 2\n");
      printf("3. Candidate 3\n");
      scanf("%d", vote);
      votes[*vote - 1]++;
      break;
    case 2:
      printf("You have chosen to display the results\n");
      display_results(votes);
      break;
    case 3:
      printf("You have chosen to exit the program\n");
      exit(0);
      break;
    default:
      printf("Invalid choice, please try again\n");
      handle_input(vote, votes);
  }
}

int main() {
  // Initialize the votes array
  int votes[3] = {0, 0, 0};
  // Initialize the vote variable
  int vote;

  // Display the welcome message
  display_welcome();

  // Display the menu
  display_menu();

  // Handle the user input
  handle_input(&vote, votes);

  // Calculate the winner
  calculate_winner(votes);

  // Display the results
  display_results(votes);

  // Exit the program
  exit(0);
}
//Code Llama-13B DATASET v1.0 Category: Text-Based Adventure Game ; Style: curious
/* Text-Based Adventure Game in C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variables
char *menu[] = {"1. Start Game", "2. How to Play", "3. Exit"};
char *game_over_message = "You have died. Game Over!";
char *win_message = "You have reached the treasure! Congratulations!";

// Functions
void print_menu();
void play_game();
void display_room(int room_number);
void display_treasure(int room_number);
void display_options(int room_number);
void print_game_over();
void print_win();

int main() {
  int choice;

  // Start the game
  printf("Welcome to the Text-Based Adventure Game!\n");
  print_menu();

  // Take input from user
  scanf("%d", &choice);

  // Check if user wants to start game or exit
  if (choice == 1) {
    play_game();
  } else if (choice == 3) {
    exit(0);
  } else {
    printf("Invalid choice. Please enter a valid choice.\n");
    print_menu();
  }

  // End the game
  printf("Thank you for playing the Text-Based Adventure Game.\n");
  return 0;
}

// Function to print the menu
void print_menu() {
  for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
    printf("%d. %s\n", i + 1, menu[i]);
  }
}

// Function to play the game
void play_game() {
  int room_number = 1;
  char option;

  while (1) {
    // Display current room
    display_room(room_number);

    // Display options
    display_options(room_number);

    // Take input from user
    scanf(" %c", &option);

    // Check if user has won or lost
    if (room_number == 5) {
      print_win();
      break;
    } else if (room_number == 0) {
      print_game_over();
      break;
    }

    // Update room number based on user's choice
    switch (option) {
      case 'N':
        room_number++;
        break;
      case 'S':
        room_number--;
        break;
      case 'E':
        room_number += 2;
        break;
      case 'W':
        room_number -= 2;
        break;
      default:
        printf("Invalid choice. Please enter a valid option.\n");
        break;
    }
  }
}

// Function to display room
void display_room(int room_number) {
  switch (room_number) {
    case 1:
      printf("You are in a dark room. There is a door to the north and a door to the south.\n");
      break;
    case 2:
      printf("You are in a room with a big red button. There is a door to the north and a door to the south.\n");
      break;
    case 3:
      printf("You are in a room with a big green button. There is a door to the north and a door to the south.\n");
      break;
    case 4:
      printf("You are in a room with a big blue button. There is a door to the north and a door to the south.\n");
      break;
    case 5:
      printf("You have reached the treasure room! There is a chest with a big red X on it. You have won the game! Congratulations!\n");
      break;
    default:
      printf("You are in a room with no doors. You have died. Game Over!\n");
      break;
  }
}

// Function to display options
void display_options(int room_number) {
  switch (room_number) {
    case 1:
      printf("Enter 'N' to go north, 'S' to go south, 'E' to go east, or 'W' to go west.\n");
      break;
    case 2:
      printf("Enter 'N' to go north, 'S' to go south, 'E' to go east, or 'W' to go west.\n");
      break;
    case 3:
      printf("Enter 'N' to go north, 'S' to go south, 'E' to go east, or 'W' to go west.\n");
      break;
    case 4:
      printf("Enter 'N' to go north, 'S' to go south, 'E' to go east, or 'W' to go west.\n");
      break;
    case 5:
      printf("Enter 'N' to go north, 'S' to go south, 'E' to go east, or 'W' to go west.\n");
      break;
    default:
      printf("You have died. Game Over! Enter any key to exit.\n");
      break;
  }
}

// Function to display game over message
void print_game_over() {
  printf("Game Over!\n");
}

// Function to display win message
void print_win() {
  printf("Congratulations! You have reached the treasure room! You have won the game!\n");
}
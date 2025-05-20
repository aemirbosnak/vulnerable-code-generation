//Falcon2-11B DATASET v1.0 Category: Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

const char* player_choices[] = {"rock", "paper", "scissors"};
const char* computer_choices[] = {"rock", "paper", "scissors"};

int get_player_choice() {
  int choice = -1;
  printf("Choose rock, paper, or scissors: ");
  while (choice < 0 || choice >= 3) {
    if (fscanf(stdin, "%d", &choice)!= 1) {
      printf("Invalid input. Please choose rock, paper, or scissors.\n");
    } else {
      break;
    }
  }
  return choice;
}

int get_computer_choice() {
  int choice = rand() % 3;
  return choice;
}

bool is_winner(const char* choice1, const char* choice2) {
  if (strcmp(choice1, choice2) == 0) {
    return false;
  } else if ((choice1 == "rock" && choice2 == "scissors") ||
           (choice1 == "paper" && choice2 == "rock") ||
           (choice1 == "scissors" && choice2 == "paper")) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int player_choice = get_player_choice();
  int computer_choice = get_computer_choice();
  int rounds = 0;

  while (true) {
    if (is_winner(player_choices[player_choice], computer_choices[computer_choice])) {
      printf("You win! %s beats %s.\n", player_choices[player_choice], computer_choices[computer_choice]);
      break;
    } else if (is_winner(computer_choices[computer_choice], player_choices[player_choice])) {
      printf("You lose! %s beats %s.\n", computer_choices[computer_choice], player_choices[player_choice]);
      break;
    } else {
      rounds++;
      printf("Round %d: It's a tie!\n", rounds);
    }

    player_choice = get_player_choice();
    computer_choice = get_computer_choice();
  }

  return 0;
}
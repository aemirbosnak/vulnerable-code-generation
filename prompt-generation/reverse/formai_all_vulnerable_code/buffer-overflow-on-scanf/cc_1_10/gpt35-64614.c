//FormAI DATASET v1.0 Category: Table Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed the random number generator with the current time
  int player_score = 0;
  int dealer_score = 0;

  printf("Welcome to the C Table Game!\n");

  while (1) { // loop until the game ends
    printf("\nYour Score: %d\n", player_score);
    printf("Dealer's Score: %d\n", dealer_score);

    char choice;
    printf("Do you want to hit (h) or stay (s)? ");
    scanf("%c", &choice);

    if (choice == 'h') { // player hits
      int card = rand() % 10 + 1; // generate random number between 1 and 10
      printf("You drew a %d!\n", card);
      player_score += card;
      if (player_score > 21) {
        printf("Bust! Dealer wins.\n");
        break;
      }
    } else if (choice == 's') { // player stays
      printf("You stayed.\n");
      break;
    } else { // invalid choice
      printf("Invalid choice. Try again.\n");
      continue;
    }

    // dealer's turn
    if (dealer_score < 17) { // dealer hits
      int card = rand() % 10 + 1;
      printf("Dealer drew a %d!\n", card);
      dealer_score += card;
      if (dealer_score > 21) {
        printf("Dealer bust! You win.\n");
        break;
      }
    } else { // dealer stays
      printf("Dealer stayed.\n");
      break;
    }
  }

  // determine winner
  if (player_score > dealer_score && player_score <= 21) {
    printf("Congratulations! You win.\n");
  } else {
    printf("Sorry, you lose.\n");
  }

  return 0;
}
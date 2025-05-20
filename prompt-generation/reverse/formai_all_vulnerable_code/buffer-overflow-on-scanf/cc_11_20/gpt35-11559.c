//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: multiplayer
#include <stdio.h>

// define the struct for a player
struct Player {
  char name[20];
  int money;
};

int main() {
  // create an array of players
  struct Player players[4];
  int num_players;
  
  // get the number of players from the user
  printf("Enter the number of players: ");
  scanf("%d", &num_players);
  getchar();
  
  // get the name and starting money for each player
  for (int i = 0; i < num_players; i++) {
    printf("Enter player %d's name: ", i+1);
    fgets(players[i].name, 20, stdin);
    printf("Enter player %d's starting money: ", i+1);
    scanf("%d", &players[i].money);
    getchar();
  }
  
  // display the current state of the game
  printf("\nCurrent state of the game:\n");
  for (int i = 0; i < num_players; i++) {
    printf("%s has %d money.\n", players[i].name, players[i].money);
  }
  
  // prompt each player to make a financial move
  for (int i = 0; i < num_players; i++) {
    printf("It is %s's turn.\n", players[i].name);
    printf("What would you like to do?\n");
    printf("1. Invest\n");
    printf("2. Purchase\n");
    printf("3. Save\n");
    printf("4. Quit the game\n");
    
    int choice;
    scanf("%d", &choice);
    getchar();
    
    // handle the player's choice
    switch (choice) {
      case 1:
        printf("How much would you like to invest? ");
        int investment;
        scanf("%d", &investment);
        if (investment > players[i].money) {
          printf("Sorry, you don't have enough money to make that investment.\n");
        } else {
          players[i].money -= investment;
          printf("You've invested %d. You now have %d money.\n", investment, players[i].money);
        }
        break;
      case 2:
        printf("What would you like to purchase? ");
        char purchase[20];
        fgets(purchase, 20, stdin);
        printf("How much does %s cost? ", purchase);
        int cost;
        scanf("%d", &cost);
        if (cost > players[i].money) {
          printf("Sorry, you don't have enough money to purchase %s.\n", purchase);
        } else {
          players[i].money -= cost;
          printf("You've purchased %s for %d. You now have %d money.\n", purchase, cost, players[i].money);
        }
        break;
      case 3:
        printf("How much would you like to save? ");
        int save;
        scanf("%d", &save);
        players[i].money += save;
        printf("You've saved %d. You now have %d money.\n", save, players[i].money);
        break;
      case 4:
        printf("Goodbye!\n");
        return 0;
      default:
        printf("Invalid choice.\n");
        break;
    }
  }
  
  // display the final state of the game
  printf("\nFinal state of the game:\n");
  for (int i = 0; i < num_players; i++) {
    printf("%s has %d money.\n", players[i].name, players[i].money);
  }
  
  return 0;
}
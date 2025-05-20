//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: rigorous
#include <stdio.h>

int main() {
  printf("Welcome to the Text-Based Adventure Game!\n\n");
  
  int choice;
  int restart = 1;

  while (restart == 1) {
    printf("You wake up in the middle of a forest. What do you do?\n\n");
    printf("1. Look around\n");
    printf("2. Stay put\n");
    printf("3. Walk around randomly\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nYou look around and see a stream to your left and a cave to your right.\n");
        printf("What would you like to do next?\n\n");
        printf("1. Follow the stream\n");
        printf("2. Explore the cave\n");
        printf("3. Stay put\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
          case 1:
            printf("\nYou follow the stream and find a small village. Congratulations, you have completed the game!\n");
            printf("Would you like to play again? (1 for yes / 0 for no): ");
            scanf("%d", &restart);
            break;
          case 2:
            printf("\nYou enter the cave and find a bear. The bear attacks you and you die. Game over :(\n");
            printf("Would you like to play again? (1 for yes / 0 for no): ");
            scanf("%d", &restart);
            break;
          case 3:
            printf("\nYou stay put and nothing happens. Boring, but at least you're safe.\n");
            printf("What would you like to do next?\n\n");
            printf("1. Follow the stream\n");
            printf("2. Explore the cave\n");
            printf("3. Stay put\n");

            printf("\nEnter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
              case 1:
                printf("\nYou follow the stream and find a small village. Congratulations, you have completed the game!\n");
                printf("Would you like to play again? (1 for yes / 0 for no): ");
                scanf("%d", &restart);
                break;
              case 2:
                printf("\nYou enter the cave and find a bear. The bear attacks you and you die. Game over :(\n");
                printf("Would you like to play again? (1 for yes / 0 for no): ");
                scanf("%d", &restart);
                break;
              case 3:
                printf("\nYou stay put and nothing happens. Boring, but at least you're safe. You sleep for the night and wake up to find that a search team has found you. You are rescued!\n");
                printf("Congratulations, you have completed the game!\n");
                printf("Would you like to play again? (1 for yes / 0 for no): ");
                scanf("%d", &restart);
                break;
              default:
                printf("\nInvalid choice. Please try again.\n");
                break;
            }
            break;
          default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
        break;
      case 2:
        printf("\nYou stay put and nothing happens. Boring, but at least you're safe.\n");
        printf("What would you like to do next?\n\n");
        printf("1. Look around\n");
        printf("2. Walk around randomly\n");
        printf("3. Stay put\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
          printf("\nYou stay put and nothing happens. Boring, but at least you're safe. You sleep for the night and wake up to find that a search team has found you. You are rescued!\n");
          printf("Congratulations, you have completed the game!\n");
          printf("Would you like to play again? (1 for yes / 0 for no): ");
          scanf("%d", &restart);
        } else {
          printf("\nYou wander off and get lost. You eventually die of starvation. Game over :(\n");
          printf("Would you like to play again? (1 for yes / 0 for no): ");
          scanf("%d", &restart);
        }
        break;
      case 3:
        printf("\nYou wander off and get lost. You eventually die of starvation. Game over :(\n");
        printf("Would you like to play again? (1 for yes / 0 for no): ");
        scanf("%d", &restart);
        break;
      default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
  }

  return 0;
}
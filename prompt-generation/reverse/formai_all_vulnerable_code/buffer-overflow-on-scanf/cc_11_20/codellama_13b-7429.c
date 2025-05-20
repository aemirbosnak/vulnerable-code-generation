//Code Llama-13B DATASET v1.0 Category: Text-Based Adventure Game ; Style: happy
void main() {
  char name[100];
  int choice;
  int score = 0;

  printf("Welcome to the Happy Adventure Game!\n");
  printf("What is your name? ");
  scanf("%s", name);

  while (choice != 4) {
    printf("You are in a room with a door to the north, a door to the south, a door to the east, and a door to the west.\n");
    printf("What do you want to do?\n");
    printf("1. Go north\n");
    printf("2. Go south\n");
    printf("3. Go east\n");
    printf("4. Go west\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("You open the door and find a room with a large pile of gold coins.\n");
        printf("You take the gold coins and add them to your score.\n");
        score += 100;
        break;
      case 2:
        printf("You open the door and find a room with a group of friendly creatures.\n");
        printf("They give you a gift and add 50 points to your score.\n");
        score += 50;
        break;
      case 3:
        printf("You open the door and find a room with a treacherous obstacle.\n");
        printf("You must solve the obstacle to continue.\n");
        printf("What do you do?\n");
        printf("1. Try to climb over the obstacle\n");
        printf("2. Try to jump over the obstacle\n");
        printf("3. Use a different strategy\n");
        scanf("%d", &choice);

        switch (choice) {
          case 1:
            printf("You try to climb over the obstacle, but it is too high.\n");
            printf("You fall and lose 20 points.\n");
            score -= 20;
            break;
          case 2:
            printf("You try to jump over the obstacle, but you don't have enough power.\n");
            printf("You fall and lose 25 points.\n");
            score -= 25;
            break;
          case 3:
            printf("You use a different strategy and succeed.\n");
            printf("You earn 30 points.\n");
            score += 30;
            break;
        }
        break;
      case 4:
        printf("You open the door and find a room with a mysterious creature.\n");
        printf("What do you do?\n");
        printf("1. Attack the creature\n");
        printf("2. Try to run away\n");
        printf("3. Use magic\n");
        scanf("%d", &choice);

        switch (choice) {
          case 1:
            printf("You attack the creature, but it is too powerful.\n");
            printf("You lose 40 points.\n");
            score -= 40;
            break;
          case 2:
            printf("You try to run away, but the creature is too fast.\n");
            printf("You lose 30 points.\n");
            score -= 30;
            break;
          case 3:
            printf("You use magic and defeat the creature.\n");
            printf("You earn 50 points.\n");
            score += 50;
            break;
        }
        break;
    }
  }

  printf("Your final score is %d.\n", score);
}
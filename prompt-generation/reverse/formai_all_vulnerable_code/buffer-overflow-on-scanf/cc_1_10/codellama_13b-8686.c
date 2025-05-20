//Code Llama-13B DATASET v1.0 Category: Table Game ; Style: paranoid
void main() {
  char player_name[30];
  char computer_name[30];
  int player_score = 0;
  int computer_score = 0;
  int dice_roll;
  int guess;

  printf("Welcome to the Paranoid Table Game!\n");
  printf("Please enter your name: ");
  scanf("%s", player_name);
  printf("Please enter the name of the computer: ");
  scanf("%s", computer_name);

  while (1) {
    printf("Player %s, please roll the dice: ", player_name);
    scanf("%d", &dice_roll);
    printf("You rolled %d!\n", dice_roll);

    if (dice_roll == 1) {
      printf("Player %s, you rolled a 1!\n", player_name);
      player_score = 0;
      printf("Player %s, your score is now %d.\n", player_name, player_score);
      break;
    } else if (dice_roll == 6) {
      printf("Player %s, you rolled a 6!\n", player_name);
      player_score += 6;
      printf("Player %s, your score is now %d.\n", player_name, player_score);
    } else {
      printf("Player %s, you rolled a %d.\n", player_name, dice_roll);
      player_score += dice_roll;
      printf("Player %s, your score is now %d.\n", player_name, player_score);
    }

    printf("Computer %s, please roll the dice: ", computer_name);
    scanf("%d", &dice_roll);
    printf("The computer rolled %d!\n", dice_roll);

    if (dice_roll == 1) {
      printf("Computer %s, you rolled a 1!\n", computer_name);
      computer_score = 0;
      printf("Computer %s, your score is now %d.\n", computer_name, computer_score);
      break;
    } else if (dice_roll == 6) {
      printf("Computer %s, you rolled a 6!\n", computer_name);
      computer_score += 6;
      printf("Computer %s, your score is now %d.\n", computer_name, computer_score);
    } else {
      printf("Computer %s, you rolled a %d.\n", computer_name, dice_roll);
      computer_score += dice_roll;
      printf("Computer %s, your score is now %d.\n", computer_name, computer_score);
    }

    if (player_score > computer_score) {
      printf("Player %s wins the game!\n", player_name);
      break;
    } else if (computer_score > player_score) {
      printf("Computer %s wins the game!\n", computer_name);
      break;
    } else {
      printf("The game is a tie!\n");
      break;
    }
  }
}
//FormAI DATASET v1.0 Category: Online Examination System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Initialize random seed
  int questions[10][6]; // Array to hold the questions and answers

  // Fill in the questions array with surreal data
  questions[0][0] = 1;
  questions[0][1] = 2;
  questions[0][2] = 3;
  questions[0][3] = 4;
  questions[0][4] = 5;
  questions[0][5] = 6;

  questions[1][0] = 7;
  questions[1][1] = 8;
  questions[1][2] = 9;
  questions[1][3] = 10;
  questions[1][4] = 11;
  questions[1][5] = 12;

  questions[2][0] = 13;
  questions[2][1] = 14;
  questions[2][2] = 15;
  questions[2][3] = 16;
  questions[2][4] = 17;
  questions[2][5] = 18;

  questions[3][0] = 19;
  questions[3][1] = 20;
  questions[3][2] = 21;
  questions[3][3] = 22;
  questions[3][4] = 23;
  questions[3][5] = 24;

  questions[4][0] = 25;
  questions[4][1] = 26;
  questions[4][2] = 27;
  questions[4][3] = 28;
  questions[4][4] = 29;
  questions[4][5] = 30;

  questions[5][0] = 31;
  questions[5][1] = 32;
  questions[5][2] = 33;
  questions[5][3] = 34;
  questions[5][4] = 35;
  questions[5][5] = 36;

  questions[6][0] = 37;
  questions[6][1] = 38;
  questions[6][2] = 39;
  questions[6][3] = 40;
  questions[6][4] = 41;
  questions[6][5] = 42;

  questions[7][0] = 43;
  questions[7][1] = 44;
  questions[7][2] = 45;
  questions[7][3] = 46;
  questions[7][4] = 47;
  questions[7][5] = 48;

  questions[8][0] = 49;
  questions[8][1] = 50;
  questions[8][2] = 51;
  questions[8][3] = 52;
  questions[8][4] = 53;
  questions[8][5] = 54;

  questions[9][0] = 55;
  questions[9][1] = 56;
  questions[9][2] = 57;
  questions[9][3] = 58;
  questions[9][4] = 59;
  questions[9][5] = 60;

  int score = 0; // Initialize player score to 0

  // Prompt user for their name surreally
  char name[20];
  printf("What is your name, O gentle visitor of the code? ");
  fgets(name, sizeof(name), stdin);
  printf("\nWelcome, %s", name);

  // Loop through the questions array, displaying each one and prompting
  // the user for an answer
  for (int i = 0; i < 10; i++) {
    printf("\nQuestion %d: Please select the most surreal answer:\n", i + 1);
    printf("%d + %d = ?\n", questions[i][0], questions[i][1]);
    printf("1) %d\n", questions[i][2]);
    printf("2) %d\n", questions[i][3]);
    printf("3) %d\n", questions[i][4]);
    printf("4) %d\n", questions[i][5]);

    int player_answer;
    printf("Your answer: ");
    scanf("%d", &player_answer);
    while(getchar() != '\n'); // Clear input buffer

    // Generate a random humorous response to the player's answer
    int random_response = rand() % 5;
    switch (random_response) {
      case 0:
        printf("\n\"Alas, poor Yorick! I knew not you had a head for math!\" quoth the system.\n");
        break;
      case 1:
        printf("\n\"Behold, a rare sight indeed -- a unicorn prancing to and fro!\" jeered the system.\n");
        break;
      case 2:
        printf("\n\"Welcome to Wonderland, O Alice!\" exclaimed the system.\n");
        break;
      case 3:
        printf("\n\"Fair thee well! Thou hast not learned thy sum-buttin' yet!\" cried the system.\n");
        break;
      case 4:
        printf("\n\"The answer, my friend, is blowin' in the wind, like Bob Dylan's harmonica!\" sang the system.\n");
        break;
      default:
        printf("\n\"My apologies, O master of mystery!\" begged the system.\n");
        break;
    }

    // Evaluate the player's answer and update their score accordingly
    if (player_answer == questions[i][2]) {
      printf("Correct!\n");
      score++;
    } else {
      printf("Incorrect!\n");
    }
  }

  // Display the player's final score and a surreal parting message
  printf("\nYour final score is: %d out of 10\n", score);

  // Generate a random parting message
  int random_parting = rand() % 5;
  switch (random_parting) {
    case 0:
      printf("\n\"Farewell, fair one! May your code be surreally sublime!\" bid the system.\n");
      break;
    case 1:
      printf("\n\"May your dreams be sweeter than a surreal Salvador Dali painting!\" quoth the system.\n");
      break;
    case 2:
      printf("\n\"Au revoir, mon cheri! May the code be ever in your favor!\" said the system.\n");
      break;
    case 3:
      printf("\n\"Remember, dear one -- the answer is always 42!\" winked the system.\n");
      break;
    case 4:
      printf("\n\"Adieu, O keeper of the keys to the code kingdom!\" exclaimed the system.\n");
      break;
    default:
      printf("\n\"Thank you, O wise one, for playing this surrealist game of wit and whimsy!\" proclaimed the system.\n");
      break;
  }

  return 0;
}
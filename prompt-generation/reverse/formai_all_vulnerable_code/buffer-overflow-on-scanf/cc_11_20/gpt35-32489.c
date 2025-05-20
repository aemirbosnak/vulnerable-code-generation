//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("\nWelcome to the Haunted House Simulator!\n");
  printf("You find yourself standing in front of an old, abandoned house.\n");
  printf("It's dark outside and the wind is howling.\n");
  printf("Do you want to enter the house? (y/n)\n");

  char choice;
  scanf("%c", &choice);

  if (choice == 'n') {
    printf("You decide not to enter the house and turn around to leave.\n");
    printf("As you begin to walk away, you hear footsteps behind you...\n");
    printf("GAME OVER\n");
    return 0;
  }

  printf("You cautiously enter the house and look around.\n");
  printf("There's a long hallway with cobwebs and dust covering everything.\n");
  printf("You decide to explore further.\n");

  int room = 1;

  while (room <= 5) {
    printf("You enter room %d.\n", room);

    if (room == 1) {
      // describe room 1
      printf("This room is empty except for an old rocking chair.\n");
      printf("As you walk past the chair, it starts to rock on its own...\n");
      printf("Do you investigate? (y/n)\n");

      scanf(" %c", &choice);

      if (choice == 'y') {
        printf("You approach the chair and look at it closely.\n");
        printf("Suddenly, you hear a whisper in your ear...\n");
        printf("GAME OVER\n");
        return 0;
      }
    }
    else if (room == 2) {
      // describe room 2
      printf("You enter a room with a large fireplace.\n");
      printf("As you walk closer to the fire, you feel the temperature rise.\n");

      srand(time(NULL));
      int chance = rand() % 2;

      if (chance == 0) {
        printf("Suddenly, the fire flares up and a ghostly figure appears in front of you...\n");
        printf("GAME OVER\n");
        return 0;
      }
      else {
        printf("You feel a warm, comforting presence surround you.\n");
      }
    }
    else if (room == 3) {
      // describe room 3
      printf("This room is filled with antique dolls.\n");
      printf("As you walk through the room, the dolls' eyes seem to follow you...\n");
      printf("Do you want to investigate further? (y/n)\n");

      scanf(" %c", &choice);

      if (choice == 'y') {
        printf("You start to examine one of the dolls when suddenly it comes to life!\n");
        printf("You jump back in terror as the dolls surround you...\n");
        printf("GAME OVER\n");
        return 0;
      }
    }
    else if (room == 4) {
      // describe room 4
      printf("You enter a room with a grand piano in the center.\n");
      printf("As you walk closer to the piano, you hear a soft melody playing.\n");

      srand(time(NULL));
      int chance = rand() % 2;

      if (chance == 0) {
        printf("Suddenly, the melody turns into a haunting tune and the piano keys start to move on their own...\n");
        printf("GAME OVER\n");
        return 0;
      }
      else {
        printf("You feel a sense of calm wash over you as the melody continues to play.\n");
      }
    }
    else if (room == 5) {
      // describe room 5
      printf("You enter a room with an ancient tomb in the center.\n");
      printf("As you approach the tomb, you feel a cold wind on your face.\n");

      srand(time(NULL));
      int chance = rand() % 2;

      if (chance == 0) {
        printf("Suddenly, the lid of the tomb flies open and a mummy appears in front of you...\n");
        printf("GAME OVER\n");
        return 0;
      }
      else {
        printf("The tomb remains undisturbed as you move on to the next room.\n");
      }
    }

    printf("Do you want to continue exploring? (y/n)\n");
    scanf(" %c", &choice);

    if (choice == 'n') {
      printf("You decide to leave the house.\n");
      printf("As you turn to leave, you hear a voice whisper your name...\n");
      printf("GAME OVER\n");
      return 0;
    }

    room++;
  }

  printf("Congratulations, you've successfully explored the entire house!\n");
  printf("As you leave, you feel a sense of relief wash over you.\n");
  printf("You vow never to enter a haunted house again.\n");

  return 0;
}
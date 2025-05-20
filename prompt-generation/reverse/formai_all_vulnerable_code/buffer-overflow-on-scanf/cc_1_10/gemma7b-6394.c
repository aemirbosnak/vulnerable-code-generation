//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_haunted_house(void)
{
  system("clear");
  srand(time(NULL));
  int rand_num = rand() % 5;

  // Create a haunted house scenario
  switch (rand_num)
  {
    case 0:
      printf("You hear a rustling in the hallway.\n");
      printf("You turn around and see a ghostly figure standing there.\n");
      printf("The figure's eyes glow red, and its voice whispers in your ear, 'Get out of here.'\n");
      break;
    case 1:
      printf("You find a bloodstained letter on the floor.\n");
      printf("The letter is from a victim of the haunted house, detailing their harrowing experience.\n");
      printf("As you read the letter, you feel a cold hand brush against your back.\n");
      break;
    case 2:
      printf("You hear the sound of a child's laughter echoing through the halls.\n");
      printf("You turn around and see a ghostly child running towards you.\n");
      printf("The child's eyes are wide with fear, and it whispers, 'Please help me.'\n");
      break;
    case 3:
      printf("You encounter a demonic entity in the living room.\n");
      printf("The entity's skin is black, and its eyes are burning red.\n");
      printf("The entity's voice is cold and dripping, and it whispers, 'You will not escape me.'\n");
      break;
    case 4:
      printf("You find a hidden room filled with occult paraphernalia.\n");
      printf("The room is filled with candles and incense, and the air is thick with the scent of blood.\n");
      printf("You feel a presence in the room, and you sense that you are being watched.\n");
      break;
  }

  // Ask the user if they want to continue
  char continue_yn;
  printf("Do you want to continue? (Y/N): ");
  scanf("%c", &continue_yn);

  // If the user wants to continue, play the game again
  if (continue_yn == 'Y')
  {
    play_haunted_house();
  }
}

int main()
{
  play_haunted_house();

  return 0;
}
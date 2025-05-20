//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void goto_next_room(int room_num)
{
  switch (room_num)
  {
    case 1:
      printf("You have entered Room 1.\n");
      break;
    case 2:
      printf("You have entered Room 2.\n");
      break;
    case 3:
      printf("You have entered Room 3.\n");
      break;
  }
  system("pause");
  main();
}

int main()
{
  int room_num = 1;
  printf("You have entered the Mysterious Mansion.\n");
  printf("Please choose a direction (north, south, east, west): ");
  char direction;
  scanf("%c", &direction);

  switch (direction)
  {
    case 'n':
      room_num++;
      goto_next_room(room_num);
      break;
    case 's':
      room_num--;
      goto_next_room(room_num);
      break;
    case 'e':
      room_num++;
      goto_next_room(room_num);
      break;
    case 'w':
      room_num--;
      goto_next_room(room_num);
      break;
  }

  return 0;
}
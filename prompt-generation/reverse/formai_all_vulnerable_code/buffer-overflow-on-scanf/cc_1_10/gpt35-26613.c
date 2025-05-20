//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define TOTAL_ROOMS 10

void print_header() {
  printf("Welcome to the Haunted Mansion!\n");
  printf("================================\n");
}

void print_menu() {
  printf("Choose an option:\n");
  printf("1. Enter a room\n");
  printf("2. Leave the mansion\n");
}

void print_room_description(int room_num) {
  switch (room_num) {
    case 1:
      printf("You enter the foyer. The room is dimly lit and you can barely see a large painting hanging on the wall.\n");
      break;
    case 2:
      printf("You enter the dining room. The room is filled with cobwebs and a mummified carcass of a rat is laying on the table.\n");
      break;
    case 3:
      printf("You enter the kitchen. The room smells of rotting food and you see a shadow move in the corner.\n");
      break;
    case 4:
      printf("You enter the living room. The room is decorated with antique furniture and broken glass litters the floor.\n");
      break;
    case 5:
      printf("You enter the library. The room is freezing cold and you see books moving on their own.\n");
      break;
    case 6:
      printf("You enter the study. The room is covered in dust and you can barely see the outlines of old papers on the desk.\n");
      break;
    case 7:
      printf("You enter the master bedroom. The room is ornately decorated and you swear you hear a faint whispering.\n");
      break;
    case 8:
      printf("You enter the guest bedroom. The room is empty except for a single chair in the corner.\n");
      break;
    case 9:
      printf("You enter the bathroom. The room is dripping with water and the smell of rust fills your nose.\n");
      break;
    case 10:
      printf("You enter the attic. The room is filled with old furniture and antiques. You hear footsteps coming toward you.\n");
      break;
    default:
      printf("You've entered a nonexistent room. Please try again.\n");
      break;
  }
}

int main() {
  int current_room = 1;
  int choice;
  
  print_header();
  
  while (current_room > 0 && current_room <= TOTAL_ROOMS) {
    print_room_description(current_room);
    print_menu();
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        printf("You enter another room...\n");
        current_room++;
        break;
      case 2:
        printf("You flee from the mansion!\n");
        current_room = -1;
        break;
      default:
        printf("That's not an option. Please try again.\n");
        break;
    }
    
    printf("\n");
  }
  
  printf("Thanks for playing!\n");
  
  return 0;
}
//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Variables initialization
  int room = 1, health_points = 100;
  int spider_venom = 0, ghost_attack = 0, jump_scare = 0;
  char direction;
  srand(time(NULL));
  
  printf("\n\n║╔══════════════════════════╗\n");
  printf("║║       Haunted House       ║║\n");
  printf("║║           Simulator       ║║\n");
  printf("║║                            ║║\n");
  printf("║║     You have 100 health    ║║\n");
  printf("║╚══════════════════════════╝╝\n\n\n");
  
  // Main game loop
  while (room <= 10 && health_points > 0) {
    // Room description and options
    printf("You are in room %d\n", room);
    switch (room) {
      case 1:
        printf("You are in a dark foyer with a creaky floor. There is a door to the east and a door to the west. Which way do you want to go? [E/W]\n");
        break;
      case 2:
        printf("You enter a dimly lit living room with cobwebs in every corner. You hear strange noises in the darkness. To the south is a corridor and to the west is another room. Where do you want to go? [S/W]\n");
        break;
      case 3:
        printf("You enter a musty library stacked with ancient books and dimly lit by candle. To the north is the corridor and to the east is another room. Where do you want to go? [N/E]\n");
        break;
      case 4:
        printf("You are in a spacious bathroom with a clawfoot tub filled with murky water and a large mirror with a broken frame. The only exit is through the door to the west. Are you ready? [Y/N]\n");
        break;
      case 5:
        printf("You enter a dark hallway with dusty portraits on the walls. To the south is a door and to the east is a staircase leading down. Which way do you want to go? [S/E]\n");
        break;
      case 6:
        printf("You find yourself in a mysterious bedroom with a large canopy bed. Strange whispers can be heard in the silence. To the west is the hallway and to the south is the balcony. Where do you want to go? [W/S]\n");
        break;
      case 7:
        printf("You step onto the balcony with a stunning view of the mountains. The only way out is through the door to the north. Do you want to jump off? [Y/N]\n");
        break;
      case 8:
        printf("You enter a dark basement with cobwebs and long forgotten artifacts. You hear strange noises in the distance. To the south is a staircase leading up and to the east is another room. Which way do you want to go? [S/E]\n");
        break;
      case 9:
        printf("You are in a creepy laboratory with glass vials and bubbling liquids. The only way out is through the door to the west. Are you brave enough to drink the potion? [Y/N]\n");
        break;
      case 10:
        printf("You have finally found the exit door. Do you want to escape or stay for more adventure? [E/S]\n");
        break;
    }

    // User input and output
    scanf(" %c", &direction);
    switch (direction) {
      case 'E':
      case 'e':
        if (room == 1) {
          printf("You enter a dark kitchen with rusted utensils and empty cans on the counter. To the north is the door to the foyer and to the west is a door leading to the yard.\n");
          room++;
        } else if (room == 3) {
          printf("You enter a small bedroom with a twin bed and a dusty desk. To the west is the door to the library.\n");
          room++;
        } else if (room == 10) {
          printf("You escape the haunted house with your heart racing.\nCongratulations, you win!\n");
          return 0;
        } else {
          printf("You cannot go that way.\n");
        }
        break;
      case 'W':
      case 'w':
        if (room == 1) {
          printf("You enter a dusty dining room with a chandelier with no lights. To the north is the door to the foyer and to the east is a door leading to the yard.\n");
          room++;
        } else if (room == 2) {
          printf("You enter a cluttered kitchen with a moldy fridge and appliances that look like they were built in the 50s. To the east is the living room.\n");
          room--;
        } else if (room == 3) {
          printf("You enter a room with scratch marks on the walls and a broken window. There are no other exits, but something doesn't feel right.\n");
          jump_scare++;
          if (jump_scare == 3) {
            printf("\n\nBOO! A giant spider jumps on you, biting you and injecting venom into your veins.\nYou lose 25 health points.\n");
            spider_venom++;
            health_points -= 25;
            jump_scare = 0;
          }
        } else if (room == 4) {
          printf("You decide not to go into the dark closet with strange noises. To the east is the bathroom.\n");
        } else if (room == 5) {
          printf("You enter a bedroom with a large canopy bed and a strange necklace on the nightstand. To the west is the hallway.\n");
          room++;
        } else if (room == 8) {
          printf("You enter a dark room with a strange portal in the center. You feel like someone or something is watching you. To the west is the basement.\n");
        } else if (room == 9) {
          printf("You decide not to drink the potion and exit the laboratory. To the east is another room.\n");
        } else {
          printf("You cannot go that way.\n");
        }
        break;
      case 'S':
      case 's':
        if (room == 2) {
          printf("You enter a corridor with flickering lights and portraits of sad looking people. To the north is the living room and to the east is another room.\n");
          room += 3;
        } else if (room == 5) {
          printf("You enter a large dining room with a table set for a banquet. To the north is the hallway and to the east is a door.\n");
          room++;
        } else if (room == 6) {
          printf("You step out onto the balcony with the crisp air filling your lungs. To the north is the bedroom.\n");
          room++;
        } else if (room == 8) {
          printf("\n\nBOO! A ghost materializes in front of you, attacking you with its ghostly hands.\nYou lose 20 health points.\n");
          ghost_attack++;
          health_points -= 20;
          if (ghost_attack == 2) {
            printf("\n\nThe ghost disappears with a blood-curdling scream.\n");
            room--;
            ghost_attack = 0;
          }
        } else if (room == 10) {
          printf("You decide to stay for more adventure.\n");
        } else {
          printf("You cannot go that way.\n");
        }
        break;
      case 'N':
      case 'n':
        if (room == 3) {
          printf("You enter a small balcony with a stunning view of the mountains. To the south is the library and to the west is another room.\n");
          room -= 3;
        } else if (room == 4) {
          printf("You take a deep breath and open the door to face your fear. \n\nAAAAAAH! A giant spider jumps on you, biting you and injecting venom into your veins.\nYou lose 25 health points.\n");
          spider_venom++;
          health_points -= 25;
          if (spider_venom == 2) {
            printf("\n\nYou feel dizzy and pass out from the spider's venom.\nGAME OVER\n");
            return 0;
          }
        } else if (room == 5) {
          printf("You enter a dimly lit room with vases and pottery. To the south is the hallway and to the west is another room.\n");
          room -= 3;
        } else if (room == 6) {
          printf("You enter a cozy study with a large desk and a fireplace. To the north is the bedroom and to the west is the library.\n");
          room--;
        } else if (room == 7) {
          printf("You decide not to jump off and go back inside. To the south is the bedroom and to the east is another room.\n");
        } else if (room == 8) {
          printf("You climb the stairs and exit the basement. To the north is the corridor.\n");
          room -= 3;
        } else if (room == 9) {
          printf("\n\nYou start to feel strange after drinking the potion and pass out.\nGAME OVER\n");
          return 0;
        } else {
          printf("You cannot go that way.\n");
        }
        break;
    }
  }
  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 10

typedef struct {
  char *name;
  char *description;
  int north;
  int east;
  int south;
  int west;
} Room;

typedef struct {
  char *name;
  char *description;
} Item;

Room rooms[MAX_ROOMS];
Item items[MAX_ITEMS];

int player_room = 0;
int player_inventory[MAX_ITEMS];

void print_room() {
  Room *room = &rooms[player_room];
  printf("You are in %s.\n", room->name);
  printf("%s\n", room->description);
  if (room->north != -1) printf("To the north, you see %s.\n", rooms[room->north].name);
  if (room->east != -1) printf("To the east, you see %s.\n", rooms[room->east].name);
  if (room->south != -1) printf("To the south, you see %s.\n", rooms[room->south].name);
  if (room->west != -1) printf("To the west, you see %s.\n", rooms[room->west].name);
}

void print_inventory() {
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (player_inventory[i] != -1) {
      printf("%s\n", items[player_inventory[i]].name);
    }
  }
}

int main() {
  // Initialize rooms
  rooms[0].name = "The Entrance Hall";
  rooms[0].description = "You are in a large, open hall with a high ceiling. The walls are covered in tapestries depicting scenes from history.";
  rooms[0].north = 1;
  rooms[0].east = 2;
  rooms[0].south = -1;
  rooms[0].west = -1;

  rooms[1].name = "The Great Hall";
  rooms[1].description = "A long table runs down the center of the hall, surrounded by chairs. A large fireplace crackles in the corner.";
  rooms[1].north = -1;
  rooms[1].east = 3;
  rooms[1].south = 0;
  rooms[1].west = 4;

  rooms[2].name = "The Library";
  rooms[2].description = "The room is lined with shelves, filled with books from floor to ceiling. A large desk sits in the center of the room, covered in papers.";
  rooms[2].north = -1;
  rooms[2].east = -1;
  rooms[2].south = 0;
  rooms[2].west = 3;

  rooms[3].name = "The Study";
  rooms[3].description = "A large window overlooks the garden. A desk sits in the corner, covered in books and papers.";
  rooms[3].north = -1;
  rooms[3].east = 4;
  rooms[3].south = 1;
  rooms[3].west = 2;

  rooms[4].name = "The Bedroom";
  rooms[4].description = "A large bed dominates the room. A fireplace is burning in the corner. A wardrobe stands against the far wall.";
  rooms[4].north = -1;
  rooms[4].east = -1;
  rooms[4].south = 1;
  rooms[4].west = 3;
  
  // Initialize items
  items[0].name = "The Sword of Destiny";
  items[0].description = "A gleaming sword with a golden hilt. The blade is engraved with runes that glow with a faint light.";

  items[1].name = "The Shield of Courage";
  items[1].description = "A large, round shield made of mithril. The surface is covered in intricate carvings depicting scenes of battle.";

  items[2].name = "The Helm of Wisdom";
  items[2].description = "A bronze helm with a visor that covers the wearer's face. The helm is adorned with gems that seem to glow with a faint light.";

  items[3].name = "The Ring of Power";
  items[3].description = "A golden ring with a large, red gem set in the center. The ring is said to grant the wearer great power.";

  // Initialize player inventory
  player_inventory[0] = -1;
  player_inventory[1] = -1;
  player_inventory[2] = -1;
  player_inventory[3] = -1;
  
  // Game loop
  while (1) {
    print_room();

    char input[100];
    printf("> ");
    scanf("%s", input);

    if (strcmp(input, "north") == 0) {
      if (rooms[player_room].north != -1) {
        player_room = rooms[player_room].north;
      } else {
        printf("You can't go that way.\n");
      }
    } else if (strcmp(input, "east") == 0) {
      if (rooms[player_room].east != -1) {
        player_room = rooms[player_room].east;
      } else {
        printf("You can't go that way.\n");
      }
    } else if (strcmp(input, "south") == 0) {
      if (rooms[player_room].south != -1) {
        player_room = rooms[player_room].south;
      } else {
        printf("You can't go that way.\n");
      }
    } else if (strcmp(input, "west") == 0) {
      if (rooms[player_room].west != -1) {
        player_room = rooms[player_room].west;
      } else {
        printf("You can't go that way.\n");
      }
    } else if (strcmp(input, "inventory") == 0) {
      print_inventory();
    } else {
      printf("I don't understand that command.\n");
    }
  }

  return 0;
}
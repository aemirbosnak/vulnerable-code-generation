//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

struct Hotel {
  char *name;
  int num_rooms;
  struct Room {
    int number;
    char *type;
    int price;
  } *rooms;
} *hotels;

int main() {
  int num_hotels;
  printf("Enter the number of hotels: ");
  scanf("%d", &num_hotels);

  hotels = malloc(num_hotels * sizeof(struct Hotel));
  for (int i = 0; i < num_hotels; i++) {
    struct Hotel *hotel = &hotels[i];
    hotel->name = malloc(20 * sizeof(char));
    printf("Enter the name of the hotel: ");
    scanf("%s", hotel->name);
    printf("Enter the number of rooms: ");
    scanf("%d", &hotel->num_rooms);
    hotel->rooms = malloc(hotel->num_rooms * sizeof(struct Room));
    for (int j = 0; j < hotel->num_rooms; j++) {
      struct Room *room = &hotel->rooms[j];
      room->number = j + 1;
      room->type = malloc(10 * sizeof(char));
      printf("Enter the type of the room: ");
      scanf("%s", room->type);
      printf("Enter the price of the room: ");
      scanf("%d", &room->price);
    }
  }

  printf("Hotel Management System\n");
  for (int i = 0; i < num_hotels; i++) {
    struct Hotel *hotel = &hotels[i];
    printf("%s (%d rooms):\n", hotel->name, hotel->num_rooms);
    for (int j = 0; j < hotel->num_rooms; j++) {
      struct Room *room = &hotel->rooms[j];
      printf("  Room %d: %s ($%d per night)\n", room->number, room->type, room->price);
    }
  }

  free(hotels);
  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 1000

typedef struct {
  int room_number;
  char *name;
  int num_guests;
  int arrival_date;
  int departure_date;
  int price;
} reservation;

reservation reservations[MAX_ROOMS];
int num_reservations = 0;

void add_reservation() {
  int room_number;
  char *name;
  int num_guests;
  int arrival_date;
  int departure_date;
  int price;

  printf("Enter the room number: ");
  scanf("%d", &room_number);

  printf("Enter the guest's name: ");
  scanf("%s", name);

  printf("Enter the number of guests: ");
  scanf("%d", &num_guests);

  printf("Enter the arrival date (YYYYMMDD): ");
  scanf("%d", &arrival_date);

  printf("Enter the departure date (YYYYMMDD): ");
  scanf("%d", &departure_date);

  printf("Enter the price: ");
  scanf("%d", &price);

  reservations[num_reservations].room_number = room_number;
  reservations[num_reservations].name = name;
  reservations[num_reservations].num_guests = num_guests;
  reservations[num_reservations].arrival_date = arrival_date;
  reservations[num_reservations].departure_date = departure_date;
  reservations[num_reservations].price = price;

  num_reservations++;
}

void print_reservations() {
  for (int i = 0; i < num_reservations; i++) {
    printf("Room number: %d\n", reservations[i].room_number);
    printf("Guest name: %s\n", reservations[i].name);
    printf("Number of guests: %d\n", reservations[i].num_guests);
    printf("Arrival date: %d\n", reservations[i].arrival_date);
    printf("Departure date: %d\n", reservations[i].departure_date);
    printf("Price: %d\n\n", reservations[i].price);
  }
}

int main() {
  int choice;

  while (1) {
    printf("1. Add a reservation\n");
    printf("2. Print reservations\n");
    printf("3. Quit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_reservation();
        break;
      case 2:
        print_reservations();
        break;
      case 3:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants and variables
#define MAX_GUESTS 100
#define MAX_ROOMS 20
#define ROOM_RATE 100
#define CHECK_IN_TIME 1200
#define CHECK_OUT_TIME 1800
#define LATE_CHECK_OUT_PENALTY 50

int main() {
  // Declare global variables
  int num_guests = 0;
  int available_rooms = 0;
  int checked_in_guests = 0;
  int late_check_out_penalty = 0;

  // Initialize hotel data
  struct Room {
    char name[20];
    int capacity;
    int available;
    int rate;
  };
  struct Guest {
    char name[20];
    int check_in_time;
    int check_out_time;
    int room_number;
    int bill_amount;
  };

  // Initialize hotel rooms
  struct Room rooms[MAX_ROOMS] = {
    {"Standard Room", 2, 5, ROOM_RATE},
    {"Deluxe Room", 4, 10, ROOM_RATE * 2},
    {"Suite", 6, 20, ROOM_RATE * 3},
  };

  // Initialize hotel guests
  struct Guest guests[MAX_GUESTS] = {
    {"John Doe", 1200, 1800, 1},
    {"Jane Doe", 1200, 1800, 2},
    {"Bob Smith", 1200, 1800, 3},
  };

  // Print hotel information
  printf("Welcome to the C Hotel Management System! \n");
  printf("Currently available rooms: %d\n", available_rooms);
  printf("Currently checked-in guests: %d\n", checked_in_guests);

  // Handle check-in requests
  while (1) {
    printf("Enter guest name: ");
    scanf("%s", guests[num_guests].name);
    printf("Enter check-in time (HH:MM): ");
    scanf("%H:%M", &guests[num_guests].check_in_time);
    printf("Enter room preference (1/2/3): ");
    scanf("%d", &guests[num_guests].room_number);

    // Check if room is available
    if (rooms[guests[num_guests].room_number].available == 0) {
      printf("Sorry, no rooms available. Try again later! \n");
      continue;
    }

    // Update guest information
    guests[num_guests].check_out_time = guests[num_guests].check_in_time + CHECK_IN_TIME;
    guests[num_guests].bill_amount = rooms[guests[num_guests].room_number].rate * CHECK_IN_TIME;

    // Update room information
    rooms[guests[num_guests].room_number].available -= 1;

    // Increment number of guests
    num_guests++;
  }

  // Handle check-out requests
  while (1) {
    for (int i = 0; i < num_guests; i++) {
      if (guests[i].check_out_time <= time(0)) {
        // Calculate late check-out penalty
        late_check_out_penalty += guests[i].bill_amount * LATE_CHECK_OUT_PENALTY;

        // Update guest information
        guests[i].check_out_time = guests[i].check_in_time + CHECK_OUT_TIME;
        guests[i].bill_amount += guests[i].bill_amount * LATE_CHECK_OUT_PENALTY;

        // Update room information
        rooms[guests[i].room_number].available += 1;

        // Print bill amount
        printf("Bill amount: %d\n", guests[i].bill_amount);
      }
    }

    // Check if all guests have checked out
    if (num_guests == 0) break;
  }

  // Print final bill amount
  printf("Late check-out penalty: %d\n", late_check_out_penalty);

  return 0;
}
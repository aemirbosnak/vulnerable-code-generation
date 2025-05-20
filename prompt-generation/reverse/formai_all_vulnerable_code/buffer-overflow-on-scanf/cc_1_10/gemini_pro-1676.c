//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: intelligent
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Hotel {
  char name[50];
  char address[100];
  char phone[20];
  char email[50];
  int num_rooms;
  float price_per_night;
  bool is_available;
} Hotel;

Hotel hotels[] = {
  {"Grand Hyatt", "123 Main Street", "555-1234", "grand.hyatt@example.com", 100, 200.0, true},
  {"Hilton Garden Inn", "456 Elm Street", "555-2345", "hilton.garden.inn@example.com", 150, 150.0, true},
  {"Marriott", "789 Oak Street", "555-3456", "marriott@example.com", 200, 250.0, false},
  {"Hyatt Regency", "1011 Pine Street", "555-4567", "hyatt.regency@example.com", 120, 180.0, true},
  {"Embassy Suites", "1213 Maple Street", "555-5678", "embassy.suites@example.com", 140, 160.0, true},
};

int num_hotels = sizeof(hotels) / sizeof(Hotel);

void print_hotel(Hotel hotel) {
  printf("Name: %s\n", hotel.name);
  printf("Address: %s\n", hotel.address);
  printf("Phone: %s\n", hotel.phone);
  printf("Email: %s\n", hotel.email);
  printf("Number of rooms: %d\n", hotel.num_rooms);
  printf("Price per night: $%.2f\n", hotel.price_per_night);
  printf("Is available: %s\n", hotel.is_available ? "Yes" : "No");
  printf("\n");
}

int main() {
  // Print the list of hotels
  printf("List of hotels:\n");
  for (int i = 0; i < num_hotels; i++) {
    print_hotel(hotels[i]);
  }

  // Get the user's input
  char input[100];
  printf("Enter the name of the hotel you want to book: ");
  scanf("%s", input);

  // Find the hotel by name
  Hotel *hotel = NULL;
  for (int i = 0; i < num_hotels; i++) {
    if (strcmp(hotels[i].name, input) == 0) {
      hotel = &hotels[i];
      break;
    }
  }

  // Check if the hotel is available
  if (hotel == NULL) {
    printf("Sorry, that hotel is not available.\n");
  } else if (!hotel->is_available) {
    printf("Sorry, that hotel is not available.\n");
  } else {
    // Book the hotel
    printf("Booking hotel %s for 1 night.\n", hotel->name);
    hotel->is_available = false;
  }

  return 0;
}
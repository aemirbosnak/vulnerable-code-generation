//FormAI DATASET v1.0 Category: Hotel Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  int roomNumber;
  int nights;
  double pricePerNight;
  double totalPrice;
} Booking;

void printMenu();
void addBooking();
void viewBookings();
void deleteBooking();
void editBooking();
void saveBookings();
void loadBookings();

Booking bookings[100];
int bookingCount = 0;

int main() {
  loadBookings();

  int choice;
  do {
    printMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        addBooking();
        break;
      case 2:
        viewBookings();
        break;
      case 3:
        deleteBooking();
        break;
      case 4:
        editBooking();
        break;
      case 5:
        saveBookings();
        break;
      case 6:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
        break;
    }
  } while (choice != 6);

  return 0;
}

void printMenu() {
  printf("==========================================\n");
  printf("=== Welcome to the C Hotel Management System ===\n");
  printf("==========================================\n");
  printf("1. Add Booking\n");
  printf("2. View Bookings\n");
  printf("3. Delete Booking\n");
  printf("4. Edit Booking\n");
  printf("5. Save Bookings\n");
  printf("6. Exit\n");
}

void addBooking() {
  printf("Adding Booking...\n");
  Booking booking;
  printf("Enter name: ");
  scanf("%s", booking.name);
  printf("Enter room number: ");
  scanf("%d", &booking.roomNumber);
  printf("Enter number of nights: ");
  scanf("%d", &booking.nights);
  printf("Enter price per night: ");
  scanf("%lf", &booking.pricePerNight);
  booking.totalPrice = booking.nights * booking.pricePerNight;
  bookings[bookingCount++] = booking;
  printf("Booking added!\n");
}

void viewBookings() {
  printf("Viewing Bookings...\n");
  if (bookingCount == 0) {
    printf("No bookings to display.\n");
    return;
  }
  for (int i = 0; i < bookingCount; i++) {
    Booking booking = bookings[i];
    printf("Name: %s | Room Number: %d | Nights: %d | Price per Night: %.2f | Total Price: %.2f\n",
           booking.name, booking.roomNumber, booking.nights, booking.pricePerNight, booking.totalPrice);
  }
}

void deleteBooking() {
  printf("Deleting Booking...\n");
  if (bookingCount == 0) {
    printf("No bookings to delete.\n");
    return;
  }
  int roomNumber;
  printf("Enter room number to delete: ");
  scanf("%d", &roomNumber);
  int found = 0;
  for (int i = 0; i < bookingCount; i++) {
    if (bookings[i].roomNumber == roomNumber) {
      found = 1;
      for (int j = i; j < bookingCount - 1; j++) {
        bookings[j] = bookings[j + 1];
      }
      bookingCount--;
      printf("Booking deleted!\n");
      break;
    }
  }
  if (!found) {
    printf("Booking not found.\n");
  }
}

void editBooking() {
  printf("Editing Booking...\n");
  if (bookingCount == 0) {
    printf("No bookings to edit.\n");
    return;
  }
  int roomNumber;
  printf("Enter room number to edit: ");
  scanf("%d", &roomNumber);
  int found = 0;
  for (int i = 0; i < bookingCount; i++) {
    if (bookings[i].roomNumber == roomNumber) {
      found = 1;
      Booking booking = bookings[i];
      printf("Name (current: %s): ", booking.name);
      scanf("%s", booking.name);
      printf("Room Number (current: %d): ", booking.roomNumber);
      scanf("%d", &booking.roomNumber);
      printf("Nights (current: %d): ", booking.nights);
      scanf("%d", &booking.nights);
      printf("Price per Night (current: %.2f): ", booking.pricePerNight);
      scanf("%lf", &booking.pricePerNight);
      booking.totalPrice = booking.nights * booking.pricePerNight;
      bookings[i] = booking;
      printf("Booking edited!\n");
      break;
    }
  }
  if (!found) {
    printf("Booking not found.\n");
  }
}

void saveBookings() {
  printf("Saving Bookings...\n");
  FILE *fp;
  fp = fopen("bookings.txt", "w");
  fprintf(fp, "%d\n", bookingCount);
  for (int i = 0; i < bookingCount; i++) {
    Booking booking = bookings[i];
    fprintf(fp, "%s\n%d\n%d\n%.2f\n", booking.name, booking.roomNumber, booking.nights, booking.pricePerNight);
  }
  fclose(fp);
  printf("Bookings saved!\n");
}

void loadBookings() {
  printf("Loading Bookings...\n");
  FILE *fp;
  fp = fopen("bookings.txt", "r");
  if (fp == NULL) {
    printf("No bookings file found.\n");
    return;
  }
  fscanf(fp, "%d", &bookingCount);
  for (int i = 0; i < bookingCount; i++) {
    Booking booking;
    fscanf(fp, "%s %d %d %lf", booking.name, &booking.roomNumber, &booking.nights, &booking.pricePerNight);
    booking.totalPrice = booking.nights * booking.pricePerNight;
    bookings[i] = booking;
  }
  fclose(fp);
  printf("Bookings loaded!\n");
}
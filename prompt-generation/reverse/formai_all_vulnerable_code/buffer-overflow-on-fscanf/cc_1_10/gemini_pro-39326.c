//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int room_number;
  int num_nights;
  float rate;
} Guest;

int main() {
  // Initialize the hotel management system.
  Guest guests[100];
  int num_guests = 0;

  // Read in the guest data from a file.
  FILE *fp = fopen("guests.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  while (!feof(fp)) {
    Guest guest;
    fscanf(fp, "%s %d %d %f", guest.name, &guest.room_number, &guest.num_nights, &guest.rate);
    guests[num_guests++] = guest;
  }

  fclose(fp);

  // Print out the guest data.
  for (int i = 0; i < num_guests; i++) {
    printf("%s %d %d %f\n", guests[i].name, guests[i].room_number, guests[i].num_nights, guests[i].rate);
  }

  // Calculate the total revenue for the hotel.
  float total_revenue = 0;
  for (int i = 0; i < num_guests; i++) {
    total_revenue += guests[i].num_nights * guests[i].rate;
  }

  printf("Total revenue: %f\n", total_revenue);

  // Free the memory allocated for the guest data.
  for (int i = 0; i < num_guests; i++) {
    free(guests[i].name);
  }

  return EXIT_SUCCESS;
}
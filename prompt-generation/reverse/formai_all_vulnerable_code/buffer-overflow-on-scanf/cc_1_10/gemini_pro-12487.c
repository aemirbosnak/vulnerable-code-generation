//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 100
#define MAX_DAYS 30

typedef struct {
  int room_number;
  char guest_name[50];
  char check_in_date[11];
  char check_out_date[11];
  int num_days;
  float total_cost;
} reservation;

reservation reservations[MAX_ROOMS];
int num_reservations = 0;

void add_reservation() {
  reservation new_reservation;
  printf("Enter room number: ");
  scanf("%d", &new_reservation.room_number);
  printf("Enter guest name: ");
  scanf(" %s", new_reservation.guest_name);
  printf("Enter check-in date (yyyy-mm-dd): ");
  scanf(" %s", new_reservation.check_in_date);
  printf("Enter check-out date (yyyy-mm-dd): ");
  scanf(" %s", new_reservation.check_out_date);
  
  // Calculate the number of days
  struct tm check_in_tm, check_out_tm;
  strptime(new_reservation.check_in_date, "%Y-%m-%d", &check_in_tm);
  strptime(new_reservation.check_out_date, "%Y-%m-%d", &check_out_tm);
  
  new_reservation.num_days = difftime(mktime(&check_out_tm), mktime(&check_in_tm)) / (60 * 60 * 24);
  
  // Calculate the total cost
  float room_rate = 100.00;
  new_reservation.total_cost = new_reservation.num_days * room_rate;
  
  // Add the new reservation to the array
  reservations[num_reservations++] = new_reservation;
}

void view_reservations() {
  printf("Reservations:\n");
  for (int i = 0; i < num_reservations; i++) {
    printf("Room %d: %s, %s - %s, %d nights, $%.2f\n",
           reservations[i].room_number,
           reservations[i].guest_name,
           reservations[i].check_in_date,
           reservations[i].check_out_date,
           reservations[i].num_days,
           reservations[i].total_cost);
  }
}

void search_reservations() {
  char search_term[50];
  printf("Enter search term: ");
  scanf(" %s", search_term);
  
  int found = 0;
  for (int i = 0; i < num_reservations; i++) {
    if (strstr(reservations[i].guest_name, search_term) != NULL ||
        strstr(reservations[i].room_number, search_term) != NULL) {
      printf("Room %d: %s, %s - %s, %d nights, $%.2f\n",
             reservations[i].room_number,
             reservations[i].guest_name,
             reservations[i].check_in_date,
             reservations[i].check_out_date,
             reservations[i].num_days,
             reservations[i].total_cost);
      found = 1;
    }
  }
  
  if (!found) {
    printf("No reservations found.\n");
  }
}

void delete_reservation() {
  int room_number;
  printf("Enter room number: ");
  scanf("%d", &room_number);
  
  int found = 0;
  for (int i = 0; i < num_reservations; i++) {
    if (reservations[i].room_number == room_number) {
      reservations[i] = reservations[num_reservations - 1];
      num_reservations--;
      found = 1;
      break;
    }
  }
  
  if (!found) {
    printf("Reservation not found.\n");
  }
}

int main() {
  int choice;
  
  do {
    printf("\nHotel Management System\n");
    printf("1. Add reservation\n");
    printf("2. View reservations\n");
    printf("3. Search reservations\n");
    printf("4. Delete reservation\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        add_reservation();
        break;
      case 2:
        view_reservations();
        break;
      case 3:
        search_reservations();
        break;
      case 4:
        delete_reservation();
        break;
      case 5:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice.\n");
    }
  } while (choice != 5);
  
  return 0;
}
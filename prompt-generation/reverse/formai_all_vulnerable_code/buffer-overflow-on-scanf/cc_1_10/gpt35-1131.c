//FormAI DATASET v1.0 Category: Hotel Management System ; Style: shocked
#include<stdio.h>
#include<string.h>

struct guest {
  char name[30];
  int room_number;
  int days_of_stay;
  float bill_amount;
};

void check_in(struct guest g[], int n) {
  printf("\nEnter Details for Check-In:\n");
  for(int i=0; i<n; i++) {
    printf("\nGuest %d -\n", i+1);
    printf("Enter Name: ");
    scanf("%s", &g[i].name);
    printf("Enter Room Number: ");
    scanf("%d", &g[i].room_number);
    printf("Enter Days of Stay: ");
    scanf("%d", &g[i].days_of_stay);
    g[i].bill_amount = 1500.0 * g[i].days_of_stay;
    printf("Bill Amount: %0.2f\n", g[i].bill_amount);
  }
}

void check_out(struct guest g[], int n) {
  int room;
  printf("\nEnter Room Number for Check-Out: ");
  scanf("%d", &room);
  for(int i=0; i<n; i++) {
    if(g[i].room_number == room) {
      printf("\nGuest Information: \n");
      printf("Name: %s\n", g[i].name);
      printf("Room Number: %d\n", g[i].room_number);
      printf("Days of Stay: %d\n", g[i].days_of_stay);
      printf("Bill Amount: %0.2f\n", g[i].bill_amount);
      strcpy(g[i].name, "");
      g[i].room_number = 0;
      g[i].days_of_stay = 0;
      g[i].bill_amount = 0.0;
      printf("\nThank you for staying with us. Have a nice day!\n");
      return;
    }
  }
  printf("\nRoom not found.\n");
}

int main() {
  int choice;
  int n = 5; // number of rooms in the hotel
  struct guest guests[n];
  do {
    printf("\n*****C Hotel Management System*****\n");
    printf("1. Check-In\n");
    printf("2. Check-Out\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        check_in(guests, n);
        break;
      case 2:
        check_out(guests, n);
        break;
      case 3:
        printf("\nThank you for using C Hotel Management System. Goodbye!\n");
        break;
      default:
        printf("\nInvalid Choice. Please try again.\n");
    }
  } while(choice != 3);
  return 0;
}
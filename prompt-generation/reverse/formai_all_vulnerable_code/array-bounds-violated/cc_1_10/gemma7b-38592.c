//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 100

typedef struct Guest {
  char name[50];
  int room_no;
  int num_days;
  double total_bill;
} Guest;

Guest guests[MAX_GUESTS];

void calculate_bill(int room_no, int num_days) {
  double rate = 0;
  switch (room_no) {
    case 1:
      rate = 1000;
      break;
    case 2:
      rate = 1200;
      break;
    case 3:
      rate = 1400;
      break;
  }

  guests[room_no].total_bill = rate * num_days;
}

void print_guests() {
  for (int i = 0; i < MAX_GUESTS; i++) {
    if (guests[i].name[0] != '\0') {
      printf("Name: %s, Room No: %d, Number of Days: %d, Total Bill: %.2lf\n", guests[i].name, guests[i].room_no, guests[i].num_days, guests[i].total_bill);
    }
  }
}

int main() {
  int i = 0;
  guests[i].name[0] = '\0';

  while (guests[i].name[0] != '\0' || i < MAX_GUESTS) {
    printf("Enter name: ");
    scanf("%s", guests[i].name);

    printf("Enter room number: ");
    scanf("%d", &guests[i].room_no);

    printf("Enter number of days: ");
    scanf("%d", &guests[i].num_days);

    calculate_bill(guests[i].room_no, guests[i].num_days);

    i++;
  }

  print_guests();

  return 0;
}
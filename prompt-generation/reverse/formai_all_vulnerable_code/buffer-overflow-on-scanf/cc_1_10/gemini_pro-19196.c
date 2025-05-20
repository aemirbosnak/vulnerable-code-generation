//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  char address[50];
  char phone[20];
  char email[50];
  int room_number;
  int days_stayed;
  float bill_amount;
} guest;

guest guests[100];
int num_guests = 0;

void add_guest() {
  printf("Enter guest name: ");
  scanf("%s", guests[num_guests].name);
  printf("Enter guest address: ");
  scanf("%s", guests[num_guests].address);
  printf("Enter guest phone: ");
  scanf("%s", guests[num_guests].phone);
  printf("Enter guest email: ");
  scanf("%s", guests[num_guests].email);
  printf("Enter guest room number: ");
  scanf("%d", &guests[num_guests].room_number);
  printf("Enter guest days stayed: ");
  scanf("%d", &guests[num_guests].days_stayed);
  printf("Enter guest bill amount: ");
  scanf("%f", &guests[num_guests].bill_amount);
  num_guests++;
  printf("Guest added successfully!\n");
}

void search_guest() {
  char name[50];
  printf("Enter guest name to search: ");
  scanf("%s", name);
  int found = 0;
  for (int i = 0; i < num_guests; i++) {
    if (strcmp(guests[i].name, name) == 0) {
      printf("Guest found!\n");
      printf("Name: %s\n", guests[i].name);
      printf("Address: %s\n", guests[i].address);
      printf("Phone: %s\n", guests[i].phone);
      printf("Email: %s\n", guests[i].email);
      printf("Room number: %d\n", guests[i].room_number);
      printf("Days stayed: %d\n", guests[i].days_stayed);
      printf("Bill amount: %f\n", guests[i].bill_amount);
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("Guest not found!\n");
  }
}

void update_guest() {
  char name[50];
  printf("Enter guest name to update: ");
  scanf("%s", name);
  int found = 0;
  for (int i = 0; i < num_guests; i++) {
    if (strcmp(guests[i].name, name) == 0) {
      printf("Guest found!\n");
      printf("Enter new guest name: ");
      scanf("%s", guests[i].name);
      printf("Enter new guest address: ");
      scanf("%s", guests[i].address);
      printf("Enter new guest phone: ");
      scanf("%s", guests[i].phone);
      printf("Enter new guest email: ");
      scanf("%s", guests[i].email);
      printf("Enter new guest room number: ");
      scanf("%d", &guests[i].room_number);
      printf("Enter new guest days stayed: ");
      scanf("%d", &guests[i].days_stayed);
      printf("Enter new guest bill amount: ");
      scanf("%f", &guests[i].bill_amount);
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("Guest not found!\n");
  }
}

void delete_guest() {
  char name[50];
  printf("Enter guest name to delete: ");
  scanf("%s", name);
  int found = 0;
  for (int i = 0; i < num_guests; i++) {
    if (strcmp(guests[i].name, name) == 0) {
      printf("Guest found!\n");
      for (int j = i; j < num_guests - 1; j++) {
        guests[j] = guests[j + 1];
      }
      num_guests--;
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("Guest not found!\n");
  }
}

void print_guests() {
  printf("Guests:\n");
  for (int i = 0; i < num_guests; i++) {
    printf("Name: %s\n", guests[i].name);
    printf("Address: %s\n", guests[i].address);
    printf("Phone: %s\n", guests[i].phone);
    printf("Email: %s\n", guests[i].email);
    printf("Room number: %d\n", guests[i].room_number);
    printf("Days stayed: %d\n", guests[i].days_stayed);
    printf("Bill amount: %f\n", guests[i].bill_amount);
    printf("\n");
  }
}

int main() {
  int choice;
  while (1) {
    printf("Hotel Management System\n");
    printf("1. Add guest\n");
    printf("2. Search guest\n");
    printf("3. Update guest\n");
    printf("4. Delete guest\n");
    printf("5. Print guests\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        add_guest();
        break;
      case 2:
        search_guest();
        break;
      case 3:
        update_guest();
        break;
      case 4:
        delete_guest();
        break;
      case 5:
        print_guests();
        break;
      case 6:
        exit(0);
      default:
        printf("Invalid choice!\n");
    }
  }
  return 0;
}
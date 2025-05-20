//FormAI DATASET v1.0 Category: Hotel Management System ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct guest {
  char name[30];
  int room_number;
  int stay_length;
  float bill_total;
};

void add_guest(struct guest list[], int *num_guests);
void display_guests(struct guest list[], int num_guests);
void checkout_guest(struct guest list[], int *num_guests);
void print_menu();

int main() {
  int choice, num_guests=0;
  struct guest guest_list[50];
  do {
    print_menu();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        add_guest(guest_list, &num_guests);
        break;
      case 2:
        display_guests(guest_list, num_guests);
        break;
      case 3:
        checkout_guest(guest_list, &num_guests);
        break;
      case 4:
        printf("Thank you for using the Hotel Management System.\n");
        exit(0);
      default:
        printf("Invalid choice. Please choose again.\n");
        break;
    }
  } while(choice != 4);

  return 0;
}

void add_guest(struct guest list[], int *num_guests) {
  if(*num_guests == 50) {
    printf("The hotel is currently at maximum capacity.\n");
    return;
  }
  
  printf("Enter guest name: ");
  scanf("%s", list[*num_guests].name);
  printf("Enter room number (1-50): ");
  scanf("%d", &list[*num_guests].room_number);
  printf("Enter length of stay: ");
  scanf("%d", &list[*num_guests].stay_length);
  list[*num_guests].bill_total = list[*num_guests].stay_length * 100.0; //Assuming each night costs $100
  printf("Guest added successfully.\n");
  (*num_guests)++;
}

void display_guests(struct guest list[], int num_guests) {
  if(num_guests == 0) {
    printf("There are currently no guests at the hotel.\n");
    return;
  }
  
  printf("Name\tRoom Number\tStay Length\tBill Total\n");
  for(int i=0; i<num_guests; i++) {
    printf("%s\t%d\t%d\t$%.2f\n", list[i].name, list[i].room_number, list[i].stay_length, list[i].bill_total);
  }
}

void checkout_guest(struct guest list[], int *num_guests) {
  if(*num_guests == 0) {
    printf("There are currently no guests to checkout.\n");
    return;
  }
  
  char name[30];
  printf("Enter guest name to checkout: ");
  scanf("%s", name);
  for(int i=0; i<*num_guests; i++) {
    if(strcmp(list[i].name, name) == 0) {
      printf("Checkout complete. Guest bill is $%.2f.\n", list[i].bill_total);
      for(int j=i; j<*num_guests-1; j++) {
        list[j] = list[j+1]; //Shift all elements after the checked out guest
      }
      (*num_guests)--;
      return;
    }
  }
  printf("Guest not found in current guests.\n");
}

void print_menu() {
  printf("Welcome to the Hotel Management System.\n");
  printf("1. Add guest\n");
  printf("2. Display current guests\n");
  printf("3. Checkout guest\n");
  printf("4. Exit\n");
}
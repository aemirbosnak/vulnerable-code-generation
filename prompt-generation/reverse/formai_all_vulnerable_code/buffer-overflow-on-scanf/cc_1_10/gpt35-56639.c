//FormAI DATASET v1.0 Category: Hotel Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room {
  int room_number;
  char room_type[10];
  float room_price;
  int availability;
};

struct customer {
  int id;
  char name[50];
  char email[50];
  char phone_number[20];
  struct room booked_room;
};

struct customer customers[100];
int customer_count = 0;

//function to add new customer
void add_customer(struct customer c) {
  customers[customer_count] = c;
  customer_count++;
}

//function to display all customers
void display_all_customers() {
  printf("\t\tAll customers\n");
  printf("-----------------------------------------------------\n");
  printf("ID\tName\t\tEmail\t\tPhone number\tRoom number\tRoom type\tPrice\n");
  printf("-----------------------------------------------------\n");
  for(int i=0; i<customer_count; i++) {
    printf("%d\t%s\t\t%s\t%s\t\t%d\t\t%s\t\t%.2f\n",customers[i].id,customers[i].name,customers[i].email,customers[i].phone_number,customers[i].booked_room.room_number,customers[i].booked_room.room_type,customers[i].booked_room.room_price);
  }
  printf("-----------------------------------------------------\n");
}

//function to search customer by id
void search_customer(int id) {
  printf("\t\tSearch result\n");
  printf("-----------------------------------------------------\n");
  printf("ID\tName\t\tEmail\t\tPhone number\tRoom number\tRoom type\tPrice\n");
  printf("-----------------------------------------------------\n");
  for(int i=0; i<customer_count; i++) {
    if(customers[i].id == id) {
      printf("%d\t%s\t\t%s\t%s\t\t%d\t\t%s\t\t%.2f\n",customers[i].id,customers[i].name,customers[i].email,customers[i].phone_number,customers[i].booked_room.room_number,customers[i].booked_room.room_type,customers[i].booked_room.room_price);
      return;
    }
  }
  printf("Customer not found\n");
}

//function to book a room
void book_room(int room_number) {
  for(int i=0; i<customer_count; i++) {
    if(customers[i].booked_room.room_number == room_number) {
      printf("Room not available\n");
      return;
    }
  }
  struct room r;
  r.room_number = room_number;
  r.availability = 0;
  if(room_number % 2 == 0) {
    strcpy(r.room_type,"Standard");
    r.room_price = 100.0;
  }
  else {
    strcpy(r.room_type,"Deluxe");
    r.room_price = 150.0;
  }
  printf("Enter customer id: ");
  scanf("%d",&customers[customer_count].id);
  printf("Enter customer name: ");
  getchar();
  fgets(customers[customer_count].name, 50, stdin);
  printf("Enter customer email: ");
  fgets(customers[customer_count].email, 50, stdin);
  printf("Enter customer phone number: ");
  fgets(customers[customer_count].phone_number, 20, stdin);
  customers[customer_count].booked_room = r;
  add_customer(customers[customer_count]);
  printf("Room booked successfully\n");
}

//function to display all available rooms
void display_available_rooms() {
  printf("\t\tAvailable rooms\n");
  printf("-----------------------------------------------------\n");
  printf("Room number\tRoom type\tPrice\n");
  printf("-----------------------------------------------------\n");
  for(int i=1; i<=100; i++) {
    int available = 1;
    for(int j=0; j<customer_count; j++) {
      if(customers[j].booked_room.room_number == i) {
        available = 0;
        break;
      }
    }
    if(available) {
      struct room r;
      r.room_number = i;
      r.availability = 1;
      if(i % 2 == 0) {
        strcpy(r.room_type,"Standard");
        r.room_price = 100.0;
      }
      else {
        strcpy(r.room_type,"Deluxe");
        r.room_price = 150.0;
      }
      printf("%d\t\t%s\t\t%.2f\n",r.room_number,r.room_type,r.room_price);
    }
  }
  printf("-----------------------------------------------------\n");
}

int main() {
  while(1) {
    printf("Welcome to C Hotel Management System\n");
    printf("1. Book a room\n");
    printf("2. Display available rooms\n");
    printf("3. Display all customers\n");
    printf("4. Search customer\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d",&choice);
    switch(choice) {
      case 1: {
        int room_number;
        printf("Enter room number: ");
        scanf("%d",&room_number);
        book_room(room_number);
        break;    
      }
      case 2: {
        display_available_rooms();
        break;
      }
      case 3: {
        display_all_customers();
        break;
      }
      case 4: {
        int id;
        printf("Enter customer id: ");
        scanf("%d",&id);
        search_customer(id);
        break;
      }
      case 5: {
        exit(0);
      }
      default: {
        printf("Invalid choice\n");
      }
    }
  }
  return 0;
}
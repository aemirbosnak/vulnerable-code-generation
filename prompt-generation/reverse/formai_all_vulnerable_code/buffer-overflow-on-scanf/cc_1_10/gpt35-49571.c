//FormAI DATASET v1.0 Category: Hotel Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hotel {
  char name[50];
  int room_num;
  int floor_num;
  int guests;
  float price;
};

struct hotel hotels[10]; // Array to store hotel data
int count = 0; // Counter for total number of hotels

// Function to add a hotel to the system
void add_hotel() {
  printf("Enter hotel name: ");
  scanf("%s", hotels[count].name);
  printf("Enter room number: ");
  scanf("%d", &hotels[count].room_num);
  printf("Enter floor number: ");
  scanf("%d", &hotels[count].floor_num);
  printf("Enter number of guests: ");
  scanf("%d", &hotels[count].guests);
  printf("Enter price: ");
  scanf("%f", &hotels[count].price);
  count++;
  printf("Hotel added successfully.\n\n");
}

// Function to display all hotels in the system
void display_hotels() {
  if(count == 0) {
    printf("No hotels added yet.\n\n");
    return;
  }
  printf("Hotels in the system:\n");
  for(int i=0; i<count; i++) {
    printf("%s - Room %d, Floor %d, Guests: %d, Price: $%.2f\n", hotels[i].name, hotels[i].room_num, hotels[i].floor_num, hotels[i].guests, hotels[i].price);
  }
  printf("\n");
}

// Function to search for a hotel by name
void search_hotel(char name[]) {
  for(int i=0; i<count; i++) {
    if(strcmp(hotels[i].name, name) == 0) {
      printf("%s - Room %d, Floor %d, Guests: %d, Price: $%.2f\n\n", hotels[i].name, hotels[i].room_num, hotels[i].floor_num, hotels[i].guests, hotels[i].price);
      return;
    }
  }
  printf("Hotel not found.\n\n");
}

// Function to delete a hotel from the system
void delete_hotel(char name[]) {
  int found = 0;
  for(int i=0; i<count; i++) {
    if(strcmp(hotels[i].name, name) == 0) {
      found = 1;
      for(int j=i; j<count-1; j++) {
        hotels[j] = hotels[j+1];
      }
      count--;
      break;
    }
  }
  if(found) {
    printf("%s deleted from the system\n\n", name);
  } else {
    printf("Hotel not found.\n\n");
  }
}

int main() {
  int choice;
  char name[50];

  while(1) {
    printf("1. Add Hotel\n2. Display Hotels\n3. Search Hotel\n4. Delete Hotel\n5. Exit\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        add_hotel();
        break;

      case 2:
        display_hotels();
        break;

      case 3:
        printf("Enter hotel name to search: ");
        scanf("%s", name);
        search_hotel(name);
        break;

      case 4:
        printf("Enter hotel name to delete: ");
        scanf("%s", name);
        delete_hotel(name);
        break;

      case 5:
        exit(0);
        break;

      default:
        printf("Invalid choice, please try again\n\n");
        break;
    }
  }

  return 0;
}
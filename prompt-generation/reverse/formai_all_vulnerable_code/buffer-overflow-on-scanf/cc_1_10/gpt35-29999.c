//FormAI DATASET v1.0 Category: Hotel Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct Room {
  int room_number;
  char room_type[10];
  int occupancy;
  float room_charge;
};

struct Room rooms[50];
int num_rooms = 0;

void display_menu();
void find_room();
void add_room();
void remove_room();
void display_rooms();
void calculate_cost();

int main() {
  int choice;
  
  do {
    display_menu();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        find_room();
        break;
      case 2:
        add_room();
        break;
      case 3:
        remove_room();
        break;
      case 4:
        display_rooms();
        break;
      case 5:
        calculate_cost();
        break;
      case 6:
        printf("Goodbye!");
        break;
      default:
        printf("Invalid choice! Try again.\n");
        break;
    }
  } while(choice != 6);

  return 0;
}

void display_menu() {
  printf("\n=== C Hotel Management System ===\n");
  printf("1. Find a room\n");
  printf("2. Add a room\n");
  printf("3. Remove a room\n");
  printf("4. Display all rooms\n");
  printf("5. Calculate cost\n");
  printf("6. Exit\n");
}

void find_room() {
  int room_number, i, found = 0;
  
  printf("Enter room number: ");
  scanf("%d", &room_number);
  
  for(i = 0; i < num_rooms; i++) {
    if(rooms[i].room_number == room_number) {
      found = 1;
      printf("Room type: %s\n", rooms[i].room_type);
      printf("Occupancy: %d\n", rooms[i].occupancy);
      printf("Room charge: %.2f\n", rooms[i].room_charge);
      break;
    }
  }
  
  if(!found) {
    printf("Room not found!\n");
  }
}

void add_room() {
  int room_number, occupancy;
  char room_type[10];
  float room_charge;
  
  printf("Enter room number: ");
  scanf("%d", &room_number);
  
  printf("Enter room type: ");
  scanf("%s", room_type);
  
  printf("Enter room occupancy: ");
  scanf("%d", &occupancy);
  
  printf("Enter room charge: ");
  scanf("%f", &room_charge);
  
  if(num_rooms < 50) {
    rooms[num_rooms].room_number = room_number;
    strcpy(rooms[num_rooms].room_type, room_type);
    rooms[num_rooms].occupancy = occupancy;
    rooms[num_rooms].room_charge = room_charge;
    
    num_rooms++;
    
    printf("Room added successfully!\n");
  } else {
    printf("Maximum rooms reached!\n");
  }
}

void remove_room() {
  int room_number, i, found = 0;
  
  printf("Enter room number: ");
  scanf("%d", &room_number);
  
  for(i = 0; i < num_rooms; i++) {
    if(rooms[i].room_number == room_number) {
      found = 1;
      
      // Shift elements to the left
      for(int j = i; j < num_rooms - 1; j++) {
        rooms[j] = rooms[j+1];
      }
      
      num_rooms--;
      
      printf("Room removed successfully!\n");
      break;
    }
  }
  
  if(!found) {
    printf("Room not found!\n");
  }
}

void display_rooms() {
  printf("List of all rooms:\n");
  for(int i = 0; i < num_rooms; i++) {
    printf("Room number: %d\n", rooms[i].room_number);
    printf("Room type: %s\n", rooms[i].room_type);
    printf("Occupancy: %d\n", rooms[i].occupancy);
    printf("Room charge: %.2f\n", rooms[i].room_charge);
    printf("-------------------------------\n");
  }
}

void calculate_cost() {
  int room_number, num_nights;
  float cost;
  
  printf("Enter room number: ");
  scanf("%d", &room_number);
  
  printf("Enter number of nights: ");
  scanf("%d", &num_nights);
  
  for(int i = 0; i < num_rooms; i++) {
    if(rooms[i].room_number == room_number) {
      cost = rooms[i].room_charge * num_nights;
      printf("Total cost: %.2f\n", cost);
      break;
    }
  }
}
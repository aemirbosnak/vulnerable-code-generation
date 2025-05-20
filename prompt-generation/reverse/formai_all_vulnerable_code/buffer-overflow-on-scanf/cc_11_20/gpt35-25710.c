//FormAI DATASET v1.0 Category: Hotel Management System ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

struct guest{
  char name[30];
  char gender[10];
  int age;
  char address[50];
  char phone[15];
  int room_number;
  int days_stay;
  int total_bill;
};

struct room{
  int room_number;
  char room_type[20];
  int price;
  int available;
};

int main(){
  struct guest guests[100];
  int guest_count = 0;

  struct room rooms[50];
  int room_count = 0;

  FILE *guest_file = fopen("guests.txt", "a");
  FILE *room_file = fopen("rooms.txt", "a");
  

  while(1){
    int choice;
    printf("\n\n\n");
    printf("1. Add new guest\n");
    printf("2. Add new room\n");
    printf("3. Check in\n");
    printf("4. Check out\n");
    printf("5. View all guests\n");
    printf("6. View all rooms\n");
    printf("7. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1){
      struct guest new_guest;

      printf("Enter name: ");
      scanf("%s", new_guest.name);

      printf("Enter gender: ");
      scanf("%s", new_guest.gender);

      printf("Enter age: ");
      scanf("%d", &new_guest.age);

      printf("Enter address: ");
      scanf("%s", new_guest.address);

      printf("Enter phone number: ");
      scanf("%s", new_guest.phone);

      fprintf(guest_file, "%s %s %d %s %s\n", new_guest.name, new_guest.gender, new_guest.age, new_guest.address, new_guest.phone);

      guests[guest_count] = new_guest;
      guest_count++;

      printf("\nGuest added successfully!\n\n");

    }else if(choice == 2){
      struct room new_room;

      printf("Enter room number: ");
      scanf("%d", &new_room.room_number);

      printf("Enter room type: ");
      scanf("%s", new_room.room_type);

      printf("Enter price: ");
      scanf("%d", &new_room.price);

      printf("Enter availability (1 = available, 0 = not available): ");
      scanf("%d", &new_room.available);

      fprintf(room_file, "%d %s %d %d\n", new_room.room_number, new_room.room_type, new_room.price, new_room.available);

      rooms[room_count] = new_room;
      room_count++;

      printf("\nRoom added successfully!\n\n");

    }else if(choice == 3){
      char name[30];
      printf("Enter guest name: ");
      scanf("%s", name);

      int room_number;
      printf("Enter room number: ");
      scanf("%d", &room_number);

      int days_stay;
      printf("Enter number of days stay: ");
      scanf("%d", &days_stay);

      for(int i = 0; i < guest_count; i++){
        if(strcmp(guests[i].name, name) == 0){
          guests[i].room_number = room_number;
          guests[i].days_stay = days_stay;

          for(int j = 0; j < room_count; j++){
            if(rooms[j].room_number == room_number){
              rooms[j].available = 0;

              guests[i].total_bill = days_stay * rooms[j].price;

              printf("\nCheck in successful!\n\n");
              break;
            }
          }

          break;
        }
      }
    }else if(choice == 4){
      int room_number;
      printf("Enter room number: ");
      scanf("%d", &room_number);

      for(int i = 0; i < guest_count; i++){
        if(guests[i].room_number == room_number){

          for(int j = 0; j < room_count; j++){
            if(rooms[j].room_number == room_number){
              rooms[j].available = 1;
              break;
            }
          }

          fprintf(guest_file, "%d %d %d %d %s\n", guests[i].room_number, guests[i].days_stay, guests[i].total_bill, guests[i].age, guests[i].phone);

          for(int k = i; k < guest_count - 1; k++){
            guests[k] = guests[k+1];
          }

          guest_count--;

          printf("\nCheck out successful!\n\n");
          break;
        }
      }
    }else if(choice == 5){
      FILE *guest_file = fopen("guests.txt", "r");
      char line[200];

      printf("\n\n");
      printf("Name   Gender   Age   Address   Phone   Room Number   Days Stayed   Total Bill\n");
      printf("--------------------------------------------------------------------------------\n");
      while(fgets(line, 200, guest_file)){
        struct guest g;
        sscanf(line, "%s %s %d %s %s %d %d %d", g.name, g.gender, &g.age, g.address, g.phone, &g.room_number, &g.days_stay, &g.total_bill);
        printf("%-6s %-8s %-4d %-10s %-11s %-13d %-12d %-10d\n", g.name, g.gender, g.age, g.address, g.phone, g.room_number, g.days_stay, g.total_bill);
      }
      printf("--------------------------------------------------------------------------------\n");
      fclose(guest_file);
    }else if(choice == 6){
      FILE *room_file = fopen("rooms.txt", "r");
      char line[200];

      printf("\n\n");
      printf("Room Number   Room Type   Price   Availability\n");
      printf("-----------------------------------------------\n");
      while(fgets(line, 200, room_file)){
        struct room r;
        sscanf(line, "%d %s %d %d", &r.room_number, r.room_type, &r.price, &r.available);
        printf("%-13d %-11s %-7d %d\n", r.room_number, r.room_type, r.price, r.available);
      }
      printf("-----------------------------------------------\n");
      fclose(room_file);
    }else if(choice == 7){
      exit(0);
    }else{
      printf("Invalid choice! Please try again.\n\n");
    }
  }

  return 0;
}
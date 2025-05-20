//FormAI DATASET v1.0 Category: Hotel Management System ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct room{
    int room_number;
    char room_type[20];
    int room_price;
} Room;

int main(){
    Room *rooms;
    int i=0, num_rooms=0, total_price=0;
    char ans[5];

    printf("***Welcome to C Hotel***\n");
    printf("How many rooms would you like to add to the system?\n");
    scanf("%d", &num_rooms);

    rooms = (Room*) malloc(sizeof(Room) * num_rooms);

    printf("Please enter the details for %d rooms...\n", num_rooms);
    for(i=0; i<num_rooms; i++){
        printf("Room %d details:\n", i+1);
        printf("Room number: ");
        scanf("%d", &rooms[i].room_number);
        printf("Room type: ");
        scanf("%s", rooms[i].room_type);
        printf("Room price: ");
        scanf("%d", &rooms[i].room_price);
    }

    printf("Would you like to view the current room list? (Y/N): ");
    scanf("%s", ans);

    if(strcmp(ans, "Y") == 0 || strcmp(ans, "y") == 0){
        printf("***Room List***\n");
        for(i=0; i<num_rooms; i++){
            printf("Room %d - Room Number: %d, Room Type: %s, Room Price: %d\n", i+1, rooms[i].room_number, rooms[i].room_type, rooms[i].room_price);
        }
    }

    printf("Would you like to calculate the total price for a given room type? (Y/N): ");
    scanf("%s", ans);

    if(strcmp(ans, "Y") == 0 || strcmp(ans, "y") == 0){
        char room_type[20];
        printf("Please enter the room type: ");
        scanf("%s", room_type);

        for(i=0; i<num_rooms; i++){
            if(strcmp(rooms[i].room_type, room_type) == 0){
                total_price += rooms[i].room_price;
            }
        }

        printf("The total price for %s rooms is: %d\n", room_type, total_price);
    }

    printf("Thank you for using C Hotel Management System!\n");

    free(rooms);
    return 0;
}
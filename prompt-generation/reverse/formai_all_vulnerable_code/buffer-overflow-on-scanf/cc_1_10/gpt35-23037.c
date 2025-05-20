//FormAI DATASET v1.0 Category: Hotel Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 50
#define MAX_NAME_LENGTH 100

typedef struct guest_t{
    char name[MAX_NAME_LENGTH];
    int room_number;
} guest;

guest hotel[MAX_ROOMS];
int next_available_room = 1;

void print_guests(){
    printf("Current guests in the hotel: \n");
    for(int i=0; i<MAX_ROOMS; i++){
        if(hotel[i].room_number != 0)
            printf("%s is in room number %d\n", hotel[i].name, hotel[i].room_number);
    }
}

void check_in(){
    if(next_available_room > MAX_ROOMS){
        printf("Sorry, there are no available rooms in the hotel.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Welcome to our hotel!\n");
    printf("Please enter your name: \n");
    scanf("%s", name);

    hotel[next_available_room-1].room_number = next_available_room;
    strcpy(hotel[next_available_room-1].name, name);

    printf("Thank you, %s, for checking in to room number %d.\n", name, next_available_room);

    next_available_room++;
}

void check_out(){
    int room_number;
    printf("Please enter your room number: \n");
    scanf("%d", &room_number);

    if(room_number <= 0 || room_number > MAX_ROOMS){
        printf("Invalid room number.\n");
        return;
    }

    if(hotel[room_number-1].room_number == 0){
        printf("That room is not occupied.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    strcpy(name, hotel[room_number-1].name);

    hotel[room_number-1].room_number = 0;
    hotel[room_number-1].name[0] = '\0';

    printf("%s has checked out from room number %d.\n", name, room_number);

    next_available_room--;
}

int main(){
    int choice;

    while(1){
        printf("\n==============\n");
        printf("C Hotel Management System\n");
        printf("==============\n");

        printf("Please select an option: \n");
        printf("1. View Current Guests\n");
        printf("2. Check In\n");
        printf("3. Check Out\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                print_guests();
                break;

            case 2:
                check_in();
                break;

            case 3:
                check_out();
                break;

            case 4:
                printf("Goodbye, thank you for using C Hotel Management System.");
                exit(0);

            default:
                printf("Invalid choice, please try again.");
                break;
        }
    }
    return 0;
}
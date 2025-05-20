//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 100

typedef struct {
    char name[50];
    int age;
    char address[100];
} Guest;

typedef struct {
    int roomNumber;
    int numberOfGuests;
    Guest guests[MAX_GUESTS];
} Room;

int main() {
    int i, j, choice;
    char name[50];
    Guest guest;
    Room room[MAX_ROOMS];

    printf("Welcome to Hotel Management System!\n");

    while(1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add guest\n2. Check in\n3. Check out\n4. View guests\n5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter guest name: ");
                scanf("%s", guest.name);
                printf("Enter guest age: ");
                scanf("%d", &guest.age);
                printf("Enter guest address: ");
                scanf("%s", guest.address);
                break;
            case 2:
                printf("Enter room number: ");
                scanf("%d", &i);
                if(room[i].numberOfGuests == 0) {
                    printf("No guests in room %d.\n", i);
                } else {
                    printf("Guests in room %d:\n", i);
                    for(j=0; j<room[i].numberOfGuests; j++) {
                        printf("Name: %s\nAge: %d\nAddress: %s\n", room[i].guests[j].name, room[i].guests[j].age, room[i].guests[j].address);
                    }
                }
                break;
            case 3:
                printf("Enter room number: ");
                scanf("%d", &i);
                if(room[i].numberOfGuests == 0) {
                    printf("No guests in room %d.\n", i);
                } else {
                    printf("Guests checked out from room %d.\n", i);
                    room[i].numberOfGuests = 0;
                }
                break;
            case 4:
                printf("Guests:\n");
                for(i=0; i<MAX_GUESTS; i++) {
                    if(guest.name[0]!= '\0') {
                        printf("Name: %s\nAge: %d\nAddress: %s\n", guest.name, guest.age, guest.address);
                    }
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
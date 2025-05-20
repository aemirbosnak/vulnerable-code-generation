//FormAI DATASET v1.0 Category: Hotel Management System ; Style: genious
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_HOTELS 10
#define MAX_ROOMS 100

struct hotel {
    int id;
    char name[50];
    int star_rating;
    int num_rooms;
    int rooms_available[MAX_ROOMS];
} hotels[MAX_HOTELS];
int num_hotels = 0;

void add_hotel() {
    printf("\nEnter details for hotel %d:\n", num_hotels+1);
    hotels[num_hotels].id = num_hotels+1;
    printf("Enter hotel name: ");
    scanf("%s", hotels[num_hotels].name);
    printf("Enter star rating: ");
    scanf("%d", &hotels[num_hotels].star_rating);
    printf("Enter number of rooms: ");
    scanf("%d", &hotels[num_hotels].num_rooms);
    for(int i=0; i<hotels[num_hotels].num_rooms; i++) {
        hotels[num_hotels].rooms_available[i] = 1;
    }
    num_hotels++;
    printf("\nHotel added successfully!\n\n");
}

void display_hotels() {
    printf("\nList of hotels:\n");
    printf("ID \t Hotel Name \t Star Rating\n");
    for(int i=0; i<num_hotels; i++) {
        printf("%d \t %s \t %d\n", hotels[i].id, hotels[i].name, hotels[i].star_rating);
    }
    printf("\n");
}

void book_room(int hotel_id) {
    int room_num;
    for(int i=0; i<num_hotels; i++) {
        if(hotels[i].id == hotel_id) {
            printf("\nAvailable rooms in %s:\n", hotels[i].name);
            printf("Room Number\n");
            for(int j=0; j<hotels[i].num_rooms; j++) {
                if(hotels[i].rooms_available[j] == 1) {
                    printf("%d\n", j+1);
                }
            }
            printf("Enter room number to book: ");
            scanf("%d", &room_num);
            if(hotels[i].rooms_available[room_num-1] == 0) {
                printf("\nSorry! Room not available.\n\n");
            }
            else {
                hotels[i].rooms_available[room_num-1] = 0;
                printf("\nCongratulations! Room booked successfully.\n\n");
            }
            return;
        }
    }
    printf("\nInvalid hotel ID!\n\n");
}

int main() {
    int choice;
    printf("\nWelcome to the Hotel Management System!\n");
    do {
        printf("1. Add Hotel\n");
        printf("2. Display Hotels\n");
        printf("3. Book Room\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_hotel();
                break;
            case 2:
                display_hotels();
                break;
            case 3: {
                int hotel_id;
                printf("\nEnter hotel ID to book room: ");
                scanf("%d", &hotel_id);
                book_room(hotel_id);
                break;
            }
            case 4:
                printf("\nThank you for using the Hotel Management System!\n\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n\n");
        }
    } while(choice != 4);
    return 0;
}
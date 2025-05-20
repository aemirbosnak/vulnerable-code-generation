//FormAI DATASET v1.0 Category: Hotel Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HOTELS 10
#define MAX_ROOMS 100

/* Global variables */
int number_of_hotels = 0;
int number_of_rooms = 0;

/* Struct definitions */
typedef struct {
    int room_number;
    int price_per_night;
    int is_booked;
} Room;

typedef struct {
    char name[50];
    Room rooms[MAX_ROOMS];
    int number_of_rooms;
} Hotel;

Hotel hotels[MAX_HOTELS];

/* Function prototypes */
void add_hotel();
void add_room(int hotel_index);
void book_room(int hotel_index, int room_index);
void print_hotels();

int main() 
{
    int choice;
    
    do {
        printf("\n\nWelcome to the Hotel Management System!\n\n");
        printf("Select an option:\n");
        printf("1. Add hotel\n");
        printf("2. Add room to hotel\n");
        printf("3. Book room\n");
        printf("4. Print all hotels\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
                add_hotel();
                break;
            case 2: {
                int hotel_index;
                printf("Enter hotel index: ");
                scanf("%d", &hotel_index);
                add_room(hotel_index);
                break;
            }
            case 3: {
                int hotel_index, room_index;
                printf("Enter hotel index: ");
                scanf("%d", &hotel_index);
                printf("Enter room index: ");
                scanf("%d", &room_index);
                book_room(hotel_index, room_index);
                break;
            }
            case 4:
                print_hotels();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
        
    } while(choice != 5);
    
    return 0;
}

void add_hotel() 
{
    if(number_of_hotels == MAX_HOTELS) {
        printf("Cannot add more hotels!\n");
        return;
    }
    
    char name[50];
    printf("Enter hotel name: ");
    scanf("%s", name);
    
    Hotel hotel;
    strcpy(hotel.name, name);
    hotel.number_of_rooms = 0;
    
    hotels[number_of_hotels++] = hotel;
    
    printf("Hotel added successfully!\n");
}

void add_room(int hotel_index) 
{
    if(hotel_index < 0 || hotel_index >= number_of_hotels) {
        printf("Invalid hotel index!\n");
        return;
    }
    
    if(hotels[hotel_index].number_of_rooms == MAX_ROOMS) {
        printf("Cannot add more rooms to this hotel!\n");
        return;
    }
    
    int room_number, price_per_night;
    printf("Enter room number: ");
    scanf("%d", &room_number);
    printf("Enter price per night: ");
    scanf("%d", &price_per_night);
    
    Room room;
    room.room_number = room_number;
    room.price_per_night = price_per_night;
    room.is_booked = 0;
    
    hotels[hotel_index].rooms[hotels[hotel_index].number_of_rooms++] = room;
    
    number_of_rooms++;
    printf("Room added to hotel successfully!\n");
}

void book_room(int hotel_index, int room_index) 
{
    if(hotel_index < 0 || hotel_index >= number_of_hotels) {
        printf("Invalid hotel index!\n");
        return;
    }
    
    if(room_index < 0 || room_index >= hotels[hotel_index].number_of_rooms) {
        printf("Invalid room index!\n");
        return;
    }
    
    if(hotels[hotel_index].rooms[room_index].is_booked) {
        printf("Room is already booked!\n");
        return;
    }
    
    hotels[hotel_index].rooms[room_index].is_booked = 1;
    
    printf("Room booked successfully!\n");
}

void print_hotels() 
{
    if(number_of_hotels == 0) {
        printf("No hotels added yet!\n");
        return;
    }
    
    printf("List of hotels:\n");
    for(int i=0; i<number_of_hotels; i++) {
        printf("%d. %s (Number of rooms: %d)\n", i, hotels[i].name, hotels[i].number_of_rooms);
        printf("Rooms: \n");
        for(int j=0; j<hotels[i].number_of_rooms; j++) {
            printf("%d. Room number: %d, Price: %d", j, hotels[i].rooms[j].room_number, hotels[i].rooms[j].price_per_night);
            if(hotels[i].rooms[j].is_booked) {
                printf(", Status: Booked\n");
            } else {
                printf(", Status: Available\n");
            }
        }
        printf("\n");
    }
}
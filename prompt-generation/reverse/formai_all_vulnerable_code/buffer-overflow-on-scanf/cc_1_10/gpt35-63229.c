//FormAI DATASET v1.0 Category: Hotel Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 50

typedef struct {
    int room_number;
    int guest_count;
    int nights_stay;
    float room_rate;
} Room;

Room rooms[MAX_ROOMS];

int num_rooms = 0;

void add_room(int room_number, int guest_count, float room_rate) {
    if (num_rooms >= MAX_ROOMS) {
        printf("Error: Maximum number of rooms exceeded.\n");
        return;
    }
    
    rooms[num_rooms].room_number = room_number;
    rooms[num_rooms].guest_count = guest_count;
    rooms[num_rooms].room_rate = room_rate;
    rooms[num_rooms].nights_stay = 0;
    
    printf("Room %d added successfully.\n", room_number);
    
    num_rooms++;
}

void check_in(int room_number, int nights_stay) {
    int i;
    
    for (i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            if (rooms[i].nights_stay > 0) {
                printf("Error: Room %d is already occupied.\n", room_number);
                return;
            }
            
            rooms[i].nights_stay = nights_stay;
            printf("Room %d checked in successfully for %d nights.\n", room_number, nights_stay);
            return;
        }
    }
    
    printf("Error: Room %d not found.\n", room_number);
}

void check_out(int room_number) {
    int i;
    
    for (i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            if (rooms[i].nights_stay == 0) {
                printf("Error: Room %d is not occupied.\n", room_number);
                return;
            }
            
            float total_cost = rooms[i].room_rate * rooms[i].nights_stay;
            float tax = total_cost * 0.1;
            float final_cost = total_cost + tax;
            
            printf("Room %d checked out successfully.\n", room_number);
            printf("Total cost: %.2f\n", total_cost);
            printf("Tax (10%%): %.2f\n", tax);
            printf("Final cost: %.2f\n", final_cost);
            
            rooms[i].nights_stay = 0;
            return;
        }
    }
    
    printf("Error: Room %d not found.\n", room_number);
}

void list_rooms() {
    int i;
    
    printf("| Room Number | Guests | Nights Stayed | Rate |\n");
    printf("+-------------+--------+---------------+------+\n");
    
    for (i = 0; i < num_rooms; i++) {
        printf("| %11d | %6d | %13d | %4.2f |\n", rooms[i].room_number, rooms[i].guest_count, rooms[i].nights_stay, rooms[i].room_rate);
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\nHotel Management System\n");
        printf("1. Add Room\n");
        printf("2. Check In\n");
        printf("3. Check Out\n");
        printf("4. List Rooms\n");
        printf("5. Exit\n");
        printf("> ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int room_number;
                int guests;
                float rate;
                
                printf("Enter Room Number: ");
                scanf("%d", &room_number);
                
                printf("Enter Number of Guests: ");
                scanf("%d", &guests);
                
                printf("Enter Room Rate: ");
                scanf("%f", &rate);
                
                add_room(room_number, guests, rate);
                
                break;
            }
            case 2: {
                int room_number;
                int nights;
                
                printf("Enter Room Number: ");
                scanf("%d", &room_number);
                
                printf("Enter Number of Nights: ");
                scanf("%d", &nights);
                
                check_in(room_number, nights);
                
                break;
            }
            case 3: {
                int room_number;
                
                printf("Enter Room Number: ");
                scanf("%d", &room_number);
                
                check_out(room_number);
                
                break;
            }
            case 4: {
                list_rooms();
                
                break;
            }
            case 5: {
                exit(0);
            }
            default: {
                printf("Error: Invalid choice.\n");
                break;
            }
        }
    }
    
    return 0;
}
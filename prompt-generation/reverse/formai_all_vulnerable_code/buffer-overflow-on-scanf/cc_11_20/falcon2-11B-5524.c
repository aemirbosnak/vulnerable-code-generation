//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rooms[10];
    int guests[10];
    int current_guest = 0;
    int room_available = 0;
    
    for(int i=0; i<10; i++) {
        rooms[i] = i + 1;
        guests[i] = 0;
    }
    
    printf("C Hotel Management System\n");
    
    printf("1. Check room availability\n");
    printf("2. Check guest details\n");
    printf("3. Book a room\n");
    printf("4. Cancel a booking\n");
    printf("5. Update guest details\n");
    printf("6. Exit\n");
    
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    while(choice!= 6) {
        switch(choice) {
            case 1:
                printf("Rooms available: ");
                for(int i=0; i<10; i++) {
                    if(rooms[i] == 0) {
                        printf("%d\n", rooms[i]);
                    }
                }
                break;
                
            case 2:
                printf("Guest details: ");
                for(int i=0; i<10; i++) {
                    printf("%d - %d\n", i+1, guests[i]);
                }
                break;
                
            case 3:
                printf("Enter room number: ");
                scanf("%d", &room_available);
                if(room_available > 0 && room_available <= 10) {
                    printf("Enter guest details: ");
                    scanf("%d %d", &current_guest, &guests[current_guest]);
                    rooms[room_available - 1] = 0;
                    guests[current_guest]++;
                    printf("Room %d booked for guest %d\n", room_available, current_guest + 1);
                }
                else {
                    printf("Invalid room number or guest details\n");
                }
                break;
                
            case 4:
                printf("Enter room number: ");
                scanf("%d", &room_available);
                if(room_available > 0 && room_available <= 10) {
                    printf("Enter guest details: ");
                    scanf("%d %d", &current_guest, &guests[current_guest]);
                    rooms[room_available - 1] = 1;
                    guests[current_guest]--;
                    printf("Room %d cancelled for guest %d\n", room_available, current_guest + 1);
                }
                else {
                    printf("Invalid room number or guest details\n");
                }
                break;
                
            case 5:
                printf("Enter room number: ");
                scanf("%d", &room_available);
                if(room_available > 0 && room_available <= 10) {
                    printf("Enter guest details: ");
                    scanf("%d %d", &current_guest, &guests[current_guest]);
                    rooms[room_available - 1] = 0;
                    guests[current_guest]++;
                    printf("Guest details updated for room %d\n", room_available);
                }
                else {
                    printf("Invalid room number or guest details\n");
                }
                break;
                
            default:
                printf("Invalid choice\n");
                break;
        }
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }
    
    return 0;
}
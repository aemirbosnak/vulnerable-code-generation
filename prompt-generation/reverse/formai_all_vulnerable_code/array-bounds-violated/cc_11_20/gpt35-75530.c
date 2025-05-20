//FormAI DATASET v1.0 Category: Hotel Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int rooms[10];
    int stay_length, num_guests, room_number, total_stays = 0;
    char option;
    
    //Initialize all rooms as empty
    for(int i = 0; i < 10; i++) {
        rooms[i] = 0;
    }
    
    //Main loop for hotel management system
    while(1) {
        
        printf("\n**********C Hotel Management System**********\n");
        printf("1. Book a room \n");
        printf("2. View all booked rooms \n");
        printf("3. Checkout a room \n");
        printf("4. Exit \n");
        
        printf("Enter an option: ");
        scanf(" %c", &option);
        
        switch (option) {
            case '1':
                printf("\nEnter room number (0-9): ");
                scanf("%d", &room_number);
                if(rooms[room_number] == 0) {
                    printf("Enter length of stay (in days): ");
                    scanf("%d", &stay_length);
                    printf("Enter number of guests: ");
                    scanf("%d", &num_guests);
                    printf("\nRoom has been booked!\n");
                    total_stays++;
                    rooms[room_number] = stay_length;
                    break;
                }
                else {
                    printf("Room is already booked. Please choose another room.\n");
                    break;
                }
                
            case '2':
                printf("\nList of all booked rooms:\n");
                for(int i = 0; i < 10; i++) {
                    if(rooms[i] != 0) {
                        printf("Room %d is booked for %d days.\n", i, rooms[i]);
                    }
                }
                break;
              
            case '3':
                printf("\nEnter room number (0-9): ");
                scanf("%d", &room_number);
                if(rooms[room_number] != 0) {
                    float room_cost = rooms[room_number] * 100.0;
                    printf("Room charges for %d days: $%.2f\n", rooms[room_number], room_cost);
                    rooms[room_number] = 0;
                    printf("Thank you for staying at C Hotel! Please come again.\n");
                    break;
                }
                else {
                    printf("Room is not currently booked.\n");
                    break;
                }
                
            case '4':
                printf("\nTotal rooms booked: %d\n", total_stays);
                printf("Thank you for using C Hotel Management System. Goodbye!\n");
                exit(0);
            
            default:
                printf("Invalid option. Please enter a valid option.\n");
                break;
        }
    }
    
    return 0;
}
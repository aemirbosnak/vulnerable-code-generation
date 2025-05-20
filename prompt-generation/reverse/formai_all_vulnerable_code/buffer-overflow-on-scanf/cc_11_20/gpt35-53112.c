//FormAI DATASET v1.0 Category: Hotel Management System ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[50];
    int room_no;
    int nights;
    float rate;
    float total_cost;
} guest;

int main()
{
    guest guests[50];
    int menu_choice = 0;
    int num_guests = 0;
    int room_count[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}; // Array to keep track of room availability
    int room, nights, i;
    float rate;

    while(menu_choice != 4) {
        printf("\n\nWelcome to C Hotel Management System\n\n");
        printf("Menu:\n");
        printf("1. Check-in\n");
        printf("2. Check-out\n");
        printf("3. View Status\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &menu_choice);

        switch(menu_choice) {
            case 1:
                if(num_guests == 50) {
                    printf("\nSorry! Maximum number of guests reached.\n\n");
                }
                else {
                    printf("\nCheck-in details:\n");
                    printf("Room number (1-10): ");
                    scanf("%d", &room);
                    if(room < 1 || room > 10) {
                        printf("\nInvalid room number.\n\n");
                        break;
                    }
                    if(room_count[room-1] == 0) {
                        printf("\nSorry! Room already occupied.\n\n");
                        break;
                    }
                    printf("Number of nights: ");
                    scanf("%d", &nights);
                    printf("Rate: ");
                    scanf("%f", &rate);
                    guests[num_guests].room_no = room;
                    strcpy(guests[num_guests].name, "Guest");
                    guests[num_guests].nights = nights;
                    guests[num_guests].rate = rate;
                    guests[num_guests].total_cost = nights * rate;
                    printf("\nTotal cost: %.2f\n", guests[num_guests].total_cost);
                    room_count[room-1]--; // Decrease room availability
                    num_guests++;
                }
                break;
            case 2:
                printf("\nCheck-out details:\n");
                printf("Room number (1-10): ");
                scanf("%d", &room);
                if(room < 1 || room > 10) {
                    printf("\nInvalid room number.\n\n");
                    break;
                }
                for(i = 0; i < num_guests; i++) {
                    if(guests[i].room_no == room) {
                        printf("\nName: %s\n", guests[i].name);
                        printf("Number of nights: %d\n", guests[i].nights);
                        printf("Rate: %.2f\n", guests[i].rate);
                        printf("Total cost: %.2f\n\n", guests[i].total_cost);
                        room_count[room-1]++; // Increase room availability
                        num_guests--;
                        guests[i] = guests[num_guests];
                        break;
                    }
                }
                if(i == num_guests) {
                    printf("\nRoom not occupied.\n\n");
                }
                break;
            case 3:
                printf("\nRoom Status:\n");
                for(i = 0; i < 10; i++) {
                    printf("Room %d: %d\n", i+1, room_count[i]);
                }
                break;
            case 4:
                printf("\nThank you for using C Hotel Management System!\n\n");
                break;
            default:
                printf("\nInvalid choice.\n\n");
        }
    }

    return 0;
}
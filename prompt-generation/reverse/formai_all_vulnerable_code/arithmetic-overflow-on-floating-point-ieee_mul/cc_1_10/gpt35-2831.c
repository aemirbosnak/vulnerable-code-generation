//FormAI DATASET v1.0 Category: Hotel Management System ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct guest{
    int roomNo;
    char name[50];
    int daysStayed;
    double cost;
};

int main(){
    printf("=====Welcome to C Hotel Management System=====\n");
    int numRooms, choice;
    double costPerDay;
    printf("Enter the number of rooms available in the hotel: ");
    scanf("%d", &numRooms);
    printf("Enter the cost per day for each room: ");
    scanf("%lf", &costPerDay);

    struct guest guests[numRooms]; // initialize guest struct array with number of rooms available

    while(1){
        printf("\nPlease select one of the following options: \n");
        printf("1. Book a room\n2. View all the bookings\n3. Check out a guest\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: // option to book a room
                printf("\nPlease enter your name: ");
                char name[50];
                scanf("%s", name);
                int room;
                printf("Please enter the room number you would like to book (1-%d): ", numRooms);
                scanf("%d", &room);
                if(guests[room-1].roomNo != 0){  // check if room is already occupied
                    printf("Sorry, this room is already booked.\n");
                    break;
                }
                int days;
                printf("Please enter the number of days you would like to book: ");
                scanf("%d", &days);
                double cost = days*costPerDay; // calculate cost of stay
                guests[room-1].roomNo = room;  // store guest information in struct array
                strcpy(guests[room-1].name, name);
                guests[room-1].daysStayed = days;
                guests[room-1].cost = cost;
                printf("Thank you for booking. Your total cost is: $%.2lf\n", cost);
                break;
            case 2: // option to view all the bookings
                printf("\nRoom No.\tGuest Name\tDays Stayed\tCost\n");
                for(int i=0; i<numRooms; i++){
                    if(guests[i].roomNo != 0){
                        printf("%d\t\t%s\t\t%d\t\t%.2lf\n", guests[i].roomNo, guests[i].name, guests[i].daysStayed, guests[i].cost);
                    }
                }
                break;
            case 3: // option to check out a guest
                printf("\nPlease enter the room number to check out: ");
                int roomNo;
                scanf("%d", &roomNo);
                if(guests[roomNo-1].roomNo == 0){
                    printf("This room is not occupied.\n");
                    break;
                }
                printf("Thank you for staying with us. Your total cost is: $%.2lf\n", guests[roomNo-1].cost);
                guests[roomNo-1].roomNo = 0;  // reset guest information in struct array
                guests[roomNo-1].daysStayed = 0;
                guests[roomNo-1].cost = 0.0;
                break;
            case 4: // exit program
                printf("Thank you for using C Hotel Management System.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}
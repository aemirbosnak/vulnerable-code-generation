//FormAI DATASET v1.0 Category: Hotel Management System ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct room{
    int room_no;
    int beds;
    int rate;
    char type[20];
    char status[20];
}r[20];

struct booking{
    int booking_no;
    char customer_name[50];
    int room_no;
    int nights;
    int total_cost;
}b[20];

int max_rooms = 10; //Setting the maximum number of rooms in the hotel
int no_of_rooms = 0; //Initializing the current number of rooms to 0

void add_room()
{
    if(no_of_rooms == max_rooms)
    {
        printf("Sorry, the hotel has reached its maximum capacity of %d rooms.\n", max_rooms);
        return;
    }

    printf("*** ADD ROOM ***\n");

    printf("Enter the room number: ");
    scanf("%d", &r[no_of_rooms].room_no);

    printf("Enter the type of room (Single/Double): ");
    scanf("%s", r[no_of_rooms].type);

    printf("Enter the number of beds (1/2): ");
    scanf("%d", &r[no_of_rooms].beds);

    printf("Enter the rate of the room (per night): ");
    scanf("%d", &r[no_of_rooms].rate);

    strcpy(r[no_of_rooms].status, "Available"); //Setting the initial status of the room to Available

    printf("Room added successfully.\n");
    no_of_rooms++; //Incrementing the current number of rooms
}

void display_rooms()
{
    if(no_of_rooms == 0)
    {
        printf("Sorry, there are no rooms in the hotel.\n");
        return;
    }

    printf("*** ROOMS IN THE HOTEL ***\n");

    printf("Room No.\tType\tBeds\tRate\tStatus\n");

    for(int i=0; i<no_of_rooms; i++)
    {
        printf("%d\t\t%s\t%d\t%d\t%s\n", r[i].room_no, r[i].type, r[i].beds, r[i].rate, r[i].status);
    }
}

void book_room()
{
    if(no_of_rooms == 0)
    {
        printf("Sorry, there are no rooms in the hotel.\n");
        return;
    }

    printf("*** BOOK A ROOM ***\n");

    printf("Enter your name: ");
    scanf("%s", b[no_of_rooms].customer_name);

    printf("Enter the room number: ");
    scanf("%d", &b[no_of_rooms].room_no);

    printf("Enter the number of nights: ");
    scanf("%d", &b[no_of_rooms].nights);

    for(int i=0; i<no_of_rooms; i++)
    {
        if(r[i].room_no == b[no_of_rooms].room_no && strcmp(r[i].status, "Available") == 0) //Checking if the room is available
        {
            strcpy(r[i].status, "Booked"); //Setting the new status of the room to Booked

            b[no_of_rooms].booking_no = 1000 + no_of_rooms; //Setting the booking number
            b[no_of_rooms].total_cost = b[no_of_rooms].nights * r[i].rate; //Calculating the total cost of the booking

            printf("Room booked successfully.\n");
            printf("Booking Number: %d\n", b[no_of_rooms].booking_no);
            printf("Total Cost: %d\n", b[no_of_rooms].total_cost);

            no_of_rooms++; //Incrementing the current number of bookings
            return;
        }
    }

    printf("Sorry, the room is not available.\n");
}

void display_bookings()
{
    if(no_of_rooms == 0)
    {
        printf("Sorry, there are no bookings in the hotel.\n");
        return;
    }

    printf("*** BOOKINGS IN THE HOTEL ***\n");

    printf("Booking No.\tCustomer Name\tRoom No.\tNights\tTotal Cost\n");

    for(int i=0; i<no_of_rooms; i++)
    {
        printf("%d\t\t%s\t\t%d\t\t%d\t%d\n", b[i].booking_no, b[i].customer_name, b[i].room_no, b[i].nights, b[i].total_cost);
    }
}

int main()
{
    int choice;
    do{
        printf("\n*** HOTEL MANAGEMENT SYSTEM ***\n");
        printf("1. Add a room\n");
        printf("2. Display rooms in the hotel\n");
        printf("3. Book a room\n");
        printf("4. Display bookings in the hotel\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                add_room();
                break;
            case 2:
                display_rooms();
                break;
            case 3:
                book_room();
                break;
            case 4:
                display_bookings();
                break;
            case 5:
                printf("Thank you for using the hotel management system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(1);

    return 0;
}
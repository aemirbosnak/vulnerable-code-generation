//FormAI DATASET v1.0 Category: Hotel Management System ; Style: realistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct guest{
    char name[50];
    char address[100];
    char phone[11];
    int room_no;
    char check_in_date[11];
    char check_out_date[11];
}guests[20];

int count = 0; //To maintain the count of the current bookings

// Functions to manage the guest details in the hotel management system

void book_room()
{
    if(count >= 20)
    {
        printf("Hotel is full. No rooms available!\n");
        return;
    }

    printf("\nEnter guest name: ");
    scanf("%s", guests[count].name);

    printf("\nEnter guest address: ");
    scanf("%s", guests[count].address);

    printf("\nEnter guest phone number: ");
    scanf("%s", guests[count].phone);

    printf("\nEnter guest room number: ");
    scanf("%d", &guests[count].room_no);

    printf("\nEnter guest check-in date: ");
    scanf("%s", guests[count].check_in_date);

    printf("\nEnter guest check-out date: ");
    scanf("%s", guests[count].check_out_date);

    printf("\nSuccessfully booked room!\n");

    count++;
}

void view_bookings()
{
    if(count == 0)
    {
        printf("\nNo bookings yet!\n");
        return;
    }

    printf("\n-- List of current bookings --\n");

    for(int i=0; i<count; i++)
    {
        printf("\nGuest Name: %s", guests[i].name);
        printf("\nGuest Address: %s", guests[i].address);
        printf("\nGuest Phone Number: %s", guests[i].phone);
        printf("\nGuest Room Number: %d", guests[i].room_no);
        printf("\nGuest Check-In Date: %s", guests[i].check_in_date);
        printf("\nGuest Check-Out Date: %s", guests[i].check_out_date);

        printf("\n--------------------------------\n");
    }
}

void cancel_booking()
{
    if(count == 0)
    {
        printf("\nNo bookings to cancel!\n");
        return;
    }

    int room_number;
    printf("\nEnter the room number you want to cancel booking for: ");
    scanf("%d", &room_number);

    for(int i=0; i<count; i++)
    {
        if(guests[i].room_no == room_number)
        {
            printf("\nBooking for room number %d by %s has been cancelled!\n", guests[i].room_no, guests[i].name);

            for(int j=i; j<count-1; j++)
            {
                guests[j] = guests[j+1];
            }

            count--;
            return;
        }
    }

    printf("\nNo bookings found for room number %d\n", room_number);
}

// Driver code for the hotel management system

int main()
{
    int choice;
    do
    {
        printf("\n-- Hotel Management System --\n");
        printf("\n1. Book Room");
        printf("\n2. View Bookings");
        printf("\n3. Cancel Booking");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                book_room();
                break;
            case 2:
                view_bookings();
                break;
            case 3:
                cancel_booking();
                break;
            case 4:
                printf("\nThank you for using the hotel management system!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
        }
        
    }while(1);

    return 0;
}
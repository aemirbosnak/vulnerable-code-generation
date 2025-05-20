//FormAI DATASET v1.0 Category: Hotel Management System ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Structure for room
struct room
{
    int room_number;
    char room_type[20];
    char occupancy_type[20];
    float room_rate;
    int availability;
};

//Function for displaying menu
void display_menu()
{
    printf("\n\nHotel Management System\n");
    printf("\n\nMenu");
    printf("\n1. Book a Room");
    printf("\n2. Checkout");
    printf("\n3. Room Availability");
    printf("\n4. Display All Rooms");
    printf("\n5. Exit");
}

//Function for booking a room
void book_room(struct room r[], int n)
{
    int room_number, i, flag = 0;
    char occupancy_type[20];
    printf("\nEnter Room Number: ");
    scanf("%d", &room_number);
    for(i=0; i<n; i++)
    {
        if(r[i].room_number == room_number)
        {
            if(r[i].availability == 1)
            {
                printf("\nEnter Occupancy Type (Single/Double/Triple): ");
                scanf("%s", occupancy_type);
                if(strcmp(occupancy_type, "Single") == 0)
                {
                    r[i].availability = 0;
                    strcpy(r[i].occupancy_type, "Single");
                    printf("\nRoom Booked Successfully!\n");
                }
                else if(strcmp(occupancy_type, "Double") == 0)
                {
                    r[i].availability = 0;
                    strcpy(r[i].occupancy_type, "Double");
                    printf("\nRoom Booked Successfully!\n");
                }
                else if(strcmp(occupancy_type, "Triple") == 0)
                {
                    r[i].availability = 0;
                    strcpy(r[i].occupancy_type, "Triple");
                    printf("\nRoom Booked Successfully!\n");
                }
                else
                {
                    printf("\nInvalid Occupancy Type!\n");
                }
            }
            else
            {
                printf("\nRoom not Available!\n");
            }
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("\nInvalid Room Number!\n");
    }
}

//Function for checkout
void checkout(struct room r[], int n)
{
    int room_number, i, flag = 0;
    float bill;
    printf("\nEnter Room Number: ");
    scanf("%d", &room_number);
    for(i=0; i<n; i++)
    {
        if(r[i].room_number == room_number)
        {
            if(r[i].availability == 0)
            {
                if(strcmp(r[i].occupancy_type, "Single") == 0)
                {
                    bill = r[i].room_rate + r[i].room_rate * 0.1;
                    printf("\nTotal Bill: %.2f\n", bill);
                }
                else if(strcmp(r[i].occupancy_type, "Double") == 0)
                {
                    bill = r[i].room_rate + r[i].room_rate * 0.15;
                    printf("\nTotal Bill: %.2f\n", bill);
                }
                else if(strcmp(r[i].occupancy_type, "Triple") == 0)
                {
                    bill = r[i].room_rate + r[i].room_rate * 0.2;
                    printf("\nTotal Bill: %.2f\n", bill);
                }
                r[i].availability = 1;
                strcpy(r[i].occupancy_type, "");
                printf("\nCheckout Successful!\n");
            }
            else
            {
                printf("\nInvalid Room Number!\n");
            }
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("\nInvalid Room Number!\n");
    }
}

//Function for checking room availability
void room_availability(struct room r[], int n)
{
    int i;
    char room_type[20];
    printf("\nEnter Room Type (Single/Double/Triple): ");
    scanf("%s", room_type);
    printf("\nRoom Number\tRoom Type\tOccupancy Type\tRoom Rate\tAvailability\n");
    for(i=0; i<n; i++)
    {
        if(strcmp(r[i].room_type, room_type) == 0 && r[i].availability == 1)
        {
            printf("%d\t\t%s\t\t%s\t\t%.2f\t\tAvailable\n", r[i].room_number, r[i].room_type, r[i].occupancy_type, r[i].room_rate);
        }
        else if(strcmp(r[i].room_type, room_type) == 0 && r[i].availability == 0)
        {
            printf("%d\t\t%s\t\t%s\t\t%.2f\t\tBooked\n", r[i].room_number, r[i].room_type, r[i].occupancy_type, r[i].room_rate);
        }
    }
}

//Function for displaying all rooms
void display_all_rooms(struct room r[], int n)
{
    int i;
    printf("\nRoom Number\tRoom Type\tOccupancy Type\tRoom Rate\tAvailability\n");
    for(i=0; i<n; i++)
    {
        if(r[i].availability == 1)
        {
            printf("%d\t\t%s\t\t%s\t\t%.2f\t\tAvailable\n", r[i].room_number, r[i].room_type, r[i].occupancy_type, r[i].room_rate);
        }
        else if(r[i].availability == 0)
        {
            printf("%d\t\t%s\t\t%s\t\t%.2f\t\tBooked\n", r[i].room_number, r[i].room_type, r[i].occupancy_type, r[i].room_rate);
        }
    }
}

//Main function
int main()
{
    //Initializing rooms
    struct room r[50];
    int n, i, choice;
    printf("\nEnter Number of Rooms: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("\nEnter Room Number: ");
        scanf("%d", &r[i].room_number);
        printf("Enter Room Type (Single/Double/Triple): ");
        scanf("%s", r[i].room_type);
        printf("Enter Room Rate: ");
        scanf("%f", &r[i].room_rate);
        r[i].availability = 1;
        strcpy(r[i].occupancy_type, "");
    }

    //Displaying menu
    do
    {
        display_menu();

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: book_room(r, n);
                    break;

            case 2: checkout(r, n);
                    break;

            case 3: room_availability(r, n);
                    break;

            case 4: display_all_rooms(r, n);
                    break;

            case 5: printf("\nThank You!\n");
                    break;

            default: printf("\nInvalid Choice!\n");
        }
    }while(choice!=5);

    return 0;
}
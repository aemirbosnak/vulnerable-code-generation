//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct room
{
    int room_no;
    char room_type[20];
    int capacity;
    int availability;
};

struct customer
{
    char name[30];
    int age;
    char address[50];
    char phone_no[15];
    char email[30];
    int room_no;
    char check_in[20];
    char check_out[20];
};

struct room rooms[100];
struct customer customers[100];
int num_of_rooms = 0;
int num_of_customers = 0;

void add_rooms()
{
    int i, n;
    printf("Enter the number of rooms to be added: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter room number: ");
        scanf("%d", &rooms[num_of_rooms].room_no);
        printf("Enter room type: ");
        scanf("%s", rooms[num_of_rooms].room_type);
        printf("Enter room capacity: ");
        scanf("%d", &rooms[num_of_rooms].capacity);
        rooms[num_of_rooms].availability = 1;
        num_of_rooms++;
    }
}

void display_rooms()
{
    int i;
    system("cls");
    printf("Room No.\tRoom Type\tCapacity\tAvailability\n");
    for(i = 0; i < num_of_rooms; i++)
    {
        printf("%d\t\t%s\t\t%d\t\t", rooms[i].room_no, rooms[i].room_type, rooms[i].capacity);
        if(rooms[i].availability == 1)
            printf("Available\n");
        else
            printf("Not Available\n");
    }
    printf("\n");
    system("pause");
}

void add_customer()
{
    int room_no, found = 0, i;
    printf("Enter room number: ");
    scanf("%d", &room_no);
    for(i = 0; i < num_of_rooms; i++)
    {
        if(rooms[i].room_no == room_no)
        {
            found = 1;
            break;
        }
    }
    if(found == 1 && rooms[i].availability == 1)
    {
        printf("Enter customer name: ");
        scanf("%s", customers[num_of_customers].name);
        printf("Enter customer age: ");
        scanf("%d", &customers[num_of_customers].age);
        printf("Enter customer address: ");
        scanf("%s", customers[num_of_customers].address);
        printf("Enter customer phone no.: ");
        scanf("%s", customers[num_of_customers].phone_no);
        printf("Enter customer email: ");
        scanf("%s", customers[num_of_customers].email);
        strcpy(customers[num_of_customers].check_in, __DATE__);
        printf("Enter check-out date (dd/mm/yyyy): ");
        scanf("%s", customers[num_of_customers].check_out);
        rooms[i].availability = 0;
        customers[num_of_customers].room_no = room_no;
        printf("Customer added successfully!\n\n");
        num_of_customers++;
    }
    else if(found == 1 && rooms[i].availability == 0)
    {
        printf("Room not available!\n\n");
    }
    else
    {
        printf("Room not found!\n\n");
    }
}

void display_customers()
{
    int i;
    system("cls");
    printf("Name\t\tAge\t\tAddress\t\tPhone No.\tEmail\t\tCheck-in Date\t\tCheck-out Date\t\tRoom No.\n");
    for(i = 0; i < num_of_customers; i++)
    {
        printf("%s\t\t%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%d\n", customers[i].name, customers[i].age, customers[i].address, customers[i].phone_no, customers[i].email, customers[i].check_in, customers[i].check_out, customers[i].room_no);
    }
    printf("\n");
    system("pause");
}

void check_out()
{
    int room_no, found = 0, i;
    printf("Enter room number to check-out: ");
    scanf("%d", &room_no);
    for(i = 0; i < num_of_customers; i++)
    {
        if(customers[i].room_no == room_no)
        {
            found = 1;
            break;
        }
    }
    if(found == 1)
    {
        rooms[room_no-1].availability = 1;
        printf("%s has successfully checked-out of Room No. %d\n\n", customers[i].name, room_no);
    }
    else
    {
        printf("Customer not found in Room No. %d\n\n", room_no);
    }
}

int main()
{
    int choice;
    while(1)
    {
        system("cls");
        printf("Welcome to C Hotel Management System\n");
        printf("1. Add Rooms\n");
        printf("2. Display Rooms\n");
        printf("3. Add Customer\n");
        printf("4. Display Customers\n");
        printf("5. Check-out\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                add_rooms();
                break;
            case 2:
                display_rooms();
                break;
            case 3:
                add_customer();
                break;
            case 4:
                display_customers();
                break;
            case 5:
                check_out();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n\n");
                break;
        }
    }
    return 0;
}
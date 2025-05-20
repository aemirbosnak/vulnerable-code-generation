//FormAI DATASET v1.0 Category: Hotel Management System ; Style: optimized
#include <stdio.h>
#include <string.h>
#define MAX_GUESTS 100 // Maximum number of guests allowed in the hotel

// Structure to store guest information
struct guest
{
    char name[50];
    int room_no;
    int days;
    float bill;
};

// Function to add a new guest to the system
void add_guest(int n, struct guest p[]) 
{
    int room_no;
    int check = 0; // To check if room number is already taken
    
    printf("Enter guest name: ");
    scanf("%s", p[n].name);
    
    // Check if room number is already taken
    do 
    {
        printf("Enter room number (1-100): ");
        scanf("%d", &room_no);

        for (int i = 0; i < n; i++) 
        {
            if (p[i].room_no == room_no) 
            {
                printf("Room number already taken, please select another room\n");
                check = 1;
                break;
            }
            else
                check = 0;
        }
    } while(check == 1);

    p[n].room_no = room_no;

    printf("Enter number of days of stay: ");
    scanf("%d", &p[n].days);

    // Calculate bill based on number of days of stay
    if (p[n].days < 5) 
        p[n].bill = 1000 * p[n].days;
    else if (p[n].days >= 5 && p[n].days < 10)
        p[n].bill = 900 * p[n].days;
    else
        p[n].bill = 800 * p[n].days;

    printf("Guest added successfully!\n\n");
}

// Function to show guest information
void show_guest(struct guest p) 
{
    printf("Name: %s\n", p.name);
    printf("Room No.: %d\n", p.room_no);
    printf("Number of days of stay: %d\n", p.days);
    printf("Total bill amount: Rs. %.2f\n\n", p.bill);
}

// Function to display guest information
void display_guests(int n, struct guest p[]) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("Guest %d\n", i+1);
        show_guest(p[i]);
    }
}

// Function to search for a guest
int search_guest(int n, struct guest p[], int room_no) 
{
    for (int i = 0; i < n; i++) 
    {
        if (p[i].room_no == room_no)
            return i;
    }
    return -1;
}

// Function to delete a guest
void delete_guest(int n, struct guest p[]) 
{
    int room_no;

    printf("Enter room number of guest to be deleted: ");
    scanf("%d", &room_no);

    int index = search_guest(n, p, room_no);

    if (index != -1)
    {
        for (int i = index; i < n-1; i++)
            p[i] = p[i+1];

        printf("Guest deleted successfully!\n\n");
    }
    else
        printf("Guest not found!\n\n");
}

// Main function
int main() 
{
    struct guest guests[MAX_GUESTS]; // Array of structures to store guest information
    int choice;
    int num_guests = 0;

    printf("Welcome to the Hotel Management System\n");

    do 
    {
        printf("1. Add Guest\n");
        printf("2. Display All Guests\n");
        printf("3. Delete Guest\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                if (num_guests < MAX_GUESTS)
                {
                    add_guest(num_guests, guests);
                    num_guests++;
                }
                else
                    printf("Maximum number of guests reached!\n\n");
                break;
            case 2:
                display_guests(num_guests, guests);
                break;
            case 3:
                delete_guest(num_guests, guests);
                num_guests--;
                break;
            case 4:
                break;
            default:
                printf("Invalid choice, please try again\n\n");
        }

    } while (choice != 4);

    printf("Thanks for using the Hotel Management System\n\n");

    return 0;
}
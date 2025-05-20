//FormAI DATASET v1.0 Category: Hotel Management System ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for guest details
struct guest
{
    char name[20];
    int age;
    char gender[8];
    char nationality[20];
    char address[50];
    int roomNo;
    int daysStay;
    float totalAmount;
};

// Function for guest check-in
void guestCheckIn(struct guest *g)
{
    printf("Enter guest details:\n");
    fflush(stdin);
    printf("Name: ");
    gets(g->name);
    printf("Age: ");
    scanf("%d",&g->age);
    fflush(stdin);
    printf("Gender: ");
    gets(g->gender);
    printf("Nationality: ");
    gets(g->nationality);
    printf("Address: ");
    gets(g->address);
    printf("Room number: ");
    scanf("%d",&g->roomNo);
    printf("Number of days stay: ");
    scanf("%d",&g->daysStay);
    g->totalAmount = g->daysStay * 2500.00;
    printf("\nGuest details recorded successfully!\nTotal amount due: %.2f\n",g->totalAmount);
}

// Function for guest check-out
void guestCheckOut(struct guest *g)
{
    printf("\nGuest details:\n");
    printf("Name: %s\n",g->name);
    printf("Age: %d\n",g->age);
    printf("Gender: %s\n",g->gender);
    printf("Nationality: %s\n",g->nationality);
    printf("Address: %s\n",g->address);
    printf("Room number: %d\n",g->roomNo);
    printf("Number of days stay: %d\n",g->daysStay);
    printf("Total amount due: %.2f\n",g->totalAmount);
    printf("\nGuest Checked Out Successfully!\n");
}

// Main function
int main()
{
    int choice=0;
    struct guest g1;
    
    // Hotel Management System Menu
    while(choice!=3)
    {
        printf("\n\t\tHotel Management System\n");
        printf("\n1. Guest Check-In\n2. Guest Check-Out\n3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: guestCheckIn(&g1);
                    break;
            
            case 2: guestCheckOut(&g1);
                    break;
            
            case 3: printf("\nThank you for using our Hotel Management System!\n");
                    break;
            
            default: printf("\nInvalid choice entered. Please try again.\n");
        }
    }
    
    return 0;
}
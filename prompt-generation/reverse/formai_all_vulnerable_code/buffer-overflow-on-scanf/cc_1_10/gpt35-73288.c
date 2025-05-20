//FormAI DATASET v1.0 Category: Hotel Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct guest_info
{
    char name[50];
    char email[50];
    char country[50];
    char room_type[50];
    int room_number;
    int days_stayed;
    float total_cost;
};
 
int main()
{
    int num_guests;
    printf("Welcome to our hotel management system!\n");
    printf("Please enter the number of guests: ");
    scanf("%d", &num_guests);
 
    struct guest_info *guests;
    guests = (struct guest_info *) malloc(num_guests * sizeof(struct guest_info));
 
    for (int i = 0; i < num_guests; i++)
    {
        printf("\n\nPlease enter the following information for guest %d\n", i+1);
 
        printf("Name: ");
        scanf("%s", guests[i].name);
 
        printf("Email: ");
        scanf("%s", guests[i].email);
 
        printf("Country: ");
        scanf("%s", guests[i].country);
 
        printf("Room Type: ");
        scanf("%s", guests[i].room_type);
 
        printf("Room Number: ");
        scanf("%d", &guests[i].room_number);
 
        printf("Days Stayed: ");
        scanf("%d", &guests[i].days_stayed);
 
        printf("Total Cost: ");
        scanf("%f", &guests[i].total_cost);
    }
 
    printf("\n\n");
    printf("Guests Information\n");
    printf("===================\n");
    printf("Name\tEmail\t\tCountry\t\tRoom Type\tRoom Number\tDays Stayed\tTotal Cost\n");
    printf("====\t=====\t\t=======\t\t=========\t===========\t===========\t==========\n");
 
    for (int i = 0; i < num_guests; i++)
    {
        printf("%s\t%s\t%s\t%s\t\t%d\t\t%d\t\t%.2f\n",
               guests[i].name, guests[i].email, guests[i].country, guests[i].room_type,
               guests[i].room_number, guests[i].days_stayed, guests[i].total_cost);
    }
 
    free(guests);
 
    printf("\n\nThank you for using our hotel management system!");
 
    return 0;
}
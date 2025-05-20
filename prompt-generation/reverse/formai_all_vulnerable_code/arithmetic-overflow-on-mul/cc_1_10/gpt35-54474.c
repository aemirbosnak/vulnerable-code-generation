//FormAI DATASET v1.0 Category: Hotel Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
    char name[50];
    int room_number;
    int nights_stayed;
    int total_bill;
};

struct guest guests[50];
int num_guests = 0;

void check_in()
{
    char name[50];
    int room_number, nights_stayed;
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter room number: ");
    scanf("%d", &room_number);
    printf("Enter number of nights stayed: ");
    scanf("%d", &nights_stayed);
    
    guests[num_guests].room_number = room_number;
    guests[num_guests].nights_stayed = nights_stayed;
    guests[num_guests].total_bill = nights_stayed * 100;
    strcpy(guests[num_guests].name, name);
    
    printf("%s has checked in to room %d for %d nights. Total bill: $%d\n", 
           guests[num_guests].name, guests[num_guests].room_number, guests[num_guests].nights_stayed, guests[num_guests].total_bill);
    num_guests++;
}

void check_out()
{
    int room_number, bill;
    printf("Enter room number: ");
    scanf("%d", &room_number);

    int i, found = 0;
    for (i = 0; i < num_guests; i++) {
        if (guests[i].room_number == room_number) {
            bill = guests[i].total_bill;
            printf("%s has checked out of room %d. Total bill: $%d\n", guests[i].name, guests[i].room_number, bill);
            for (int j = i; j < num_guests - 1; j++) {
                guests[j] = guests[j+1]; 
            }
            num_guests--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Room number not found.\n");
    }
}

void print_guests()
{
    printf("Name \tRoom \tNights \tBill\n");
    int i;
    for (i = 0; i < num_guests; i++) {
        printf("%s \t%d \t%d \t$%d\n", guests[i].name, guests[i].room_number, guests[i].nights_stayed, guests[i].total_bill);
    }
}

int main()
{
    int choice;
    do {
        printf("1. Check-in\n");
        printf("2. Check-out\n");
        printf("3. Print guests\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: check_in(); break;
            case 2: check_out(); break;
            case 3: print_guests(); break;
            case 4: printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice.\n"); break;
        }
    } while (1);
}
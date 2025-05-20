//FormAI DATASET v1.0 Category: Hotel Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining structure for hotel guests
typedef struct {
    char name[50];
    int room_number;
    int days_stayed;
    float bill_amount;
} Guest;

// Function to add a new guest to the system
void add_guest(Guest *guests, int *num_of_guests) {
    printf("\nEnter guest name: ");
    scanf("%s", guests[*num_of_guests].name);
    printf("Enter room number: ");
    scanf("%d", &guests[*num_of_guests].room_number);
    printf("Enter days stayed: ");
    scanf("%d", &guests[*num_of_guests].days_stayed);
    printf("Enter bill amount: ");
    scanf("%f", &guests[*num_of_guests].bill_amount);
    (*num_of_guests)++;
    printf("\nGuest added successfully!\n");
}

// Function to display all guests in the system
void display_all_guests(Guest *guests, int num_of_guests) {
    if(num_of_guests == 0) {
        printf("\nNo guests in the system!\n");
        return;
    }
    printf("\nAll guests in the system:\n");
    printf("Name\tRoom Number\tDays Stayed\tBill Amount\n");
    for(int i=0;i<num_of_guests;i++) {
        printf("%s\t%d\t\t%d\t\t%.2f\n", guests[i].name, guests[i].room_number, guests[i].days_stayed, guests[i].bill_amount);
    }
}

// Function to search for a guest by name
void search_guest_by_name(Guest *guests, int num_of_guests) {
    char target_name[50];
    printf("\nEnter target name: ");
    scanf("%s", target_name);
    int found = 0;
    for(int i=0;i<num_of_guests;i++) {
        if(strcmp(guests[i].name, target_name) == 0) {
            printf("\nGuest found!\n");
            printf("Name\tRoom Number\tDays Stayed\tBill Amount\n");
            printf("%s\t%d\t\t%d\t\t%.2f\n", guests[i].name, guests[i].room_number, guests[i].days_stayed, guests[i].bill_amount);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("\nGuest not found!\n");
    }
}

// Function to search for a guest by room number
void search_guest_by_room_number(Guest *guests, int num_of_guests) {
    int target_room_number;
    printf("\nEnter target room number: ");
    scanf("%d", &target_room_number);
    int found = 0;
    for(int i=0;i<num_of_guests;i++) {
        if(guests[i].room_number == target_room_number) {
            printf("\nGuest found!\n");
            printf("Name\tRoom Number\tDays Stayed\tBill Amount\n");
            printf("%s\t%d\t\t%d\t\t%.2f\n", guests[i].name, guests[i].room_number, guests[i].days_stayed, guests[i].bill_amount);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("\nGuest not found!\n");
    }
}

// Function to calculate total bill amount for all guests
float calculate_total_bill_amount(Guest *guests, int num_of_guests) {
    float total_bill_amount = 0;
    for(int i=0;i<num_of_guests;i++) {
        total_bill_amount += guests[i].bill_amount;
    }
    return total_bill_amount;
}

// Main function
int main() {
    Guest guests[100];
    int num_of_guests = 0;
    int menu_choice;
    while(1) {
        printf("\n--- Hotel Management System ---\n");
        printf("1. Add guest\n");
        printf("2. Display all guests\n");
        printf("3. Search for a guest by name\n");
        printf("4. Search for a guest by room number\n");
        printf("5. Calculate total bill amount for all guests\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);
        switch(menu_choice) {
            case 1:
                add_guest(guests, &num_of_guests);
                break;
            case 2:
                display_all_guests(guests, num_of_guests);
                break;
            case 3:
                search_guest_by_name(guests, num_of_guests);
                break;
            case 4:
                search_guest_by_room_number(guests, num_of_guests);
                break;
            case 5:
                printf("\nTotal bill amount for all guests: %.2f\n", calculate_total_bill_amount(guests, num_of_guests));
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}
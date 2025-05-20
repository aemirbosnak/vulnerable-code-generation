//FormAI DATASET v1.0 Category: Hotel Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100

typedef struct {
    char name[50];
    int room_number;
    char check_in_date[15];
    char check_out_date[15];
} Guest;

Guest guests[MAX_GUESTS];
int num_guests = 0;

void add_guest() {
    if (num_guests == MAX_GUESTS) {
        printf("Maximum number of guests reached.\n");
        return;
    }
    
    Guest guest;
    printf("Enter guest name: ");
    fgets(guest.name, 50, stdin);
    guest.name[strcspn(guest.name, "\n")] = 0;  // remove newline character from input
    
    printf("Enter room number: ");
    scanf("%d", &guest.room_number);
    getchar();  // consume newline character left by scanf
    
    printf("Enter check-in date (dd/mm/yyyy): ");
    fgets(guest.check_in_date, 15, stdin);
    guest.check_in_date[strcspn(guest.check_in_date, "\n")] = 0;
    
    printf("Enter check-out date (dd/mm/yyyy): ");
    fgets(guest.check_out_date, 15, stdin);
    guest.check_out_date[strcspn(guest.check_out_date, "\n")] = 0;
    
    guests[num_guests++] = guest;
    printf("Guest added successfully.\n");
}

void remove_guest() {
    int room_number;
    printf("Enter room number of guest to remove: ");
    scanf("%d", &room_number);
    
    int found = 0;
    for (int i = 0; i < num_guests; i++) {
        if (guests[i].room_number == room_number) {
            // shift remaining elements down by one
            for (int j = i; j < num_guests - 1; j++) {
                guests[j] = guests[j+1];
            }
            num_guests--;
            found = 1;
            break;
        }
    }
    
    if (found) {
        printf("Guest removed successfully.\n");
    } else {
        printf("Guest not found.\n");
    }
}

void print_guests() {
    if (num_guests == 0) {
        printf("No guests currently checked in.\n");
        return;
    }
    
    printf("Guests currently checked in:\n");
    printf("Name\tRoom\tCheck In\tCheck Out\n");
    for (int i = 0; i < num_guests; i++) {
        Guest guest = guests[i];
        printf("%s\t%d\t%s\t%s\n", guest.name, guest.room_number, guest.check_in_date, guest.check_out_date);
    }
}

int main() {
    int option;
    while (1) {
        printf("\nHotel Management System\n");
        printf("1. Add Guest\n");
        printf("2. Remove Guest\n");
        printf("3. Print Guests\n");
        printf("4. Exit\n");
        
        printf("\nEnter option (1-4): ");
        scanf("%d", &option);
        getchar();  // consume newline character left by scanf
        
        switch (option) {
            case 1:
                add_guest();
                break;
            case 2:
                remove_guest();
                break;
            case 3:
                print_guests();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }
    
    return 0;
}
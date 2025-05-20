//FormAI DATASET v1.0 Category: Hotel Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int room_number;
    float room_rate;
    char checkin_date[12];
    char checkout_date[12];
    int num_of_guests;
} guest;

guest guests[10];
int num_of_guests = 0;

void add_guest() {
    printf("\nAdding New Guest: \n");

    if (num_of_guests >= 10) {
        printf("Cannot add more than 10 guests\n");
        return;
    }

    printf("Enter Guest's Name: ");
    scanf("%s", guests[num_of_guests].name);

    printf("Enter Room Number: ");
    scanf("%d", &guests[num_of_guests].room_number);

    printf("Enter Room Rate: ");
    scanf("%f", &guests[num_of_guests].room_rate);

    printf("Enter Check-in Date (dd/mm/yyyy): ");
    scanf("%s", guests[num_of_guests].checkin_date);

    printf("Enter Check-out Date (dd/mm/yyyy): ");
    scanf("%s", guests[num_of_guests].checkout_date);

    printf("Enter Number of Guests: ");
    scanf("%d", &guests[num_of_guests].num_of_guests);

    num_of_guests++;
    printf("\nGuest Added Successfully!\n");
}

void view_guests() {
    printf("\nViewing All Guests: \n");

    if (num_of_guests == 0) {
        printf("No Guests Found.\n");
        return;
    }

    printf("Name\t\tRoom No.\tRoom Rate\tCheck-in\tCheck-out\tNum Guests\n");

    for (int i = 0; i < num_of_guests; i++) {
        printf("%s\t\t%d\t\t%.2f\t\t%s\t\t%s\t\t%d\n", guests[i].name,
               guests[i].room_number, guests[i].room_rate, guests[i].checkin_date,
               guests[i].checkout_date, guests[i].num_of_guests);
    }
}

void search_guest() {
    char name[50];

    printf("\nSearching Guest: \n");

    printf("Enter the Name of the Guest to Search: ");
    scanf("%s", name);

    for (int i = 0; i < num_of_guests; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            printf("Name\t\tRoom No.\tRoom Rate\tCheck-in\tCheck-out\tNum Guests\n");
            printf("%s\t\t%d\t\t%.2f\t\t%s\t\t%s\t\t%d\n", guests[i].name,
                   guests[i].room_number, guests[i].room_rate, guests[i].checkin_date,
                   guests[i].checkout_date, guests[i].num_of_guests);
            return;
        }
    }

    printf("Guest Not Found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n\nC Hotel Management System\n");
        printf("*******************************\n");
        printf("1. Add New Guest\n");
        printf("2. View All Guests\n");
        printf("3. Search Guest\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_guest();
                break;
            case 2:
                view_guests();
                break;
            case 3:
                search_guest();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice.\n");
        }
    }

    return 0;
}
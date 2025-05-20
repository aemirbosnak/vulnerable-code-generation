//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    int room_number;
    int num_nights;
    float total_cost;
} guest;

guest guests[100];
int num_guests = 0;

void add_guest() {
    printf("Enter guest name: ");
    scanf("%s", guests[num_guests].name);
    printf("Enter guest address: ");
    scanf("%s", guests[num_guests].address);
    printf("Enter guest phone number: ");
    scanf("%s", guests[num_guests].phone);
    printf("Enter guest email address: ");
    scanf("%s", guests[num_guests].email);
    printf("Enter guest room number: ");
    scanf("%d", &guests[num_guests].room_number);
    printf("Enter number of nights guest will stay: ");
    scanf("%d", &guests[num_guests].num_nights);
    guests[num_guests].total_cost = guests[num_guests].num_nights * 100;
    num_guests++;
}

void print_guests() {
    for (int i = 0; i < num_guests; i++) {
        printf("Guest %d:\n", i + 1);
        printf("Name: %s\n", guests[i].name);
        printf("Address: %s\n", guests[i].address);
        printf("Phone: %s\n", guests[i].phone);
        printf("Email: %s\n", guests[i].email);
        printf("Room number: %d\n", guests[i].room_number);
        printf("Number of nights: %d\n", guests[i].num_nights);
        printf("Total cost: %.2f\n", guests[i].total_cost);
        printf("\n");
    }
}

void search_guest_by_name() {
    char name[50];
    printf("Enter guest name: ");
    scanf("%s", name);
    for (int i = 0; i < num_guests; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            printf("Guest found:\n");
            printf("Name: %s\n", guests[i].name);
            printf("Address: %s\n", guests[i].address);
            printf("Phone: %s\n", guests[i].phone);
            printf("Email: %s\n", guests[i].email);
            printf("Room number: %d\n", guests[i].room_number);
            printf("Number of nights: %d\n", guests[i].num_nights);
            printf("Total cost: %.2f\n", guests[i].total_cost);
            printf("\n");
            return;
        }
    }
    printf("Guest not found.\n");
}

void search_guest_by_room_number() {
    int room_number;
    printf("Enter guest room number: ");
    scanf("%d", &room_number);
    for (int i = 0; i < num_guests; i++) {
        if (guests[i].room_number == room_number) {
            printf("Guest found:\n");
            printf("Name: %s\n", guests[i].name);
            printf("Address: %s\n", guests[i].address);
            printf("Phone: %s\n", guests[i].phone);
            printf("Email: %s\n", guests[i].email);
            printf("Room number: %d\n", guests[i].room_number);
            printf("Number of nights: %d\n", guests[i].num_nights);
            printf("Total cost: %.2f\n", guests[i].total_cost);
            printf("\n");
            return;
        }
    }
    printf("Guest not found.\n");
}

void edit_guest() {
    char name[50];
    printf("Enter guest name: ");
    scanf("%s", name);
    for (int i = 0; i < num_guests; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            printf("Enter new guest name: ");
            scanf("%s", guests[i].name);
            printf("Enter new guest address: ");
            scanf("%s", guests[i].address);
            printf("Enter new guest phone number: ");
            scanf("%s", guests[i].phone);
            printf("Enter new guest email address: ");
            scanf("%s", guests[i].email);
            printf("Enter new guest room number: ");
            scanf("%d", &guests[i].room_number);
            printf("Enter new number of nights guest will stay: ");
            scanf("%d", &guests[i].num_nights);
            guests[i].total_cost = guests[i].num_nights * 100;
            printf("Guest updated.\n");
            return;
        }
    }
    printf("Guest not found.\n");
}

void delete_guest() {
    char name[50];
    printf("Enter guest name: ");
    scanf("%s", name);
    for (int i = 0; i < num_guests; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            for (int j = i + 1; j < num_guests; j++) {
                guests[j - 1] = guests[j];
            }
            num_guests--;
            printf("Guest deleted.\n");
            return;
        }
    }
    printf("Guest not found.\n");
}

int main() {
    int choice;
    do {
        printf("Hotel Management System\n");
        printf("1. Add guest\n");
        printf("2. Print guests\n");
        printf("3. Search guest by name\n");
        printf("4. Search guest by room number\n");
        printf("5. Edit guest\n");
        printf("6. Delete guest\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_guest();
                break;
            case 2:
                print_guests();
                break;
            case 3:
                search_guest_by_name();
                break;
            case 4:
                search_guest_by_room_number();
                break;
            case 5:
                edit_guest();
                break;
            case 6:
                delete_guest();
                break;
            case 7:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);
    return 0;
}
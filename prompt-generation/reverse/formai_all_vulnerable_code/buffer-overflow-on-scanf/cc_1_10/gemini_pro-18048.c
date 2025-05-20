//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    char id[20];
    char password[20];
    int room_number;
    int days_stayed;
    float bill;
} Guest;

Guest guests[100];
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

    printf("Enter guest id: ");
    scanf("%s", guests[num_guests].id);

    printf("Enter guest password: ");
    scanf("%s", guests[num_guests].password);

    printf("Enter guest room number: ");
    scanf("%d", &guests[num_guests].room_number);

    printf("Enter guest days stayed: ");
    scanf("%d", &guests[num_guests].days_stayed);

    guests[num_guests].bill = 0;

    num_guests++;
}

void view_guests() {
    for (int i = 0; i < num_guests; i++) {
        printf("Guest %d\n", i + 1);
        printf("Name: %s\n", guests[i].name);
        printf("Address: %s\n", guests[i].address);
        printf("Phone: %s\n", guests[i].phone);
        printf("Email: %s\n", guests[i].email);
        printf("Id: %s\n", guests[i].id);
        printf("Password: %s\n", guests[i].password);
        printf("Room number: %d\n", guests[i].room_number);
        printf("Days stayed: %d\n", guests[i].days_stayed);
        printf("Bill: $%.2f\n", guests[i].bill);
        printf("\n");
    }
}

void update_guest() {
    int guest_index;

    printf("Enter guest index: ");
    scanf("%d", &guest_index);

    printf("Enter new guest name: ");
    scanf("%s", guests[guest_index].name);

    printf("Enter new guest address: ");
    scanf("%s", guests[guest_index].address);

    printf("Enter new guest phone number: ");
    scanf("%s", guests[guest_index].phone);

    printf("Enter new guest email address: ");
    scanf("%s", guests[guest_index].email);

    printf("Enter new guest id: ");
    scanf("%s", guests[guest_index].id);

    printf("Enter new guest password: ");
    scanf("%s", guests[guest_index].password);

    printf("Enter new guest room number: ");
    scanf("%d", &guests[guest_index].room_number);

    printf("Enter new guest days stayed: ");
    scanf("%d", &guests[guest_index].days_stayed);
}

void delete_guest() {
    int guest_index;

    printf("Enter guest index: ");
    scanf("%d", &guest_index);

    for (int i = guest_index; i < num_guests - 1; i++) {
        guests[i] = guests[i + 1];
    }

    num_guests--;
}

void calculate_bill() {
    for (int i = 0; i < num_guests; i++) {
        guests[i].bill = guests[i].days_stayed * 100;
    }
}

void print_bill() {
    for (int i = 0; i < num_guests; i++) {
        printf("Guest %d\n", i + 1);
        printf("Name: %s\n", guests[i].name);
        printf("Bill: $%.2f\n", guests[i].bill);
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add guest\n");
        printf("2. View guests\n");
        printf("3. Update guest\n");
        printf("4. Delete guest\n");
        printf("5. Calculate bill\n");
        printf("6. Print bill\n");
        printf("7. Exit\n");

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
                update_guest();
                break;
            case 4:
                delete_guest();
                break;
            case 5:
                calculate_bill();
                break;
            case 6:
                print_bill();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
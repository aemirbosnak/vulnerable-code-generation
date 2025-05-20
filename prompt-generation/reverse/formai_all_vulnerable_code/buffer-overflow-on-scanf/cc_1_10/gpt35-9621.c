//FormAI DATASET v1.0 Category: Hotel Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char address[100];
    char phone[20];
    int age;
    char email[50];
} guest;

typedef struct {
    int room_number;
    char room_type[20];
    int num_beds;
    float price_per_night;
    char availability[10];
} room;

void add_guest(guest *g) {
    printf("Enter guest details: \n");
    printf("Name: ");
    fgets(g->name, 50, stdin);
    printf("Address: ");
    fgets(g->address, 100, stdin);
    printf("Phone: ");
    fgets(g->phone, 20, stdin);
    printf("Age: ");
    scanf("%d", &g->age);
    printf("Email: ");
    fgets(g->email, 50, stdin);
}

void add_room(room *r) {
    printf("Enter room details: \n");
    printf("Room number: ");
    scanf("%d", &r->room_number);
    printf("Room type: ");
    fgets(r->room_type, 20, stdin);
    printf("Number of beds: ");
    scanf("%d", &r->num_beds);
    printf("Price per night: ");
    scanf("%f", &r->price_per_night);
    printf("Availability (yes or no): ");
    fgets(r->availability, 10, stdin);
}

void print_guest(guest g) {
    printf("Name: %s", g.name);
    printf("Address: %s", g.address);
    printf("Phone: %s", g.phone);
    printf("Age: %d\n", g.age);
    printf("Email: %s", g.email);
}

void print_room(room r) {
    printf("Room number: %d\n", r.room_number);
    printf("Room type: %s", r.room_type);
    printf("Number of beds: %d\n", r.num_beds);
    printf("Price per night: $%.2f\n", r.price_per_night);
    printf("Availability: %s", r.availability);
}

int main() {
    int choice;
    guest g;
    room r;

    // Main menu loop
    while (1) {
        printf("\n\n       C HOTEL MANAGEMENT SYSTEM\n");
        printf("==========================================\n\n");
        printf("1. Add guest\n");
        printf("2. Add room\n");
        printf("3. Print guest details\n");
        printf("4. Print room details\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_guest(&g);
                break;
            case 2:
                add_room(&r);
                break;
            case 3:
                printf("\n\n        GUEST DETAILS\n");
                printf("==========================================\n\n");
                print_guest(g);
                break;
            case 4:
                printf("\n\n        ROOM DETAILS\n");
                printf("==========================================\n\n");
                print_room(r);
                break;
            case 5:
                printf("\n\n        THANK YOU FOR USING C HOTEL MANAGEMENT SYSTEM!\n");
                printf("=====================================================\n\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }

    return 0;
}
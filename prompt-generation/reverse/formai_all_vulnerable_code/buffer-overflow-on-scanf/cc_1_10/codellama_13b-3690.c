//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: innovative
// Hotel Management System in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures to store data
typedef struct {
    int id;
    char name[50];
    char address[100];
    int rooms;
    int price;
} Hotel;

typedef struct {
    int id;
    char name[50];
    char phone[20];
    char email[50];
} Customer;

// Function to display menu
void displayMenu() {
    printf("1. Add hotel\n");
    printf("2. Display all hotels\n");
    printf("3. Search hotel by ID\n");
    printf("4. Book a room\n");
    printf("5. Display all customers\n");
    printf("6. Search customer by ID\n");
    printf("7. Exit\n");
}

// Function to add hotel
void addHotel() {
    Hotel hotel;
    printf("Enter hotel ID: ");
    scanf("%d", &hotel.id);
    printf("Enter hotel name: ");
    scanf("%s", hotel.name);
    printf("Enter hotel address: ");
    scanf("%s", hotel.address);
    printf("Enter number of rooms: ");
    scanf("%d", &hotel.rooms);
    printf("Enter room price: ");
    scanf("%d", &hotel.price);
    printf("Hotel added successfully!\n");
}

// Function to display all hotels
void displayHotels() {
    Hotel *hotels = (Hotel*) malloc(sizeof(Hotel) * 100);
    int n = 0;
    while (n < 100) {
        printf("Hotel %d: %s, %s, %d rooms, %d per night\n", hotels[n].id, hotels[n].name, hotels[n].address, hotels[n].rooms, hotels[n].price);
        n++;
    }
    free(hotels);
}

// Function to search hotel by ID
void searchHotel() {
    int id;
    printf("Enter hotel ID: ");
    scanf("%d", &id);
    Hotel *hotels = (Hotel*) malloc(sizeof(Hotel) * 100);
    int n = 0;
    while (n < 100) {
        if (hotels[n].id == id) {
            printf("Hotel found: %s, %s, %d rooms, %d per night\n", hotels[n].name, hotels[n].address, hotels[n].rooms, hotels[n].price);
            break;
        }
        n++;
    }
    free(hotels);
}

// Function to book a room
void bookRoom() {
    int hotelId;
    printf("Enter hotel ID: ");
    scanf("%d", &hotelId);
    Hotel *hotels = (Hotel*) malloc(sizeof(Hotel) * 100);
    int n = 0;
    while (n < 100) {
        if (hotels[n].id == hotelId) {
            if (hotels[n].rooms > 0) {
                hotels[n].rooms--;
                printf("Room booked successfully!\n");
            } else {
                printf("No rooms available\n");
            }
            break;
        }
        n++;
    }
    free(hotels);
}

// Function to display all customers
void displayCustomers() {
    Customer *customers = (Customer*) malloc(sizeof(Customer) * 100);
    int n = 0;
    while (n < 100) {
        printf("Customer %d: %s, %s, %s\n", customers[n].id, customers[n].name, customers[n].phone, customers[n].email);
        n++;
    }
    free(customers);
}

// Function to search customer by ID
void searchCustomer() {
    int id;
    printf("Enter customer ID: ");
    scanf("%d", &id);
    Customer *customers = (Customer*) malloc(sizeof(Customer) * 100);
    int n = 0;
    while (n < 100) {
        if (customers[n].id == id) {
            printf("Customer found: %s, %s, %s\n", customers[n].name, customers[n].phone, customers[n].email);
            break;
        }
        n++;
    }
    free(customers);
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addHotel();
                break;
            case 2:
                displayHotels();
                break;
            case 3:
                searchHotel();
                break;
            case 4:
                bookRoom();
                break;
            case 5:
                displayCustomers();
                break;
            case 6:
                searchCustomer();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
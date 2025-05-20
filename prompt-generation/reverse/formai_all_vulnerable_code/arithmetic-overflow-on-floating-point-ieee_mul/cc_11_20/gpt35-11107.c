//FormAI DATASET v1.0 Category: Hotel Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hotel {
    char name[50];
    int room_number;
    char room_type[20];
    char guest_name[50];
    int nights;
    float rate;
    float total;
};
typedef struct hotel Hotel;

int main() {
    // Initialize variables
    Hotel hotel_record[100];
    int num_customers = 0;
    int choice;
    
    // Display menu and get user input
    do {
        printf("\n1. Add customer\n");
        printf("2. Display all customers\n");
        printf("3. Search customer by room number\n");
        printf("4. Search customers by guest name\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Perform selected action
        switch (choice) {
            case 1: // Add customer
                printf("\nAdd customer:\n");
                printf("Enter hotel name: ");
                scanf("%s", hotel_record[num_customers].name);
                printf("Enter room number: ");
                scanf("%d", &hotel_record[num_customers].room_number);
                printf("Enter room type: ");
                scanf("%s", hotel_record[num_customers].room_type);
                printf("Enter guest name: ");
                scanf("%s", hotel_record[num_customers].guest_name);
                printf("Enter number of nights: ");
                scanf("%d", &hotel_record[num_customers].nights);
                printf("Enter rate per night: ");
                scanf("%f", &hotel_record[num_customers].rate);
                hotel_record[num_customers].total = hotel_record[num_customers].nights * hotel_record[num_customers].rate;
                num_customers++;
                printf("Customer added successfully!\n");
                break;
                
            case 2: // Display all customers
                if (num_customers == 0) {
                    printf("No customers found.\n");
                } else {
                    printf("\nAll customers:\n");
                    printf("| %-15s | %-5s | %-10s | %-15s | %-6s | %-10s |\n",
                           "Hotel Name", "Room #", "Room Type", "Guest Name", "Nights", "Total");
                    for (int i = 0; i < num_customers; i++) {
                        printf("| %-15s | %-5d | %-10s | %-15s | %-6d | $%-9.2f |\n",
                               hotel_record[i].name, hotel_record[i].room_number, hotel_record[i].room_type,
                               hotel_record[i].guest_name, hotel_record[i].nights, hotel_record[i].total);
                    }
                }
                break;
                
            case 3: // Search customer by room number
                printf("\nSearch customer by room number:\n");
                int search_room_number;
                printf("Enter room number: ");
                scanf("%d", &search_room_number);
                for (int i = 0; i < num_customers; i++) {
                    if (hotel_record[i].room_number == search_room_number) {
                        printf("| %-15s | %-5d | %-10s | %-15s | %-6d | $%-9.2f |\n",
                               hotel_record[i].name, hotel_record[i].room_number, hotel_record[i].room_type,
                               hotel_record[i].guest_name, hotel_record[i].nights, hotel_record[i].total);
                        break;
                    }
                    if (i == num_customers - 1) {
                        printf("Customer not found.\n");
                    }
                }
                break;
                
            case 4: // Search customers by guest name
                printf("\nSearch customers by guest name:\n");
                char search_guest_name[50];
                printf("Enter guest name: ");
                scanf("%s", search_guest_name);
                int found = 0;
                printf("| %-15s | %-5s | %-10s | %-15s | %-6s | %-10s |\n",
                       "Hotel Name", "Room #", "Room Type", "Guest Name", "Nights", "Total");
                for (int i = 0; i < num_customers; i++) {
                    if (strcmp(hotel_record[i].guest_name, search_guest_name) == 0) {
                        printf("| %-15s | %-5d | %-10s | %-15s | %-6d | $%-9.2f |\n",
                               hotel_record[i].name, hotel_record[i].room_number, hotel_record[i].room_type,
                               hotel_record[i].guest_name, hotel_record[i].nights, hotel_record[i].total);
                        found = 1;
                    }
                }
                if (found == 0) {
                    printf("No customers found.\n");
                }
                break;
                
            case 5: // Exit program
                printf("\nExiting program...\n");
                break;
                
            default: // Invalid input
                printf("\nInvalid input.\n");
        }
    } while (choice != 5);
    
    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct hotel {
    char name[50];
    char address[50];
    int num_rooms;
    double price;
} hotel;

typedef struct guest {
    char name[50];
    char address[50];
    int num_nights;
    double total_cost;
} guest;

hotel hotels[] = {
    {"Hilton", "123 Main St", 100, 150.00},
    {"Marriott", "456 Elm St", 200, 200.00},
    {"Best Western", "789 Oak St", 150, 120.00}
};

guest guests[] = {
    {"John Smith", "123 Main St", 2, 300.00},
    {"Jane Doe", "456 Elm St", 3, 450.00},
    {"Bill Jones", "789 Oak St", 1, 120.00}
};

int main() {
    int choice;
    int i, j;

    printf("Welcome to the Hotel Management System!\n");

    do {
        printf("Please select an option:\n");
        printf("1. List hotels\n");
        printf("2. List guests\n");
        printf("3. Make a reservation\n");
        printf("4. Check out a guest\n");
        printf("5. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Hotels:\n");
                for (i = 0; i < 3; i++) {
                    printf("%s, %s, %d rooms, $%.2f per night\n",
                        hotels[i].name, hotels[i].address, hotels[i].num_rooms, hotels[i].price);
                }
                break;
            case 2:
                printf("Guests:\n");
                for (i = 0; i < 3; i++) {
                    printf("%s, %s, %d nights, $%.2f total cost\n",
                        guests[i].name, guests[i].address, guests[i].num_nights, guests[i].total_cost);
                }
                break;
            case 3:
                printf("Make a reservation:\n");
                printf("Enter your name: ");
                scanf("%s", guests[3].name);
                printf("Enter your address: ");
                scanf("%s", guests[3].address);
                printf("Enter the hotel you want to stay at: ");
                scanf("%s", guests[3].name);
                for (i = 0; i < 3; i++) {
                    if (strcmp(hotels[i].name, guests[3].name) == 0) {
                        printf("Enter the number of nights you want to stay: ");
                        scanf("%d", &guests[3].num_nights);
                        guests[3].total_cost = guests[3].num_nights * hotels[i].price;
                        printf("Your total cost is $%.2f.\n", guests[3].total_cost);
                    }
                }
                break;
            case 4:
                printf("Check out a guest:\n");
                printf("Enter your name: ");
                scanf("%s", guests[3].name);
                for (i = 0; i < 3; i++) {
                    if (strcmp(guests[i].name, guests[3].name) == 0) {
                        printf("Your total cost is $%.2f.\n", guests[i].total_cost);
                        for (j = i; j < 2; j++) {
                            guests[j] = guests[j+1];
                        }
                        break;
                    }
                }
                break;
            case 5:
                printf("Thank you for using the Hotel Management System!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
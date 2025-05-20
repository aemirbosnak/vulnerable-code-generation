//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *room_type;
    int days_stayed;
    float bill;
} guest;

int main() {
    printf("Welcome to the Hotel Happiness! Let's get you checked in.\n");

    // Create an array of guests
    guest guests[100];
    int num_guests = 0;

    // Get the guest's information
    while (1) {
        printf("Enter the guest's name: ");
        char name[100];
        scanf("%s", name);
        if (strcmp(name, "") == 0) {
            break;
        }

        printf("Enter the guest's age: ");
        int age;
        scanf("%d", &age);

        printf("Enter the guest's room type (single/double/suite): ");
        char room_type[100];
        scanf("%s", room_type);

        printf("Enter the number of days the guest will be staying: ");
        int days_stayed;
        scanf("%d", &days_stayed);

        // Calculate the guest's bill
        float bill = 0;
        if (strcmp(room_type, "single") == 0) {
            bill = days_stayed * 100;
        } else if (strcmp(room_type, "double") == 0) {
            bill = days_stayed * 150;
        } else if (strcmp(room_type, "suite") == 0) {
            bill = days_stayed * 200;
        }

        // Add the guest to the array
        guests[num_guests].name = strdup(name);
        guests[num_guests].age = age;
        guests[num_guests].room_type = strdup(room_type);
        guests[num_guests].days_stayed = days_stayed;
        guests[num_guests].bill = bill;
        num_guests++;
    }

    // Print the guest's information
    printf("\nHere is a list of the guests:\n");
    for (int i = 0; i < num_guests; i++) {
        printf("Guest %d:\n", i + 1);
        printf("Name: %s\n", guests[i].name);
        printf("Age: %d\n", guests[i].age);
        printf("Room type: %s\n", guests[i].room_type);
        printf("Days stayed: %d\n", guests[i].days_stayed);
        printf("Bill: $%.2f\n", guests[i].bill);
        printf("\n");
    }

    // Free the memory allocated for the guests' names and room types
    for (int i = 0; i < num_guests; i++) {
        free(guests[i].name);
        free(guests[i].room_type);
    }

    return 0;
}
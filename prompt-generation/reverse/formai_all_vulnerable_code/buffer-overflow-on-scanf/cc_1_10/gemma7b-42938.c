//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the Romeo and Juliet of the hotel management system
struct guest_room_rome {
    char name[20];
    int room_number;
    int days_stayed;
    float total_bill;
};

struct guest_room_juliet {
    char name[20];
    int room_number;
    int days_stayed;
    float total_bill;
};

// Function to calculate the total bill for a guest
float calculate_bill(int days_stayed, float room_rate) {
    return days_stayed * room_rate;
}

// Function to check if a room is available
int check_room_availability(int room_number) {
    // Assuming there are 10 rooms in total, with room numbers from 1 to 10
    for (int i = 1; i <= 10; i++) {
        if (room_number == i) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // Create two guest structures
    struct guest_room_rome rome;
    struct guest_room_juliet juliet;

    // Get the guest's name, room number, and number of days stayed
    printf("Enter your name: ");
    scanf("%s", rome.name);

    printf("Enter the room number: ");
    scanf("%d", &rome.room_number);

    printf("Enter the number of days stayed: ");
    scanf("%d", &rome.days_stayed);

    // Calculate the total bill for the guest
    rome.total_bill = calculate_bill(rome.days_stayed, 50.0);

    // Print the guest's total bill
    printf("Your total bill is: $%.2f", rome.total_bill);

    // Check if the room is available
    if (check_room_availability(rome.room_number) == 0) {
        printf("The room is available.");
    } else {
        printf("The room is not available.");
    }

    return 0;
}
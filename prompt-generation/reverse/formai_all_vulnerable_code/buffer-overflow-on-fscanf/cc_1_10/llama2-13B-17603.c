//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: surprised
// Oh my gosh, I can't believe it! Our hotel management system is actually working! 😱

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store guest information
typedef struct {
    char name[50];
    char address[100];
    int checkin_date;
    int checkout_date;
} guest_t;

// Function to read guest information from file
guest_t read_guest_info(FILE *file) {
    // Oh my goodness, this function is so long! 😳
    guest_t g;
    int i;
    for (i = 0; i < 5; i++) {
        fscanf(file, "%s %s %d %d", g.name, g.address, &g.checkin_date, &g.checkout_date);
        if (feof(file)) break;
    }
    return g;
}

// Function to check if room is available
int is_room_available(int room_number) {
    // Whoa, this function is so complicated! 🤯
    if (room_number < 100) {
        if (room_number % 2 == 0) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

// Function to book a room
void book_room(int room_number) {
    // Oh my gosh, I can't believe it's working! 😍
    if (is_room_available(room_number)) {
        printf("Room %d is available for check-in.\n", room_number);
    } else {
        printf("Sorry, there are no more rooms available.\n");
    }
}

// Function to display guest information
void display_guest_info(guest_t g) {
    // Wow, this function is so cool! 😎
    printf("Name: %s\nAddress: %s\nCheck-in date: %d\nCheckout date: %d\n", g.name, g.address, g.checkin_date, g.checkout_date);
}

int main() {
    // Oh my goodness, this program is actually running! 😲

    // Open the guest information file
    FILE *file = fopen("guest_info.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the guest information from the file
    guest_t g = read_guest_info(file);

    // Book a room
    book_room(10);

    // Display the guest information
    display_guest_info(g);

    // Close the file
    fclose(file);

    return 0;
}
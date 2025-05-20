//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room {
	int room_number;
	char room_type;
	int availability;
	float price;
};

struct guest {
	int guest_id;
	char guest_name[50];
	char guest_address[100];
	char guest_phone[20];
	char guest_email[50];
};

struct booking {
	int booking_id;
	int guest_id;
	int room_number;
	char check_in[11];
	char check_out[11];
};

// function to add a new room
void add_room(struct room *rooms, int *num_rooms) {
	// get room details from user
	printf("Enter room number: ");
	scanf("%d", &rooms[*num_rooms].room_number);
	printf("Enter room type (S/D/T): ");
	scanf(" %c", &rooms[*num_rooms].room_type);
	printf("Enter room availability (0/1): ");
	scanf("%d", &rooms[*num_rooms].availability);
	printf("Enter room price: ");
	scanf("%f", &rooms[*num_rooms].price);

	// increment the number of rooms
	(*num_rooms)++;
}

// function to add a new guest
void add_guest(struct guest *guests, int *num_guests) {
	// get guest details from user
	printf("Enter guest ID: ");
	scanf("%d", &guests[*num_guests].guest_id);
	printf("Enter guest name: ");
	scanf(" %[^\n]%*c", guests[*num_guests].guest_name);
	printf("Enter guest address: ");
	scanf(" %[^\n]%*c", guests[*num_guests].guest_address);
	printf("Enter guest phone: ");
	scanf(" %[^\n]%*c", guests[*num_guests].guest_phone);
	printf("Enter guest email: ");
	scanf(" %[^\n]%*c", guests[*num_guests].guest_email);

	// increment the number of guests
	(*num_guests)++;
}

// function to add a new booking
void add_booking(struct booking *bookings, int *num_bookings, struct room *rooms, int num_rooms, struct guest *guests, int num_guests) {
	// get booking details from user
	printf("Enter booking ID: ");
	scanf("%d", &bookings[*num_bookings].booking_id);
	printf("Enter guest ID: ");
	scanf("%d", &bookings[*num_bookings].guest_id);
	printf("Enter room number: ");
	scanf("%d", &bookings[*num_bookings].room_number);
	printf("Enter check-in date (YYYY-MM-DD): ");
	scanf(" %[^\n]%*c", bookings[*num_bookings].check_in);
	printf("Enter check-out date (YYYY-MM-DD): ");
	scanf(" %[^\n]%*c", bookings[*num_bookings].check_out);

	// check if the room is available
	int room_available = 0;
	for (int i = 0; i < num_rooms; i++) {
		if (rooms[i].room_number == bookings[*num_bookings].room_number && rooms[i].availability == 1) {
			room_available = 1;
			break;
		}
	}

	// check if the guest exists
	int guest_exists = 0;
	for (int i = 0; i < num_guests; i++) {
		if (guests[i].guest_id == bookings[*num_bookings].guest_id) {
			guest_exists = 1;
			break;
		}
	}

	// if the room is available and the guest exists, add the booking
	if (room_available && guest_exists) {
		(*num_bookings)++;
	} else {
		printf("Error: Room not available or guest does not exist.\n");
	}
}

// function to display all rooms
void display_rooms(struct room *rooms, int num_rooms) {
	printf("All rooms:\n");
	for (int i = 0; i < num_rooms; i++) {
		printf("Room number: %d, Room type: %c, Availability: %d, Price: %.2f\n", rooms[i].room_number, rooms[i].room_type, rooms[i].availability, rooms[i].price);
	}
}

// function to display all guests
void display_guests(struct guest *guests, int num_guests) {
	printf("All guests:\n");
	for (int i = 0; i < num_guests; i++) {
		printf("Guest ID: %d, Guest name: %s, Guest address: %s, Guest phone: %s, Guest email: %s\n", guests[i].guest_id, guests[i].guest_name, guests[i].guest_address, guests[i].guest_phone, guests[i].guest_email);
	}
}

// function to display all bookings
void display_bookings(struct booking *bookings, int num_bookings) {
	printf("All bookings:\n");
	for (int i = 0; i < num_bookings; i++) {
		printf("Booking ID: %d, Guest ID: %d, Room number: %d, Check-in date: %s, Check-out date: %s\n", bookings[i].booking_id, bookings[i].guest_id, bookings[i].room_number, bookings[i].check_in, bookings[i].check_out);
	}
}

// main function
int main() {
	// create an array of rooms
	struct room rooms[100];
	int num_rooms = 0;

	// create an array of guests
	struct guest guests[100];
	int num_guests = 0;

	// create an array of bookings
	struct booking bookings[100];
	int num_bookings = 0;

	// display the main menu
	int choice;
	do {
		printf("Hotel Management System\n");
		printf("1. Add a new room\n");
		printf("2. Add a new guest\n");
		printf("3. Add a new booking\n");
		printf("4. Display all rooms\n");
		printf("5. Display all guests\n");
		printf("6. Display all bookings\n");
		printf("7. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		// perform the selected action
		switch (choice) {
			case 1:
				add_room(rooms, &num_rooms);
				break;
			case 2:
				add_guest(guests, &num_guests);
				break;
			case 3:
				add_booking(bookings, &num_bookings, rooms, num_rooms, guests, num_guests);
				break;
			case 4:
				display_rooms(rooms, num_rooms);
				break;
			case 5:
				display_guests(guests, num_guests);
				break;
			case 6:
				display_bookings(bookings, num_bookings);
				break;
			case 7:
				printf("Exiting the program...\n");
				break;
			default:
				printf("Invalid choice. Please enter a number between 1 and 7.\n");
		}
	} while (choice != 7);

	return 0;
}
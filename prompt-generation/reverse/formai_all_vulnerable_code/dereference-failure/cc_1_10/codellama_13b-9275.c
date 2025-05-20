//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: Donald Knuth
/*
 * hotel.c
 *
 * A simple hotel management system example program in a Donald Knuth style.
 *
 * Author: [Your Name]
 * Date:   [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_ROOMS 10

// Struct to represent a customer
typedef struct {
    char name[50];
    int room_number;
    int age;
} customer_t;

// Struct to represent a room
typedef struct {
    int room_number;
    int capacity;
    int occupancy;
    customer_t *customers[MAX_CUSTOMERS];
} room_t;

// Function to allocate memory for a new customer
customer_t *allocate_customer(char *name, int age) {
    customer_t *new_customer = malloc(sizeof(customer_t));
    strcpy(new_customer->name, name);
    new_customer->age = age;
    return new_customer;
}

// Function to allocate memory for a new room
room_t *allocate_room(int room_number, int capacity) {
    room_t *new_room = malloc(sizeof(room_t));
    new_room->room_number = room_number;
    new_room->capacity = capacity;
    new_room->occupancy = 0;
    return new_room;
}

// Function to add a customer to a room
void add_customer_to_room(room_t *room, customer_t *customer) {
    if (room->occupancy < room->capacity) {
        room->customers[room->occupancy] = customer;
        room->occupancy++;
    } else {
        printf("Room is full!\n");
    }
}

// Function to remove a customer from a room
void remove_customer_from_room(room_t *room, customer_t *customer) {
    for (int i = 0; i < room->occupancy; i++) {
        if (room->customers[i] == customer) {
            room->customers[i] = NULL;
            room->occupancy--;
            break;
        }
    }
}

// Function to display the details of a customer
void display_customer(customer_t *customer) {
    printf("Name: %s\n", customer->name);
    printf("Age: %d\n", customer->age);
}

// Function to display the details of a room
void display_room(room_t *room) {
    printf("Room Number: %d\n", room->room_number);
    printf("Capacity: %d\n", room->capacity);
    printf("Occupancy: %d\n", room->occupancy);
    printf("Customers:\n");
    for (int i = 0; i < room->occupancy; i++) {
        display_customer(room->customers[i]);
    }
}

// Function to display the details of all rooms
void display_all_rooms(room_t *rooms[], int num_rooms) {
    for (int i = 0; i < num_rooms; i++) {
        display_room(rooms[i]);
    }
}

int main() {
    // Create an array of rooms
    room_t *rooms[MAX_ROOMS];

    // Allocate memory for each room
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i] = allocate_room(i + 1, 4);
    }

    // Create an array of customers
    customer_t *customers[MAX_CUSTOMERS];

    // Allocate memory for each customer
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        customers[i] = allocate_customer("Customer", i + 1);
    }

    // Add customers to rooms
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        add_customer_to_room(rooms[i % MAX_ROOMS], customers[i]);
    }

    // Remove customers from rooms
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        remove_customer_from_room(rooms[i % MAX_ROOMS], customers[i]);
    }

    // Display the details of all rooms
    display_all_rooms(rooms, MAX_ROOMS);

    // Free memory for each room
    for (int i = 0; i < MAX_ROOMS; i++) {
        free(rooms[i]);
    }

    // Free memory for each customer
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        free(customers[i]);
    }

    return 0;
}
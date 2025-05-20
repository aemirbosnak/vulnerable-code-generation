//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char room_no[10];
} Guest;

typedef struct {
    char name[50];
    char room_no[10];
} Room;

int main() {
    int num_guests = 0;
    int num_rooms = 0;
    
    printf("Welcome to the Hotel Management System!\n");
    
    // Prompt for number of guests
    printf("Enter the number of guests: ");
    scanf("%d", &num_guests);
    
    // Allocate memory for guest data
    Guest *guests = malloc(num_guests * sizeof(Guest));
    if (guests == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Prompt for guest information
    for (int i = 0; i < num_guests; i++) {
        printf("Guest %d:\n", i+1);
        
        // Prompt for name
        printf("Enter guest name: ");
        fgets(guests[i].name, sizeof(guests[i].name), stdin);
        
        // Prompt for age
        printf("Enter guest age: ");
        scanf("%d", &guests[i].age);
        
        // Prompt for room number
        printf("Enter guest room number: ");
        fgets(guests[i].room_no, sizeof(guests[i].room_no), stdin);
    }
    
    // Prompt for number of rooms
    printf("Enter the number of rooms: ");
    scanf("%d", &num_rooms);
    
    // Allocate memory for room data
    Room *rooms = malloc(num_rooms * sizeof(Room));
    if (rooms == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Prompt for room information
    for (int i = 0; i < num_rooms; i++) {
        printf("Room %d:\n", i+1);
        
        // Prompt for room number
        printf("Enter room number: ");
        fgets(rooms[i].room_no, sizeof(rooms[i].room_no), stdin);
    }
    
    // Display guest information
    printf("Guest Information:\n");
    for (int i = 0; i < num_guests; i++) {
        printf("%s, age %d, room %s\n", guests[i].name, guests[i].age, guests[i].room_no);
    }
    
    // Display room information
    printf("Room Information:\n");
    for (int i = 0; i < num_rooms; i++) {
        printf("%s\n", rooms[i].room_no);
    }
    
    // Free allocated memory
    free(guests);
    free(rooms);
    
    printf("Thank you for using the Hotel Management System!\n");
    return 0;
}
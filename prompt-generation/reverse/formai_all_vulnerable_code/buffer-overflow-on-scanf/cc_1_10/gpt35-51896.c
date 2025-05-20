//FormAI DATASET v1.0 Category: Hotel Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hotel {
    char name[30];
    int num_rooms;
    int num_available;
    float price;
    int rating;
};

void add_hotel(struct hotel *h, int size);
void display_hotels(struct hotel *h, int size);
void reserve_room(struct hotel *h, int size);
void menu();

int main()
{
    int choice;
    int size = 0;
    struct hotel *hotel_data = NULL;
    
    do {
        menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_hotel(hotel_data, size);
                size++;
                break;
            case 2:
                display_hotels(hotel_data, size);
                break;
            case 3:
                reserve_room(hotel_data, size);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void menu()
{
    printf("Welcome to the Hotel Management System!\n");
    printf("Please select an option:\n");
    printf("1. Add a hotel\n");
    printf("2. Display hotels\n");
    printf("3. Reserve a room\n");
    printf("4. Exit\n");
}

void add_hotel(struct hotel *h, int size)
{
    if (size == 0) {
        h = (struct hotel*)malloc(sizeof(struct hotel));
    } else {
        h = (struct hotel*)realloc(h, size * sizeof(struct hotel));
    }
    
    printf("Enter hotel name: ");
    scanf("%s", h[size].name);
    
    printf("Enter number of rooms: ");
    scanf("%d", &h[size].num_rooms);
    
    printf("Enter number of available rooms: ");
    scanf("%d", &h[size].num_available);
    
    printf("Enter price per night: ");
    scanf("%f", &h[size].price);
    
    printf("Enter hotel rating (1-5): ");
    scanf("%d", &h[size].rating);
    
    printf("Hotel added successfully!\n");
}

void display_hotels(struct hotel *h, int size)
{
    if (size == 0) {
        printf("No hotels found.\n");
    } else {
        printf("Hotels:\n");
        for (int i = 0; i < size; i++) {
            printf("%d. %s\n", i+1, h[i].name);
            printf("   Number of rooms: %d\n", h[i].num_rooms);
            printf("   Number of available rooms: %d\n", h[i].num_available);
            printf("   Price per night: $%.2f\n", h[i].price);
            printf("   Rating: %d/5\n", h[i].rating);
        }
    }
}

void reserve_room(struct hotel *h, int size)
{
    char name[30];
    int room_num;
    int found = 0;
    
    if (size == 0) {
        printf("No hotels found.\n");
    } else {
        printf("Enter hotel name: ");
        scanf("%s", name);
        
        for (int i = 0; i < size; i++) {
            if (strcmp(h[i].name, name) == 0) {
                found = 1;
                printf("Enter room number: ");
                scanf("%d", &room_num);
                if (h[i].num_available >= 1) {
                    printf("Room %d reserved at %s for $%.2f per night.\n", room_num, h[i].name, h[i].price);
                    h[i].num_available--;
                } else {
                    printf("No rooms available at %s.\n", h[i].name);
                }
                break;
            }
        }
        
        if (found == 0) {
            printf("Hotel not found.\n");
        }
    }
}
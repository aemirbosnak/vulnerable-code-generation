//FormAI DATASET v1.0 Category: Hotel Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct to hold the hotel information
struct hotel {
    char name[20];
    int available_rooms;
    float price_per_room;
};

typedef struct hotel Hotel;

int main() {
    int choice, num_of_hotels;
    char search_name[20];
    int search_available_rooms;
    float search_price_per_room;
    
    printf("Welcome to C Hotel Management System\n");
    printf("\nEnter the number of hotels: ");
    scanf("%d", &num_of_hotels);
    
    //Creating an array of hotels with user input
    Hotel hotels[num_of_hotels];
    for (int i = 0; i < num_of_hotels; i++) {
        printf("\nEnter the name of hotel %d: ", i+1);
        getchar();
        fgets(hotels[i].name, 20, stdin);
        printf("Enter the number of available rooms: ");
        scanf("%d", &hotels[i].available_rooms);
        printf("Enter the price per room: ");
        scanf("%f", &hotels[i].price_per_room);
    }
    
    do {
        printf("\nHotel Management Options:\n");
        printf("1. Search a Hotel by Name\n");
        printf("2. Search a Hotel by Number of Available Rooms\n");
        printf("3. Search a Hotel by Price per Room\n");
        printf("4. Exit\n");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);
    
        switch(choice) {
            case 1:
                //Search hotel by name
                printf("\nEnter the name of hotel to search: ");
                getchar();
                fgets(search_name, 20, stdin);
                for (int i = 0; i < num_of_hotels; i++) {
                    if (strcmp(search_name, hotels[i].name) == 0) {
                        printf("\n Hotel Details");
                        printf("\nName: %s", hotels[i].name);
                        printf("Available Rooms: %d", hotels[i].available_rooms);
                        printf("Price per Room: %.2f\n", hotels[i].price_per_room);
                        break;
                    }
                    if (i == num_of_hotels-1) {
                        printf("\nHotel not found!\n");
                    }
                }
                break;
            case 2:
                //Search hotel by number of available rooms
                printf("\nEnter the number of available rooms to search: ");
                scanf("%d", &search_available_rooms);
                for (int i = 0; i < num_of_hotels; i++) {
                    if (search_available_rooms == hotels[i].available_rooms) {
                        printf("\n Hotel Details");
                        printf("\nName: %s", hotels[i].name);
                        printf("Available Rooms: %d", hotels[i].available_rooms);
                        printf("Price per Room: %.2f\n", hotels[i].price_per_room);
                        break;
                    }
                    if (i == num_of_hotels-1) {
                        printf("\nHotel not found!\n");
                    }
                }
                break;
            case 3:
                //Search hotel by price per room
                printf("\nEnter the price per room to search: ");
                scanf("%f", &search_price_per_room);
                for (int i = 0; i < num_of_hotels; i++) {
                    if (search_price_per_room == hotels[i].price_per_room) {
                        printf("\n Hotel Details");
                        printf("\nName: %s", hotels[i].name);
                        printf("Available Rooms: %d", hotels[i].available_rooms);
                        printf("Price per Room: %.2f\n", hotels[i].price_per_room);
                        break;
                    }
                    if (i == num_of_hotels-1) {
                        printf("\nHotel not found!\n");
                    }
                }
                break;
            case 4:
                //Exiting the program
                printf("\nExiting Hotel Management System. Goodbye!");
                exit(0);
            default:
                printf("\nInvalid Input! Please try again.");
        }
    } while(1);
    
    return 0;
}
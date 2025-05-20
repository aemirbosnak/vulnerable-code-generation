//FormAI DATASET v1.0 Category: Hotel Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hotel {
    char name[20];
    char city[20];
    int rating;
    float price;
};

struct reservation {
    char hotel_name[20];
    int num_of_rooms;
    int num_of_nights;
    float total_cost;
};

void print_menu() {
    printf("\nPlease select an option:\n");
    printf("1. List hotels\n");
    printf("2. Search hotels\n");
    printf("3. Reserve a hotel\n");
    printf("4. List reservations\n");
    printf("5. Exit\n\n");
}

void list_hotels(struct hotel *hotels, int num_hotels) {
    printf("\nHotels:\n\n");
    for (int i = 0; i < num_hotels; i++) {
        printf("%d. %s\n", i+1, hotels[i].name);
        printf("   City: %s\n", hotels[i].city);
        printf("   Rating: %d stars\n", hotels[i].rating);
        printf("   Price per night: $%.2f\n\n", hotels[i].price);
    }
}

void search_hotels(struct hotel *hotels, int num_hotels, char *city) {
    printf("\nHotels in %s:\n\n", city);
    int num_results = 0;
    for (int i = 0; i < num_hotels; i++) {
        if (strcmp(hotels[i].city, city) == 0) {
            printf("%d. %s\n", num_results+1, hotels[i].name);
            printf("   Rating: %d stars\n", hotels[i].rating);
            printf("   Price per night: $%.2f\n\n", hotels[i].price);
            num_results++;
        }
    }
    if (num_results == 0) {
        printf("No hotels found in %s.\n\n", city);
    }
}

void reserve_hotel(struct hotel *hotels, int num_hotels, struct reservation *reservations, int *num_reservations) {
    printf("\nPlease enter a hotel name: ");
    char input_name[20];
    scanf("%s", input_name);
    int hotel_index = -1;
    for (int i = 0; i < num_hotels; i++) {
        if (strcmp(hotels[i].name, input_name) == 0) {
            hotel_index = i;
            break;
        }
    }
    if (hotel_index == -1) {
        printf("Hotel not found.\n\n");
        return;
    }
    printf("Please enter the number of rooms: ");
    int num_of_rooms;
    scanf("%d", &num_of_rooms);
    printf("Please enter the number of nights: ");
    int num_of_nights;
    scanf("%d", &num_of_nights);
    float cost = num_of_rooms * num_of_nights * hotels[hotel_index].price;
    reservations[*num_reservations].num_of_rooms = num_of_rooms;
    reservations[*num_reservations].num_of_nights = num_of_nights;
    reservations[*num_reservations].total_cost = cost;
    strcpy(reservations[*num_reservations].hotel_name, input_name);
    (*num_reservations)++;
    printf("\nReservation made for %d rooms at %s for %d nights.\n", num_of_rooms, input_name, num_of_nights);
    printf("Total cost: $%.2f\n\n", cost);
}

void list_reservations(struct reservation *reservations, int num_reservations) {
    printf("\nReservations:\n\n");
    for (int i = 0; i < num_reservations; i++) {
        printf("%d. %s\n", i+1, reservations[i].hotel_name);
        printf("   Number of rooms: %d\n", reservations[i].num_of_rooms);
        printf("   Number of nights: %d\n", reservations[i].num_of_nights);
        printf("   Total cost: $%.2f\n\n", reservations[i].total_cost);
    }
}

int main() {
    struct hotel hotels[3] = {
        {"Hilton", "New York City", 5, 200.00},
        {"Marriott", "Los Angeles", 4, 150.00},
        {"Holiday Inn", "Chicago", 3, 100.00}
    };
    struct reservation reservations[10];
    int num_reservations = 0;
    int num_hotels = 3;
    int choice = 0;
    printf("Welcome to the hotel management system!\n");
    while (choice != 5) {
        print_menu();
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                list_hotels(hotels, num_hotels);
                break;
            case 2:
                printf("\nPlease enter a city: ");
                char input_city[20];
                scanf("%s", input_city);
                search_hotels(hotels, num_hotels, input_city);
                break;
            case 3:
                reserve_hotel(hotels, num_hotels, reservations, &num_reservations);
                break;
            case 4:
                list_reservations(reservations, num_reservations);
                break;
            case 5:
                printf("\nThank you for using the hotel management system!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }
    return 0;
}
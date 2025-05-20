//FormAI DATASET v1.0 Category: Hotel Management System ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Hotel {
    char name[50];
    int roomNumber;
    float price;
};

void displayMenu();
int selectOption();
void addHotel(struct Hotel *list, int *count);
void displayHotels(struct Hotel *list, int count);
void searchHotels(struct Hotel *list, int count);

int main() {
    struct Hotel list[100];
    int count = 0;

    while(1) {
        displayMenu();
        int option = selectOption();

        switch(option) {
            case 1: addHotel(list, &count); break;
            case 2: displayHotels(list, count); break;
            case 3: searchHotels(list, count); break;
            case 4: printf("Thank you for using our Hotel Management System! Goodbye!\n"); exit(0);
            default: printf("Invalid option. Please try again.\n"); break;
        }
    }
}

void displayMenu() {
    printf("\nWELCOME TO HOSPITALITY INN HOTEL!\n");
    printf("1. Add a new hotel\n");
    printf("2. Display all hotels\n");
    printf("3. Search hotel by room number\n");
    printf("4. Exit\n");
    printf("Please select an option: ");
}

int selectOption() {
    int option;
    scanf("%d", &option);
    return option;
}

void addHotel(struct Hotel *list, int *count) {
    printf("\nENTER HOTEL DETAILS:\n");
    printf("Name: ");
    scanf("%s", list[*count].name);
    printf("Room number: ");
    scanf("%d", &list[*count].roomNumber);
    printf("Price per night: ");
    scanf("%f", &list[*count].price);

    (*count)++;
    printf("Hotel added successfully!\n");
}

void displayHotels(struct Hotel *list, int count) {
    if(count == 0) {
        printf("\nNo hotels to display.\n");
        return;
    }

    printf("\nHOTEL LIST:\n");
    for(int i=0; i<count; i++) {
        printf("Hotel name: %s\n", list[i].name);
        printf("Room number: %d\n", list[i].roomNumber);
        printf("Price per night: $%.2f\n", list[i].price);
        printf("\n");
    }
}

void searchHotels(struct Hotel *list, int count) {
    int room;

    if(count == 0) {
        printf("\nNo hotels to search.\n");
        return;
    }

    printf("\nEnter the room number you want to search: ");
    scanf("%d", &room);
    
    for(int i=0; i<count; i++) {
        if(list[i].roomNumber == room) {
            printf("\nHOTEL FOUND:\n");
            printf("Name: %s\n", list[i].name);
            printf("Room number: %d\n", list[i].roomNumber);
            printf("Price per night: $%.2f\n", list[i].price);
            return;
        }
    }

    printf("\nNo hotel found with room number %d.\n", room);
}
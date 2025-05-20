//FormAI DATASET v1.0 Category: Hotel Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to define hotels
struct hotel {
    char name[100];
    char address[100];
    int rating;
};

// function to print available hotels
void printHotels(struct hotel h[], int n) {
    printf("\nAvailable hotels:\n");
    printf("-----------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i+1, h[i].name);
        printf("\tAddress: %s\n", h[i].address);
        printf("\tRating: %d\n", h[i].rating);
    }
}

// function to add a new hotel
void addHotel(struct hotel h[], int n) {
    printf("\nEnter details of the new hotel:\n");
    printf("Name: ");
    scanf(" %[^\n]s", h[n].name);
    printf("Address: ");
    scanf(" %[^\n]s", h[n].address);
    printf("Rating: ");
    scanf("%d", &h[n].rating);
    printf("\nNew hotel added successfully!\n");
}

// function to delete a hotel by name
void deleteHotel(struct hotel h[], int n) {
    char name[100];
    printf("\nEnter the name of the hotel to be deleted: ");
    scanf(" %[^\n]s", name);
    int del_index = -1;
    for (int i = 0; i < n; i++) {
        if (strcmp(name, h[i].name) == 0) {
            del_index = i;
            break;
        }
    }
    if (del_index == -1) {
        printf("\nHotel not found!\n");
    } else {
        for (int i = del_index; i < n-1; i++) {
            h[i] = h[i+1];
        }
        printf("\nHotel deleted successfully!\n");
    }   
}

// function to update hotel details by name
void updateHotel(struct hotel h[], int n) {
    char name[100];
    printf("\nEnter the name of the hotel to be updated: ");
    scanf(" %[^\n]s", name);
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (strcmp(name, h[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nHotel not found!\n");
    } else {
        printf("\nEnter updated details of the hotel:\n");
        printf("Name: ");
        scanf(" %[^\n]s", h[index].name);
        printf("Address: ");
        scanf(" %[^\n]s", h[index].address);
        printf("Rating: ");
        scanf("%d", &h[index].rating);
        printf("\nHotel details updated successfully!\n");
    }
}

int main() {
    int n, choice;
    printf("How many hotels do you want to add? ");
    scanf("%d", &n);
    struct hotel h[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of hotel %d:\n", i+1);
        printf("Name: ");
        scanf(" %[^\n]s", h[i].name);
        printf("Address: ");
        scanf(" %[^\n]s", h[i].address);
        printf("Rating: ");
        scanf("%d", &h[i].rating);
    }
    do {
        // menu display
        printf("\n\nHotel Management System\n");
        printf("-----------------------\n");
        printf("1. Print available hotels\n");
        printf("2. Add a new hotel\n");
        printf("3. Delete a hotel\n");
        printf("4. Update hotel details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printHotels(h, n);
                break;
            case 2:
                // add new hotel
                addHotel(h, n);
                n++;
                break;
            case 3:
                // delete hotel
                deleteHotel(h, n);
                if (n > 0) {
                    n--;
                }
                break;
            case 4:
                // update hotel details
                updateHotel(h, n);
                break;
            case 5:
                // exit
                printf("\nExiting program... Thank you!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
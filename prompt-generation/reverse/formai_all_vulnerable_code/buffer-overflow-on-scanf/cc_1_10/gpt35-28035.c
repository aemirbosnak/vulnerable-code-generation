//FormAI DATASET v1.0 Category: Hotel Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing information of a guest
struct Guest {
    char name[50];
    int age;
    char gender[10];
    char mobile[20];
};

// Array of all the guests in the hotel
struct Guest guests[100];
int num_of_guests = 0;

// Function to add a new guest
void add_guest() {
    struct Guest new_guest;
    printf("Enter guest name: ");
    scanf("%s", new_guest.name);
    printf("Enter guest age: ");
    scanf("%d", &new_guest.age);
    printf("Enter guest gender: ");
    scanf("%s", new_guest.gender);
    printf("Enter guest mobile number: ");
    scanf("%s", new_guest.mobile);

    guests[num_of_guests] = new_guest;
    num_of_guests++;
    printf("Guest %d added successfully!\n", num_of_guests);
}

// Function to search for a guest by name
void search_guest() {
    char name_to_search[50];
    printf("Enter guest name to search: ");
    scanf("%s", name_to_search);

    int found = 0;
    for(int i=0; i<num_of_guests; i++) {
        if(strcmp(guests[i].name, name_to_search) == 0) {
            printf("Guest %s found at index %d:\n", guests[i].name, i);
            printf("\tAge: %d\n", guests[i].age);
            printf("\tGender: %s\n", guests[i].gender);
            printf("\tMobile: %s\n", guests[i].mobile);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Guest not found!\n");
    }
}

// Function to display all guests
void display_guests() {
    if(num_of_guests == 0) {
        printf("No guests added yet!\n");
    }
    for(int i=0; i<num_of_guests; i++) {
        printf("Guest %d:\n", i+1);
        printf("\tName: %s\n", guests[i].name);
        printf("\tAge: %d\n", guests[i].age);
        printf("\tGender: %s\n", guests[i].gender);
        printf("\tMobile: %s\n", guests[i].mobile);
    }
}

// Main function
int main() {
    int choice = 0;
    while(choice != 4) {
        printf("\n\nMENU\n");
        printf("1. Add Guest\n");
        printf("2. Search Guest\n");
        printf("3. Display All Guests\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_guest();
                break;
            case 2:
                search_guest();
                break;
            case 3:
                display_guests();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
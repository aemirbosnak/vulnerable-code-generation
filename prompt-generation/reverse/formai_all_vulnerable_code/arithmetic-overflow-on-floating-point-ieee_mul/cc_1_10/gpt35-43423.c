//FormAI DATASET v1.0 Category: Hotel Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int room_number;
    float room_rate;
    int num_of_nights;
    float total_bill;
} guest;

guest hotel[50];
int count = 0;

void add_guest() {
    printf("\nEnter guest name: ");
    scanf("%s", hotel[count].name);
    printf("Enter room number: ");
    scanf("%d", &hotel[count].room_number);
    printf("Enter room rate: ");
    scanf("%f", &hotel[count].room_rate);
    printf("Enter number of nights: ");
    scanf("%d", &hotel[count].num_of_nights);
    
    hotel[count].total_bill = hotel[count].room_rate * hotel[count].num_of_nights;
    
    printf("\n%s has successfully checked-in to Room %d for %d nights.", hotel[count].name, hotel[count].room_number, hotel[count].num_of_nights);
    printf("\n%s's total bill is %.2f.\n", hotel[count].name, hotel[count].total_bill);
    
    count++;
}

void view_guests() {
    if (count == 0) {
        printf("\nNo guests currently checked-in.\n");
    }
    else {
        printf("\nGuests currently checked-in:\n");
        for (int i = 0; i < count; i++) {
            printf("\nGuest name: %s", hotel[i].name);
            printf("\tRoom number: %d", hotel[i].room_number);
            printf("\tTotal bill: %.2f\n", hotel[i].total_bill);
        }
    }
}

void checkout_guest() {
    char name[50];
    int found = 0;
    printf("\nEnter guest name to check-out: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(hotel[i].name, name) == 0) {
            printf("\n%s has successfully checked-out of Room %d after %d nights.", hotel[i].name, hotel[i].room_number, hotel[i].num_of_nights);
            printf("\n%s's total bill is %.2f.", hotel[i].name, hotel[i].total_bill);
            
            for (int j = i; j < count; j++) {
                hotel[j] = hotel[j+1];
            }
            count--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nThe guest name you entered is not checked-in.\n");
    }
}

int main() {
    int choice;
    printf("Welcome to C Hotel Management System!\n\n");
    printf("Please select an option:\n");
    while (1) {
        printf("\n1. Check-in guest\n");
        printf("2. View guests\n");
        printf("3. Check-out guest\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_guest();
                break;
            case 2:
                view_guests();
                break;
            case 3:
                checkout_guest();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice. Please choose again.\n");
        }
    }
    return 0;
}
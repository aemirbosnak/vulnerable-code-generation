//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct guest {
    char name[20];
    int room_no;
    int num_of_days;
    int total_bill;
};

int main() {
    printf("Welcome to The Sherlock Hotel Management System\n");
    printf("Please enter the number of guests staying: ");
    int num_of_guests;
    scanf("%d", &num_of_guests);

    struct guest guests[num_of_guests];
    int i, j, temp;

    // Getting guest details
    for(i = 0; i < num_of_guests; i++) {
        printf("\nPlease enter the name of guest %d: ", i + 1);
        scanf("%s", guests[i].name);
        printf("Please enter the room number of guest %d: ", i + 1);
        scanf("%d", &guests[i].room_no);
        printf("Please enter the number of days guest %d will be staying: ", i + 1);
        scanf("%d", &guests[i].num_of_days);
    }

    // Calculating total bill for each guest
    for(i = 0; i < num_of_guests; i++) {
        guests[i].total_bill = guests[i].num_of_days * 100;
    }

    // Sorting guests based on total bill
    for(i = 0; i < num_of_guests - 1; i++) {
        for(j = 0; j < num_of_guests - i - 1; j++) {
            if(guests[j].total_bill < guests[j + 1].total_bill) {
                temp = guests[j].total_bill;
                guests[j].total_bill = guests[j + 1].total_bill;
                guests[j + 1].total_bill = temp;
            }
        }
    }

    printf("\nHotel management system\n\n");
    printf("Name             Room Number       Days Staying       Total Bill\n");
      
    // Displaying guest details
    for(i = 0; i < num_of_guests; i++) {
        printf("%-18s %-18d %-18d $%-18d\n", guests[i].name, guests[i].room_no, guests[i].num_of_days, guests[i].total_bill);
    }

    return 0;
}
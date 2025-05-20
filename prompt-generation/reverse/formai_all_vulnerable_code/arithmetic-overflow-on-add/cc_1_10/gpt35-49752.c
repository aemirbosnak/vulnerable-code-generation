//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

struct guest {
    char name[20];
    int roomNum;
    int numNights;
    float costPerNight;
};

int main() {

    int numGuests, choice, i;
    float totalCost;
    struct guest guests[100];

    printf("Welcome to our hotel management system!\n");

    while(1) {

        printf("\nWhat would you like to do?\n");
        printf("1. Add a new guest\n");
        printf("2. View all guests\n");
        printf("3. Calculate total revenue\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("\nEnter guest name: ");
                scanf("%s", guests[numGuests].name);
                printf("Enter room number: ");
                scanf("%d", &guests[numGuests].roomNum);
                printf("Enter number of nights: ");
                scanf("%d", &guests[numGuests].numNights);
                printf("Enter cost per night: ");
                scanf("%f", &guests[numGuests].costPerNight);
                printf("Guest added successfully!\n");
                numGuests++;
                break;

            case 2:
                printf("\nGuest List\n");
                printf("===========\n");
                for(i=0; i<numGuests; i++) {
                    printf("%s\t%d\t%d\t$%.2f\n", guests[i].name, guests[i].roomNum, guests[i].numNights, guests[i].costPerNight);
                }
                printf("\n");
                break;

            case 3:
                totalCost = 0;
                for(i=0; i<numGuests; i++) {
                    totalCost += guests[i].numNights * guests[i].costPerNight;
                }
                printf("\nTotal Revenue: $%.2f\n", totalCost);
                break;

            case 4:
                printf("\nThank you for using our hotel management system!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}
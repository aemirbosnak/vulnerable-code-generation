//FormAI DATASET v1.0 Category: Hotel Management System ; Style: minimalist
#include <stdio.h>
#include <string.h>

typedef struct{
    char name[30];
    char address[50];
    int roomNum;
    int noOfDays;
    float roomPrice;
    float totalBill;
}guest;

int main(){
    int choice, guestCount = 0;
    guest guests[20];
    
    printf("Welcome to C Hotel Management System.\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add guest\n");
        printf("2. View all guests\n");
        printf("3. Calculate bill\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("\nEnter guest name: ");
                scanf("%s", guests[guestCount].name);
                printf("Enter guest address: ");
                scanf("%s", guests[guestCount].address);
                printf("Enter guest room number: ");
                scanf("%d", &guests[guestCount].roomNum);
                printf("Enter number of days: ");
                scanf("%d", &guests[guestCount].noOfDays);
                printf("Enter room price per day: ");
                scanf("%f", &guests[guestCount].roomPrice);
                printf("Guest added successfully!\n");
                guestCount++;
                break;
            case 2:
                if(guestCount == 0){
                    printf("\nNo guests added yet.\n");
                } else {
                    printf("\nGuest Details:\n\n");
                    for(int i=0; i<guestCount; i++){
                        printf("Guest %d:\n", i+1);
                        printf("Name: %s\n", guests[i].name);
                        printf("Address: %s\n", guests[i].address);
                        printf("Room number: %d\n", guests[i].roomNum);
                        printf("Number of days: %d\n", guests[i].noOfDays);
                        printf("Room price per day: %.2f\n\n", guests[i].roomPrice);
                    }
                }
                break;
            case 3:
                if(guestCount == 0){
                    printf("\nNo guests added yet.\n");
                } else {
                    for(int i=0; i<guestCount; i++){
                        guests[i].totalBill = guests[i].roomPrice * guests[i].noOfDays;
                        printf("Guest %d's Total bill is: $%.2f\n", i+1, guests[i].totalBill);
                    }
                }
                break;
            case 4:
                printf("\nThank you for using C Hotel Management System.\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
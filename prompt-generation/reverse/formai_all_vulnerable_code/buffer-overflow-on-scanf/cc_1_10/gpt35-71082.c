//FormAI DATASET v1.0 Category: Hotel Management System ; Style: lively
#include<stdio.h>

struct guest {
    char name[100];
    int roomNumber;
    char checkIn[25];
    char checkOut[25];
    int numberOfPeople;
    int totalPrice;
} guests[50];

int main() {
    int n, i;
    printf("\n Welcome to C Hotel Management System! \n");
    printf("\n Please enter the number of guests checking in today: ");
    scanf("%d", &n);
    printf("\n");
    
    // Taking input for guest details
    for(i=0; i<n; i++){
        printf("Enter guest name: ");
        scanf("%s", &guests[i].name);
        
        printf("Enter room number: ");
        scanf("%d", &guests[i].roomNumber);
        
        printf("Enter check-in date and time (dd-mm-yyyy HH:MM): ");
        scanf("%s", &guests[i].checkIn);
        
        printf("Enter check-out date and time (dd-mm-yyyy HH:MM): ");
        scanf("%s", &guests[i].checkOut);
        
        printf("Enter number of people staying: ");
        scanf("%d", &guests[i].numberOfPeople);
        
        printf("Enter total price: ");
        scanf("%d", &guests[i].totalPrice);
        
        printf("\n");
    }
    
    // Displaying guest details
    printf("\n\n************** GUEST DETAILS **************\n");
    for(i=0; i<n; i++){
        printf("\n Guest %d", i+1);
        printf("\n Name: %s", guests[i].name);
        printf("\n Room Number: %d", guests[i].roomNumber);
        printf("\n Check-in date and time: %s", guests[i].checkIn);
        printf("\n Check-out date and time: %s", guests[i].checkOut);
        printf("\n Number of people staying: %d", guests[i].numberOfPeople);
        printf("\n Total price: %d", guests[i].totalPrice);
        printf("\n\n");
    }
    
    return 0;
}
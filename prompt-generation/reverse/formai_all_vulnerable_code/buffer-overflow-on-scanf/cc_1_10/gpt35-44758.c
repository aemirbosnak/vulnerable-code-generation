//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure of the hotel
struct Hotel {
    char name[50];
    int roomNo;
    float price;
    int status;
};

//Function prototypes
void addRooms(struct Hotel *h);
void displayRooms(struct Hotel *h, int count);
void bookRoom(struct Hotel *h, int count);
void checkout(struct Hotel *h, int count);
float calculateTotal(int duration, float price);

//Main function
int main() {
    int choice, count=0;
    struct Hotel h[50]; //Creating an array of hotel rooms
    
    do {
        printf("\nWelcome to the Hotel Management System\n");
        printf("1. Add Rooms\n");
        printf("2. Display Rooms\n");
        printf("3. Book Room\n");
        printf("4. Checkout\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addRooms(h);
                count++;
                break;
            case 2:
                displayRooms(h, count);
                break;
            case 3:
                bookRoom(h, count);
                break;
            case 4:
                checkout(h, count);
                break;
            case 5:
                printf("\nThank you for using Hotel Management System!");
                exit(0);
            default:
                printf("Invalid choice!");
        }
        
    } while(choice!=5);
    
    return 0;
}

//Function to add rooms to the hotel
void addRooms(struct Hotel *h) {
    printf("\nEnter the details of the room\n");
    printf("Name: ");
    scanf("%s", h->name);
    printf("Room No: ");
    scanf("%d", &h->roomNo);
    printf("Price: ");
    scanf("%f", &h->price);
    h->status = 0;
}

//Function to display all the rooms in the hotel
void displayRooms(struct Hotel *h, int count) {
    if(count==0) {
        printf("\nNo rooms added!\n");
    } else {
        printf("\n%-15s%-15s%-15s%-15s\n", "Room No", "Name", "Price", "Status");
        for(int i=0;i<count;i++) {
            printf("%-15d", (h+i)->roomNo);
            printf("%-15s", (h+i)->name);
            printf("%-15.2f", (h+i)->price);
            if((h+i)->status==0) {
                printf("%-15s\n", "Vacant");
            } else {
                printf("%-15s\n", "Occupied");
            }
        }
    }
}

//Function to book a room
void bookRoom(struct Hotel *h, int count) {
    int roomNo, found=0;
    for(int i=0;i<count;i++) {
        if((h+i)->status==0) {
            printf("\nRoom No: %d is vacant\n", (h+i)->roomNo);
            found=1;
        }
    }
    if(found==0) {
        printf("Sorry! No rooms available at the moment\n");
        return;
    }
    printf("Enter the Room No you want to book: ");
    scanf("%d", &roomNo);
    for(int i=0;i<count;i++) {
        if((h+i)->roomNo==roomNo) {
            if((h+i)->status==0) {
                printf("\nEnter the duration of stay (in days): ");
                int duration;
                scanf("%d", &duration);
                float totalPrice = calculateTotal(duration, (h+i)->price);
                printf("\nTotal Price for Room No: %d is %.2f", roomNo, totalPrice);
                (h+i)->status = 1;
                return;
            } else {
                printf("\nSorry! Room No: %d is already occupied\n", roomNo);
                return;
            }
        }
    }
    printf("Room No %d not found\n", roomNo);
}

//Function to calculate the total price for a given duration
float calculateTotal(int duration, float price) {
    return duration*price;
}

//Function to checkout of a room
void checkout(struct Hotel *h, int count) {
    int roomNo, found=0;
    for(int i=0;i<count;i++) {
        if((h+i)->status==1) {
            printf("\nRoom No: %d is occupied\n", (h+i)->roomNo);
            found=1;
        }
    }
    if(found==0) {
        printf("Sorry! No rooms occupied at the moment\n");
        return;
    }
    printf("Enter the Room No to checkout: ");
    scanf("%d", &roomNo);
    for(int i=0;i<count;i++) {
        if((h+i)->roomNo==roomNo) {
            if((h+i)->status==1) {
                printf("\nCheckout successful\n");
                (h+i)->status = 0;
                return;
            } else {
                printf("\nRoom No: %d is not occupied\n", roomNo);
                return;
            }
        }
    }
    printf("Room No %d not found\n", roomNo);
}
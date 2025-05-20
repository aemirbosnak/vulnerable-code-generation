//FormAI DATASET v1.0 Category: Hotel Management System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

//Hotel structure
struct hotel{
    char room[5];
    char name[20];
    char checkin[12];
    char checkout[12];
};

//Function to add a new guest
void addGuest(struct hotel *h){
    int i;
    for(i=0;i<SIZE;i++){
        if(strcmp((h+i)->room, "") == 0){   //If room is empty
            printf("Enter room number: ");
            scanf("%s", (h+i)->room);
            printf("Enter guest name: ");
            scanf("%s", (h+i)->name);
            printf("Enter check-in date (dd/mm/yyyy): ");
            scanf("%s", (h+i)->checkin);
            printf("Enter check-out date (dd/mm/yyyy): ");
            scanf("%s", (h+i)->checkout);
            printf("Guest added successfully!\n");
            break;
        }
    }
    if(i==SIZE){
        printf("Sorry! The hotel is full.\n");
    }
}

//Function to display all guests
void displayAll(struct hotel *h){
    int i;
    printf("\nRoom  Guest             Check-in    Check-out\n");
    printf("------------------------------------------------\n");
    for(i=0;i<SIZE;i++){
        if(strcmp((h+i)->room, "") != 0){   //If room is not empty
            printf("%-6s%-18s%-12s%-12s\n", (h+i)->room, (h+i)->name, (h+i)->checkin, (h+i)->checkout);
        }
    }
}

//Function to search for a guest by name
void searchGuest(struct hotel *h){
    char name[20];
    int i, flag=0;
    printf("\nEnter guest name: ");
    scanf("%s", name);
    for(i=0;i<SIZE;i++){
        if(strcmp((h+i)->name, name) == 0){   //If guest name matches
            printf("\nRoom  Guest             Check-in    Check-out\n");
            printf("------------------------------------------------\n");
            printf("%-6s%-18s%-12s%-12s\n", (h+i)->room, (h+i)->name, (h+i)->checkin, (h+i)->checkout);
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("Guest not found!\n");
    }
}

//Function to delete a guest by room number
void deleteGuest(struct hotel *h){
    char room[5];
    int i, flag=0;
    printf("\nEnter room number: ");
    scanf("%s", room);
    for(i=0;i<SIZE;i++){
        if(strcmp((h+i)->room, room) == 0){   //If room number matches
            strcpy((h+i)->room, "");
            strcpy((h+i)->name, "");
            strcpy((h+i)->checkin, "");
            strcpy((h+i)->checkout, "");
            printf("Guest deleted successfully!\n");
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("Guest not found!\n");
    }
}

int main(){
    struct hotel hotelList[SIZE];
    int choice;
    while(1){
        printf("\n*****HOTEL MANAGEMENT SYSTEM*****\n");
        printf("1. Add a new guest\n");
        printf("2. Display all guests\n");
        printf("3. Search for a guest by name\n");
        printf("4. Delete a guest by room number\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: addGuest(hotelList);
                    break;
            case 2: displayAll(hotelList);
                    break;
            case 3: searchGuest(hotelList);
                    break;
            case 4: deleteGuest(hotelList);
                    break;
            case 5: printf("\nThank you for using the Hotel Management System!\n");
                    exit(0);
            default: printf("\nInvalid choice! Please enter a valid choice.\n");
        }
    }
    return 0;
}
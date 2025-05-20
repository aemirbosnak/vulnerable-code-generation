//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct room{
    char name[20];
    int num;
    char type[20];
};

struct guest{
    char name[20];
    char address[40];
    int age;
    int checkin;
    int checkout;
};

int main(){

    struct room rooms[5]={
        {"Room1",1,"Single"},
        {"Room2",2,"Double"},
        {"Room3",3,"Suite"},
        {"Room4",4,"Twin"},
        {"Room5",5,"Triple"}
    };

    struct guest guests[5]={
        {"John Doe", "123 Main St, Anytown USA", 35, 1, 15},
        {"Jane Doe", "456 Elm St, Anytown USA", 32, 1, 14},
        {"Mike Smith", "789 Oak St, Anytown USA", 27, 1, 13},
        {"Sara Johnson", "111 Pine St, Anytown USA", 45, 2, 15},
        {"Jim Brown", "222 Willow St, Anytown USA", 38, 3, 15}
    };

    int i, j;

    printf("\nWelcome to Hotel Management System\n");
    printf("1. View Rooms\n");
    printf("2. View Guests\n");
    printf("3. Check In\n");
    printf("4. Check Out\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &i);

    switch(i){
        case 1:
            for(j=0; j<5; j++){
                printf("\nRoom %d: %s\n", j+1, rooms[j].name);
                printf("Room Number: %d\n", rooms[j].num);
                printf("Room Type: %s\n", rooms[j].type);
            }
            break;
        case 2:
            for(j=0; j<5; j++){
                printf("\nGuest %d: %s\n", j+1, guests[j].name);
                printf("Address: %s\n", guests[j].address);
                printf("Age: %d\n", guests[j].age);
                printf("Check-in: %d\n", guests[j].checkin);
                printf("Check-out: %d\n", guests[j].checkout);
            }
            break;
        case 3:
            printf("\nEnter Guest Name: ");
            scanf("%s", guests[0].name);
            printf("\nEnter Room Number: ");
            scanf("%d", &rooms[0].num);
            printf("\nEnter Room Type: ");
            scanf("%s", rooms[0].type);
            printf("\nCheck-in Date: ");
            scanf("%d", &guests[0].checkin);
            printf("\nCheck-out Date: ");
            scanf("%d", &guests[0].checkout);
            break;
        case 4:
            printf("\nEnter Guest Name: ");
            scanf("%s", guests[0].name);
            printf("\nEnter Room Number: ");
            scanf("%d", &rooms[0].num);
            printf("\nEnter Room Type: ");
            scanf("%s", rooms[0].type);
            printf("\nCheck-in Date: ");
            scanf("%d", &guests[0].checkin);
            printf("\nCheck-out Date: ");
            scanf("%d", &guests[0].checkout);
            printf("\nCheck-out Complete!\n");
            break;
        case 5:
            printf("\nThank you for using our Hotel Management System! Goodbye.\n");
            break;
        default:
            printf("\nInvalid input. Please try again.\n");
            break;
    }
    return 0;
}
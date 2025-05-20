//FormAI DATASET v1.0 Category: Hotel Management System ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct guest{
    char name[50];
    int room_num;
    int days_of_stay;
    float room_charge;
    float total_charge;
};

int main(){
    int numGuests;
    printf("Welcome to the Genius Hotel Management System!\n");
    printf("How many guests are checking in today?\n");
    scanf("%d",&numGuests);

    struct guest *guests = malloc(numGuests * sizeof(struct guest));

    for(int i=0; i<numGuests; i++){
        printf("Enter name of guest %d: ",i+1);
        scanf("%s",(guests+i)->name);
        printf("Enter room number for guest %d: ",i+1);
        scanf("%d",&(guests+i)->room_num);
        printf("Enter number of days of stay for guest %d: ",i+1);
        scanf("%d",&(guests+i)->days_of_stay);

        switch((guests+i)->room_num){
            case 101:
            case 102:
            case 103:
                (guests+i)->room_charge = 150.00;
                break;
            case 201:
            case 203:
            case 301:
                (guests+i)->room_charge = 200.00;
                break;
            case 302:
            case 303:
                (guests+i)->room_charge = 250.00;
                break;
            default:
                printf("Invalid room number. Please try again.\n");
                i--;
        }
        (guests+i)->total_charge = (guests+i)->room_charge * (guests+i)->days_of_stay;
    }

    printf("\n\nHotel Guest List\n");
    for(int i=0; i<numGuests; i++){
        printf("Guest %d: %s\n",i+1,(guests+i)->name);
        printf("Room number: %d\n",(guests+i)->room_num);
        printf("Days of stay: %d\n",(guests+i)->days_of_stay);
        printf("Room charge per day: %.2f\n",(guests+i)->room_charge);
        printf("Total charge for stay: %.2f\n\n",(guests+i)->total_charge);
    }

    free(guests);
    return 0;
}
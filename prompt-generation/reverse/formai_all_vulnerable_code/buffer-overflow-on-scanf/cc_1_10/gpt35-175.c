//FormAI DATASET v1.0 Category: Hotel Management System ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define HOTEL "HOTEL MANAGEMENT SYSTEM"

struct hotel{
    int roomNumber;
    char guestName[50];
    char guestAddress[100];
    char guestPhone[15];
    int numberOfOccupants;
    int roomType;
    int daysOfStay;
    float roomCost;
    float roomServiceCost;
}h[100];

int count=0;
int room1=0, room2=0, room3=0; //keep track of available rooms

void MainMenu();
void addGuestDetails();
void ListOfOccupants();
void billing();
void searchForGuest();

int main(){
    printf("\n\n\t\t%s\n",HOTEL);
    MainMenu();
    return 0;
}

void MainMenu(){
    int choice;
    do{
        printf("\n----------------------------------------");
        printf("\n|             MAIN MENU                |");
        printf("\n----------------------------------------");
        printf("\n| OPTIONS:                             |");
        printf("\n|      1.  Add Guest Details           |");
        printf("\n|      2.  List of Occupants           |");
        printf("\n|      3.  Bill for Room Services      |");
        printf("\n|      4.  Search for Guest            |");
        printf("\n|      5.  Exit                        |");
        printf("\n----------------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                addGuestDetails();
                break;
            case 2:
                ListOfOccupants();
                break;
            case 3:
                billing();
                break;
            case 4:
                searchForGuest();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice entered. Please try again.");
                MainMenu();
        }
    }while(choice!=5);
}

void addGuestDetails(){
    printf("\n----------------------------------------");
    printf("\nGuest Details Entry");
    printf("\n----------------------------------------");

    int occupied=0;

    printf("\nEnter Guest Name: ");
    scanf("%s",h[count].guestName);

    printf("\nEnter Guest Address: ");
    scanf("%s",h[count].guestAddress);

    printf("\nEnter Guest Phone Number: ");
    scanf("%s",h[count].guestPhone);

    do{
        printf("\nEnter Room Type (1.Single, 2.Double, 3.Deluxe): ");
        scanf("%d",&h[count].roomType);

        switch(h[count].roomType){
            case 1:
                if(room1==10){
                    printf("\nSorry! No single rooms are available! Please try again.");
                    occupied=1;
                }
                else{
                    h[count].roomNumber=101+room1;
                    printf("\nYour room number is: %d",h[count].roomNumber);
                    room1++;
                }
                break;
            case 2:
                if(room2==10){
                    printf("\nSorry! No double rooms are available! Please try again.");
                    occupied=1;
                }
                else{
                    h[count].roomNumber=201+room2;
                    printf("\nYour room number is: %d",h[count].roomNumber);
                    room2++;
                }
                break;
            case 3:
                if(room3==10){
                    printf("\nSorry! No deluxe rooms are available! Please try again.");
                    occupied=1;
                }
                else{
                    h[count].roomNumber=301+room3;
                    printf("\nYour room number is: %d",h[count].roomNumber);
                    room3++;
                }
                break;
            default:
                printf("\nInvalid Choice Entered! Please try again.");
                occupied=1;
                break;
        }
    }while(occupied==1);

    printf("\nEnter Number of Occupants: ");
    scanf("%d",&h[count].numberOfOccupants);

    printf("\nEnter number of Days of Stay: ");
    scanf("%d",&h[count].daysOfStay);

    switch(h[count].roomType){
        case 1:
            h[count].roomCost=h[count].daysOfStay*5000;
            break;
        case 2:
            h[count].roomCost=h[count].daysOfStay*8000;
            break;
        case 3:
            h[count].roomCost=h[count].daysOfStay*12000;
            break;
        default:
            break;

    }

    count++;
    printf("\nRecord Successfully Saved!");
    MainMenu();

}

void ListOfOccupants(){
    printf("\n----------------------------------------");
    printf("\nList of Occupants");
    printf("\n----------------------------------------");

    if(count==0){
        printf("\nNo Occupants Found!");
        MainMenu();
    }

    int i;
    for(i=0;i<count;i++){
        printf("\n\nGuest Name: %s",h[i].guestName);
        printf("\nGuest Address: %s",h[i].guestAddress);
        printf("\nGuest Phone No: %s",h[i].guestPhone);
        printf("\nRoom Number: %d",h[i].roomNumber);
        printf("\nNumber of Occupants: %d",h[i].numberOfOccupants);
        printf("\nNumber of Days of Stay: %d",h[i].daysOfStay);
    }

    MainMenu();

}

void billing(){
    printf("\n----------------------------------------");
    printf("\nBilling of Room Services");
    printf("\n----------------------------------------");

    float total=0;

    if(count==0){
        printf("\nNo Bill to Generate!");
        MainMenu();
    }

    int roomno,i;

    printf("\nEnter Room Number: ");
    scanf("%d",&roomno);

    for(i=0;i<count;i++){
        if(h[i].roomNumber==roomno){
            printf("\n\nGuest Name: %s",h[i].guestName);
            printf("\nNumber of Days of Stay: %d",h[i].daysOfStay);

            printf("\nEnter Room Service Cost: ");
            scanf("%f",&h[i].roomServiceCost);

            total=h[i].roomCost+h[i].roomServiceCost;

            printf("\nTotal Cost: Rs. %.2f",total);
        }
    }
    MainMenu();
}

void searchForGuest(){
    printf("\n----------------------------------------");
    printf("\nSearch for Guest");
    printf("\n----------------------------------------");

    if(count==0){
        printf("\nNo Occupants Found!");
        MainMenu();
    }

    char guestname[50];
    int i,found=0;

    printf("\nEnter Guest Name: ");
    scanf("%s",guestname);

    for(i=0;i<count;i++){
        if(strcmp(h[i].guestName,guestname)==0){
            printf("\n\nGuest Name: %s",h[i].guestName);
            printf("\nGuest Address: %s",h[i].guestAddress);
            printf("\nGuest Phone No: %s",h[i].guestPhone);
            printf("\nRoom Number: %d",h[i].roomNumber);
            printf("\nNumber of Occupants: %d",h[i].numberOfOccupants);
            printf("\nNumber of Days of Stay: %d",h[i].daysOfStay);
            found=1;
        }
    }

    if(found==0){
        printf("\n\nSorry! Guest Not Found!");
    }

    MainMenu();
}
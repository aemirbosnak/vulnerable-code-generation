//FormAI DATASET v1.0 Category: Hotel Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Guest{
    char name[20];
    char room_type[10];
    int room_number;
    int num_of_nights;
    int price;
};

void display_menu(){
    printf("\n\n");
    printf("############################ \n");
    printf("### WELCOME TO CASTLE INN ### \n");
    printf("############################ \n");
    printf("\n");
    printf("SELECT A ROOM TYPE:\n");
    printf("1. Royal Suite\n");
    printf("2. Knight's Quarters\n");
    printf("3. Peasant's Chamber\n");
    printf("4. Check-out\n");
}

void display_rooms(){
    printf("\n");
    printf("############################ \n");
    printf("#### AVAILABLE ROOMS ##### \n");
    printf("############################ \n");
    printf("\n");
    printf("Royal Suite: Room 101 - $500 per night\n");
    printf("              Room 102 - $500 per night\n");
    printf("              Room 103 - $500 per night\n");
    printf("Knight's Quarters: Room 201 - $250 per night\n");
    printf("                   Room 202 - $250 per night\n");
    printf("                   Room 203 - $250 per night\n");
    printf("Peasant's Chamber: Room 301 - $50 per night\n");
    printf("                   Room 302 - $50 per night\n");
    printf("                   Room 303 - $50 per night\n");
}

int calculate_price(char* room_type, int num_of_nights){
    int price = 0;
    if(strcmp(room_type, "Royal Suite") == 0){
        price = num_of_nights * 500;
    }
    else if(strcmp(room_type, "Knight's Quarters") == 0){
        price = num_of_nights * 250;
    }
    else if(strcmp(room_type, "Peasant's Chamber") == 0){
        price = num_of_nights * 50;
    }
    return price;
}

int main(){
    struct Guest guests[10];
    int choice, index = 0;

    do{
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                display_rooms();
                printf("Enter room number: ");
                scanf("%d", &guests[index].room_number);
                strcpy(guests[index].name, "Guest1");
                strcpy(guests[index].room_type, "Royal Suite");
                printf("Enter number of nights: ");
                scanf("%d", &guests[index].num_of_nights);
                guests[index].price = calculate_price(guests[index].room_type, guests[index].num_of_nights);
                printf("\n");
                printf("Welcome to your Royal Suite! \n");
                printf("Your booking details are as follows:\n");
                printf("Name: %s\n", guests[index].name);
                printf("Room Type: %s\n", guests[index].room_type);
                printf("Room Number: %d\n", guests[index].room_number);
                printf("Number of nights: %d\n", guests[index].num_of_nights);
                printf("Price: $%d\n", guests[index].price);
                printf("\n");
                index++;
                break;
            case 2:
                display_rooms();
                printf("Enter room number: ");
                scanf("%d", &guests[index].room_number);
                strcpy(guests[index].name, "Guest1");
                strcpy(guests[index].room_type, "Knight's Quarters");
                printf("Enter number of nights: ");
                scanf("%d", &guests[index].num_of_nights);
                guests[index].price = calculate_price(guests[index].room_type, guests[index].num_of_nights);
                printf("\n");
                printf("Welcome to the Knight's Quarters! \n");
                printf("Your booking details are as follows:\n");
                printf("Name: %s\n", guests[index].name);
                printf("Room Type: %s\n", guests[index].room_type);
                printf("Room Number: %d\n", guests[index].room_number);
                printf("Number of nights: %d\n", guests[index].num_of_nights);
                printf("Price: $%d\n", guests[index].price);
                printf("\n");
                index++;
                break;
            case 3:
                display_rooms();
                printf("Enter room number: ");
                scanf("%d", &guests[index].room_number);
                strcpy(guests[index].name, "Guest1");
                strcpy(guests[index].room_type, "Peasant's Chamber");
                printf("Enter number of nights: ");
                scanf("%d", &guests[index].num_of_nights);
                guests[index].price = calculate_price(guests[index].room_type, guests[index].num_of_nights);
                printf("\n");
                printf("Welcome to the Peasant's Chamber! \n");
                printf("Your booking details are as follows:\n");
                printf("Name: %s\n", guests[index].name);
                printf("Room Type: %s\n", guests[index].room_type);
                printf("Room Number: %d\n", guests[index].room_number);
                printf("Number of nights: %d\n", guests[index].num_of_nights);
                printf("Price: $%d\n", guests[index].price);
                printf("\n");
                index++;
                break;
            case 4:
                printf("\n");
                printf("############################ \n");
                printf("#### CHECK-OUT SUMMARY #### \n");
                printf("############################ \n");
                printf("\n");
                for(int i = 0; i < index; i++){
                    printf("Guest %d\n", i+1);
                    printf("Name: %s\n", guests[i].name);
                    printf("Room Type: %s\n", guests[i].room_type);
                    printf("Room Number: %d\n", guests[i].room_number);
                    printf("Number of Nights: %d\n", guests[i].num_of_nights);
                    printf("Price: $%d\n", guests[i].price);
                    printf("\n");
                }
                break;
            default:
                printf("\n");
                printf("Invalid choice. Please try again.\n");
                break;
        }

    }while(choice != 4);

    return 0;
}
//FormAI DATASET v1.0 Category: Hotel Management System ; Style: complex
#include<stdio.h>
#include<string.h>

//Defining the structure of a room
struct room {
    int room_number;
    char type[20];
    char status[20];
    float price;
};

//Function to add rooms
void add_room(struct room hotel_rooms[], int room_count) {
    printf("Enter room number: ");
    scanf("%d",&hotel_rooms[room_count].room_number);
    printf("Enter room type: ");
    scanf("%s",hotel_rooms[room_count].type);
    printf("Enter room status: ");
    scanf("%s",hotel_rooms[room_count].status);
    printf("Enter room price: ");
    scanf("%f",&hotel_rooms[room_count].price);
    printf("\nRoom added successfully\n");
}

//Function to display all rooms
void display_rooms(struct room hotel_rooms[], int room_count) {
    printf("\nRoom Number\tRoom Type\tRoom Status\tPrice\n");
    for(int i=0;i<room_count;i++) {
        printf("%d\t\t%s\t\t%s\t\t%.2f\n",hotel_rooms[i].room_number,hotel_rooms[i].type,hotel_rooms[i].status,hotel_rooms[i].price);
    }
}

//Function to display available rooms
void display_available_rooms(struct room hotel_rooms[], int room_count) {
    printf("\nAvailable Rooms\n");
    printf("\nRoom Number\tRoom Type\tRoom Status\tPrice\n");
    for(int i=0;i<room_count;i++) {
        if(strcmp(hotel_rooms[i].status,"available")==0) {
            printf("%d\t\t%s\t\t%s\t\t%.2f\n",hotel_rooms[i].room_number,hotel_rooms[i].type,hotel_rooms[i].status,hotel_rooms[i].price);
        }
    }
}

//Function to book a room
void book_room(struct room hotel_rooms[], int room_count) {
    int room_number;
    printf("\nEnter room number to book: ");
    scanf("%d",&room_number);
    for(int i=0;i<room_count;i++) {
        if(hotel_rooms[i].room_number==room_number && strcmp(hotel_rooms[i].status,"available")==0) {
            strcpy(hotel_rooms[i].status,"booked");
            printf("\nRoom booked successfully\n");
            return;
        }
    }
    printf("\nRoom not available\n");
}

int main() {
    struct room hotel_rooms[100];
    int room_count = 0,choice;
    while(1) {
        printf("\n\n\t\tHotel Management System\n");
        printf("\n1. Add Room\n");
        printf("2. Display All Rooms\n");
        printf("3. Display Available Rooms\n");
        printf("4. Book Room\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                add_room(hotel_rooms,room_count);
                room_count++;
                break;
            case 2:
                display_rooms(hotel_rooms,room_count);
                break;
            case 3:
                display_available_rooms(hotel_rooms,room_count);
                break;
            case 4:
                book_room(hotel_rooms,room_count);
                break;
            case 5:
                printf("\nExiting the program");
                return 0;
                break;
            default:
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Hotel Management System ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXROOMS 50
#define MAXGUESTS 100

// structures
typedef struct {
    int roomno;
    char type[20];
    int price;
    char status[10];
} Room;

typedef struct {
    char name[20];
    int age;
    char sex[10];
    char address[100];
    char phone[20];
    char email[50];
    int roomno;
} Guest;

// global variables
Room rooms[MAXROOMS];
Guest guests[MAXGUESTS];

int numrooms = 0;
int numguests = 0;

// function prototypes
void add_room();
void display_rooms();
void checkin_guest();
void checkout_guest();
void display_guests();

int main() {
    int choice;

    do {
        printf("\n-------------------\n");
        printf("Hotel Management System\n");
        printf("-------------------\n");
        printf("1. Add Room\n");
        printf("2. Display Rooms\n");
        printf("3. Check-in Guest\n");
        printf("4. Check-out Guest\n");
        printf("5. Display Guests\n");
        printf("6. Exit\n");
        printf("-------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_room();
                break;
            case 2:
                display_rooms();
                break;
            case 3:
                checkin_guest();
                break;
            case 4:
                checkout_guest();
                break;
            case 5:
                display_guests();
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while(choice != 6);

    return 0;
}

void add_room() {
    int roomno, price;
    char type[20], status[10];

    printf("Enter Room No: ");
    scanf("%d", &roomno);
    printf("Enter Room Type: ");
    scanf("%s", type);
    printf("Enter Room Price: ");
    scanf("%d", &price);
    strcpy(status, "Available");

    rooms[numrooms].roomno = roomno;
    strcpy(rooms[numrooms].type, type);
    rooms[numrooms].price = price;
    strcpy(rooms[numrooms].status, status);

    numrooms++;

    printf("\nRoom Added Successfully!\n");
}

void display_rooms() {
    printf("-------------------\n");
    printf("ROOMS\n");
    printf("-------------------\n");
    printf("Room No   Type         Price       Status\n");
    printf("-------------------\n");
    for(int i=0; i<numrooms; i++) {
        printf("%-10d %-12s $%-10d %-10s\n", rooms[i].roomno, rooms[i].type, rooms[i].price, rooms[i].status);
    }
}

void checkin_guest() {
    if(numguests == MAXGUESTS) {
        printf("Error: No More Rooms Available!\n");
        return;
    }

    char name[20], sex[10], address[100], phone[20], email[50];
    int age, roomno;

    printf("Enter Guest Name: ");
    scanf("%s", name);
    printf("Enter Guest Age: ");
    scanf("%d", &age);
    printf("Enter Guest Sex: ");
    scanf("%s", sex);
    printf("Enter Guest Address: ");
    scanf("%s", address);
    printf("Enter Guest Phone: ");
    scanf("%s", phone);
    printf("Enter Guest Email: ");
    scanf("%s", email);

    printf("\n-------------------\n");
    display_rooms(); // display available rooms
    printf("-------------------\n");
    printf("Enter Room No: ");
    scanf("%d", &roomno);

    for(int i=0; i<numrooms; i++) {
        if(rooms[i].roomno == roomno && strcmp(rooms[i].status, "Available") == 0) {
            guests[numguests].roomno = roomno;
            strcpy(guests[numguests].name, name);
            guests[numguests].age = age;
            strcpy(guests[numguests].sex, sex);
            strcpy(guests[numguests].address, address);
            strcpy(guests[numguests].phone, phone);
            strcpy(guests[numguests].email, email);

            strcpy(rooms[i].status, "Occupied");

            numguests++;

            printf("\nGuest Checked-in Successfully!\n");
            return;
        }
    }

    printf("\nError: Room Not Available or Invalid Room No!\n");
}

void checkout_guest() {
    char name[20];
    int roomno;
    int found = 0;

    printf("Enter Guest Name: ");
    scanf("%s", name);
    printf("\n-------------------\n");
    display_guests(); // display all guests
    printf("-------------------\n");
    printf("Enter Room No: ");
    scanf("%d", &roomno);

    for(int i=0; i<numguests; i++) {
        if(strcmp(guests[i].name, name) == 0 && guests[i].roomno == roomno) {
            for(int j=0; j<numrooms; j++) {
                if(rooms[j].roomno == roomno) {
                    strcpy(rooms[j].status, "Available");
                    break;
                }
            }

            for(int k=i; k<numguests-1; k++) {
                guests[k] = guests[k+1];
            }

            numguests--;

            printf("\nGuest Checked-out Successfully!\n");
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nError: Guest Not Found or Invalid Room No!\n");
    }
}

void display_guests() {
    printf("-------------------\n");
    printf("GUESTS\n");
    printf("-------------------\n");
    printf("Room No.   Name         Age  Sex   Address                    Phone         Email\n");
    printf("-------------------\n");
    for(int i=0; i<numguests; i++) {
        printf("%-10d %-12s %-4d %-5s %-25s %-14s %-s\n", guests[i].roomno, guests[i].name, guests[i].age, guests[i].sex, guests[i].address, guests[i].phone, guests[i].email);
    }
}
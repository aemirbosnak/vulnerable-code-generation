//FormAI DATASET v1.0 Category: Hotel Management System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[50];
    int age;
    char gender[20];
    char contact[20];
    int room_num;
    int num_days;
    float bill;
}guest;

int total_rooms = 10;
guest *room;

void check_in();
void check_out();
void display_guest();
void display_all_guest();

int main(){
    int choice;

    room = (guest*) calloc(total_rooms, sizeof(guest));

    do{
        printf("\n\nHotel Management System\n\n");
        printf("1. Check in\n");
        printf("2. Check out\n");
        printf("3. Display Guest\n");
        printf("4. Display All Guests\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: check_in(); break;
            case 2: check_out(); break;
            case 3: display_guest(); break;
            case 4: display_all_guest(); break;
            case 5: exit(0); break;
            default: printf("Invalid choice. Try again."); break;
        }
    }while(1);

    return 0;
}

void check_in(){
    int room_choice, i, flag = 0;

    for(i = 0; i < total_rooms; i++){
        if(room[i].name[0] == '\0'){
            printf("\nRoom available. Enter the guest details:\n");

            room[i].room_num = i+1;

            printf("Name: ");
            scanf("%s", &room[i].name);

            printf("Age: ");
            scanf("%d", &room[i].age);

            printf("Gender: ");
            scanf("%s", &room[i].gender);

            printf("Contact Number: ");
            scanf("%s", &room[i].contact);

            printf("Number of days of stay: ");
            scanf("%d", &room[i].num_days);

            room[i].bill = 1500 * room[i].num_days;

            printf("Room allocated successfully.\n");
            flag = 1;
            break;
        }
    }

    if(!flag){
        printf("All rooms occupied.\n");
    }
}

void check_out(){
    int room_choice, i, flag = 0;

    printf("Enter the room number to check out: ");
    scanf("%d", &room_choice);

    for(i = 0; i < total_rooms; i++){
        if(room[i].room_num == room_choice){
            printf("Guest Bill\n\n");
            printf("Room number: %d\n", room[i].room_num);
            printf("Name: %s\n", room[i].name);
            printf("Age: %d\n", room[i].age);
            printf("Gender: %s\n", room[i].gender);
            printf("Contact Number: %s\n", room[i].contact);
            printf("Number of days of stay: %d\n", room[i].num_days);
            printf("Billing amount: %.2f\n", room[i].bill);

            room[i].name[0] = '\0';
            printf("Room checked out successfully.\n");
            flag = 1;
            break;
        }
    }

    if(!flag){
        printf("Room not found.\n");
    }
}

void display_guest(){
    int room_choice, i, flag = 0;

    printf("Enter the room number to display guest details: ");
    scanf("%d", &room_choice);

    for(i = 0; i < total_rooms; i++){
        if(room[i].room_num == room_choice){
            printf("Guest Details\n\n");
            printf("Room number: %d\n", room[i].room_num);
            printf("Name: %s\n", room[i].name);
            printf("Age: %d\n", room[i].age);
            printf("Gender: %s\n", room[i].gender);
            printf("Contact Number: %s\n", room[i].contact);
            printf("Number of days of stay: %d\n", room[i].num_days);
            printf("Billing amount: %.2f\n", room[i].bill);
            flag = 1;
            break;
        }
    }

    if(!flag){
        printf("Room not found.\n");
    }
}

void display_all_guest(){
    int i, flag = 0;

    printf("All Guest Details\n\n");

    for(i = 0; i < total_rooms; i++){
        if(room[i].name[0] != '\0'){
            printf("Room number: %d\n", room[i].room_num);
            printf("Name: %s\n", room[i].name);
            printf("Age: %d\n", room[i].age);
            printf("Gender: %s\n", room[i].gender);
            printf("Contact Number: %s\n", room[i].contact);
            printf("Number of days of stay: %d\n", room[i].num_days);
            printf("Billing amount: %.2f\n\n", room[i].bill);
            flag = 1;
        }
    }

    if(!flag){
        printf("No guests found.\n");
    }
}
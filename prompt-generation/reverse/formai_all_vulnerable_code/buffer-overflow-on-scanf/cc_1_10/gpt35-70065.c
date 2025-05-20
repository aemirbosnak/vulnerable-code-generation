//FormAI DATASET v1.0 Category: Hotel Management System ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Rooms {
    char room_number[5];
    char room_type[15];
    char availability[10];
    float rent;
}room[50];

int num_rooms;

void add_rooms();
void display_rooms();
void edit_rooms();
void delete_rooms();
void search_rooms();
void room_menu();

int main(){
    int choice;
    num_rooms = 0;

    do{
        printf("\n\n\n\t\t========= HOTEL MANAGEMENT SYSTEM =========");
        printf("\n\n\t\t        1. ROOM MENU");
        printf("\n\n\t\t        2. EXIT");
        printf("\n\n\t\t===========================================");
        printf("\n\n\t\tWhat would you like to do? Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                room_menu();
                break;
            case 2:
                printf("\n\n\t\t******** THANK YOU FOR USING OUR SYSTEM ********\n\n\n");
                break;
            default:
                printf("\n\n\t\tINVALID CHOICE!! Please re-enter your choice.\n\n");
        }

    }while(choice != 2);

    return 0;
}

void room_menu(){
    int choice;

    do{
        printf("\n\n\n\t\t========= ROOMS MENU =========");
        printf("\n\n\t\t        1. ADD ROOM");
        printf("\n\n\t\t        2. DISPLAY ALL ROOMS");
        printf("\n\n\t\t        3. EDIT ROOM DETAILS");
        printf("\n\n\t\t        4. DELETE ROOM");
        printf("\n\n\t\t        5. SEARCH FOR ROOM");
        printf("\n\n\t\t        6. BACK TO MAIN MENU");
        printf("\n\n\t\t================================");
        printf("\n\n\t\tWhat would you like to do? Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_rooms();
                break;
            case 2:
                display_rooms();
                break;
            case 3:
                edit_rooms();
                break;
            case 4:
                delete_rooms();
                break;
            case 5:
                search_rooms();
                break;
            case 6:
                printf("\n\n\t\t******** BACK TO MAIN MENU ********\n\n");
                break;
            default:
                printf("\n\n\t\tINVALID CHOICE!! Please re-enter your choice.\n\n");
        }

    }while(choice != 6);
}

void add_rooms(){
    int i, r_no;
    char ans;

    printf("\n\n\t\t****** ADD ROOM ******\n\n");

    do{
        printf("\n\t\tEnter the room number: ");
        scanf("%d", &r_no);

        for(i = 0; i < num_rooms; i++){
            if(r_no == atoi(room[i].room_number)){
                printf("\n\t\tThe room is already exist!!");
                printf("\n\t\tPlease enter a valid room number : ");
                scanf("%d", &r_no);
                i = -1;
            }
        }
        sprintf(room[num_rooms].room_number, "%d", r_no);

        printf("\n\t\tEnter the room type: ");
        scanf("%s", &room[num_rooms].room_type);

        printf("\n\t\tEnter the rent: ");
        scanf("%f", &room[num_rooms].rent);

        printf("\n\t\tEnter the availability (BOOKED / AVAILABLE) : ");
        scanf("%s", &room[num_rooms].availability);

        num_rooms++;

        printf("\n\t\tDo you want to add another room? (y/n) : ");
        scanf("%s", &ans);

    }while(ans == 'Y' || ans == 'y');

}

void display_rooms(){
    int i;
    printf("\n\n\t\t******** DISPLAY ALL ROOMS ********\n\n");

    printf("\n\tRoom No.\tRoom Type\tRent\tAvailability\n");
    for(i = 0; i < num_rooms; i++){
        printf("\n\t   %s\t\t   %s\t\t %.2f\t   %s", room[i].room_number, room[i].room_type, room[i].rent, room[i].availability);
    }
    printf("\n\n\tThere are %d available rooms.\n", num_rooms);
}

void edit_rooms(){
    int i, r_no;

    printf("\n\n\t\t****** EDIT ROOM DETAILS ******\n\n");

    printf("\n\t\tEnter room number to edit details: ");
    scanf("%d", &r_no);

    for(i = 0; i < num_rooms; i++){
        if(atoi(room[i].room_number) == r_no){
            printf("\n\t\tRoom Details : \n\n");
            printf("\t\t\tRoom Number : %s\n", room[i].room_number);
            printf("\t\t\tRoom Type : %s\n", room[i].room_type);
            printf("\t\t\tRent : %.2f\n", room[i].rent);
            printf("\t\t\tAvailability : %s\n", room[i].availability);

            printf("\n\n\n\t\tWhat do you want to edit? : \n");
            printf("\n\n\t\t\t1. Room Number");
            printf("\n\n\t\t\t2. Room Type");
            printf("\n\n\t\t\t3. Rent");
            printf("\n\n\t\t\t4. Availability");
            printf("\n\n\t\t\t5. Cancel");
            printf("\n\n\t\tEnter your choice : ");

           int choice;
           scanf("%d",&choice);

            switch(choice){
                case 1:
                    printf("\n\t\tNew room number : ");
                    scanf("%d", &r_no);
                    for(int j = 0; j < num_rooms; j++){
                        if(j != i && atoi(room[j].room_number) == r_no){
                            printf("\n\t\tThe room is already exist!!");
                            printf("\n\t\tPlease enter a valid room number : ");
                            scanf("%d", &r_no);
                            j = -1;
                        }
                    }
                    sprintf(room[i].room_number, "%d", r_no);
                    printf("\n\t\tRoom Number updated...");
                    break;
                case 2:
                    printf("\n\t\tNew room type : ");
                    scanf("%s", &room[i].room_type);
                    printf("\n\t\tRoom Type updated...");
                    break;
                case 3:
                    printf("\n\t\tNew rent : ");
                    scanf("%f", &room[i].rent);
                    printf("\n\t\tRent updated...");
                    break;
                case 4:
                    printf("\n\t\tNew availability : ");
                    scanf("%s", &room[i].availability);
                    printf("\n\t\tAvailability status updated...");
                    break;
                case 5:
                    break;
                default:
                    printf("\n\t\tINVALID CHOICE!! Please enter a valid choice.\n");
            }
            break;
        }
    }
    if(i == num_rooms)
        printf("\n\tRoom not found...");
}

void delete_rooms(){
    int i, r_no;

    printf("\n\n\t****** DELETE ROOM ******\n\n");

    printf("\n\tEnter the room number to delete: ");
    scanf("%d", &r_no);

    for(i = 0; i < num_rooms; i++){
        if(atoi(room[i].room_number) == r_no){
            printf("\n\tRoom found!!");
            printf("\tRoom details : \n");
            printf("\t\tRoom Number : %s\n", room[i].room_number);
            printf("\t\tRoom Type : %s\n", room[i].room_type);
            printf("\t\tRent : %.2f\n", room[i].rent);
            printf("\t\tAvailability : %s\n", room[i].availability);

            for(int j = i; j < num_rooms-1; j++){
                room[j] = room[j+1];
            }

            num_rooms--;
            printf("\n\tDeletion successful...");
            break;
        }
    }
    if(i == num_rooms)
        printf("\n\tSorry, couldn't find the room...");

}

void search_rooms(){
    int i, r_no;
    char ans;

    printf("\n\n\t****** SEARCH ROOM ******\n\n");

    do{
        printf("\n\n\tEnter room number to search for: ");
        scanf("%d", &r_no);

        for(i = 0; i < num_rooms; i++){
            if(atoi(room[i].room_number) == r_no){
                printf("\n\tRoom found!!\n");
                printf("\t\tRoom Number : %s\n", room[i].room_number);
                printf("\t\tRoom Type : %s\n", room[i].room_type);
                printf("\t\tRent : %.2f\n", room[i].rent);
                printf("\t\tAvailability : %s\n", room[i].availability);
                break;
            }
        }
        if(i == num_rooms)
            printf("\n\tSorry, couldn't find the room...");

        printf("\n\tDo you want to search another room? (y/n) : ");
        scanf("%s", &ans);

    }while(ans == 'Y' || ans == 'y');
}
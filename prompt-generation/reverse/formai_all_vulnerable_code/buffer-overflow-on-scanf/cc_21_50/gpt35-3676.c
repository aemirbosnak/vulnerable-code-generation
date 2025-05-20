//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Room{
    int room_number;
    char guest_name[20];
    char guest_phone[11];
    char guest_email[40];
    int reserved;
    int num_of_guests;
    float cost_per_night;
};

typedef struct Room Room;

int main(){
    Room room_list[50];
    int user_choice, room_num, num_of_guests, num_of_nights, i, j, flag;
    float total_cost = 0.0;
    char user_input[20];
    FILE *fp;

    // Opening existing file with room information
    fp = fopen("rooms.dat", "rb");
    
    // Checking if file exists, creating a new one if it doesn't
    if(fp==NULL){
        printf("Error! rooms.dat not found. Creating new file...\n");
        fp = fopen("rooms.dat", "wb");
        for(i=1; i<=50; i++){
            room_list[i-1].room_number = i;
            room_list[i-1].reserved = 0;
            fwrite(&room_list[i-1], sizeof(Room), 1, fp);
        }
        printf("New rooms.dat file created successfully!\n");
        fclose(fp);
        fp = fopen("rooms.dat", "rb");
    }
    
    // Reading data from file into room_list array
    fread(&room_list, sizeof(Room), 50, fp);
    
    // Closing file
    fclose(fp);
    
    // Cyberpunk-style interface
    printf("==============================================\n");
    printf("                 APEX HOTEL                    \n");
    printf("==============================================\n");
    printf("\n");
    printf("Welcome to the Apex Hotel!\n");
    printf("What can we assist you with today?\n");
    printf("1. Check room availability\n");
    printf("2. Book a room\n");
    printf("3. View reservation details\n");
    printf("4. Cancel a reservation\n");
    printf("5. Exit system\n");
    
    // Loop for user interaction
    while(1){
        printf("Enter a number to select an option: ");
        scanf("%d", &user_choice);
        
        switch(user_choice){
            case 1:
                printf("ROOM NUMBER       STATUS\n");
                printf("=========================\n");
                for(i=0; i<50; i++){
                    if(room_list[i].reserved == 0){
                        printf("%d           Available\n", room_list[i].room_number);
                    }
                    else{
                        printf("%d           Reserved\n", room_list[i].room_number);
                    }
                }
                break;
                
            case 2:
                printf("Enter desired room number: ");
                scanf("%d", &room_num);
                if(room_num < 1 || room_num > 50){
                    printf("Invalid room number. Please try again.\n");
                    break;
                }
                // Checking if room is already reserved
                if(room_list[room_num-1].reserved == 1){
                    printf("The room is already reserved. Please choose another room.\n");
                }
                else{
                    // If room is available, prompting user for booking details
                    printf("Enter guest name: ");
                    scanf("%s", room_list[room_num-1].guest_name);
                    printf("Enter guest phone number: ");
                    scanf("%s", room_list[room_num-1].guest_phone);
                    printf("Enter guest email address: ");
                    scanf("%s", room_list[room_num-1].guest_email);
                    printf("Enter number of guests: ");
                    scanf("%d", &num_of_guests);
                    room_list[room_num-1].num_of_guests = num_of_guests;
                    printf("Enter number of nights: ");
                    scanf("%d", &num_of_nights);
                    room_list[room_num-1].reserved = 1;
                    room_list[room_num-1].cost_per_night = 75.0;
                    total_cost = num_of_nights * 75.0;
                    printf("\n***************************\n");
                    printf("*      RESERVATION         *\n");
                    printf("* Room Number: %d          *\n", room_list[room_num-1].room_number);
                    printf("* Guest Name: %s         *\n", room_list[room_num-1].guest_name);
                    printf("* Number of Guests: %d    *\n", room_list[room_num-1].num_of_guests);
                    printf("* Nights: %d               *\n", num_of_nights);
                    printf("* Total Cost: %.2f       *\n", total_cost);
                    printf("***************************\n");
                }
                break;
                
            case 3:
                printf("Enter room number: ");
                scanf("%d", &room_num);
                if(room_num < 1 || room_num > 50){
                    printf("Invalid room number. Please try again.\n");
                    break;
                }
                if(room_list[room_num-1].reserved == 0){
                    printf("Room is not currently reserved.\n");
                }
                else{
                    printf("RESERVATION FOR ROOM %d:\n", room_list[room_num-1].room_number);
                    printf("Guest Name: %s\n", room_list[room_num-1].guest_name);
                    printf("Guest Phone Number: %s\n", room_list[room_num-1].guest_phone);
                    printf("Guest Email Address: %s\n", room_list[room_num-1].guest_email);
                    printf("Number of Guests: %d\n", room_list[room_num-1].num_of_guests);
                    printf("Cost per night: %.2f\n", room_list[room_num-1].cost_per_night);
                    printf("Total Cost: %.2f\n", room_list[room_num-1].cost_per_night * num_of_nights);
                }
                break;
                
            case 4:
                printf("Enter room number to cancel reservation: ");
                scanf("%d", &room_num);
                if(room_num < 1 || room_num > 50){
                    printf("Invalid room number. Please try again.\n");
                    break;
                }
                if(room_list[room_num-1].reserved == 0){
                    printf("The room is not currently reserved.\n");
                }
                else{
                    printf("Are you sure you want to cancel the reservation for room %d? (y/n)\n", room_list[room_num-1].room_number);
                    scanf("%s", user_input);
                    if(strcmp(user_input, "y") == 0){
                        room_list[room_num-1].reserved = 0;
                        printf("Reservation has been cancelled for room %d.\n", room_list[room_num-1].room_number);
                    }
                    else{
                        printf("Reservation for room %d has not been cancelled.\n", room_list[room_num-1].room_number);
                    }
                }
                break;
            
            case 5:
                printf("Exiting system...\n");
                // Opening file for writing 
                fp = fopen("rooms.dat", "wb");
                if(fp==NULL){
                    printf("Error! rooms.dat could not be opened.\n");
                    exit(1);
                }
                // Writing updated room information to file
                fwrite(&room_list, sizeof(Room), 50, fp);
                // Closing file
                fclose(fp);
                exit(0);
                break;
                
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}
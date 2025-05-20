//FormAI DATASET v1.0 Category: Hotel Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Defining a struct for the hotel guest information
struct guest{
    char name[30];
    char room_type[20];
    int room_number;
    int nights;
    float bill;
};

// Function to calculate bill based on room type and duration of stay
float calculate_bill(char room_type[], int nights){
    if(strcmp(room_type, "single") == 0){
        return 50 * nights;
    } else if(strcmp(room_type, "double") == 0){
        return 80 * nights;
    } else if(strcmp(room_type, "suite") == 0){
        return 150 * nights;
    } else{
        return -1;
    }
}

// Function to generate a random room number between 101 and 999
int generate_room_number(){
    srand(time(0));
    return (rand() % (999 - 101 + 1)) + 101;
}

int main(){
    int choice, i, num_guests = 0, guest_index = -1;
    struct guest guests[20];
    char search_name[30];

    // Greeting message
    printf("Welcome to the C Hotel Management System!\n");

    while(1){
        // Menu options
        printf("\n---------------------------------------------\n");
        printf("1. Check in a guest\n");
        printf("2. Check out a guest\n");
        printf("3. Search for a guest\n");
        printf("4. Display guest list\n");
        printf("5. Exit\n");
        printf("---------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                // Check in a guest
                printf("\nEnter guest name: ");
                scanf("%s", guests[num_guests].name);
                printf("Enter room type (single, double, suite): ");
                scanf("%s", guests[num_guests].room_type);
                guests[num_guests].room_number = generate_room_number();
                printf("Your room number is: %d\n", guests[num_guests].room_number);
                printf("Enter number of nights: ");
                scanf("%d", &guests[num_guests].nights);
                guests[num_guests].bill = calculate_bill(guests[num_guests].room_type, guests[num_guests].nights);
                printf("Your bill is: %.2f\n", guests[num_guests].bill);
                num_guests++;
                printf("Checked in successfully!\n");
                break;
            case 2:
                // Check out a guest
                printf("\nEnter room number: ");
                int room_num;
                scanf("%d", &room_num);
                for(i=0; i<num_guests; i++){
                    if(guests[i].room_number == room_num){
                        printf("%s has checked out of room %d\n", guests[i].name, guests[i].room_number);
                        guest_index = i;
                    }
                }
                if(guest_index == -1){
                    printf("No guest found with that room number.\n");
                } else{
                    for(i=guest_index; i<num_guests-1; i++){
                        guests[i] = guests[i+1];
                    }
                    num_guests--;
                    guest_index = -1;
                }
                break;
            case 3:
                // Search for a guest by name
                printf("\nEnter guest name to search for: ");
                scanf("%s", search_name);
                for(i=0; i<num_guests; i++){
                    if(strcmp(guests[i].name, search_name) == 0){
                        printf("%s is staying in room %d with a bill of %.2f for %d nights.\n", guests[i].name, guests[i].room_number, guests[i].bill, guests[i].nights);
                        guest_index = i;
                    }
                }
                if(guest_index == -1){
                    printf("No guest found with that name.\n");
                } else{
                    guest_index = -1;
                }
                break;
            case 4:
                // Display guest list sorted by room number
                printf("\nGuest List:\n");
                printf("Name\t\tRoom Number\tRoom Type\tNights\tBill\n");
                struct guest temp;
                for(i=0; i<num_guests; i++){
                    for(int j=i+1; j<num_guests; j++){
                        if(guests[i].room_number > guests[j].room_number){
                            temp = guests[i];
                            guests[i] = guests[j];
                            guests[j] = temp;
                        }
                    }
                }
                for(i=0; i<num_guests; i++){
                    printf("%-15s\t%-10d\t%-10s\t%-5d\t%.2f\n", guests[i].name, guests[i].room_number, guests[i].room_type, guests[i].nights, guests[i].bill);
                }
                break;
            case 5:
                printf("\nThank you for using the C Hotel Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please choose again.\n");
        }
    }
    return 0;
}
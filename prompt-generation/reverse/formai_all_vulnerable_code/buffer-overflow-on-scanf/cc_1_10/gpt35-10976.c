//FormAI DATASET v1.0 Category: Hotel Management System ; Style: single-threaded
#include <stdio.h>
#include <string.h>

// Structure to hold hotel room details
struct room {
    int room_num;
    char name[30];
    int num_of_guests;
    int num_of_nights;
    float room_rate;
};

// Declare functions
void add_room();
void view_rooms();
void edit_room();
void search_room();
void delete_room();

// Global variables
struct room rooms[100];
int num_of_rooms = 0;

int main() {
    int choice;
    
    printf("Welcome to C Hotel Management System!\n");
    printf("-------------------------------------\n\n");
    
    do {
        // Display menu
        printf("1. Add Room\n");
        printf("2. View Rooms\n");
        printf("3. Edit Room\n");
        printf("4. Search Room\n");
        printf("5. Delete Room\n");
        printf("6. Exit\n\n");
        
        // Get user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Call the corresponding function based on user choice
        switch(choice) {
            case 1:
                add_room();
                break;
            case 2:
                view_rooms();
                break;
            case 3:
                edit_room();
                break;
            case 4:
                search_room();
                break;
            case 5:
                delete_room();
                break;
            case 6:
                printf("\nThank you for using C Hotel Management System!\n");
                break;
            default:
                printf("\nInvalid Choice. Please choose a valid option.\n");
        }
        
        printf("\n");
    } while(choice != 6);
    
    return 0;
}

void add_room() {
    printf("\nAdd Room\n");
    printf("--------\n\n");
    
    // Get room details from user
    printf("Enter room number: ");
    scanf("%d", &rooms[num_of_rooms].room_num);
    
    printf("Enter guest name: ");
    scanf("%s", rooms[num_of_rooms].name);
    
    printf("Enter number of guests: ");
    scanf("%d", &rooms[num_of_rooms].num_of_guests);
    
    printf("Enter number of nights: ");
    scanf("%d", &rooms[num_of_rooms].num_of_nights);
    
    printf("Enter room rate: ");
    scanf("%f", &rooms[num_of_rooms].room_rate);
    
    // Increment number of rooms
    num_of_rooms++;
    
    printf("\nRoom added successfully.\n");
}

void view_rooms() {
    int i;
    
    printf("\nView Rooms\n");
    printf("-----------\n\n");
    
    if(num_of_rooms == 0) {
        printf("No rooms available.\n");
        return;
    }
    
    printf("Room Number\tGuest Name\tGuests\tNights\tRate\n");
    
    for(i=0; i<num_of_rooms; i++) {
        printf("%d\t\t%s\t\t%d\t%d\t%.2f\n", rooms[i].room_num, rooms[i].name, rooms[i].num_of_guests, rooms[i].num_of_nights, rooms[i].room_rate);
    }
}

void edit_room() {
    int room_num, i, choice;
    
    printf("\nEdit Room\n");
    printf("---------\n\n");
    
    if(num_of_rooms == 0) {
        printf("No rooms available.\n");
        return;
    }
    
    // Get the room number to be edited
    printf("Enter room number to edit: ");
    scanf("%d", &room_num);
    
    // Find the room by room number
    for(i=0; i<num_of_rooms; i++) {
        if(rooms[i].room_num == room_num) {
            // Display room details
            printf("Room Number\tGuest Name\tGuests\tNights\tRate\n");
            printf("%d\t\t%s\t\t%d\t%d\t%.2f\n", rooms[i].room_num, rooms[i].name, rooms[i].num_of_guests, rooms[i].num_of_nights, rooms[i].room_rate);
            
            // Ask user what to edit
            printf("\nEnter 1 to edit guest name\n");
            printf("Enter 2 to edit number of guests\n");
            printf("Enter 3 to edit number of nights\n");
            printf("Enter 4 to edit room rate\n");
            printf("Enter 5 to go back to main menu\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            
            // Edit the selected field
            switch(choice) {
                case 1:
                    printf("Enter new guest name: ");
                    scanf("%s", rooms[i].name);
                    break;
                case 2:
                    printf("Enter new number of guests: ");
                    scanf("%d", &rooms[i].num_of_guests);
                    break;
                case 3:
                    printf("Enter new number of nights: ");
                    scanf("%d", &rooms[i].num_of_nights);
                    break;
                case 4:
                    printf("Enter new room rate: ");
                    scanf("%f", &rooms[i].room_rate);
                    break;
                case 5:
                    return;
                default:
                    printf("Invalid Choice. Please choose a valid option.\n");
            }
            
            printf("\nRoom updated successfully.\n");
            return;
        }
    }
    
    printf("Room not found.\n");
}

void search_room() {
    int room_num, i;
    
    printf("\nSearch Room\n");
    printf("-----------\n\n");
    
    if(num_of_rooms == 0) {
        printf("No rooms available.\n");
        return;
    }
    
    // Get the room number to be searched
    printf("Enter room number to search: ");
    scanf("%d", &room_num);
    
    // Find the room by room number
    for(i=0; i<num_of_rooms; i++) {
        if(rooms[i].room_num == room_num) {
            // Display room details
            printf("Room Number\tGuest Name\tGuests\tNights\tRate\n");
            printf("%d\t\t%s\t\t%d\t%d\t%.2f\n", rooms[i].room_num, rooms[i].name, rooms[i].num_of_guests, rooms[i].num_of_nights, rooms[i].room_rate);
            return;
        }
    }
    
    printf("Room not found.\n");
}

void delete_room() {
    int room_num, i, j;
    
    printf("\nDelete Room\n");
    printf("-----------\n\n");
    
    if(num_of_rooms == 0) {
        printf("No rooms available.\n");
        return;
    }
    
    // Get the room number to be deleted
    printf("Enter room number to delete: ");
    scanf("%d", &room_num);
    
    // Find the room by room number
    for(i=0; i<num_of_rooms; i++) {
        if(rooms[i].room_num == room_num) {
            // Shift all rooms after the deleted room one place to the left
            for(j=i+1; j<num_of_rooms; j++) {
                rooms[j-1] = rooms[j];
            }
            
            // Decrement number of rooms
            num_of_rooms--;
            
            printf("\nRoom deleted successfully.\n");
            return;
        }
    }
    
    printf("Room not found.\n");
}
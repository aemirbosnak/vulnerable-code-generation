//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define cyberpunk style colors for user interface 
#define CYAN    "\x1B[36m"
#define MAGENTA "\x1B[35m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define RED     "\x1B[31m"
#define RESET   "\x1B[0m"

// Define hotel structure for storing information about guests and rooms
struct hotel {
    char guest_name[50];
    int room_number;
    char room_type[20];
    int nights;
};

// Define main function
int main() {
    
    // Define variables for menu
    int choice;
    int num_guests = 0; // Initializes guest counter
    
    // Allocate memory for hotel information
    struct hotel *guests = (struct hotel*) malloc(sizeof(struct hotel));
    
    // Print header
    printf(YELLOW "============ C HOTEL MANAGEMENT SYSTEM ===========\n\n" RESET);
    
    // Loop for menu options
    do {
        // Print menu options
        printf(GREEN "1. Add guest\n");
        printf("2. View all guests\n");
        printf("3. Search for guest\n");
        printf("4. Delete guest\n");
        printf("5. Exit\n\n" RESET);

        // Prompt for menu choice
        printf("Please enter your choice: ");
        scanf("%d",&choice);
        printf("\n");

        switch(choice) {
            
            case 1: // Add guest
                
                // Prompt and store guest information
                printf(CYAN "Please enter guest name: ");
                scanf("%s", guests[num_guests].guest_name);
                printf("Please enter room number: ");
                scanf("%d", &guests[num_guests].room_number);
                printf("Please enter room type: ");
                scanf("%s", guests[num_guests].room_type);
                printf("Please enter nights stayed: ");
                scanf("%d", &guests[num_guests].nights);
                
                // Increment guest counter
                num_guests++;
                
                // Reallocate memory for additional guests
                guests = (struct hotel*) realloc(guests, (num_guests+1)*sizeof(struct hotel));
                
                printf("\n" RESET);
                break;
                
            case 2: // View all guests
                
                if(num_guests==0) { // Check if there are any guests
                    printf(RED "No guests in the system.\n\n" RESET);
                    break;
                } 
                
                // Print all guests information
                printf(CYAN "Guest Name\tRoom Number\tRoom Type\tNights Stayed\n" RESET);
                for(int i=0; i<num_guests; i++) {
                    printf("%s\t\t%d\t\t%s\t\t%d\n", 
                            guests[i].guest_name, guests[i].room_number, guests[i].room_type, guests[i].nights);
                }
                printf("\n");
                break;
                
            case 3: // Search for guest
                
                if(num_guests==0) { // Check if there are any guests
                    printf(RED "No guests in the system.\n\n" RESET);
                    break;
                }
                
                // Prompt for guest name to search
                char search_name[50];
                printf(CYAN "Please enter guest name to search: ");
                scanf("%s", search_name);
                printf("\n" RESET);
                
                // Loop through guests and search by name
                int found = 0; // Flag for whether guest is found or not
                for(int i=0; i<num_guests; i++) {
                    if(strcmp(guests[i].guest_name, search_name) == 0) {
                        printf(CYAN "Guest Name\tRoom Number\tRoom Type\tNights Stayed\n" RESET);
                        printf("%s\t\t%d\t\t%s\t\t%d\n\n", 
                                guests[i].guest_name, guests[i].room_number, guests[i].room_type, guests[i].nights);
                        found = 1; // Set flag to indicate guest was found
                        break;
                    }
                }
                if(!found) { // Check if guest was not found
                    printf(RED "Guest not found.\n\n" RESET);
                }
                break;
                
            case 4: // Delete guest
                
                if(num_guests==0) { // Check if there are any guests
                    printf(RED "No guests in the system.\n\n" RESET);
                    break;
                }
                
                // Prompt for guest name to delete
                char delete_name[50];
                printf(CYAN "Please enter guest name to delete: ");
                scanf("%s", delete_name);
                printf("\n" RESET);
                
                // Loop through guests and search by name
                int deleted = 0; // Flag for whether guest is deleted or not
                for(int i=0; i<num_guests; i++) {
                    if(strcmp(guests[i].guest_name, delete_name) == 0) {
                        // Delete guest by shifting succeeding elements to the left
                        for(int j=i; j<num_guests-1; j++) {
                            guests[j] = guests[j+1];
                        }
                        num_guests--; // Decrement guest counter
                        deleted = 1; // Set flag to indicate guest was deleted
                        printf(GREEN "Guest has been successfully deleted.\n\n" RESET);
                        break;
                    }
                }
                if(!deleted) { // Check if guest was not deleted
                    printf(RED "Guest not found.\n\n" RESET);
                }
                break;
                
            case 5: // Exit
                
                printf(YELLOW "Exiting C Hotel Management System...\n\n" RESET);
                break;
                
            default: // Invalid choice
                
                printf(RED "Invalid choice. Please try again.\n\n" RESET);
                break;
        }
        
    } while(choice != 5); // While choice is not exit
    
    // Free allocated memory
    free(guests);
    
    // Return success
    return 0;
}
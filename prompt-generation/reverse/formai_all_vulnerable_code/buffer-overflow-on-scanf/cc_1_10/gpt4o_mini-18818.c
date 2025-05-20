//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void show_menu();
void travel_to_year(int year);
void display_event(int year);
void clear_input_buffer();

int main() {
    int choice;

    while (1) {
        show_menu();
        printf("Enter the year (or -1 to exit): ");
        scanf("%d", &choice);

        // Exit condition
        if (choice == -1) {
            printf("Exiting Time Travel Simulator. Safe travels!\n");
            break;
        }
        
        // Validate the year
        if (choice < 0) {
            printf("Please enter a valid year or -1 to exit.\n");
            continue;
        }
        
        travel_to_year(choice);
    }
    return 0;
}

// Function to display the main menu
void show_menu() {
    printf("\n--- Time Travel Simulator ---\n");
    printf("Welcome, time traveler!\n");
    printf("Choose a year to travel to:\n");
}

// Function simulating time travel
void travel_to_year(int year) {
    printf("*** Engaging time travel sequence to the year %d ***\n", year);
    display_event(year);
}

// Function to display an event based on the year
void display_event(int year) {
    switch(year) {
        case 2023:
            printf("In 2023, humanity is dealing with climate change and technological advancements in AI.\n");
            break;
        case 2000:
            printf("In 2000, the world was worried about the Y2K bug.\n");
            break;
        case 1994:
            printf("In 1994, the first massive online multiplayer game was released - 'Meridian 59.'\n");
            break;
        case 1989:
            printf("In 1989, the Berlin Wall came down, marking a significant end to the Cold War.\n");
            break;
        case 1776:
            printf("In 1776, the Declaration of Independence was adopted in the United States.\n");
            break;
        case 1066:
            printf("In 1066, the Norman Conquest of England took place.\n");
            break;
        default:
            printf("In %d, there's no significant event recorded in this simulator. Explore the unknown!\n", year);
            break;
    }
}

// Function to clear the input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRAVELS 10

// Function to simulate the time travel 
void timeTravel(int year) {
    switch (year) {
        case 2023:
            printf("Welcome to the year 2023! Don’t forget to update your social media profile...\n");
            printf("... Also, watch out for aliens! They're everywhere!\n");
            break;
        case 1960:
            printf("You've arrived in 1960! Watch out for hula hoops and Elvis impersonators!\n");
            break;
        case 1999:
            printf("Welcome to 1999! Be careful, the Y2K problem is looming! Upgrade your floppy disks!\n");
            break;
        case 3000:
            printf("Welcome to the year 3000! It’s a great time for robots, but bad news for barbers...\n");
            break;
        case 1800:
            printf("You've traveled back to the 1800s! Time to put on your top hat and get ready for a duel!\n");
            break;
        case -500:
            printf("Congratulations! You've landed in 500 BC! Time to learn some ancient wisdom - and keep your sandals on!\n");
            break;
        default:
            printf("Unknown year! It seems you've stumbled into a time-loop! Good luck getting back!\n");
            break;
    }
}

// Function to present traveling options
void presentOptions() {
    printf("\nPick a year to travel to:\n");
    printf("1: 2023\n");
    printf("2: 1960\n");
    printf("3: 1999\n");
    printf("4: 3000\n");
    printf("5: 1800\n");
    printf("6: 500 BC\n");
    printf("0: Exit Time Travel Simulator\n");
}

int main() {
    int choice;
    
    printf("Welcome to the Time Travel Simulator 3000!\n");
    printf("Prepare yourself, brave traveler! (or very confused potato!)\n");
    
    while (1) {
        presentOptions();
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Exiting the Time Travel Simulator. Remember, what goes forward must come back!\n");
            break;
        }
        
        switch (choice) {
            case 1:
                timeTravel(2023);
                break;
            case 2:
                timeTravel(1960);
                break;
            case 3:
                timeTravel(1999);
                break;
            case 4:
                timeTravel(3000);
                break;
            case 5:
                timeTravel(1800);
                break;
            case 6:
                timeTravel(-500);
                break;
            default:
                printf("That's not a time period! Are you trying to mess with the space-time continuum?\n");
                break;
        }
        
        printf("Do you wish to travel again? (1 for Yes, 0 for No): ");
        int travelAgain;
        scanf("%d", &travelAgain);
        
        if (travelAgain == 0) {
            printf("Thank you for using the Time Travel Simulator! Please check your atoms for errors!\n");
            break;
        } else {
            printf("Great! The time machine is ready! Who knows where or when you’ll end up next?\n");
        }
    }
    
    printf("Time travel is risky, so wear your seatbelt!!!\n");
    
    return 0;
}
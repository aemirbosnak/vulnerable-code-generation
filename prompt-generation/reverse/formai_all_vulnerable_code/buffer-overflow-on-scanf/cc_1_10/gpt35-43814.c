//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed random number generator
    
    int latitude = rand() % 90; // Generate random latitude between 0 and 89
    int longitude = rand() % 180; // Generate random longitude between 0 and 179
    
    printf("Initial coordinates: (%d, %d)\n", latitude, longitude);
    
    int choice;
    do {
        // Print menu
        printf("\nChoose an option:\n");
        printf("1. Move North\n");
        printf("2. Move South\n");
        printf("3. Move East\n");
        printf("4. Move West\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        
        // Switch statement to handle user input
        switch (choice) {
            case 1:
                latitude++;
                break;
            case 2:
                latitude--;
                break;
            case 3:
                longitude++;
                break;
            case 4:
                longitude--;
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
        
        // Print updated coordinates
        printf("(%d, %d)\n", latitude, longitude);
    
    } while (choice != 5); // Loop until user chooses to exit
    
    return 0;
}
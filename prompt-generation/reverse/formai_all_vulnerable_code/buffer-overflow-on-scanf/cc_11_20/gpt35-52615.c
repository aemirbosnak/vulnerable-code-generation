//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
    // generate random starting position
    srand(time(NULL));
    int x = rand() % 100;
    int y = rand() % 100;
    
    printf("Current position: (%d, %d)\n", x, y);
    
    // simulate GPS navigation
    while(1) {
        int choice;
        printf("Choose a direction:\n1. North\n2. East\n3. South\n4. West\n5. Stop navigating\n");
        scanf("%d", &choice);
        
        // move in chosen direction
        switch(choice) {
            case 1:
                y += 10;
                printf("Moved north. Current position: (%d, %d)\n", x, y);
                break;
            case 2:
                x += 10;
                printf("Moved east. Current position: (%d, %d)\n", x, y);
                break;
            case 3:
                y -= 10;
                printf("Moved south. Current position: (%d, %d)\n", x, y);
                break;
            case 4:
                x -= 10;
                printf("Moved west. Current position: (%d, %d)\n", x, y);
                break;
            case 5:
                printf("Stopped navigating.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        
        // randomly shift position
        int shiftChoice = rand() % 4;
        switch(shiftChoice) {
            case 0:
                x += 5;
                printf("Shifted slightly east. Current position: (%d, %d)\n", x, y);
                break;
            case 1:
                x -= 5;
                printf("Shifted slightly west. Current position: (%d, %d)\n", x, y);
                break;
            case 2:
                y += 5;
                printf("Shifted slightly north. Current position: (%d, %d)\n", x, y);
                break;
            case 3:
                y -= 5;
                printf("Shifted slightly south. Current position: (%d, %d)\n", x, y);
                break;
        }
    }
    
    return 0;
}
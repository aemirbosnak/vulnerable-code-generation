//FormAI DATASET v1.0 Category: Funny ; Style: energetic
#include <stdio.h>

int main() {
    
    int energy_level = 100; // Starting energy level
    int count = 0; // Number of activities
    int choice; // User's choice of activity
    
    printf("\nWelcome to the Energetic Program!\n");
    printf("Choose from the following activities:\n");
    
    while(energy_level > 0) {
        // Display the available activities
        printf("\n1. Jumping Jacks\n2. Running in Place\n3. Dancing\n");
        printf("4. Push-Ups\n5. Rest\n\n");
        printf("Your energy level is: %d\n", energy_level);
        printf("Enter your choice of activity: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nJumping Jacks! Great way to get the blood flowing!\n");
                energy_level -= 10;
                count++;
                break;
            case 2:
                printf("\nRunning in Place! Keep that heart rate up!\n");
                energy_level -= 15;
                count++;
                break;
            case 3:
                printf("\nDancing! Let's get the party started!\n");
                energy_level -= 20;
                count++;
                break;
            case 4:
                printf("\nPush-Ups! Working those muscles!\n");
                energy_level -= 25;
                count++;
                break;
            case 5:
                printf("\nRest! Taking a break to recharge!\n");
                energy_level += 5;
                break;
            default:
                printf("Not a valid choice!\n");
        }

        // If energy level is less than or equal to zero, end the program
        if(energy_level <= 0) {
            printf("\nYou have run out of energy! Time to call it quits!\n");
            break;
        }

    }

    printf("\nYou've completed %d energetic activities! Great job!\n", count); 

    return 0;
}
//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>

int main() {
    int calories = 0;
    int steps = 0;
    int distance = 0;
    
    printf("Welcome to the C Fitness Tracker!\n");
    printf("Enter your starting number of calories burned: ");
    scanf("%d", &calories);
    
    printf("Enter your starting number of steps taken: ");
    scanf("%d", &steps);
    
    printf("Enter your starting distance traveled (in miles): ");
    scanf("%d", &distance);
    
    // loop until user wants to exit
    while(1) {
        int option;
        
        printf("\nWhat would you like to do?\n");
        printf("1. Record calories burned\n");
        printf("2. Record steps taken\n");
        printf("3. Record distance traveled\n");
        printf("4. Exit\n");
        scanf("%d", &option);
        
        if(option == 1) {
            int burned;
            printf("Enter number of calories burned: ");
            scanf("%d", &burned);
            calories += burned;
            printf("Total calories burned: %d\n", calories);
        }
        else if(option == 2) {
            int taken;
            printf("Enter number of steps taken: ");
            scanf("%d", &taken);
            steps += taken;
            printf("Total steps taken: %d\n", steps);
        }
        else if(option == 3) {
            int traveled;
            printf("Enter distance traveled (in miles): ");
            scanf("%d", &traveled);
            distance += traveled;
            printf("Total distance traveled: %d miles\n", distance);
        }
        else if(option == 4) {
            printf("Thank you for using the C Fitness Tracker!\n");
            break;
        }
        else {
            printf("Invalid option, please try again.\n");
        }
    }
    
    return 0;
}
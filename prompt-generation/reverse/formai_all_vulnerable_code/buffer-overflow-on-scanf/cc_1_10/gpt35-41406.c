//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int investigation_day = 1; // Initializing investigation day of the case
    int gym_visits = 0; // Initializing number of gym visits for the suspect
    int jogging_distance = 0; // Initializing jogging distance for the suspect
    
    printf("Welcome to the Fitness Tracker of Sherlock Holmes!\n\n");
    printf("Today is the first day of our investigation.\n\n");
    
    while (investigation_day <= 7) { // Conducting investigation for a week
        
        printf("Day %d of investigation\n", investigation_day);
        
        printf("Enter the number of times the suspect visited the gym: ");
        scanf("%d", &gym_visits);
        
        printf("Enter the jogging distance done by the suspect (in kms): ");
        scanf("%d", &jogging_distance);
        
        if (gym_visits >= 4 && jogging_distance <= 5) { // Check for suspect's alibi
            
            printf("\nThe suspect's alibi checks out.\n\n");
            
        } else {
            
            printf("\nAlert! The suspect might be involved in the case.\n");
            printf("We need to keep a close eye on the suspect's fitness activities.\n\n");
            
            if (gym_visits < 4) {
                printf("The suspect has not been visiting the gym enough.\n");
                printf("We need to find out where they're spending their time instead.\n");
            }
            
            if (jogging_distance > 5) {
                printf("The suspect has been running farther than usual.\n");
                printf("We need to find out where all that energy is being used.\n");
            }
        }
        
        investigation_day++; // Incrementing the day count
    }

    printf("The investigation has ended.\n");
    printf("Thank you for using the Fitness Tracker of Sherlock Holmes!\n");

    return 0;
}
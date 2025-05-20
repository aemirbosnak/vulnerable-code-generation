//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: immersive
#include <stdio.h>

int main() {
    int day = 1; // Day counter
    float previous_weight, current_weight, weight_gain_loss; // Weight variables
    float daily_calorie_intake, calorie_intake_goal; // Calorie variables
    
    // Prompt user for previous weight
    printf("What was your previous weight (in pounds)? ");
    scanf("%f", &previous_weight);
    
    // Prompt user for current weight
    printf("What is your current weight (in pounds)? ");
    scanf("%f", &current_weight);
    
    // Calculate weight gain or loss
    weight_gain_loss = current_weight - previous_weight;
    
    // Display weight gain or loss
    printf("You have %s%.1f pounds since your last weigh-in.\n", 
    weight_gain_loss >= 0 ? "gained " : "lost ", weight_gain_loss);
    
    // Prompt user for daily calorie intake
    printf("How many calories do you consume per day? ");
    scanf("%f", &daily_calorie_intake);
    
    // Prompt user for calorie intake goal
    printf("What is your calorie intake goal per day? ");
    scanf("%f", &calorie_intake_goal);
    
    // Calculate percentage of goal met
    float percent_goal_met = (daily_calorie_intake / calorie_intake_goal) * 100;
    
    // Display percentage of goal met
    printf("You have met %.1f%% of your daily calorie intake goal.\n", percent_goal_met);
    
    // Loop through 30 days
    while(day <= 30) {
        // Prompt user for current weight
        printf("\nDay %d\n", day); // Print day number
        printf("What is your current weight (in pounds)? ");
        scanf("%f", &current_weight);
        
        // Calculate weight gain or loss
        weight_gain_loss = current_weight - previous_weight;
        
        // Display weight gain or loss
        printf("You have %s%.1f pounds since your last weigh-in.\n", 
        weight_gain_loss >= 0 ? "gained " : "lost ", weight_gain_loss);
        
        // Update previous weight
        previous_weight = current_weight;
        
        // Prompt user for daily calorie intake
        printf("How many calories did you consume today? ");
        scanf("%f", &daily_calorie_intake);
        
        // Calculate difference between daily calorie intake and goal
        float calorie_intake_difference = calorie_intake_goal - daily_calorie_intake;
        
        // Check if goal was met
        if(calorie_intake_difference == 0) {
            printf("You met your calorie intake goal!\n");
        }
        else if(calorie_intake_difference < 0) {
            printf("You exceeded your calorie intake goal by %.1f calories.\n", 
            calorie_intake_difference * -1);
        }
        else {
            printf("You missed your calorie intake goal by %.1f calories.\n", calorie_intake_difference);
        }
        
        // Increment day counter
        day++;
    }
    
    return 0;
}
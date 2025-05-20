//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
                
        int maxCalories = 5000;
        int burntCalories = 0;
        int foodConsumed = 0;
        time_t t;
        
        //initialize random seed
        srand((unsigned) time(&t));
        
        printf("Welcome to the post-apocalyptic fitness tracker!\n");
        
        while(burntCalories < maxCalories && foodConsumed < maxCalories){

            char activity[20];
            int caloriesBurnt;
            int caloriesConsumed;

            printf("Enter your activity: ");
            scanf("%s", activity);

            //calculate burnt calories for activity
            caloriesBurnt = rand() % 500;
            burntCalories += caloriesBurnt;
            printf("You burnt %d calories!\n", caloriesBurnt);

            //calculate consumed calories for food
            printf("Enter consumed calories: ");
            scanf("%d", &caloriesConsumed);
            foodConsumed += caloriesConsumed;
            printf("You have consumed %d calories.\n", caloriesConsumed);

            //show progress
            printf("\nCurrent burnt calories: %d\n", burntCalories);
            printf("Current consumed calories: %d\n", foodConsumed);

            printf("-------------------------------------\n");
            printf("\n");
        }
        
        if(burntCalories >= maxCalories){
            printf("Congratulations! You have successfully burnt %d calories.\n", burntCalories);
        } else if(foodConsumed >= maxCalories){
            printf("You have consumed %d calories. This is not going to end well in a post-apocalyptic world. RIP.\n", foodConsumed);
        }
        
        return 0;
}
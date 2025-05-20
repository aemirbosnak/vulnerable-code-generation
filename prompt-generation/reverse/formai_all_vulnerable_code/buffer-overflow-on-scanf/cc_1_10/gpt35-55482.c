//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate random number
int generateRandom(int min, int max){
    int num;
    if(min < 0 || max < 0){
        printf("Error: Minimum and maximum cannot be negative!\n");
        num = -1;
    }
    else if(max < min){
        printf("Error: Maximum cannot be less than minimum!\n");
        num = -1;
    }
    else{
        num = (rand() % (max - min + 1)) + min;
    }
    return num;
}

int main(){
    srand(time(NULL)); //Seed for random number generation
    
    int age, height, weight, minHeartRate, maxHeartRate, targetHeartRate;
    char gender, choice;
    
    printf("Welcome to the C Fitness Tracker!\n");
    
    printf("Please enter your age: ");
    scanf("%d", &age);
    
    printf("Please enter your height (in cm): ");
    scanf("%d", &height);
    
    printf("Please enter your weight (in kg): ");
    scanf("%d", &weight);
    
    printf("Please enter your gender (M/F): ");
    scanf(" %c", &gender);
    
    //Calculate minimum and maximum heart rate
    if(gender == 'M' || gender == 'm'){
        minHeartRate = 220 - age;
        maxHeartRate = 205 + (0.5 * age);
    }
    else if(gender == 'F' || gender == 'f'){
        minHeartRate = 226 - age;
        maxHeartRate = 190 + (0.5 * age);
    }
    else{
        printf("Error: Invalid gender entered!\n");
        return 0;
    }
    
    //Display the minimum and maximum heart rate
    printf("Your minimum heart rate should be %d bpm and your maximum heart rate should be %d bpm\n", minHeartRate, maxHeartRate);
    
    //Calculate target heart rate range
    targetHeartRate = generateRandom(minHeartRate, maxHeartRate);
    
    //Display target heart rate range
    printf("Your target heart rate range is %d bpm to %d bpm\n", targetHeartRate, targetHeartRate+30);
    
    //Ask if user wants to calculate again
    printf("Would you like to calculate again? (Y/N): ");
    scanf(" %c", &choice);
    
    while(choice == 'Y' || choice == 'y'){
        printf("\n");
        printf("Please enter your age: ");
        scanf("%d", &age);
    
        printf("Please enter your height (in cm): ");
        scanf("%d", &height);
    
        printf("Please enter your weight (in kg): ");
        scanf("%d", &weight);
    
        printf("Please enter your gender (M/F): ");
        scanf(" %c", &gender);
    
        //Calculate minimum and maximum heart rate
        if(gender == 'M' || gender == 'm'){
            minHeartRate = 220 - age;
            maxHeartRate = 205 + (0.5 * age);
        }
        else if(gender == 'F' || gender == 'f'){
            minHeartRate = 226 - age;
            maxHeartRate = 190 + (0.5 * age);
        }
        else{
            printf("Error: Invalid gender entered!\n");
            return 0;
        }
    
        //Display the minimum and maximum heart rate
        printf("Your minimum heart rate should be %d bpm and your maximum heart rate should be %d bpm\n", minHeartRate, maxHeartRate);
    
        //Calculate target heart rate range
        targetHeartRate = generateRandom(minHeartRate, maxHeartRate);
    
        //Display target heart rate range
        printf("Your target heart rate range is %d bpm to %d bpm\n", targetHeartRate, targetHeartRate+30);
    
        //Ask if user wants to calculate again
        printf("Would you like to calculate again? (Y/N): ");
        scanf(" %c", &choice);
    }
    printf("Thank you for using the C Fitness Tracker!\n");
    return 0;
}
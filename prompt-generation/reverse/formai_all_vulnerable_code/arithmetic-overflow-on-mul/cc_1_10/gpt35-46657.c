//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0));

    //Initialize Fitness Level
    int fitnessLevel = rand()%100 + 1;
    printf("Your Fitness Level has been initialized to: %d\n\n", fitnessLevel);

    //Start Fitness Tracker
    printf("Starting Fitness Tracker...\n");
    printf("Enter your current heart rate (BPM): ");
    int heartRate;
    scanf("%d", &heartRate);
    while(heartRate>200){
        printf("Invalid Heart Rate. Please enter again: ");
        scanf("%d", &heartRate);
    }
    printf("Heart Rate Recorded: %d BPM\n", heartRate);

    //Calculate Calories Burned
    float caloriesBurned = ((float)heartRate/150.0)*(float)(fitnessLevel/2);
    printf("Calories Burned: %.2f\n", caloriesBurned);

    //Simulate Zombie Attack
    int hasZombieAttacked = rand()%2;

    if(hasZombieAttacked){
        printf("ALERT: ZOMBIE ATTACK DETECTED!\n");
        printf("Enter the estimated number of zombies: ");
        int zombies;
        scanf("%d", &zombies);
        printf("Processing...\n");

        //Calculate Damage and Health Remaining
        int damage = zombies*(rand()%50 + 1);
        int healthRemaining = fitnessLevel - damage;
        if(healthRemaining<=0){
            printf("GAME OVER - YOU HAVE DIED.");
            return 0;
        }
        else{
            printf("You have taken %d damage. Health Remaining: %d\n", damage, healthRemaining);
        }
    }
    else{
        printf("No Zombie Attack Detected. Keep going!\n");
    }

    //Print Final Fitness Level
    printf("Your Final Fitness Level: %d\n", fitnessLevel);

    return 0;
}
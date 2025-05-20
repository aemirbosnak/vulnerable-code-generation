//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: detailed
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Structure to store the user data
struct User{
    char name[30];
    int age;
    float weight;
    float height;
};

//Structure to store the fitness data
struct Fitness{
    float calories_burnt;
    int steps;
    float distance;
};

int main(){
    
    struct User user;
    struct Fitness fitness;
    int choice;
    FILE *fp;
    fp = fopen("fitness.txt", "a+");
    
    printf("\nWelcome to the Fitness Tracker App!\n");
    
    //Menu
    while(1){
        printf("\n\nMenu:\n");
        printf("1. Enter User Details\n");
        printf("2. Enter Fitness Data\n");
        printf("3. View User Details\n");
        printf("4. View Fitness Data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
                
            case 1:
                fflush(stdin);
                printf("\nEnter Your Name: ");
                fgets(user.name, 30, stdin);
                user.name[strcspn(user.name, "\n")] = 0;
                printf("Enter Your Age: ");
                scanf("%d", &user.age);
                printf("Enter Your Weight(Kg): ");
                scanf("%f", &user.weight);
                printf("Enter Your Height(M): ");
                scanf("%f", &user.height);
                break;
                
            case 2:
                printf("\nEnter Calories Burnt: ");
                scanf("%f", &fitness.calories_burnt);
                printf("Enter Number of Steps: ");
                scanf("%d", &fitness.steps);
                printf("Enter Distance Travelled(Km): ");
                scanf("%f", &fitness.distance);
                //Write data to file
                fprintf(fp, "\nName: %s\nAge: %d\nWeight: %.2fKg\nHeight: %.2fM\nCalories Burnt: %.2f\nSteps: %d\nDistance: %.2fKm\n", user.name, user.age, user.weight, user.height, fitness.calories_burnt, fitness.steps, fitness.distance);
                printf("\nData Saved Successfully!\n");
                break;
                
            case 3:
                printf("\nUser Details:\n");
                printf("Name: %s\n", user.name);
                printf("Age: %d\n", user.age);
                printf("Weight: %.2fKg\n", user.weight);
                printf("Height: %.2fM\n", user.height);
                break;
                
            case 4:
                printf("\nFitness Data:\n");
                //Read data from file and print
                char line[256];
                while(fgets(line, sizeof(line), fp)){
                    printf("%s", line);
                }
                break;
                
            case 5:
                fclose(fp);
                printf("\nThank You for Using the Fitness Tracker App!\n");
                exit(0);
                break;
                
            default:
                printf("\nInvalid Choice! Please Try Again!\n");
        }
    }
    return 0;
}
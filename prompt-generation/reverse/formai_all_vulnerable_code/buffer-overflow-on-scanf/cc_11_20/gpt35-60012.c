//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: random
//Unique Time Travel Simulator
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL)); //seed for random number generation
    int year = 2021; //current year
    int age = 25; //current age
    int choice = 0; //variable to store user's choice
    int travelYear = 0; //variable to store year to time travel
    int travelAge = 0; //variable to store age to time travel
    
    printf("*** Welcome to the Time Travel Simulator ***\n\n");

    printf("You are currently in the year %d and you are %d years old\n\n", year, age);
    
    printf("What year do you want to time travel to? (Enter a year between 1900 to 2100): ");
    scanf("%d", &travelYear);
    
    printf("What age do you want to time travel to? (Enter an age between 0 to 100): ");
    scanf("%d", &travelAge);
    
    //check if user's input is valid
    if(travelYear < 1900 || travelYear > 2100 || travelAge < 0 || travelAge > 100){
        printf("\nInvalid input! Please enter a valid year and age between the given range.\n");
        printf("Exiting the program...\n");
        return 0;
    }
    
    //checking user's choice of year to time travel to
    if(travelYear > year){
        printf("\nYou want to go to the future!\n");
        printf("Are you sure you want to time travel to the year %d? (Enter 1 for Yes, 2 for No): ", travelYear);
        scanf("%d", &choice);
        
        if(choice == 2){
            printf("\nTime travel cancelled! Exiting the program...\n");
            return 0;
        }else{
            int diff = travelYear - year; //calculating difference in years
            age += diff; //adding difference to current age
            year = travelYear; //updating current year
        }
        
    }else if(travelYear < year){
        printf("\nYou want to go to the past!\n");
        printf("Are you sure you want to time travel to the year %d? (Enter 1 for Yes, 2 for No): ", travelYear);
        scanf("%d", &choice);
        
        if(choice == 2){
            printf("\nTime travel cancelled! Exiting the program...\n");
            return 0;
        }else{
            int diff = year - travelYear; //calculating difference in years
            age -= diff; //subtracting difference from current age
            year = travelYear; //updating current year
        }
    }else{
        printf("\nYou are already in the year %d!\n", year);
    }
    
    //checking user's choice of age
    if(travelAge > age){
        printf("\nYou want to be %d years old in the year %d\n", travelAge, year);
        printf("Are you sure you want to time travel to this age? (Enter 1 for Yes, 2 for No): ");
        scanf("%d", &choice);
        
        if(choice == 2){
            printf("\nTime travel cancelled! Exiting the program...\n");
            return 0;
        }else{
            int diff = travelAge - age; //calculating difference in age
            age += diff; //adding difference to current age
        }
        
    }else if(travelAge < age){
        printf("\nYou want to be %d years old in the year %d\n", travelAge, year);
        printf("Are you sure you want to time travel to this age? (Enter 1 for Yes, 2 for No): ");
        scanf("%d", &choice);
        
        if(choice == 2){
            printf("\nTime travel cancelled! Exiting the program...\n");
            return 0;
        }else{
            int diff = age - travelAge; //calculating difference in age
            age -= diff; //subtracting difference from current age
        }
    }else{
        printf("\nYou are already %d years old in the year %d!\n", age, year);
    }
    
    printf("\nTime travel successful!\n");
    printf("You are now in the year %d and you are %d years old\n", year, age);
    printf("Thanks for using our Time Travel Simulator!\n");
    
    return 0;
}
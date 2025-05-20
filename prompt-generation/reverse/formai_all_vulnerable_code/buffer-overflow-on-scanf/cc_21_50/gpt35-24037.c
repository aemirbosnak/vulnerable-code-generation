//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); //set the seed for the random number generator
    
    //prompt the user to enter a year
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter a year you want to travel to (from 1900 to 2100): ");
    int year;
    scanf("%d", &year);
    
    //check if the input year is valid
    if(year < 1900 || year > 2100){
        printf("Invalid year! Please enter a year between 1900 and 2100.");
        return 0;
    }
    
    //generate a random date within the input year
    int month = rand() % 12 + 1;
    int day;
    if(month == 2){ //if it's February, check for leap year
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
            day = rand() % 29 + 1; //leap year, February has 29 days
        }
        else{
            day = rand() % 28 + 1; //not a leap year, February has 28 days
        }
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11){ //if it's April, June, September or November
        day = rand() % 30 + 1; //these months have 30 days
    }
    else{
        day = rand() % 31 + 1; //other months have 31 days
    }
    printf("Your time travel destination is: %d/%d/%d\n", day, month, year);
    
    //simulate the time travel process
    printf("Initializing time travel...\n");
    for(int i = 0; i < 10; i++){
        printf("...");
        sleep(1);
    }
    printf("\nTime travel complete!\n");
    
    //print a message about the current situation
    if(year < 1945){
        printf("You have arrived in a time of great conflict and turmoil, as World War 2 is still ongoing.\n");
    }
    else if(year >= 1945 && year < 1969){
        printf("You have arrived in the aftermath of World War 2, the rebuilding of Europe and the beginning of the Cold War.\n");
    }
    else if(year >= 1969 && year < 1987){
        printf("You have arrived in the late 20th century, during the time of the Vietnam War and the rise of counterculture.\n");
    }
    else if(year >= 1987 && year < 2000){
        printf("You have arrived in the era of technological innovation and the fall of the Berlin Wall.\n");
    }
    else if(year >= 2000 && year < 2010){
        printf("You have arrived in the dawn of the 21st century, a time when terrorism and new technology dominate the world stage.\n");
    }
    else if(year >= 2010 && year <= 2100){
        printf("You have arrived in the future! The world has changed dramatically and you are now in a new and unknown era.\n");
    }
    else{
        printf("Something went wrong with the time travel, as you have ended up in a time where humans do not exist yet!\n");
    }
    
    printf("Enjoy your time travel adventure and don't forget that time is a valuable and limited resource!\n");
    
    return 0;
}
//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Claude Shannon
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
    // declare variables
    char name[20]; 
    int age, lucky_num, fortune_num; 
    
    // prompt user for input
    printf("Welcome to the Automated Fortune Teller! \n");
    printf("Please enter your name: "); 
    scanf("%s", name); 
    printf("Please enter your age: "); 
    scanf("%d", &age); 
    printf("Please enter your lucky number: "); 
    scanf("%d", &lucky_num); 
    
    // generate a random fortune number
    srand(time(NULL)); 
    fortune_num = rand() % 10 + 1; 

    // print out the fortune based on the fortune number
    switch(fortune_num) {
        case 1:
            printf("%s, you will find happiness in unexpected places. \n", name);
            break;
        case 2:
            printf("%s, you will soon receive good news from someone you love. \n", name);
            break;
        case 3:
            printf("%s, a great opportunity for success is heading your way. \n", name);
            break;
        case 4:
            printf("%s, make sure to take care of your health and wellbeing in the coming weeks. \n", name);
            break;
        case 5:
            printf("%s, you will encounter some challenges in the near future, but you will overcome them. \n", name);
            break;
        case 6:
            printf("%s, you will experience a significant change in your life in the next year. \n", name);
            break;
        case 7:
            printf("%s, it's important to trust your instincts when making big decisions. \n", name);
            break;
        case 8:
            printf("%s, you will soon be given an opportunity to pursue a long-held dream. \n", name);
            break;
        case 9:
            printf("%s, try to stay positive and focus on the good in your life during difficult times. \n", name);
            break;
        case 10:
            printf("%s, you will soon make a new friend who will have a big impact on your life. \n", name);
            break;
        default:
            printf("Error: Could not generate fortune. Please try again later. \n");
            return 1;
    }
    
    // print out summary of user input and fortune
    printf("Summary: \n");
    printf("Name: %s \n", name);
    printf("Age: %d \n", age);
    printf("Lucky Number: %d \n", lucky_num);
    printf("Your fortune number is %d. \n", fortune_num);
    
    return 0; 
}
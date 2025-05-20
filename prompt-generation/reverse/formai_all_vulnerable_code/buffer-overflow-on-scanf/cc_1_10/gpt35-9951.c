//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to generate a random number between specified range
int randomRange(int min, int max){
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

//function to get user's input and validate
int getUserInput(){
    int num;
    printf("Enter a number between 1 and 10: ");
    scanf("%d", &num);
    while(num < 1 || num > 10){
        printf("Invalid input! Enter a number between 1 and 10: ");
        scanf("%d", &num);
    }
    return num;
}

//main function
int main(){
    srand(time(NULL));  //initialize random number generator using current time
    int fortuneNum = randomRange(1,10);  //generate a random number as the fortune
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I will predict your future based on the number you choose.\n\n");
    int userNum = getUserInput();  //get user's input and validate
    printf("You have chosen the number %d.\n\n", userNum);
    printf("Analyzing your future...\n\n");
    //display fortune based on the number chosen by user
    switch(userNum){
        case 1:
            printf("Your future looks very bright! Good things are coming your way...\n");
            break;
        case 2:
            printf("You will face some challenges in the near future, but they will make you a stronger person...\n");
            break;
        case 3:
            printf("You will soon meet someone who will change your life forever...\n");
            break;
        case 4:
            printf("Your hard work will pay off soon. Keep going!\n");
            break;
        case 5:
            printf("You will have some unexpected expenses in the coming weeks. Be prepared...\n");
            break;
        case 6:
            printf("There will be some changes in your job that will require you to adapt quickly...\n");
            break;
        case 7:
            printf("You will have an opportunity to travel to a new and exciting place soon...\n");
            break;
        case 8:
            printf("Your family will be a great source of comfort and support in the coming months...\n");
            break;
        case 9:
            printf("You will soon have a chance to pursue a passion or hobby that you've been putting off...\n");
            break;
        case 10:
            printf("Be cautious in your financial decisions over the next few weeks. Don't take unnecessary risks...\n");
            break;
    }
    printf("\nThank you for using the Automated Fortune Teller. Good luck!\n");
    return 0;
}
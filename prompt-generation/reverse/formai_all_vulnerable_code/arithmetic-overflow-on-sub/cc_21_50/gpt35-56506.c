//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main() {
    char name[20];
    int birthYr;
    time_t t;
    srand((unsigned) time(&t));
    
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    
    printf("Hello, %s! Please enter your birth year: ", name);
    scanf("%d", &birthYr);
    
    int age = 2021 - birthYr;
    char sign[20];
    switch(birthYr % 12) {
        case 0: strcpy(sign, "Monkey"); break;
        case 1: strcpy(sign, "Rooster"); break;
        case 2: strcpy(sign, "Dog"); break;
        case 3: strcpy(sign, "Pig"); break;
        case 4: strcpy(sign, "Rat"); break;
        case 5: strcpy(sign, "Ox"); break;
        case 6: strcpy(sign, "Tiger"); break;
        case 7: strcpy(sign, "Rabbit"); break;
        case 8: strcpy(sign, "Dragon"); break;
        case 9: strcpy(sign, "Snake"); break;
        case 10: strcpy(sign, "Horse"); break;
        case 11: strcpy(sign, "Sheep"); break;
    }
    
    printf("\n%s, get ready to hear your fortune!\n", name);
    printf("According to the stars, your sign is the %s.\n", sign);
    printf("Your age is %d.\n", age);
    printf("Your lucky number is %d.\n", rand() % 10 + 1);
    printf("Your lucky color is ");
    switch(rand() % 5) {
        case 0: printf("red.\n"); break;
        case 1: printf("green.\n"); break;
        case 2: printf("blue.\n"); break;
        case 3: printf("yellow.\n"); break;
        case 4: printf("purple.\n"); break;
    }
    
    printf("Your fortune for today is: ");
    switch(rand() % 5) {
        case 0: printf("You will find love today!\n"); break;
        case 1: printf("You will have a successful day at work.\n"); break;
        case 2: printf("You will receive an unexpected gift.\n"); break;
        case 3: printf("You should be cautious of a potential danger.\n"); break;
        case 4: printf("You will have a happy reunion with an old friend.\n"); break;
    }
    
    printf("\nThank you for using the Automated Fortune Teller! Goodbye, %s!\n", name);
    return 0;
}
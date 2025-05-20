//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int main()
{
    srand(time(0));
    int choice;
    char gender[10];
    char name[30];
    int age;
    char zodiac[20];
    char personality[50];
    char future[100];
    printf("Welcome to the Automated Fortune Teller\n");
    printf("Enter your gender (Male/Female): ");
    scanf("%s",gender);
    printf("Enter your name: ");
    scanf("%s",name);
    printf("Enter your age: ");
    scanf("%d",&age);
    printf("Enter your zodiac sign: ");
    scanf("%s",zodiac);
    printf("Enter your personality traits (comma separated): ");
    scanf("%s",personality);
    printf("You are a %s, %d year old %s with %s personality traits.\n",gender,age,zodiac,personality);
    printf("What would you like to know about your future?\n");
    printf("1. Love life\n2. Career\n3. Health\n4. Wealth\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Your love life will be filled with passion and excitement.\n");
            break;
        case 2:
            printf("You will have a successful career and achieve great things.\n");
            break;
        case 3:
            printf("You will enjoy good health and live a long life.\n");
            break;
        case 4:
            printf("You will amass great wealth and live a luxurious life.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    return 0;
}
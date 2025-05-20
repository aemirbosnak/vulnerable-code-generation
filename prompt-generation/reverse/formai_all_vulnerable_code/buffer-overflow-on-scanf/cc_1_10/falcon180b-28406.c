//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int rand_num(int min, int max);

int main()
{
    int choice;
    char name[20];
    int age;
    int lucky_num;

    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\n%s, I sense you are seeking guidance. What would you like to know?\n", name);
    printf("1. Your lucky number\n2. Your future career\n3. Your love life\n4. Your health\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            lucky_num = rand_num(1, 100);
            printf("\n%s, your lucky number is %d!", name, lucky_num);
            break;

        case 2:
            printf("\n%s, I see great things in your future career. You will be successful in whatever you choose to do.\n", name);
            break;

        case 3:
            printf("\n%s, I sense that love is in the air for you. Keep your heart open and you will find your soulmate.\n", name);
            break;

        case 4:
            printf("\n%s, your health is important. Make sure to take care of yourself both physically and mentally.\n", name);
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
    }

    return 0;
}

int rand_num(int min, int max)
{
    int num;
    time_t t;
    srand(time(&t));
    num = rand() % (max - min + 1) + min;
    return num;
}
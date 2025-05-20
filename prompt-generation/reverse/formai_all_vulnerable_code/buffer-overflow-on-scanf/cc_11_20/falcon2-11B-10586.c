//Falcon2-11B DATASET v1.0 Category: Automated Fortune Teller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    int age, gender, profession, luck;
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your age:\n");
    scanf("%d", &age);
    printf("Please enter your gender:\n");
    printf("(1) Male\n(2) Female\n");
    scanf("%d", &gender);
    switch(gender)
    {
        case 1:
            printf("You are a male.\n");
            break;
        case 2:
            printf("You are a female.\n");
            break;
        default:
            printf("Invalid input.\n");
            return 0;
    }
    printf("Please enter your profession:\n");
    printf("(1) Student\n(2) Teacher\n(3) Doctor\n(4) Engineer\n");
    scanf("%d", &profession);
    switch(profession)
    {
        case 1:
            printf("You are a student.\n");
            break;
        case 2:
            printf("You are a teacher.\n");
            break;
        case 3:
            printf("You are a doctor.\n");
            break;
        case 4:
            printf("You are an engineer.\n");
            break;
        default:
            printf("Invalid input.\n");
            return 0;
    }
    printf("Please enter your lucky number:\n");
    scanf("%d", &luck);
    printf("Your lucky number is %d.\n", luck);
    printf("Your age is %d, you are a %s, your profession is %s, and your lucky number is %d.\n", age, gender == 1? "male" : "female", profession == 1? "student" : (profession == 2? "teacher" : (profession == 3? "doctor" : "engineer")), luck);
    return 0;
}
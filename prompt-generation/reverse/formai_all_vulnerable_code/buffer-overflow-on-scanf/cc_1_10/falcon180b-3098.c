//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

char* responses[]={"You will find love soon.","Your relationship will grow stronger.","You will have a romantic encounter today.","Your love life will be full of surprises.","You will have a passionate connection with someone special."};
char* responses2[]={"It's time to let go of the past.","Focus on yourself and your passions.","Love will come when you least expect it.","Be patient and trust the journey.","Believe in yourself and your worth."};

int main()
{
    srand(time(NULL));
    int choice,choice2;
    char name[20];
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s",name);
    printf("\nHello, %s! I am here to guide you through matters of the heart.\n",name);
    printf("Please choose a category:\n");
    printf("1. Love\n2. Career\n3. Health\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("\nLove it is! Please enter your question: ");
            char question[50];
            scanf("%s",question);
            printf("\n\n");
            if(tolower(question[strlen(question)-1])!='?')
            {
                printf("You forgot to end your question with a question mark!\n\n");
                printf("Please try again.\n");
                main();
            }
            else
            {
                int randnum=rand()%5;
                printf("\nThe Automated Fortune Teller has an answer for you:\n");
                printf("%s\n",responses[randnum]);
            }
            break;
        case 2:
            printf("\nCareer it is! Please enter your question: ");
            char question2[50];
            scanf("%s",question2);
            printf("\n\n");
            if(tolower(question2[strlen(question2)-1])!='?')
            {
                printf("You forgot to end your question with a question mark!\n\n");
                printf("Please try again.\n");
                main();
            }
            else
            {
                int randnum2=rand()%5;
                printf("\nThe Automated Fortune Teller has an answer for you:\n");
                printf("%s\n",responses2[randnum2]);
            }
            break;
        case 3:
            printf("\nHealth it is! Please enter your question: ");
            char question3[50];
            scanf("%s",question3);
            printf("\n\n");
            if(tolower(question3[strlen(question3)-1])!='?')
            {
                printf("You forgot to end your question with a question mark!\n\n");
                printf("Please try again.\n");
                main();
            }
            else
            {
                int randnum3=rand()%5;
                printf("\nThe Automated Fortune Teller has an answer for you:\n");
                printf("%s\n",responses2[randnum3]);
            }
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
            main();
    }
    return 0;
}
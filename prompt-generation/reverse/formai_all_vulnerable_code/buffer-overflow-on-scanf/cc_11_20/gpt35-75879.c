//FormAI DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main() {
    char name[20],ans;
    int choice,mark=0,i;
    time_t t;

    printf("Enter your name: ");
    scanf("%s",name);

    printf("\nWelcome to the Online Examination System, %s!\n", name);
 
    printf("\nRules: \n1. There are 10 multiple choice questions.\n2. Each question carries 10 marks.\n3. Answer the questions by typing the corresponding option (a, b, c, or d).\n"); 

    printf("\nAre you ready to start the exam? (Y/N): ");
    scanf(" %c", &ans);

    if(ans=='Y' || ans=='y') {
        printf("\nLet's start the exam!\n");

        srand((unsigned) time(&t));

        for(i=1;i<=10;i++) {
            choice=rand()%4+1;

            printf("\nQuestion %d:\n", i);
        
            switch(choice) {
                case 1:
                    printf("What is the capital of India?\n");
                    printf("a) Delhi\nb) Mumbai\nc) Chennai\nd) Kolkata\n");
                    if(getchar()=='a')
                        mark+=10;
                    break;
                case 2:
                    printf("What is the largest planet in our solar system?\n");
                    printf("a) Mercury\nb) Venus\nc) Jupiter\nd) Saturn\n");
                    if(getchar()=='c')
                        mark+=10;
                    break;
                case 3:
                    printf("Who invented the telephone?\n");
                    printf("a) Thomas Edison\nb) Alexander Graham Bell\nc) Isaac Newton\nd) Albert Einstein\n");
                    if(getchar()=='b')
                        mark+=10;
                    break;
                case 4:
                    printf("Which country won the FIFA World Cup 2018?\n");
                    printf("a) Brazil\nb) Germany\nc) France\nd) Argentina\n");
                    if(getchar()=='c')
                        mark+=10;
                    break;
            }
        }
        printf("\nCongratulations, %s! You have completed the exam!\n", name);
        printf("\nYour final score is %d/100.\n", mark);
    } 
    else {
        printf("\nGoodbye!\n");
        exit(0);
    }
    return 0;
}
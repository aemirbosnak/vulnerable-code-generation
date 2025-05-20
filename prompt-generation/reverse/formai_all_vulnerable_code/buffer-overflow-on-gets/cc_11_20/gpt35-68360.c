//FormAI DATASET v1.0 Category: Online Examination System ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int questions, score=0, ans, i;
    char ch, name[30];

    printf("Welcome to the Online Examination System\n\n");
    printf("Please Enter Your Name: ");
    gets(name);

    printf("\n\nHello %s! Let's Begin\n", name);

    do {
        printf("\nEnter the number of questions(1-10): ");
        scanf("%d", &questions);
    } while(questions<=0 || questions>10);

    printf("\n\n");

    for(i=1; i<=questions; i++) {
        printf("Question #%d\n\n", i);

        switch(i) {
            case 1:
                printf("What is the value of x in the equation 2x + 5 = 15?\n");
                printf("1) x = 2\n");
                printf("2) x = 5\n");
                printf("3) x = 7.5\n");
                printf("4) x = 8\n\n");
                ans = 4;
                break;
            case 2:
                printf("What is the capital of France?\n");
                printf("1) London\n");
                printf("2) Paris\n");
                printf("3) Rome\n");
                printf("4) Madrid\n\n");
                ans = 2;
                break;
            case 3:
                printf("What is the square root of 49?\n");
                printf("1) 4\n");
                printf("2) 7\n");
                printf("3) 9\n");
                printf("4) 11\n\n");
                ans = 2;
                break;
            case 4:
                printf("What is the currency of Japan?\n");
                printf("1) Yen\n");
                printf("2) Dollar\n");
                printf("3) Peso\n");
                printf("4) Euro\n\n");
                ans = 1;
                break;
            case 5:
                printf("What is the largest planet in our solar system?\n");
                printf("1) Neptune\n");
                printf("2) Mars\n");
                printf("3) Jupiter\n");
                printf("4) Saturn\n\n");
                ans = 3;
                break;
            case 6:
                printf("Which country won the FIFA world cup 2018?\n");
                printf("1) Germany\n");
                printf("2) Brazil\n");
                printf("3) France\n");
                printf("4) Argentina\n\n");
                ans = 3;
                break;
            case 7:
                printf("What is the largest mammal on earth?\n");
                printf("1) Elephant\n");
                printf("2) Giraffe\n");
                printf("3) Blue whale\n");
                printf("4) Rhinoceros\n\n");
                ans = 3;
                break;
            case 8:
                printf("What is the atomic number of Oxygen?\n");
                printf("1) 6\n");
                printf("2) 7\n");
                printf("3) 8\n");
                printf("4) 9\n\n");
                ans = 3;
                break;
            case 9:
                printf("What is the hottest planet in our solar system?\n");
                printf("1) Venus\n");
                printf("2) Mars\n");
                printf("3) Neptune\n");
                printf("4) Mercury\n\n");
                ans = 1;
                break;
            case 10:
                printf("What is the smallest country in the world?\n");
                printf("1) Germany\n");
                printf("2) Australia\n");
                printf("3) Vatican City\n");
                printf("4) Japan\n\n");
                ans = 3;
                break;
        }

        printf("Enter Your Answer: ");
        scanf("%d", &ch);

        if(ch == ans) {
            printf("\nCorrect Answer!\n");
            score++;
        } else {
            printf("\nWrong Answer!\n");
            printf("The Correct Answer is %d\n", ans);
        }
    }

    printf("\n\n%s, Your score is %d of %d", name, score, questions);

    if(score >= (questions/2) && score < questions) {
        printf("\n\nWell Done! You have passed\n");
    } else if(score == questions) {
        printf("\n\nCongratulations! You have passed with flying colors\n");
    } else {
        printf("\n\nSorry! You have not passed. Please Try Again\n");
    }

    return 0;
}
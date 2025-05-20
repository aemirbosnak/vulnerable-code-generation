//FormAI DATASET v1.0 Category: Math exercise ; Style: ephemeral
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand(time(NULL));
    
    printf("Welcome to the Math Game! \nCan you answer this question?\n");
    
    double num1 = rand()/(double)RAND_MAX;
    double num2 = rand()/(double)RAND_MAX;
    
    int operator = rand()%4;

    switch(operator){
        case 0:
            printf("What is the value of %.2lf + %.2lf?\n", num1, num2);
            double ans = num1 + num2;
            double userAns;
            scanf("%lf", &userAns);
            if(fabs(ans - userAns) < 0.0001){
                printf("Correct! Nice job! \n");
            }else{
                printf("Sorry, that's not correct. The answer is %.2lf\n", ans);
            }
            break;
        case 1:
            printf("What is the value of %.2lf - %.2lf?\n", num1, num2);
            ans = num1 - num2;
            scanf("%lf", &userAns);
            if(fabs(ans - userAns) < 0.0001){
                printf("Correct! Nice job! \n");
            }else{
                printf("Sorry, that's not correct. The answer is %.2lf\n", ans);
            }
            break;
        case 2:
            printf("What is the value of %.2lf * %.2lf?\n", num1, num2);
            ans = num1 * num2;
            scanf("%lf", &userAns);
            if(fabs(ans - userAns) < 0.0001){
                printf("Correct! Nice job! \n");
            }else{
                printf("Sorry, that's not correct. The answer is %.2lf\n", ans);
            }
            break;
        case 3:
            if(num2 == 0){
                num2 += 0.1;
            }
            printf("What is the value of %.2lf / %.2lf?\n", num1, num2);
            ans = num1 / num2;
            scanf("%lf", &userAns);
            if(fabs(ans - userAns) < 0.0001){
                printf("Correct! Nice job! \n");
            }else{
                printf("Sorry, that's not correct. The answer is %.2lf\n", ans);
            }
            break;
        default:
            printf("Oops, something went wrong. Try again later. \n");
            break;
    }

    return 0;
}
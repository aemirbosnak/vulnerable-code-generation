//FormAI DATASET v1.0 Category: Arithmetic ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0));
    int a = rand()%1000 + 1;
    int b = rand()%1000 + 1;
    int sum=a+b;
    printf("Let's test our arithmetic skills!\n");
    printf("What is %d plus %d?\n", a, b);
    int ans;
    scanf("%d",&ans);
    if(ans==sum){
        printf("Wow, you are quite good at this!\n");
    }else{
        printf("Oh no.. The answer is %d\n", sum);
        printf("But don't worry!\n");
        printf("Here's another question: What is %d minus %d?\n", a, b);
        int ans2;
        scanf("%d",&ans2);
        if(ans2==a-b){
            printf("You got it! You're better at this than I thought\n");
        }else{
            printf("Hmm.. that's not quite right. The answer is %d\n", a-b);
            printf("Well, let's try something new. Have you heard of MOD? No? Well it's okay, let me explain\n");
            printf("MOD gives you the remainder after dividing two numbers.\n");
            printf("For example, 10 MOD 3 is 1, because when you divide 10 by 3, you get a remainder of 1.\n");
            printf("Now, what is %d MOD %d?\n", sum, b);
            int ans3;
            scanf("%d",&ans3);
            if(ans3==sum%b){
                printf("Impressive! You picked that up quickly!\n");
            }else{
                printf("Oops.. the answer is %d\n", sum%b);
                printf("But wait, let's try one more question!\n");
                printf("What is %d multiplied by %d?\n", a, b);
                int ans4;
                scanf("%d", &ans4);
                if(ans4==a*b){
                    printf("Amazing! You got it right!\n");
                }else{
                    printf("Haha.. sorry that's wrong. The correct answer is %d\n", a*b);
                    printf("Let's finish this off with one final question. What is %d divided by %d?\n", sum, a);
                    int ans5;
                    scanf("%d", &ans5);
                    if(ans5==sum/a){
                        printf("Yay! That's the right answer!\n");
                        printf("Congratulations, you have officially passed the Arithmetic Challenge!\n");
                    }else{
                        printf("Oh no.. the correct answer is %d.\n", sum/a);
                        printf("Sorry you didn't pass the Arithmetic Challenge, better luck next time!\n");
                    }
                }
            }
        }
    }
    return 0;
}
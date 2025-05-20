//FormAI DATASET v1.0 Category: Math exercise ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int n1, n2, result, ans, level, score = 0;
    char choice;
    printf("Welcome to the Math Quiz Game!\n\n");

    do{
        printf("Enter the difficulty level [1(Easy) 2(Medium) 3(Hard)]: ");
        scanf("%d", &level);
        srand(time(NULL));
        if(level == 1){
            n1 = rand() % 10;
            n2 = rand() % 10;
        }
        else if(level == 2){
            n1 = rand() % 50;
            n2 = rand() % 50;
        }
        else if(level == 3){
            n1 = rand() % 100;
            n2 = rand() % 100;
        }
        else{
            printf("\nInvalid option! Please enter again.\n");
            continue;
        }

        result = n1 + n2;
        printf("\nWhat is the result of %d + %d? ", n1, n2);
        scanf("%d", &ans);

        if(ans == result){
            printf("\nCongratulations, you got it right!\n");
            score++;
        }
        else{
            printf("\nOops, the correct answer is %d.\n", result);
        }

        printf("\nDo you want to play again? [Y/N]: ");
        scanf(" %c", &choice);

    }while(choice == 'Y' || choice == 'y');

    printf("\nFinal score: %d\n\nThank you for playing the Math Quiz Game!\n", score);

    return 0;
}
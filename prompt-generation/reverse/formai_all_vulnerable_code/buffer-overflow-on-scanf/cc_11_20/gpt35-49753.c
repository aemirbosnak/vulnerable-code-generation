//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_question(int ques)
{
    switch(ques)
    {
        case 1:
            printf("\n\nWhat is the symbol of the element Sodium? ");
            break;
        case 2:
            printf("\n\nWhat is the atomic number of the element Chromium? ");
            break;
        case 3:
            printf("\n\nWhat is the full name of the element Ag? ");
            break;
        case 4:
            printf("\n\nWhat is the chemical symbol for the element Xenon? ");
            break;
        case 5:
            printf("\n\nWhat is the period of the element Au? ");
            break;
        case 6:
            printf("\n\nWhat is the group number of the element Iron? ");
            break;
        case 7:
            printf("\n\nWhat is the name of the element with atomic number 50? ");
            break;
        case 8:
            printf("\n\nWhat is the valency of the element Magnesium? ");
            break;
        case 9:
            printf("\n\nWhat is the melting point of the element Mercury? ");
            break;
        case 10:
            printf("\n\nWhat is the boiling point of the element Sulfur? ");
            break;
        default:
            printf("\n\nOops! There seems to be an error! Please try again later.");
            break;
    }
}

int main()
{
    char ans[20];
    int ques = 1, score = 0;
    
    printf("Welcome to the Cryptic Periodic Table Quiz!\n\n");
    printf("In this quiz, you will be given a series of questions about the elements in the periodic table.\n");
    printf("You will have to answer these questions by typing in the correct answers in a cryptic manner.\n");
    printf("Let's begin!\n");
    
    while(ques <= 10)
    {
        print_question(ques);
        scanf("%s", ans);
        
        switch(ques)
        {
            case 1:
                if(strcmp(ans, "Na") == 0 || strcmp(ans, "na") == 0)
                {
                    printf("\nCorrect! Sodium has a chemical symbol Na.\n");
                    score++;
                }
                else
                {
                    printf("\nIncorrect! Sodium has a chemical symbol Na.\n");
                }
                break;
            case 2:
                if(strcmp(ans, "24") == 0)
                {
                    printf("\nCorrect! Chromium has an atomic number of 24.\n");
                    score++;
                }
                else
                {
                    printf("\nIncorrect! Chromium has an atomic number of 24.\n");
                }
                break;
            case 3:
                if(strcmp(ans, "Silver") == 0 || strcmp(ans, "silver") == 0)
                {
                    printf("\nCorrect! The full name of Ag is Silver.\n");
                    score++;
                }
                else
                {
                    printf("\nIncorrect! The full name of Ag is Silver.\n");
                }
                break;
            case 4:
                if(strcmp(ans, "Xe") == 0 || strcmp(ans, "xe") == 0)
                {
                    printf("\nCorrect! Xenon has a chemical symbol Xe.\n");
                    score++;
                }
                else
                {
                    printf("\nIncorrect! Xenon has a chemical symbol Xe.\n");
                }
                break;
            case 5:
                if(strcmp(ans, "6") == 0)
                {
                    printf("\nCorrect! Gold is in period 6.\n");
                    score++;
                }
                else
                {
                    printf("\nIncorrect! Gold is in period 6.\n");
                }
                break;
            case 6:
                if(strcmp(ans, "8") == 0)
                {
                    printf("\nCorrect! Iron is in group 8.\n");
                    score++;
                }
                else
                {
                    printf("\nIncorrect! Iron is in group 8.\n");
                }
                break;
            case 7:
                if(strcmp(ans, "Tin") == 0 || strcmp(ans, "tin") == 0)
                {
                    printf("\nCorrect! The element with atomic number 50 is Tin.\n");
                    score++;
                }
                else
                {
                    printf("\nIncorrect! The element with atomic number 50 is Tin.\n");
                }
                break;
            case 8:
                if(strcmp(ans, "2") == 0)
                {
                    printf("\nCorrect! Magnesium has a valency of 2.\n");
                    score++;
                }
                else
                {
                    printf("\nIncorrect! Magnesium has a valency of 2.\n");
                }
                break;
            case 9:
                if(strcmp(ans, "234") == 0)
                {
                    printf("\nCorrect! The melting point of Mercury is 234 K.\n");
                    score++;
                }
                else
                {
                    printf("\nIncorrect! The melting point of Mercury is 234 K.\n");
                }
                break;
            case 10:
                if(strcmp(ans, "718") == 0)
                {
                    printf("\nCorrect! The boiling point of Sulfur is 718 K.\n");
                    score++;
                }
                else
                {
                    printf("\nIncorrect! The boiling point of Sulfur is 718 K.\n");
                }
                break;
            default:
                printf("\nOops! There seems to be an error! Please try again later.\n");
                break;
        }
        ques++;
    }
    
    printf("\n\nCongratulations! You have completed the Cryptic Periodic Table Quiz!\n");
    printf("Your final score is %d out of 10.\n\n", score);
    return 0;
}
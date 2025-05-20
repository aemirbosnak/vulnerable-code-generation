//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    char name[100];
    int score = 0;
    int choice;char ans;

    //Title
    printf("\n\t\t\tC PERIODIC TABLE QUIZ\n");

    //Asking for name
    printf("\n Enter your name: ");
    scanf("%s", name);

    //Rules
    printf("\nWelcome %s! Let's get started!\n", name);
    printf("\nHere are the rules:\n");
    printf("\n1. You will get 10 questions to answer..");
    printf("\n2. Four options will be given for each question.");
    printf("\n3. Answer by entering the option number (e.g. A, B, C or D).");
    printf("\n4. Every correct answer will fetch you 1 point.");
    printf("\n5. Every wrong answer will reduce your score by 0.25 points.");

    //Quiz Begins
    printf("\n\n Quiz Begins: \n\n");

    //Question 1
    printf("1. What is the symbol of hydrogen?\n");
    printf("A. H\tB. He\n");
    printf("C. Li\tD. Be\n");
    printf("Enter your answer: ");
    scanf(" %c",&ans);
    if(ans=='A' || ans=='a')
    {
        printf("\nCorrect Answer! Note that every correct answer will fetch you 1 point.\n");
        score++;
    }
    else
    {
        printf("\nWrong Answer! Note that every wrong answer will reduce your score by 0.25 points.\n");
        score = score - 0.25;
    }

    //Question 2
    printf("\n2. Who discovered the periodic table?\n");
    printf("A. John Dalton\tB. Dmitri Mendeleev\n");
    printf("C. Antoine Lavoisier\tD. Jons Jakob Berzelius\n");
    printf("Enter your answer: ");
    scanf(" %c",&ans);
    if(ans=='B' || ans=='b')
    {
        printf("\nCorrect Answer!\n");
        score++;
    }
    else
    {
        printf("\nWrong Answer! Note that every wrong answer will reduce your score by 0.25 points.\n");
        score = score - 0.25;
    }

    //Question 3
    printf("\n3. What is the atomic number of iron?\n");
    printf("A. 26\tB. 27\n");
    printf("C. 28\tD. 29\n");
    printf("Enter your answer: ");
    scanf(" %c",&ans);
    if(ans=='A' || ans=='a')
    {
        printf("\nCorrect Answer!\n");
        score++;
    }
    else
    {
        printf("\nWrong Answer! Note that every wrong answer will reduce your score by 0.25 points.\n");
        score = score - 0.25;
    }

    //Question 4
    printf("\n4. What is mercury at room temperature?\n");
    printf("A. Solid\tB. Liquid\n");
    printf("C. Gas\tD. None of these\n");
    printf("Enter your answer: ");
    scanf(" %c",&ans);
    if(ans=='B' || ans=='b')
    {
        printf("\nCorrect Answer!\n");
        score++;
    }
    else
    {
        printf("\nWrong Answer! Note that every wrong answer will reduce your score by 0.25 points.\n");
        score = score - 0.25;
    }

    //Question 5
    printf("\n5. Who discovered the electron?\n");
    printf("A. JJ Thomson\tB. Ernest Rutherford\n");
    printf("C. Niels Bohr\tD. Max Planck\n");
    printf("Enter your answer: ");
    scanf(" %c",&ans);
    if(ans=='A' || ans=='a')
    {
        printf("\nCorrect Answer!\n");
        score++;
    }
    else
    {
        printf("\nWrong Answer! Note that every wrong answer will reduce your score by 0.25 points.\n");
        score = score - 0.25;
    }

    //Question 6
    printf("\n6. Which metal is the best conductor of electricity?\n");
    printf("A. Gold\tB. Iron\n");
    printf("C. Copper\tD. Silver\n");
    printf("Enter your answer: ");
    scanf(" %c",&ans);
    if(ans=='D' || ans=='d')
    {
        printf("\nCorrect Answer!\n");
        score++;
    }
    else
    {
        printf("\nWrong Answer! Note that every wrong answer will reduce your score by 0.25 points.\n");
        score = score - 0.25;
    }

    //Question 7
    printf("\n7. How many elements are in the periodic table?\n");
    printf("A. 92\tB. 108\n");
    printf("C. 118\tD. 150\n");
    printf("Enter your answer: ");
    scanf(" %c",&ans);
    if(ans=='C' || ans=='c')
    {
        printf("\nCorrect Answer!\n");
        score++;
    }
    else
    {
        printf("\nWrong Answer! Note that every wrong answer will reduce your score by 0.25 points.\n");
        score = score - 0.25;
    }

    //Question 8
    printf("\n8. What is the molecular formula of ethanol?\n");
    printf("A. C2H5OH\tB. CH3COOH\n");
    printf("C. CH4O\tD. C2H6O\n");
    printf("Enter your answer: ");
    scanf(" %c",&ans);
    if(ans=='A' || ans=='a')
    {
        printf("\nCorrect Answer!\n");
        score++;
    }
    else
    {
        printf("\nWrong Answer! Note that every wrong answer will reduce your score by 0.25 points.\n");
        score = score - 0.25;
    }

    //Question 9
    printf("\n9. Who proposed the concept of oxidation and reduction?\n");
    printf("A. Robert Boyle\tB. Antoine Lavoisier\n");
    printf("C. JJ Thomson\tD. Max Planck\n");
    printf("Enter your answer: ");
    scanf(" %c",&ans);
    if(ans=='B' || ans=='b')
    {
        printf("\nCorrect Answer!\n");
        score++;
    }
    else
    {
        printf("\nWrong Answer! Note that every wrong answer will reduce your score by 0.25 points.\n");
        score = score - 0.25;
    }

    //Question 10
    printf("\n10. What is the chemical formula for water?\n");
    printf("A. H2O\tB. CO2\n");
    printf("C. NaCl\tD. HCl\n");
    printf("Enter your answer: ");
    scanf(" %c",&ans);
    if(ans=='A' || ans=='a')
    {
        printf("\nCorrect Answer!\n");
        score++;
    }
    else
    {
        printf("\nWrong Answer! Note that every wrong answer will reduce your score by 0.25 points.\n");
        score = score - 0.25;
    }

    //Final Score Calculation
    printf("\n\n %s, your final score is: %d\n",name,score);

    //Result
    if(score < 5)
    {
        printf("\nSorry %s, You are not eligible for Certificate.\n", name);
    }
    else if(score < 8)
    {
        printf("\nCongratulations %s! You are eligible for Bronze Certificate.\n", name);
    }
    else if(score < 10)
    {
        printf("\nCongratulations %s!! You are eligible for Silver Certificate.\n", name);
    }
    else
    {
        printf("\nCongratulations %s!!! You are eligible for Gold Certificate.\n", name);
    }

    return 0;
}
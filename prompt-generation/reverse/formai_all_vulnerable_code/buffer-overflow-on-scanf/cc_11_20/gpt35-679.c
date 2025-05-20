//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int count=0;
    char choice;
    int answer;

    srand(time(NULL));  //Random seed initialization
    
    printf("\nWelcome to the C Periodic Table Quiz.\n");
    printf("Answer the multiple choice questions to test your knowledge.\n");
    printf("Ready to begin? (y/n) ");
    scanf("%c", &choice);

    while(choice=='y'||choice=='Y')
    {
        int atomic_number = rand() % 118 + 1;
        int question_num = rand() % 3 + 1;

        switch(question_num)
        {
            case 1: printf("\nWhat is the symbol for the element with atomic number %d?\n",atomic_number);
                    printf("a) H\tb) He\tc) Li\td) Be\n");
                    printf("Answer (a/b/c/d): ");
                    scanf(" %c", &choice);
                    answer = (choice=='b'||choice=='B') ? 1 : 0;
                    break;

            case 2: printf("\nWhat is the name for the element with atomic number %d?\n",atomic_number);
                    printf("a) Carbon\tb) Iron\tc) Sodium\td) Potassium\n");
                    printf("Answer (a/b/c/d): ");
                    scanf(" %c", &choice);
                    answer = (choice=='c'||choice=='C') ? 1 : 0;
                    break;

            case 3: printf("\nWhat is the atomic number of the element with symbol 'Cu'?\n");
                    printf("a) 28\tb) 29\tc) 30\td) 31\n");
                    printf("Answer (a/b/c/d): ");
                    scanf(" %c", &choice);
                    answer = (choice=='b'||choice=='B') ? 1 : 0;
                    break;

            default: answer=0;  //Invalid option selected
        }

        if(answer)
        {
            printf("\nCorrect answer!\n");
            count++;
        }
        else
        {
            printf("\nWrong answer! The correct answer was %c)\n", (question_num==1)?'b':((question_num==2)?'c':'b'));
        }

        printf("\nDo you want to continue? (y/n)");
        scanf(" %c", &choice);
    }

    printf("\nYou scored %d points. Thanks for playing!\n",count);

    return 0;
}
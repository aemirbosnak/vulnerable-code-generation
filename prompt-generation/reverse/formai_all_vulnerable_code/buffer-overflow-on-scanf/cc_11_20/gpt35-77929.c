//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int score = 0;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int atomic_number = rand() % 118 + 1;
        int correct_answer = 0;
        int user_answer = 0;
        
        printf("\nQuestion %d: What element has atomic number %d?\n", i+1, atomic_number);
        
        switch(atomic_number)
        {
            case 1:
                printf("a) Hydrogen\nb) Helium\nc) Lithium\nd) Beryllium\n");
                correct_answer = 'a';
                break;
            case 2:
                printf("a) Helium\nb) Hydrogen\nc) Lithium\nd) Beryllium\n");
                correct_answer = 'a';
                break;
            case 3:
                printf("a) Lithium\nb) Beryllium\nc) Boron\nd) Carbon\n");
                correct_answer = 'a';
                break;
            case 4:
                printf("a) Beryllium\nb) Lithium\nc) Carbon\nd) Nitrogen\n");
                correct_answer = 'a';
                break;
            case 5:
                printf("a) Boron\nb) Carbon\nc) Nitrogen\nd) Oxygen\n");
                correct_answer = 'a';
                break;
            case 6:
                printf("a) Carbon\nb) Boron\nc) Nitrogen\nd) Oxygen\n");
                correct_answer = 'a';
                break;
            case 7:
                printf("a) Nitrogen\nb) Carbon\nc) Oxygen\nd) Fluorine\n");
                correct_answer = 'a';
                break;
            case 8:
                printf("a) Oxygen\nb) Nitrogen\nc) Fluorine\nd) Neon\n");
                correct_answer = 'a';
                break;
            case 9:
                printf("a) Fluorine\nb) Oxygen\nc) Neon\nd) Sodium\n");
                correct_answer = 'a';
                break;
            case 10:
                printf("a) Neon\nb) Fluorine\nc) Sodium\nd) Magnesium\n");
                correct_answer = 'a';
                break;
            //...Continues for all 118 elements
            default:
                printf("Error");
                return 1;
        }
        
        scanf(" %c", &user_answer);
        
        if(user_answer == correct_answer)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect. The correct answer is %c\n", correct_answer);
        }
    }
    printf("\nQuiz complete. You scored %d out of 10.", score);
    return 0;
}
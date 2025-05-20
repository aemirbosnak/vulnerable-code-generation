//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void exam_system()
{
    char ch;
    printf("Enter 'a' to answer a question, 'q' to quit: ");
    scanf(" %c", &ch);

    if (ch == 'a')
    {
        // Get the question number
        int num;
        printf("Enter the question number: ");
        scanf("%d", &num);

        // Answer the question
        switch (num)
        {
            case 1:
                printf("Answer: a\n");
                break;
            case 2:
                printf("Answer: b\n");
                break;
            case 3:
                printf("Answer: c\n");
                break;
            default:
                printf("Invalid question number\n");
                break;
        }

        // Go to the next question
        exam_system();
    }
    else if (ch == 'q')
    {
        // Quit the exam
        printf("Thank you for taking the exam\n");
    }
    else
    {
        // Invalid input
        printf("Invalid input\n");
        exam_system();
    }
}

int main()
{
    exam_system();

    return 0;
}
//FormAI DATASET v1.0 Category: Online Examination System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char user_name[50];
    int option;
    int score = 0;

    printf("Welcome to our C Online Examination System\n");
    printf("Please enter your name to get started: ");
    scanf("%s", user_name);

    printf("Hi %s! Are you ready for the exam?\n", user_name);
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Select an option (1 or 2): ");
    scanf("%d", &option);

    if (option == 1)
    {
        printf("\nGreat! Let's start the exam now.\n");

        printf("\nQuestion 1: What is the size of int in C?\n");
        printf("1. 2 bytes\n");
        printf("2. 4 bytes\n");
        printf("3. 8 bytes\n");
        printf("4. 16 bytes\n");
        printf("Select an option (1, 2, 3 or 4): ");
        scanf("%d", &option);
        if (option == 2)
        {
            score++;
        }

        printf("\nQuestion 2: What is the output of the following code?\n");
        printf("int i = 10;\n");
        printf("printf(\"%%d\", ++i);\n");
        printf("\n");
        printf("1. 10\n");
        printf("2. 11\n");
        printf("3. 12\n");
        printf("4. 0\n");
        printf("Select an option (1, 2, 3 or 4): ");
        scanf("%d", &option);
        if (option == 3)
        {
            score++;
        }

        printf("\nQuestion 3: Which of the following is not a keyword in C?\n");
        printf("1. break\n");
        printf("2. continue\n");
        printf("3. goto\n");
        printf("4. throw\n");
        printf("Select an option (1, 2, 3 or 4): ");
        scanf("%d", &option);
        if (option == 4)
        {
            score++;
        }

        printf("\nQuestion 4: What is the output of the following code?\n");
        printf("int arr[5] = {1, 2, 3, 4, 5};\n");
        printf("printf(\"%%d\", arr[3]);\n");
        printf("\n");
        printf("1. 1\n");
        printf("2. 2\n");
        printf("3. 3\n");
        printf("4. 4\n");
        printf("Select an option (1, 2, 3 or 4): ");
        scanf("%d", &option);
        if (option == 4)
        {
            score++;
        }

        printf("\nQuestion 5: What is the output of the following code?\n");
        printf("int i;\n");
        printf("for(i=0;i<5;i++)\n");
        printf("{\n");
        printf("    printf(\"%%d \", i);\n");
        printf("}\n");
        printf("\n");
        printf("1. 1 2 3 4 5\n");
        printf("2. 0 1 2 3 4\n");
        printf("3. 5 4 3 2 1\n");
        printf("4. None of the above\n");
        printf("Select an option (1, 2, 3 or 4): ");
        scanf("%d", &option);
        if (option == 2)
        {
            score++;
        }

        printf("\nCongratulations %s! You have completed the exam.\n", user_name);
        printf("Your score is: %d/5\n", score);

        if (score >= 3)
        {
            printf("Well done! You have passed the exam.\n");
        }
        else
        {
            printf("Sorry! You have failed the exam.\n");
        }
    }
    else
    {
        printf("\nOkay, take your time. Let us know when you are ready to take the exam.\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    printf("Welcome to the Typing Speed Test \n");
    printf("Type each sentence exactly as written and press enter \n");

    char sentence1[] = "But, soft! what light through yonder window breaks?";
    char sentence2[] = "It is the east, and Juliet is the sun.";
    char sentence3[] = "Arise, fair sun, and kill the envious moon,";
    char sentence4[] = "Who is already sick and pale with grief";

    int correct = 0, incorrect = 0;

    printf("\n %s \n", sentence1);
    clock_t start = clock();
    char response1[100];
    gets(response1);
    clock_t end = clock();
    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken for typing Sentence 1: %f seconds\n", time_taken);

    if(strcmp(response1, sentence1) == 0)
    {
        correct++;
        printf("Correct! \n");
    }
    else
    {
        incorrect++;
        printf("Incorrect! \n");
    }

    printf("\n %s \n", sentence2);
    start = clock();
    char response2[100];
    gets(response2);
    end = clock();
    time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken for typing Sentence 2: %f seconds\n", time_taken);

    if(strcmp(response2, sentence2) == 0)
    {
        correct++;
        printf("Correct! \n");
    }
    else
    {
        incorrect++;
        printf("Incorrect! \n");
    }

    printf("\n %s \n", sentence3);
    start = clock();
    char response3[100];
    gets(response3);
    end = clock();
    time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken for typing Sentence 3: %f seconds\n", time_taken);

    if(strcmp(response3, sentence3) == 0)
    {
        correct++;
        printf("Correct! \n");
    }
    else
    {
        incorrect++;
        printf("Incorrect! \n");
    }

    printf("\n %s \n", sentence4);
    start = clock();
    char response4[100];
    gets(response4);
    end = clock();
    time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken for typing Sentence 4: %f seconds\n", time_taken);

    if(strcmp(response4, sentence4) == 0)
    {
        correct++;
        printf("Correct! \n");
    }
    else
    {
        incorrect++;
        printf("Incorrect! \n");
    }

    printf("\nYou typed %d sentences correctly and %d sentences incorrectly! \n", correct, incorrect);

    return 0;
}
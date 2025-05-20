//FormAI DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m, i, j, k;
    char key[100], response[100];
    int score = 0;

    printf("Welcome to the C online examination system!\n");
    printf("How many questions would you like to answer? ");
    scanf("%d", &n);

    printf("Enter the questions and their correct keys:\n");
    char questions[100][100];
    char keys[100][100];

    for (i = 0; i < n; i++)
    {
        printf("%d. ", i + 1);
        fgets(questions[i], 100, stdin);
        fgets(questions[i], 100, stdin);
        printf("Key: ");
        fgets(keys[i], 100, stdin);
        int len = strlen(keys[i]);
        if (keys[i][len - 1] == '\n')
        {
            keys[i][len - 1] = '\0';
        }
    }

    printf("\nYou have %d questions to answer. Good luck!\n", n);

    for (i = 0; i < n; i++)
    {
        printf("%d. %s", i + 1, questions[i]);
        fgets(response, 100, stdin);
        int len = strlen(response);
        if (response[len - 1] == '\n')
        {
            response[len - 1] = '\0';
        }
        if (strcmp(response, keys[i]) == 0)
        {
            score++;
        }
    }

    printf("\nYour score is %d/%d.\n", score, n);
    return 0;
}
//FormAI DATASET v1.0 Category: Online Examination System ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, n, marks=0;
    char ans;
    
    printf("Welcome to the Online Examination System!\n");
    printf("Please enter the number of questions in the exam: ");
    scanf("%d",&n);
    
    char* key = (char*)malloc(n*sizeof(char)); // dynamically allocate memory for answer key

    // prompt user to enter answer key
    printf("Please enter the correct answer for each question (A/B/C/D):\n");
    for(i=0; i<n; i++)
    {
        printf("Question %d: ",i+1);
        scanf(" %c",&key[i]);
    }
    
    // take exam and evaluate marks
    printf("\nLet's take the exam now!\n");
    for(i=0; i<n; i++)
    {
        printf("Question %d: ",i+1);
        scanf(" %c",&ans);
        if(ans == key[i]) // check if answer is correct
        {
            printf("Correct!\n");
            marks++;
        }
        else
        {
            printf("Incorrect! The correct answer is %c.\n",key[i]);
        }
    }
    
    // display final marks and grade
    float percentage = ((float)marks/n)*100;
    printf("\nThank you for taking the online exam!\n");
    printf("Your marks: %d/%d\n",marks,n);
    printf("Percentage: %.2f%%\n",percentage);
    if(percentage >= 90)
    {
        printf("Grade: A\n");
    }
    else if(percentage >= 80)
    {
        printf("Grade: B\n");
    }
    else if(percentage >= 70)
    {
        printf("Grade: C\n");
    }
    else if(percentage >= 60)
    {
        printf("Grade: D\n");
    }
    else
    {
        printf("Grade: F\n");
    }

    free(key); // free allocated memory for answer key

    return 0;
}
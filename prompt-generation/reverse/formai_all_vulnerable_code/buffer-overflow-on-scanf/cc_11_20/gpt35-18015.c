//FormAI DATASET v1.0 Category: Online Examination System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[50], course[20], ans;
    int i, choice, marks=0;
    printf("Enter your name: ");
    fgets(name, 50, stdin);
    printf("Enter your course: ");
    scanf("%s", course);
    printf("\n\t-------------------------");
    printf("\n\t     Online Exam System");
    printf("\n\t-------------------------\n");
    printf("\n\tWelcome %s to the %s Exam\n", name, course);
    printf("\n\tThere are total 5 questions\n");
    printf("\n\tSelect the correct option:\n");
    printf("\n\t1. What is the capital of India?\n");
    printf("\tA. Mumbai           B. Chennai\n");
    printf("\tC. Kolkata          D. New Delhi\n");
    printf("\n\tYour answer (Enter A/B/C/D): ");
    fflush(stdin);
    scanf("%c", &ans);
    if(ans=='D' || ans=='d')
    {
        printf("\n\tCorrect answer!\n");
        marks++;
    }
    else
    {
        printf("\n\tWrong answer!\n");
    }
    printf("\n\t2. What is the full form of RAM?\n");
    printf("\tA. Random Access Memory  B. Read Access Memory\n");
    printf("\tC. Run Access Memory     D. Register Access Memory\n");
    printf("\n\tYour answer (Enter A/B/C/D): ");
    fflush(stdin);
    scanf("%c", &ans);
    if(ans=='A' || ans=='a')
    {
        printf("\n\tCorrect answer!\n");
        marks++;
    }
    else
    {
        printf("\n\tWrong answer!\n");
    }
    printf("\n\t3. Who invented the telephone?\n");
    printf("\tA. Thomas Edison    B. Alexander Graham Bell\n");
    printf("\tC. Michael Faraday  D. Guglielmo Marconi\n");
    printf("\n\tYour answer (Enter A/B/C/D): ");
    fflush(stdin);
    scanf("%c", &ans);
    if(ans=='B' || ans=='b')
    {
        printf("\n\tCorrect answer!\n");
        marks++;
    }
    else
    {
        printf("\n\tWrong answer!\n");
    }
    printf("\n\t4. Who wrote the play 'Julius Caesar'?\n");
    printf("\tA. William Shakespeare     B. John Milton\n");
    printf("\tC. Thomas Hardy             D. Charles Dickens\n");
    printf("\n\tYour answer (Enter A/B/C/D): ");
    fflush(stdin);
    scanf("%c", &ans);
    if(ans=='A' || ans=='a')
    {
        printf("\n\tCorrect answer!\n");
        marks++;
    }
    else
    {
        printf("\n\tWrong answer!\n");
    }
    printf("\n\t5. Who painted the famous painting 'The Last Supper'?\n");
    printf("\tA. Leonardo da Vinci       B. Vincent van Gogh\n");
    printf("\tC. Michelangelo            D. Pablo Picasso\n");
    printf("\n\tYour answer (Enter A/B/C/D): ");
    fflush(stdin);
    scanf("%c", &ans);
    if(ans=='A' || ans=='a')
    {
        printf("\n\tCorrect answer!\n");
        marks++;
    }
    else
    {
        printf("\n\tWrong answer!\n");
    }
    printf("\n\t-------------------------");
    printf("\n\t   Results and Summary");
    printf("\n\t-------------------------\n");
    printf("\n\tName: %s", name);
    printf("\tCourse: %s", course);
    printf("\n\tTotal number of questions: 5");
    printf("\n\tNumber of correct answers: %d", marks);
    printf("\n\tPercentage obtained: %.2f%%", (float)(marks*100)/5);
    printf("\n\n\tThank you for participating in the exam!");
    return 0;
}
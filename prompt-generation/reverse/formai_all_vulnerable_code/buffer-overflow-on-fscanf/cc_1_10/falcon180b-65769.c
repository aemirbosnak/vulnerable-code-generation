//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 1000
#define TRUE 1
#define FALSE 0

//Structure for a question
struct question
{
    char ques[MAX];
    int op1, op2, op3, op4, ans;
};

//Structure for a student
struct student
{
    char name[50];
    int rollno;
    int score;
};

//Function to load questions from a text file
void loadQuestions(struct question questions[], FILE *fp)
{
    int i = 0;
    while(fscanf(fp, "%s %d %d %d %d", questions[i].ques, &questions[i].op1, &questions[i].op2, &questions[i].op3, &questions[i].ans)!= EOF)
    {
        i++;
    }
}

//Function to check if an option is correct
int checkOption(int option, int ans)
{
    if(option == ans)
        return TRUE;
    else
        return FALSE;
}

//Function to evaluate the score of a student
void evaluateScore(struct question questions[], int numQuestions, struct student students[], int numStudents)
{
    int i, j;
    for(i=0; i<numStudents; i++)
    {
        students[i].score = 0;
        for(j=0; j<numQuestions; j++)
        {
            if(checkOption(students[i].rollno % 4 + 1, questions[j].ans))
                students[i].score += 10;
        }
    }
}

//Main function
int main()
{
    FILE *fp;
    struct question questions[MAX];
    struct student students[50];
    int numQuestions, numStudents, i, j;

    //Load questions from file
    fp = fopen("questions.txt", "r");
    if(fp == NULL)
    {
        printf("Error loading questions\n");
        exit(0);
    }
    loadQuestions(questions, fp);
    numQuestions = i;
    fclose(fp);

    //Load students from file
    fp = fopen("students.txt", "r");
    if(fp == NULL)
    {
        printf("Error loading students\n");
        exit(0);
    }
    while(fscanf(fp, "%s %d", students[i].name, &students[i].rollno)!= EOF)
    {
        i++;
    }
    numStudents = i;
    fclose(fp);

    //Evaluate score and print result
    evaluateScore(questions, numQuestions, students, numStudents);
    printf("Online Examination System\n");
    for(i=0; i<numStudents; i++)
    {
        printf("Name: %s\nRoll No.: %d\nScore: %d\n", students[i].name, students[i].rollno, students[i].score);
    }

    return 0;
}
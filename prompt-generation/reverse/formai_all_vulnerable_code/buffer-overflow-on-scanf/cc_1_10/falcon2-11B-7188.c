//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_QUES_LEN 100
#define MAX_ANS_LEN 100

struct question
{
    char question[MAX_QUES_LEN];
    char answer[MAX_ANS_LEN];
};

struct student
{
    char name[MAX_NAME_LEN];
    int marks[20];
};

int main()
{
    struct question questions[] = {
        {"What is the capital of India?", "New Delhi"},
        {"What is the largest country in the world?", "Russia"},
        {"What is the most populous country in the world?", "China"},
        {"What is the largest ocean in the world?", "Pacific Ocean"},
        {"What is the largest river in the world?", "Amazon"},
        {"What is the tallest mountain in the world?", "Mount Everest"},
        {"What is the hottest planet in the solar system?", "Venus"},
        {"What is the coldest planet in the solar system?", "Uranus"},
        {"What is the largest moon in the solar system?", "Ganymede"},
        {"What is the smallest moon in the solar system?", "Deimos"}
    };

    struct student students[] = {
        {"John Doe", {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
        {"Jane Smith", {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
        {"Alice Johnson", {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
        {"Bob Brown", {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}
    };

    int i, j;

    printf("Welcome to the Online Examination System!\n");
    printf("Enter the number of students: ");
    scanf("%d", &i);

    printf("Enter the name of the first student: ");
    scanf("%s", students[0].name);
    printf("Enter the name of the second student: ");
    scanf("%s", students[1].name);
    printf("Enter the name of the third student: ");
    scanf("%s", students[2].name);
    printf("Enter the name of the fourth student: ");
    scanf("%s", students[3].name);

    printf("\nEnter the name of the first question: ");
    scanf("%s", questions[0].question);
    printf("Enter the name of the second question: ");
    scanf("%s", questions[1].question);
    printf("Enter the name of the third question: ");
    scanf("%s", questions[2].question);
    printf("Enter the name of the fourth question: ");
    scanf("%s", questions[3].question);
    printf("Enter the name of the fifth question: ");
    scanf("%s", questions[4].question);
    printf("Enter the name of the sixth question: ");
    scanf("%s", questions[5].question);
    printf("Enter the name of the seventh question: ");
    scanf("%s", questions[6].question);
    printf("Enter the name of the eighth question: ");
    scanf("%s", questions[7].question);
    printf("Enter the name of the ninth question: ");
    scanf("%s", questions[8].question);
    printf("Enter the name of the tenth question: ");
    scanf("%s", questions[9].question);

    for (i = 0; i < 4; i++)
    {
        printf("\nStudent %d's marks: ", i+1);
        for (j = 0; j < 10; j++)
        {
            printf("%d ", students[i].marks[j]);
        }
        printf("\n");
    }

    return 0;
}
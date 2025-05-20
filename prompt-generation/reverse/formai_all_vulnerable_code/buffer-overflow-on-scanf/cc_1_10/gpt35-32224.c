//FormAI DATASET v1.0 Category: Data mining ; Style: active
#include <stdio.h>

#define MAX_STUDENTS 100 // maximum number of students
#define MAX_GRADES 3     // maximum number of grades per student

struct Student // define struct for each student
{
    char name[50];
    int grades[MAX_GRADES];
    float average_grade;
};

void calculate_average_grade(struct Student* s)
{
    float sum = 0;
    for (int i = 0; i < MAX_GRADES; i++)
    {
        sum += s->grades[i];
    }
    s->average_grade = sum / MAX_GRADES;
}

int main()
{
    struct Student students[MAX_STUDENTS];
    int num_students;

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // input student details
    for (int i = 0; i < num_students; i++)
    {
        printf("Enter the name of student %d: ", i+1);
        scanf("%s", students[i].name);

        for (int j = 0; j < MAX_GRADES; j++)
        {
            printf("Enter grade %d for student %d: ", j+1, i+1);
            scanf("%d", &students[i].grades[j]);
        }

        calculate_average_grade(&students[i]);
    }

    // find the student(s) with the highest average grade
    float max_avg_grade = 0;
    for (int i = 0; i < num_students; i++)
    {
        if (students[i].average_grade > max_avg_grade)
        {
            max_avg_grade = students[i].average_grade;
        }
    }

    printf("\nStudent(s) with the highest average grade:\n");
    for (int i = 0; i < num_students; i++)
    {
        if (students[i].average_grade == max_avg_grade)
        {
            printf("%s\n", students[i].name);
        }
    }

    return 0;
}
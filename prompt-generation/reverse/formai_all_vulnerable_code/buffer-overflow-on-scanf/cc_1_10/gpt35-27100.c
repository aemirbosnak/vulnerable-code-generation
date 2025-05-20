//FormAI DATASET v1.0 Category: Database simulation ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student
{
    char name[20];
    int roll_no;
    float marks;
};

void display(struct Student s)
{
    printf("\n%s\t%d\t%.2f", s.name, s.roll_no, s.marks);
}

int main()
{
    int choice;
    int num_of_students = 0;
    char next_operation = 'y';
    struct Student *students = NULL;

    while (next_operation == 'y')
    {
        printf("\n1. Add student data");
        printf("\n2. Display student data");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                num_of_students++;
                students = (struct Student *)realloc(students, num_of_students * sizeof(struct Student));

                printf("\nEnter name of student %d: ", num_of_students);
                scanf("%s", students[num_of_students-1].name);

                printf("Enter roll number of student %d: ", num_of_students);
                scanf("%d", &students[num_of_students-1].roll_no);

                printf("Enter marks of student %d: ", num_of_students);
                scanf("%f", &students[num_of_students-1].marks);

                break;

            case 2:
                printf("\nName\tRoll No\tMarks");
                for (int i = 0; i < num_of_students; i++)
                {
                    display(students[i]);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid input.");
        }

        printf("\nDo you want to perform another operation? (y/n): ");
        fflush(stdin);
        scanf("%c", &next_operation);
    }

    free(students);

    return 0;
}
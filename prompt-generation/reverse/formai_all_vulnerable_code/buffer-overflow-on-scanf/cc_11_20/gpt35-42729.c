//FormAI DATASET v1.0 Category: Online Examination System ; Style: satisfied
#include<stdio.h>

struct student		//Defining a student structure to store student details
{
    char name[50];
    int roll_no;
    int marks[5];
    int total_marks;
};

int main()
{
    int n, i, j, choice, count=0, total_stu=0;
    struct student stu[100];		//Creating an array of student structures to store multiple student details
    do						//Loop for choosing an operation until user closes the program
    {
        printf("\n\n\tMenu\n1. Add Student\n2. Display Students\n3. Check Results\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:			//Add student details
                printf("\nEnter the number of students: ");
                scanf("%d", &n);
                total_stu+=n;	
                for(i=count; i<total_stu; i++)
                {
                    printf("\nEnter details for student %d:\n", i+1);
                    printf("\tName: ");
                    getchar();
                    fgets(stu[i].name, sizeof(stu[i].name), stdin);
                    printf("\tRoll Number: ");
                    scanf("%d", &stu[i].roll_no);
                    printf("\tMarks obtained in 5 subjects: ");
                    for(j=0; j<5; j++)
                        scanf("%d", &stu[i].marks[j]);
                    stu[i].total_marks=0;
                    for(j=0; j<5; j++)
                        stu[i].total_marks+=stu[i].marks[j];		//Calculate total marks for student
                }
                count+=n;
                break;
            case 2:			//Display student details
                printf("\n\n\t\t\tStudent Details\n");
                printf("------------------------------------------------------------------------------------------\n");
                printf("|\tRoll No\t|\t  Name\t\t|\tSubject Marks\t|\tTotal Marks\t|\n");
                printf("------------------------------------------------------------------------------------------\n");
                for(i=0; i<count; i++)
                {
                    printf("|\t%d\t|\t%-16s|\t", stu[i].roll_no, stu[i].name);
                    for(j=0; j<5; j++)
                        printf("%d ", stu[i].marks[j]);
                    printf("\t\t|\t%d\t|\n", stu[i].total_marks);
                }
                printf("------------------------------------------------------------------------------------------\n");
                break;
            case 3:			//Check results
                printf("\n\n\t\tResult Analysis\n");
                printf("------------------------------------------------------------------------------------------\n");
                printf("|\tRoll No\t|\t  Name\t\t|\tSubject Marks\t|\tTotal Marks\t|\tResult\t|\n");
                printf("------------------------------------------------------------------------------------------\n");
                for(i=0; i<count; i++)
                {
                    printf("|\t%d\t|\t%-16s|\t", stu[i].roll_no, stu[i].name);
                    for(j=0; j<5; j++)
                        printf("%d ", stu[i].marks[j]);
                    printf("\t\t|\t%d\t|\t", stu[i].total_marks);
                    if(stu[i].total_marks>=200)
                        printf("Pass\t|\n");
                    else
                        printf("Fail\t|\n");
                }
                printf("------------------------------------------------------------------------------------------\n");
                break;
            case 4:			//Exit program
                printf("\nExiting program...\n");
                break;
            default:			//Invalid choice
                printf("\nInvalid choice! Choose a number from 1 to 4.\n");
        }
    }while(choice!=4);		//Loop until user chooses to exit
    return 0;
}
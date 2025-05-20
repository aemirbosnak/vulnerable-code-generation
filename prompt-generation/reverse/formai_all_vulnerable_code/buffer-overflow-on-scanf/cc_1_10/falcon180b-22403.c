//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct student
{
    int id;
    char name[50];
    char course[50];
    int age;
    float marks;
};

void add_student(struct student *s)
{
    FILE *fp;
    fp=fopen("database.txt","a");
    fprintf(fp,"%d\t%s\t%s\t%d\t%.2f\n",s->id,s->name,s->course,s->age,s->marks);
    fclose(fp);
    printf("\nStudent added successfully!");
}

void view_database()
{
    FILE *fp;
    char ch;
    fp=fopen("database.txt","r");
    while((ch=fgetc(fp))!=EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
}

void search_student(int id)
{
    FILE *fp;
    struct student s;
    fp=fopen("database.txt","r");
    while(fscanf(fp,"%d\t%s\t%s\t%d\t%.2f\n",&s.id,s.name,s.course,&s.age,&s.marks)!=EOF)
    {
        if(s.id==id)
        {
            printf("\nName: %s\nCourse: %s\nAge: %d\nMarks: %.2f",s.name,s.course,s.age,s.marks);
        }
    }
    fclose(fp);
}

void main()
{
    int choice,id;
    struct student s;

    while(1)
    {
        printf("\n1.Add student\n2.View database\n3.Search student\n4.Exit");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter student ID:");
                scanf("%d",&id);
                printf("\nEnter student name:");
                scanf("%s",s.name);
                printf("\nEnter student course:");
                scanf("%s",s.course);
                printf("\nEnter student age:");
                scanf("%d",&s.age);
                printf("\nEnter student marks:");
                scanf("%f",&s.marks);
                add_student(&s);
                break;

            case 2:
                view_database();
                break;

            case 3:
                printf("\nEnter student ID to search:");
                scanf("%d",&id);
                search_student(id);
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }
}
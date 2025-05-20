//FormAI DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>

struct student{
    char name[20];
    int rollno;
    char branch[20];
    float cgpa;
};

int main()
{
    struct student s;
    FILE *fp;

    fp=fopen("Students.txt","wb");

    if(fp==NULL)
    {
        printf("Error opening file");
    }
    else
    {
        printf("Enter Student Name: ");
        scanf("%s",s.name);

        printf("Enter Roll No.: ");
        scanf("%d",&s.rollno);

        printf("Enter Branch: ");
        scanf("%s",s.branch);

        printf("Enter CGPA: ");
        scanf("%f",&s.cgpa);

        fwrite(&s,sizeof(s),1,fp);

        printf("Data successfully written to file\n");

        fclose(fp);
    }

    fp=fopen("Students.txt","rb");

    if(fp==NULL)
    {
        printf("Error opening file");
    }
    else
    {
        printf("\nReading Data from file:\n");
        fread(&s,sizeof(s),1,fp);

        printf("\nStudent Name: %s",s.name);
        printf("\nRoll No.: %d",s.rollno);
        printf("\nBranch: %s",s.branch);
        printf("\nCGPA: %f",s.cgpa);

        fclose(fp);
    }

    return 0;
}
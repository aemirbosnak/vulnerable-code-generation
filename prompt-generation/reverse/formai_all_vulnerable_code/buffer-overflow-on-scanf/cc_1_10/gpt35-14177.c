//FormAI DATASET v1.0 Category: Database querying ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student 
{
    char name[50];
    int age;
    int id;
    float gpa;
};

void insertToDB(struct student s)
{
    FILE *fp;
    fp = fopen("database.txt", "a");
    fprintf(fp, "%s %d %d %.2f\n", s.name, s.age, s.id, s.gpa);
    fclose(fp);
}

void readFromDB()
{
    FILE *fp;
    fp = fopen("database.txt", "r");
    struct student s;
    while(fscanf(fp, "%s %d %d %f", s.name, &s.age, &s.id, &s.gpa) == 4)
    {
        printf("Name: %s, Age: %d, ID: %d, GPA: %.2f\n", s.name, s.age, s.id, s.gpa);
    }
    fclose(fp);
}

void searchById(int id)
{
    FILE *fp;
    fp = fopen("database.txt", "r");
    struct student s;
    while(fscanf(fp, "%s %d %d %f", s.name, &s.age, &s.id, &s.gpa) == 4)
    {
        if(s.id == id)
        {
            printf("Name: %s, Age: %d, ID: %d, GPA: %.2f\n", s.name, s.age, s.id, s.gpa);
            return;
        }
    }
    printf("No student found with ID %d\n", id);
    fclose(fp);
}

void searchByName(char* name)
{
    FILE *fp;
    fp = fopen("database.txt", "r");
    struct student s;
    while(fscanf(fp, "%s %d %d %f", s.name, &s.age, &s.id, &s.gpa) == 4)
    {
        if(strcmp(s.name, name) == 0)
        {
            printf("Name: %s, Age: %d, ID: %d, GPA: %.2f\n", s.name, s.age, s.id, s.gpa);
        }
    }
    fclose(fp);
}

int main()
{
    int choice;
    do 
    {
        printf("\n-- Menu --\n");
        printf("1. Insert a new student record\n");
        printf("2. Read all student records\n");
        printf("3. Search for a student by ID\n");
        printf("4. Search for a student by name\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                printf("\nEnter the following details of the student:\n");
                struct student s;
                printf("Name: ");
                scanf("%s", s.name);
                printf("Age: ");
                scanf("%d", &s.age);
                printf("ID: ");
                scanf("%d", &s.id);
                printf("GPA: ");
                scanf("%f", &s.gpa);
                insertToDB(s);
                printf("\nNew record inserted successfully!\n\n");
                break;
            }
            case 2:
            {
                printf("\nAll student records:\n");
                readFromDB();
                printf("\n");
                break;
            }
            case 3:
            {
                int id;
                printf("\nEnter the ID of the student you want to search for: ");
                scanf("%d", &id);
                searchById(id);
                printf("\n");
                break;
            }
            case 4:
            {
                char name[50];
                printf("\nEnter the name of the student you want to search for: ");
                scanf("%s", name);
                searchByName(name);
                printf("\n");
                break;
            }
            case 5:
            {
                printf("\nGoodbye!\n");
                exit(0);
            }
            default:
            {
                printf("\nInvalid choice. Please try again.\n");
                break;
            }
        }
    } while(1);
    
    return 0;
}
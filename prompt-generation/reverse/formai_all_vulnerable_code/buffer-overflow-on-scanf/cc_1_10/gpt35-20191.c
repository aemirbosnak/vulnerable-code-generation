//FormAI DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    char name[50];
    int age;
    char grade;
};

int main(){
    struct Student s;
    FILE *fp;
    char filename[20];
    char choice;

    printf("Enter filename to create: ");
    scanf("%s", filename);

    fp = fopen(filename, "wb");

    if(fp == NULL){
        printf("Error creating file");
        exit(1);
    }

    do{
        printf("\nEnter student's name: ");
        scanf("%s", s.name);

        printf("Enter student's age: ");
        scanf("%d", &s.age);

        printf("Enter student's grade: ");
        scanf(" %c", &s.grade);

        fwrite(&s, sizeof(s), 1, fp);

        printf("\nEnter another student? (y/n): ");
        scanf(" %c", &choice);
    }while(choice == 'y');


    fclose(fp);

    fp = fopen(filename, "rb");

    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }

    printf("\n\nStudents in the file: \n\n");

    while(fread(&s, sizeof(s), 1, fp) == 1){
        printf("Name: %s\n", s.name);
        printf("Age: %d\n", s.age);
        printf("Grade: %c\n\n", s.grade);
    }

    fclose(fp);

    return 0;
}
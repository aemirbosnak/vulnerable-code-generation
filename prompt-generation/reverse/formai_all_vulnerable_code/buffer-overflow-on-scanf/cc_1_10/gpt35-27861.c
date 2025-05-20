//FormAI DATASET v1.0 Category: File handling ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 50

typedef struct Student{
    char name[SIZE];
    int rollNo;
    float marks;
}Student;

void addStudent(){
    FILE *fp;
    Student s;
    fp = fopen("students.dat", "ab+");
    if(fp == NULL){
        printf("Error in opening file.\n");
        return;
    }
    printf("Enter name: ");
    fgets(s.name, SIZE, stdin);
    strtok(s.name, "\n"); // removes newline character from input
    printf("Enter roll number: ");
    scanf("%d", &s.rollNo);
    printf("Enter marks: ");
    scanf("%f", &s.marks);
    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
}

void displayAll(){
    FILE *fp;
    Student s;
    fp = fopen("students.dat", "rb");
    if(fp == NULL){
        printf("Error in opening file.\n");
        return;
    }
    printf("%-20s %-20s %-20s\n", "Name", "Roll No.", "Marks");
    while(fread(&s, sizeof(Student), 1, fp) == 1){
        printf("%-20s %-20d %-20.2f\n", s.name, s.rollNo, s.marks);
    }
    fclose(fp);
}

void search(){
    FILE *fp;
    Student s;
    int rollNo, found = 0;
    fp = fopen("students.dat", "rb");
    if(fp == NULL){
        printf("Error in opening file.\n");
        return;
    }
    printf("Enter rollNo to search: ");
    scanf("%d", &rollNo);
    while(fread(&s, sizeof(Student), 1, fp) == 1){
        if(s.rollNo == rollNo){
            found = 1;
            printf("%-20s %-20d %-20.2f\n", s.name, s.rollNo, s.marks);
            break;
        }
    }
    if(!found){
        printf("Record not found.\n");
    }
    fclose(fp);
}

void update(){
    FILE *fp;
    Student s;
    int rollNo, found = 0;
    fp = fopen("students.dat", "rb+");
    if(fp == NULL){
        printf("Error in opening file.\n");
        return;
    }
    printf("Enter rollNo to update: ");
    scanf("%d", &rollNo);
    while(fread(&s, sizeof(Student), 1, fp) == 1){
        if(s.rollNo == rollNo){
            found = 1;
            printf("Enter new name: ");
            getchar(); // to clear input buffer
            fgets(s.name, SIZE, stdin);
            strtok(s.name, "\n"); // removes newline character from input
            printf("Enter new marks: ");
            scanf("%f", &s.marks);
            fseek(fp, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);
            printf("Record updated.\n");
            break;
        }
    }
    if(!found){
        printf("Record not found.\n");
    }
    fclose(fp);
}

void delete(){
    FILE *fp, *fpTemp;
    Student s;
    int rollNo, found = 0;
    fp = fopen("students.dat", "rb");
    if(fp == NULL){
        printf("Error in opening file.\n");
        return;
    }
    fpTemp = fopen("temp.dat", "wb+");
    if(fpTemp == NULL){
        printf("Error in opening temporary file.\n");
        return;
    }
    printf("Enter rollNo to delete: ");
    scanf("%d", &rollNo);
    while(fread(&s, sizeof(Student), 1, fp) == 1){
        if(s.rollNo == rollNo){
            found = 1;
            continue;
        }
        fwrite(&s, sizeof(Student), 1, fpTemp);
    }
    if(!found){
        printf("Record not found.\n");
    }
    else{
        printf("Record deleted.\n");
    }
    fclose(fp);
    fclose(fpTemp);
    remove("students.dat");
    rename("temp.dat", "students.dat");
}

int main(){
    int choice;
    do{
        printf("\n*****MENU*****\n");
        printf("1. Add student\n");
        printf("2. Display all students\n");
        printf("3. Search student by roll number\n");
        printf("4. Update student details\n");
        printf("5. Delete student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: addStudent();
                    break;
            case 2: displayAll();
                    break;
            case 3: search();
                    break;
            case 4: update();
                    break;
            case 5: delete();
                    break;
            case 6: printf("Exiting program...\n");
                    break;
            default: printf("Invalid choice.\n");
        }
    }while(choice != 6);
    return 0;
}
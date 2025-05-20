//FormAI DATASET v1.0 Category: File handling ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
    char name[50];
    int roll;
    float marks;
};

void updateRecord(FILE *fptr, struct Student student){
    long int size = sizeof(student);
    fseek(fptr, size * (student.roll - 1), SEEK_SET);
    fwrite(&student, sizeof(student), 1, fptr);
}

void addRecord(FILE *fptr, struct Student student){
    fseek(fptr, 0, SEEK_END);
    fwrite(&student, sizeof(student), 1, fptr);
}

void displayRecord(FILE *fptr, int roll){
    struct Student student;
    long int size = sizeof(student);
    fseek(fptr, size * (roll - 1), SEEK_SET);
    fread(&student, sizeof(student), 1, fptr);
    printf("Name: %s\n", student.name);
    printf("Roll: %d\n", student.roll);
    printf("Marks: %.2f\n", student.marks);
}

int main(){
    FILE *fptr;
    struct Student student;

    fptr = fopen("students.dat", "rb+");

    if (fptr == NULL){
        fptr = fopen("students.dat","wb+");
        if (fptr == NULL){
            printf("File cannot be created.\n");
            exit(1);
        }
    }

    printf("Enter student name: ");
    scanf("%s", student.name);
    printf("Enter roll number: ");
    scanf("%d", &student.roll);
    printf("Enter marks: ");
    scanf("%f", &student.marks);

    addRecord(fptr, student);

    printf("Do you want to update record? (y/n)\n");
    getchar();
    char choice = getchar();
    if(choice == 'y' || choice == 'Y'){
        printf("Enter updated marks: ");
        scanf("%f", &student.marks);
        updateRecord(fptr, student);
    }
    printf("Do you want to display record? (y/n)\n");
    getchar();
    choice = getchar();
    if(choice == 'y' || choice == 'Y'){
        printf("Enter roll number: ");
        int roll;
        scanf("%d", &roll);
        displayRecord(fptr, roll);
    }

    fclose(fptr);

    return 0;
}
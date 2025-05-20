//FormAI DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int roll;
    float marks;
};

void writeToFile(struct student s){
    FILE *fp;
    fp = fopen("students.dat", "ab");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    fwrite(&s, sizeof(struct student), 1, fp);
    fclose(fp);
}

int main() {
    int choice;
    struct student s;
    printf("Welcome to the Student Record System!\n");
    do {
        printf("Enter your choice:\n");
        printf("1. Add a student record\n");
        printf("2. Read all student records\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the name of the student:\n");
                scanf("%s", s.name);
                printf("Enter the roll number of the student:\n");
                scanf("%d", &s.roll);
                printf("Enter the marks of the student:\n");
                scanf("%f", &s.marks);
                writeToFile(s);
                printf("Student record added successfully!\n");
                break;
            case 2:
                printf("All student records:\n");
                FILE *fp;
                fp = fopen("students.dat", "rb");
                if (fp == NULL) {
                    printf("Error opening file\n");
                    return 0;
                }
                while (fread(&s, sizeof(struct student), 1, fp)) {
                    printf("Name: %s\n", s.name);
                    printf("Roll: %d\n", s.roll);
                    printf("Marks: %.2f\n", s.marks);
                }
                fclose(fp);
                break;
            case 3:
                printf("Thank you for using the Student Record System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}
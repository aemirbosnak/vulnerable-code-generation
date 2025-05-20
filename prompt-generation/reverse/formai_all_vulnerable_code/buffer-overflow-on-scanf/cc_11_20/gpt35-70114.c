//FormAI DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    float grade;
};

int main() {
    int option, id;
    char name[50];
    float grade;
    FILE *fp;
    struct student s;

    // create a binary file called "student_data"
    fp = fopen("student_data", "wb");

    if (fp == NULL) {
        printf("Error creating student data file!\n");
        exit(1);
    }

    do {
        // display menu options
        printf("\n1. Add student data\n");
        printf("2. Display all student data\n");
        printf("3. Search for a student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // get student data from user
                printf("Enter student ID: ");
                scanf("%d", &id);
                printf("Enter student name: ");
                scanf("%s", name);
                printf("Enter grade: ");
                scanf("%f", &grade);

                // write student data to file
                s.id = id;
                strcpy(s.name, name);
                s.grade = grade;
                fwrite(&s, sizeof(struct student), 1, fp);
                printf("Student data added successfully\n");
                break;
            case 2:
                // display all student data in file
                rewind(fp); // go to beginning of file
                printf("\nStudent data:\n");
                printf("ID\tName\t\tGrade\n");
                while (fread(&s, sizeof(struct student), 1, fp) == 1) {
                    printf("%d\t%s\t\t%.2f\n", s.id, s.name, s.grade);
                }
                break;
            case 3:
                // search for a student by ID
                printf("Enter student ID: ");
                scanf("%d", &id);
                rewind(fp); // go to beginning of file
                while (fread(&s, sizeof(struct student), 1, fp) == 1) {
                    if (s.id == id) {
                        printf("Student data:\n");
                        printf("ID\tName\t\tGrade\n");
                        printf("%d\t%s\t\t%.2f\n", s.id, s.name, s.grade);
                        break;
                    }
                }
                if (s.id != id) {
                    printf("No student found with ID %d\n", id); 
                }
                break;
            case 4:
                // exit program
                fclose(fp);
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (1);

    return 0;
}
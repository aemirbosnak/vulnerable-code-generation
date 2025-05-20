//FormAI DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

struct student {
    int id;
    char name[SIZE];
    int age;
    char program[SIZE];
    float gpa;
};

void display_menu() {
    printf("\n\t\t\tSTUDENT DATABASE SIMULATION\n");
    printf("1. Add a student record\n");
    printf("2. Search for a student record\n");
    printf("3. Delete a student record\n");
    printf("4. Display all student records\n");
    printf("5. Exit\n");
}

int main() {
    char filename[] = "students.dat"; // file name for database
    FILE *fp;
    fp = fopen(filename, "rb"); // open file in binary mode to read data
    if (fp == NULL) { // if the file does not exist, create an empty file
        fp = fopen(filename, "wb"); // open file in binary mode to write data
        fclose(fp);
        fp = fopen(filename, "rb"); // reopen file in binary mode to read data
    }

    struct student s; // student record
    int choice, id, found = 0;
    char name[SIZE], program[SIZE];
    float gpa;
    long int size = sizeof(s);

    while (1) {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter student ID: ");
                scanf("%d", &s.id);
                printf("Enter student name: ");
                scanf("%s", s.name);
                printf("Enter student age: ");
                scanf("%d", &s.age);
                printf("Enter student program: ");
                scanf("%s", s.program);
                printf("Enter student GPA: ");
                scanf("%f", &s.gpa);

                fseek(fp, 0, SEEK_END); // move file pointer to the end of the file
                fwrite(&s, size, 1, fp); // write the student record to the file

                printf("\nStudent record added successfully.\n");
                break;

            case 2:
                printf("\nEnter student ID to search: ");
                scanf("%d", &id);

                rewind(fp); // move file pointer to the beginning of the file
                while (fread(&s, size, 1, fp) == 1) { // read each student record from the file
                    if (s.id == id) { // if the ID matches
                        found = 1;
                        printf("\nStudent record found!\n");
                        printf("ID: %d\n", s.id);
                        printf("Name: %s\n", s.name);
                        printf("Age: %d\n", s.age);
                        printf("Program: %s\n", s.program);
                        printf("GPA: %.2f\n", s.gpa);
                        break;
                    }
                }

                if (!found) {
                    printf("\nStudent record not found!\n");
                }
                break;

            case 3:
                printf("\nEnter student ID to delete: ");
                scanf("%d", &id);

                FILE *temp; // temporary file to store non-deleted records
                temp = fopen("temp.dat", "w+b"); // create temporary file in binary mode to write and read data

                rewind(fp); // move file pointer to the beginning of the file
                while (fread(&s, size, 1, fp) == 1) { // read each student record from the file
                    if (s.id != id) { // if the ID does not match
                        fwrite(&s, size, 1, temp); // write the student record to the temporary file
                    }
                }

                fclose(fp); // close original file
                fclose(temp); // close temporary file

                remove(filename); // delete original file
                rename("temp.dat", filename); // rename temporary file to original file

                fp = fopen(filename, "rb"); // reopen updated file in binary mode to read data

                printf("\nStudent record deleted successfully.\n");
                break;

            case 4:
                rewind(fp); // move file pointer to the beginning of the file
                printf("\nStudent records:\n");
                while (fread(&s, size, 1, fp) == 1) { // read each student record from the file
                    printf("\nID: %d\n", s.id);
                    printf("Name: %s\n", s.name);
                    printf("Age: %d\n", s.age);
                    printf("Program: %s\n", s.program);
                    printf("GPA: %.2f\n", s.gpa);
                }
                break;

            case 5:
                fclose(fp); // close file before exiting
                printf("\nGoodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}
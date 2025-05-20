//FormAI DATASET v1.0 Category: File handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50

struct student {
    int id;
    char name[MAX_NAME_LENGTH];
    float gpa;
};

int main() {

    FILE *fp_in, *fp_out;
    int choice;
    char file_name[MAX_NAME_LENGTH];
    struct student s;

    printf("Welcome to the Student Records Program!\n\n");

    do {
        printf("Please choose one of the following options:\n");
        printf("1. Add a student record\n");
        printf("2. List all student records\n");
        printf("3. Exit Program\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter student ID: ");
            scanf("%d", &s.id);
            printf("Enter student name: ");
            scanf("%s", s.name);
            printf("Enter student GPA: ");
            scanf("%f", &s.gpa);

            printf("\nEnter name of output file: ");
            scanf("%s", file_name);

            fp_out = fopen(file_name, "ab");
            if (fp_out == NULL) {
                printf("Error opening file!\n\n");
                continue;
            }

            fwrite(&s, sizeof(struct student), 1, fp_out);
            fclose(fp_out);
            printf("Record added!\n\n");

        } else if (choice == 2) {
            printf("\nEnter name of input file: ");
            scanf("%s", file_name);

            fp_in = fopen(file_name, "rb");
            if (fp_in == NULL) {
                printf("Error opening file!\n\n");
                continue;
            }

            printf("\nStudent Records:\n");
            printf("ID\tName\t\tGPA\n");

            while (fread(&s, sizeof(struct student), 1, fp_in)) {
                printf("%d\t%s\t\t%.2f\n", s.id, s.name, s.gpa);
            }

            fclose(fp_in);
            printf("\n");

        } else if (choice != 3) {
            printf("\nInvalid choice!\n\n");
        }

    } while (choice != 3);

    printf("Thank you for using the Student Records Program!\n");

    return 0;
}
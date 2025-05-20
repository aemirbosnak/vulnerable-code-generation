//FormAI DATASET v1.0 Category: Database simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    float cgpa;
};

int main() {
    int choice;
    struct student s;

    FILE *fp;

    fp = fopen("students.dat", "rb+");

    if (fp == NULL) {
        fp = fopen("students.dat", "wb+");

        if (fp == NULL) {
            printf("Error opening file");
            exit(1);
        }
    }

    while (1) {
        printf("\n1. Add student");
        printf("\n2. List students");
        printf("\n3. Search for a student by ID");
        printf("\n4. Update student details");
        printf("\n5. Delete student by ID");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student ID: ");
                scanf("%d", &s.id);

                printf("Enter student name: ");
                scanf("%s", s.name);

                printf("Enter student CGPA: ");
                scanf("%f", &s.cgpa);

                fseek(fp, 0, SEEK_END);
                fwrite(&s, sizeof(s), 1, fp);

                printf("\nStudent added successfully!");
                break;

            case 2:
                rewind(fp);
                printf("\nID \tNAME \t\tCGPA\n");

                while (fread(&s, sizeof(s), 1, fp) == 1) {
                    printf("%d \t%-20s \t%.2f\n", s.id, s.name, s.cgpa);
                }

                break;

            case 3:
                printf("Enter student ID to search: ");
                int id_to_search;
                scanf("%d", &id_to_search);

                rewind(fp);
                int found = 0;

                while (fread(&s, sizeof(s), 1, fp) == 1) {
                    if (s.id == id_to_search) {
                        printf("\nStudent found!\nID: %d\nName: %s\nCGPA: %.2f\n", s.id, s.name, s.cgpa);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("\nStudent not found!");
                }

                break;

            case 4:
                printf("Enter student ID to update: ");
                int id_to_update;
                scanf("%d", &id_to_update);

                rewind(fp);
                found = 0;

                while (fread(&s, sizeof(s), 1, fp) == 1) {
                    if (s.id == id_to_update) {
                        printf("\nEnter new data for this student: \n");

                        printf("New name: ");
                        scanf("%s", s.name);

                        printf("New CGPA: ");
                        scanf("%f", &s.cgpa);

                        fseek(fp, -sizeof(s), SEEK_CUR);
                        fwrite(&s, sizeof(s), 1, fp);

                        printf("\nStudent details updated successfully!");
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("\nStudent not found!");
                }

                break;

            case 5:
                printf("Enter student ID to delete: ");
                int id_to_delete;
                scanf("%d", &id_to_delete);

                FILE *tmp_fp;
                tmp_fp = fopen("temp.dat", "wb");

                rewind(fp);

                while (fread(&s, sizeof(s), 1, fp) == 1) {
                    if (s.id != id_to_delete) {
                        fwrite(&s, sizeof(s), 1, tmp_fp);
                    }
                }

                fclose(fp);
                fclose(tmp_fp);

                remove("students.dat");
                rename("temp.dat", "students.dat");

                fp = fopen("students.dat", "rb+");

                printf("\nStudent deleted successfully!");

                break;

            case 6:
                fclose(fp);
                exit(0);

            default:
                printf("\nInvalid choice!");
                break;
        }
    }

    return 0;
}
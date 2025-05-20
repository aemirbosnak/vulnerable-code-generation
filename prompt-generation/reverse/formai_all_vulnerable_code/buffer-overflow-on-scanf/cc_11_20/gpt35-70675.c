//FormAI DATASET v1.0 Category: File handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[20];
    float gpa;
};

int main() {
    FILE *fp;
    int choice, id, i, count, index;
    char name[20];
    float gpa;
    struct student st;

    while(1) {
        printf("1. Add student\n");
        printf("2. View all students\n");
        printf("3. Search student by ID\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                fp = fopen("students.dat", "ab");
                if(fp == NULL) {
                    printf("Error opening file.\n");
                    exit(1);
                }
                printf("Enter student ID: ");
                scanf("%d", &id);
                printf("Enter student name: ");
                scanf("%s", name);
                printf("Enter student GPA: ");
                scanf("%f", &gpa);
                st.id = id;
                strcpy(st.name, name);
                st.gpa = gpa;
                fwrite(&st, sizeof(struct student), 1, fp);
                printf("Student added successfully!\n");
                fclose(fp);
                break;
            case 2:
                fp = fopen("students.dat", "rb");
                if(fp == NULL) {
                    printf("Error opening file.\n");
                    exit(1);
                }
                printf("List of all students:\n");
                count = 0;
                while(fread(&st, sizeof(struct student), 1, fp)) {
                    printf("ID: %d, Name: %s, GPA: %.2f\n", st.id, st.name, st.gpa);
                    count++;
                }
                printf("Total number of students: %d\n", count);
                fclose(fp);
                break;
            case 3:
                fp = fopen("students.dat", "rb");
                if(fp == NULL) {
                    printf("Error opening file.\n");
                    exit(1);
                }
                printf("Enter student ID: ");
                scanf("%d", &id);
                index = -1;
                for(i = 0; fread(&st, sizeof(struct student), 1, fp); i++) {
                    if(st.id == id) {
                        index = i;
                        break;
                    }
                }
                if(index == -1) {
                    printf("No student found with ID %d\n", id);
                } else {
                    printf("Student found at index %d\n", index);
                    printf("ID: %d, Name: %s, GPA: %.2f\n", st.id, st.name, st.gpa);
                }
                fclose(fp);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
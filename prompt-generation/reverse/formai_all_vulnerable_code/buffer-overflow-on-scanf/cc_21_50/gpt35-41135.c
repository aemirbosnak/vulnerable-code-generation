//FormAI DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    int choice, count = 0;
    FILE *fp;
    struct student st;

    while (1) {
        printf("\n1. Add a student record");
        printf("\n2. Display student records");
        printf("\n3. Search for a student record");
        printf("\n4. Update a student record");
        printf("\n5. Delete a student record");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Adding a student record
                fp = fopen("students.txt", "a");
                if (fp == NULL) {
                    printf("\nError opening file!");
                    exit(1);
                }
                printf("\nEnter student name: ");
                scanf("%s", st.name);
                printf("Enter roll number: ");
                scanf("%d", &st.roll);
                printf("Enter marks: ");
                scanf("%f", &st.marks);

                fwrite(&st, sizeof(st), 1, fp);
                printf("\nRecord added successfully!");
                fclose(fp);
                break;

            case 2:
                // Displaying all student records
                fp = fopen("students.txt", "r");
                if (fp == NULL) {
                    printf("\nError opening file!");
                    exit(1);
                }
                printf("\n\n%-20s %-10s %-10s", "Name", "Roll No.", "Marks");
                printf("\n-------------------------------------------------");

                while (fread(&st, sizeof(st), 1, fp)) {
                    printf("\n%-20s %-10d %-10.2f", st.name, st.roll, st.marks);
                    count++;
                }
                fclose(fp);
                if(count == 0) {
                    printf("\nFile is empty!");
                }
                break;

            case 3:
                // Searching for a student record
                fp = fopen("students.txt", "r");
                if (fp == NULL) {
                    printf("\nError opening file!");
                    exit(1);
                }
                printf("\nEnter roll number to search: ");
                int search_roll;
                scanf("%d", &search_roll);
                count = 0;

                while (fread(&st, sizeof(st), 1, fp)) {
                    if (st.roll == search_roll) {
                        printf("\n%-20s %-10d %-10.2f", st.name, st.roll, st.marks);
                        count++;
                    }
                }
                fclose(fp);
                if(count == 0) {
                    printf("\nRecord not found!");
                }
                break;

            case 4:
                // Updating a student record
                fp = fopen("students.txt", "r+");
                if (fp == NULL) {
                    printf("\nError opening file!");
                    exit(1);
                }
                printf("\nEnter roll number to update: ");
                int update_roll;
                scanf("%d", &update_roll);
                int found = 0;

                while (fread(&st, sizeof(st), 1, fp)) {
                    if (st.roll == update_roll) {
                        printf("\nEnter new name: ");
                        scanf("%s", st.name);
                        printf("Enter new marks: ");
                        scanf("%f", &st.marks);

                        fseek(fp, -sizeof(st), SEEK_CUR);
                        fwrite(&st, sizeof(st), 1, fp);
                        found = 1;
                        break;
                    }
                }
                fclose(fp);
                if(found == 0) {
                    printf("\nRecord not found!");
                } else {
                    printf("\nRecord updated successfully!");
                }
                break;

            case 5:
                // Deleting a student record
                fp = fopen("students.txt", "r");
                if (fp == NULL) {
                    printf("\nError opening file!");
                    exit(1);
                }
                FILE *fp2 = fopen("temp.txt", "w");
                if (fp2 == NULL) {
                    printf("\nError opening file!");
                    exit(1);
                }
                printf("\nEnter roll number to delete: ");
                int delete_roll;
                scanf("%d", &delete_roll);
                count = 0;

                while (fread(&st, sizeof(st), 1, fp)) {
                    if (st.roll != delete_roll) {
                        fwrite(&st, sizeof(st), 1, fp2);
                    } else {
                        count++;
                    }
                }
                fclose(fp);
                fclose(fp2);

                if(count == 0) {
                    printf("\nRecord not found!");
                } else {
                    fp = fopen("students.txt", "w");
                    fp2 = fopen("temp.txt", "r");

                    while (fread(&st, sizeof(st), 1, fp2)) {
                        fwrite(&st, sizeof(st), 1, fp);
                    }

                    fclose(fp);
                    fclose(fp2);
                    printf("\nRecord deleted successfully!");
                }
                break;

            case 6:
                // Exiting the program
                return 0;

            default:
                printf("\nInvalid choice! Try again.");
                break;
        }
    }
}
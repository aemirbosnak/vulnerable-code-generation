//FormAI DATASET v1.0 Category: Database simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct student {
    int id;
    char name[50];
    float gpa;
};

int main() {
    struct student db[MAX];
    int size = 0;

    while(1) {
        printf("\n==============================\n");
        printf("STUDENT DATABASE SIMULATION\n");
        printf("==============================\n");
        printf("1. Add a student\n");
        printf("2. View all students\n");
        printf("3. Search for a student\n");
        printf("4. Remove a student\n");
        printf("5. Update student information\n");
        printf("6. Exit\n");
        printf("==============================\n");
        printf("Enter choice: ");

        int choice;
        scanf("%d", &choice);

        if(choice == 1) {
            if(size == MAX) {
                printf("Database is full!\n");
            } else {
                printf("\nEnter student id: ");
                scanf("%d", &db[size].id);

                printf("Enter student name: ");
                scanf("%s", db[size].name);

                printf("Enter student GPA: ");
                scanf("%f", &db[size].gpa);

                size++;
                printf("\nStudent added successfully!\n");
            }
        } else if(choice == 2) {
            printf("\n==============================\n");
            printf("ALL STUDENTS\n");
            printf("==============================\n");

            if(size == 0) {
                printf("No students found!\n");
            } else {
                for(int i = 0; i < size; i++) {
                    printf("ID: %d\n", db[i].id);
                    printf("Name: %s\n", db[i].name);
                    printf("GPA: %.2f\n", db[i].gpa);
                    printf("-------------------------\n");
                }
            }
        } else if(choice == 3) {
            printf("\nEnter student id to search: ");
            int search_id;
            scanf("%d", &search_id);

            for(int i = 0; i < size; i++) {
                if(db[i].id == search_id) {
                    printf("\nID: %d\n", db[i].id);
                    printf("Name: %s\n", db[i].name);
                    printf("GPA: %.2f\n", db[i].gpa);
                    break;
                }
                if(i == size-1) {
                    printf("\nStudent not found!\n");
                }
            }
        } else if(choice == 4) {
            printf("\nEnter student id to remove: ");
            int remove_id;
            scanf("%d", &remove_id);

            for(int i = 0; i < size; i++) {
                if(db[i].id == remove_id) {
                    for(int j = i; j < size - 1; j++) {
                        memcpy(&db[j], &db[j+1], sizeof(struct student));
                    }
                    size--;
                    printf("\nStudent removed successfully!\n");
                    break;
                }
                if(i == size-1) {
                    printf("\nStudent not found!\n");
                }
            }
        } else if(choice == 5) {
            printf("\nEnter student id to update: ");
            int update_id;
            scanf("%d", &update_id);

            for(int i = 0; i < size; i++) {
                if(db[i].id == update_id) {
                    printf("Enter new name: ");
                    scanf("%s", db[i].name);

                    printf("Enter new GPA: ");
                    scanf("%f", &db[i].gpa);

                    printf("\nStudent information updated successfully!\n");
                    break;
                }
                if(i == size-1) {
                    printf("\nStudent not found!\n");
                }
            }
        } else if(choice == 6) {
            printf("\nBye!\n");
            break;
        } else {
            printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
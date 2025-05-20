//FormAI DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    float score;
} Student;

int main() {
    int choice, n;
    printf("Enter the number of students:");
    scanf("%d", &n);
    Student students[n];
    for (int i = 0; i < n; i++) {
        students[i].id = i + 1;
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter the score of student %d: ", i + 1);
        scanf("%f", &students[i].score);
    }
    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Display all students\n");
        printf("2. Display student by ID\n");
        printf("3. Display students with score above a given value\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("ALL STUDENTS:\n");
                for (int i = 0; i < n; i++) {
                    printf("ID: %d | Name: %s | Score: %.2f\n", students[i].id, students[i].name, students[i].score);
                }
                break;
            case 2:
                printf("Enter student ID to display: ");
                int id;
                scanf("%d", &id);
                if (id > n || id < 1) {
                    printf("Invalid ID!\n");
                } else {
                    printf("STUDENT WITH ID %d:\n", id);
                    printf("Name: %s | Score: %.2f\n", students[id-1].name, students[id-1].score);
                }
                break;
            case 3:
                printf("Enter minimum score to display: ");
                float min_score;
                int count = 0;
                scanf("%f", &min_score);
                printf("STUDENTS WITH SCORES ABOVE %.2f:\n", min_score);
                for (int i = 0; i < n; i++) {
                    if (students[i].score > min_score) {
                        count++;
                        printf("ID: %d | Name: %s | Score: %.2f\n", students[i].id, students[i].name, students[i].score);
                    }
                }
                if (count == 0) {
                    printf("No students found!\n");
                }
                break;
            case 4:
                return 0;
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    }
    return 0;
}
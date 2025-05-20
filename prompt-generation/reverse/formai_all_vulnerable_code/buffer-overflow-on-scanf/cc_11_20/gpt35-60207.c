//FormAI DATASET v1.0 Category: Database simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int roll;
    char name[20];
    int marks;
};

int main(void) {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct student *list = malloc(sizeof(struct student) * n);

    /* Database Initialization */
    for (int i = 0; i < n; i++) {
        printf("Enter the details of Student %d:\n", i+1);
        printf("Roll No: ");
        scanf("%d", &list[i].roll);
        printf("Name: ");
        scanf("%s", list[i].name);
        printf("Marks: ");
        scanf("%d", &list[i].marks);
    }

    /* Database Display */
    printf("\nDetails of all students:\n");
    printf("------------------------\n");
    printf("Roll No\tName\tMarks\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\n", list[i].roll, list[i].name, list[i].marks);
    }

    /* Database Search by Roll No */
    int roll_no;

    printf("\nEnter Roll No. to search: ");
    scanf("%d", &roll_no);

    for (int i = 0; i < n; i++) {
        if (list[i].roll == roll_no) {
            printf("\nDetails of Student with Roll No. %d:\n", roll_no);
            printf("Roll No: %d\n", list[i].roll);
            printf("Name: %s\n", list[i].name);
            printf("Marks: %d\n", list[i].marks);
            break;
        }
    }

    /* Database Delete by Roll No */
    printf("\n");

    int delete_index = -1;

    printf("Enter Roll No. to delete: ");
    scanf("%d", &roll_no);

    for (int i = 0; i < n; i++) {
        if (list[i].roll == roll_no) {
            delete_index = i;
            break;
        }
    }

    if (delete_index == -1) {
        printf("No student found with Roll No. %d\n", roll_no);
    } else {
        for (int i = delete_index; i < n-1; i++) {
            list[i] = list[i+1];
        }
        printf("Details of Student with Roll No. %d deleted successfully!\n", roll_no);
        n--;
    }

    /* Database Display after Delete */
    printf("\nDetails of all students after Delete:\n");
    printf("------------------------------------\n");
    printf("Roll No\tName\tMarks\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\n", list[i].roll, list[i].name, list[i].marks);
    }

    /* Database Update by Roll No */
    printf("\n");

    int update_index = -1;

    printf("Enter Roll No. to update: ");
    scanf("%d", &roll_no);

    for (int i = 0; i < n; i++) {
        if (list[i].roll == roll_no) {
            update_index = i;
            break;
        }
    }

    if (update_index == -1) {
        printf("No student found with Roll No. %d\n", roll_no);
    } else {
        printf("\nEnter the new details of Student with Roll No. %d:\n", roll_no);
        printf("Name: ");
        scanf("%s", list[update_index].name);
        printf("Marks: ");
        scanf("%d", &list[update_index].marks);
        printf("Details of Student with Roll No. %d updated successfully!\n", roll_no);
    }

    /* Database Display after Update */
    printf("\nDetails of all students after Update:\n");
    printf("------------------------------------\n");
    printf("Roll No\tName\tMarks\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\n", list[i].roll, list[i].name, list[i].marks);
    }

    free(list);
    return 0;
}
//FormAI DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    float cgpa;
};

void insert(struct Student st[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter roll no, name and cgpa of student %d: ", i+1);
        scanf("%d %s %f", &st[i].roll_no, st[i].name, &st[i].cgpa);
    }
}

void display(struct Student st[], int n) {
    int i;
    printf("-------------------------------------------------------------------\n");
    printf("Roll No.\tName\t\tCGPA\n");
    printf("-------------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%s\t\t%.2f\n", st[i].roll_no, st[i].name, st[i].cgpa);
    }
    printf("-------------------------------------------------------------------\n");
}

int search(struct Student st[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (st[i].roll_no == key) {
            return i;
        }
    }
    return -1;
}

void delete(struct Student st[], int n, int key) {
    int i, j;
    i = search(st, n, key);
    if (i == -1) {
        printf("Student with Roll No. %d not found!\n", key);
        return;
    }
    for (j = i; j < n - 1; j++) {
        st[j] = st[j + 1];
    }
}

void update(struct Student st[], int n, int key) {
    int i, ch;
    i = search(st, n, key);
    if (i == -1) {
        printf("Student with Roll No. %d not found!\n", key);
        return;
    }
    printf("Enter new name and cgpa of student %d: ", key);
    scanf("%s %f", st[i].name, &st[i].cgpa);
}

int main() {
    int n, ch, key;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student st[n];
    do {
        printf("\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Update\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(st, n);
            break;
        case 2:
            display(st, n);
            break;
        case 3:
            printf("Enter roll no to search: ");
            scanf("%d", &key);
            if (search(st, n, key) == -1) {
                printf("Student with Roll No. %d not found!\n", key);
            }
            else {
                printf("Student with Roll No. %d found at index %d.\n", key, search(st, n, key));
            }
            break;
        case 4:
            printf("Enter roll no to delete: ");
            scanf("%d", &key);
            delete(st, n, key);
            n--;
            break;
        case 5:
            printf("Enter roll no to update: ");
            scanf("%d", &key);
            update(st, n, key);
            break;
        case 6:
            printf("Exiting program...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (1);
    return 0;
}
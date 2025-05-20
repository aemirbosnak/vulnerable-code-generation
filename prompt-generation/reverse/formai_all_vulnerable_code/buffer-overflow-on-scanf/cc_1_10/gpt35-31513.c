//FormAI DATASET v1.0 Category: Database simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int rollno;
    char name[50];
    float cgpa;
};

struct node {
    struct student data;
    struct node *next;
};

struct node *head = NULL;

void add_student() {
    struct student s;
    printf("\nEnter the roll number: ");
    scanf("%d", &s.rollno);
    printf("\nEnter the name: ");
    scanf("%s", s.name);
    printf("\nEnter the CGPA: ");
    scanf("%f", &s.cgpa);
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = s;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    printf("\nStudent added successfully!");
}

void display_all_students() {
    if (head == NULL) {
        printf("\nNo students added yet!");
        return;
    }
    printf("\nRoll No.\tName\t\tCGPA\n");
    printf("--------------------------------------------------\n");
    struct node *current = head;
    while (current != NULL) {
        printf("%d\t\t%s\t\t%.2f\n", current->data.rollno, current->data.name, current->data.cgpa);
        current = current->next;
    }
}

void search_student() {
    if (head == NULL) {
        printf("\nNo students added yet!");
        return;
    }
    int rollno;
    printf("\nEnter the roll number to search: ");
    scanf("%d", &rollno);
    struct node *current = head;
    while (current != NULL) {
        if (current->data.rollno == rollno) {
            printf("\nRoll No.\tName\t\tCGPA\n");
            printf("--------------------------------------------------\n");
            printf("%d\t\t%s\t\t%.2f\n", current->data.rollno, current->data.name, current->data.cgpa);
            return;
        }
        current = current->next;
    }
    printf("\nStudent not found!");
}

void delete_student() {
    if (head == NULL) {
        printf("\nNo students added yet!");
        return;
    }
    int rollno, found = 0;
    printf("\nEnter the roll number to delete: ");
    scanf("%d", &rollno);
    if (head->data.rollno == rollno) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        printf("\nStudent deleted successfully!");
        return;
    }
    struct node *current = head;
    while (current->next != NULL) {
        if (current->next->data.rollno == rollno) {
            found = 1;
            struct node *temp = current->next;
            current->next = current->next->next;
            free(temp);
            printf("\nStudent deleted successfully!");
            return;
        }
        current = current->next;
    }
    if (found == 0) {
        printf("\nStudent not found!");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n\n1. Add student\n2. Display all students\n3. Search student\n4. Delete student\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_all_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                delete_student();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Data mining ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[30];
    int age;
    float salary;
} Employee;

typedef struct node {
    Employee emp;
    struct node* next;
} Node;

void load_data(Node** head) ;
void display_data(Node* head, char* name) ;
void add_employee(Node** head, Employee emp) ;
Node* find_employee(Node* head, char* name) ;
void remove_employee(Node** head, char* name) ;
void sort_employees(Node** head) ;

int main() {

    Node* head = NULL;
    load_data(&head);

    char choice;
    char name[30];
    Employee emp;

    do {
        printf("\n\nMENU:\n");
        printf("1. Display Employee Data\n");
        printf("2. Add New Employee\n");
        printf("3. Remove an Employee\n");
        printf("4. Sort Employees by Salary\n");
        printf("5. Exit\n");
        printf("Enter Your Choice (1-5): ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("\nEnter Employee Name: ");
                scanf("%s", name);
                display_data(head, name);
                break;

            case '2':
                printf("\nEnter Employee ID, Name, Age and Salary: ");
                scanf("%d %s %d %f", &emp.id, emp.name, &emp.age, &emp.salary);
                add_employee(&head, emp);
                printf("\nEmployee Added Successfully!\n");
                break;

            case '3':
                printf("\nEnter Employee Name: ");
                scanf("%s", name);
                remove_employee(&head, name);
                printf("\nEmployee Removed Successfully!\n");
                break;

            case '4':
                sort_employees(&head);
                printf("\nEmployees Sorted by Salary!\n");
                break;

            case '5':
                printf("\nThank you for using the program!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != '5');

    return 0;
}

void load_data(Node** head) {
    FILE* fp = fopen("employee.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Employee emp;
    while (fscanf(fp, "%d %s %d %f", &emp.id, emp.name, &emp.age, &emp.salary) != EOF) {
        add_employee(head, emp);
    }

    fclose(fp);
}

void display_data(Node* head, char* name) {
    Node* temp = find_employee(head, name);
    if (temp == NULL) {
        printf("\nEmployee Not Found!\n");
        return;
    }

    printf("\nEmployee Details:\n");
    printf("ID: %d\n", temp->emp.id);
    printf("Name: %s\n", temp->emp.name);
    printf("Age: %d\n", temp->emp.age);
    printf("Salary: %f\n", temp->emp.salary);
}

void add_employee(Node** head, Employee emp) {
    Node* temp = *head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->emp = emp;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Node* find_employee(Node* head, char* name) {
    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->emp.name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void remove_employee(Node** head, char* name) {
    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL && strcmp(temp->emp.name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Employee Not Found!\n");
        return;
    }

    if (prev == NULL) {
        *head = (*head)->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

void sort_employees(Node** head) {
    Node *current = *head, *index = NULL;
    Employee temp;

    if (*head == NULL) {
        return;
    } else {
        while (current != NULL) {
            index = current->next;

            while (index != NULL) {
                if (current->emp.salary > index->emp.salary) {
                    temp = current->emp;
                    current->emp = index->emp;
                    index->emp = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}
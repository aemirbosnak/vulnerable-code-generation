//FormAI DATASET v1.0 Category: Linked list operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list
typedef struct Student {
    int roll_no;
    char name[20];
    float cgpa;
    struct Student* next;
} Student;

// Declare global variables
Student* head = NULL;
int count = 0;

// Function to add new node at the beginning of the list
void add_node_front(int roll_no, char name[], float cgpa) {
    Student* new_node = (Student*) malloc(sizeof(Student));
    new_node->roll_no = roll_no;
    strcpy(new_node->name, name);
    new_node->cgpa = cgpa;
    new_node->next = head;
    head = new_node;
    count++;
}

// Function to add new node at the end of the list
void add_node_back(int roll_no, char name[], float cgpa) {
    Student* new_node = (Student*) malloc(sizeof(Student));
    new_node->roll_no = roll_no;
    strcpy(new_node->name, name);
    new_node->cgpa = cgpa;
    new_node->next = NULL;

    if(head == NULL) {
        head = new_node;
    } else {
        Student* current_node = head;
        while(current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    count++;
}

// Function to delete node from the list
void delete_node(int roll_no) {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Student* current_node = head;
    Student* previous_node = NULL;

    while(current_node != NULL && current_node->roll_no != roll_no) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    if(current_node == NULL) {
        printf("Roll no.%d not found in the list!\n", roll_no);
    } else {
        if(previous_node == NULL) {
            head = current_node->next;
        } else {
            previous_node->next = current_node->next;
        }
        free(current_node);
        printf("Roll no.%d deleted successfully!\n", roll_no);
        count--;
    }
}

// Function to print all nodes of the list
void print_all_nodes() {
    printf("Total number of nodes in the list: %d\n", count);
    printf("Roll No.\tName\t\tCGPA\n");

    Student* current_node = head;

    while(current_node != NULL) {
        printf("%d\t\t%s\t\t%.2f\n", current_node->roll_no, 
                                      current_node->name, 
                                      current_node->cgpa);
        current_node = current_node->next;
    }
}

int main() {
    printf("Welcome to the student database system!\n");
    printf("You can add, delete and view students in the database.\n");

    while(1) {
        printf("\nMenu:\n");
        printf("1. Add new student at the front of the list\n");
        printf("2. Add new student at the back of the list\n");
        printf("3. Delete a student from the list\n");
        printf("4. Print the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int roll_no;
                char name[20];
                float cgpa;
                printf("Enter Roll No.: ");
                scanf("%d", &roll_no);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter CGPA: ");
                scanf("%f", &cgpa);
                add_node_front(roll_no, name, cgpa);
                printf("Student added successfully!\n");
                break;
            }
            case 2: {
                int roll_no;
                char name[20];
                float cgpa;
                printf("Enter Roll No.: ");
                scanf("%d", &roll_no);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter CGPA: ");
                scanf("%f", &cgpa);
                add_node_back(roll_no, name, cgpa);
                printf("Student added successfully!\n");
                break;
            }
            case 3: {
                int roll_no;
                printf("Enter Roll No. to delete: ");
                scanf("%d", &roll_no);
                delete_node(roll_no);
                break;
            }
            case 4: {
                print_all_nodes();
                break;
            }
            case 5: {
                printf("Exiting program...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice! Please try again.\n");
            }
        }
    }

    return 0;
}
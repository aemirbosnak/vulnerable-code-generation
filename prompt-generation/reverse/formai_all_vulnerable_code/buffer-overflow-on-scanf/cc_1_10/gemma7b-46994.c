//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store employee information
struct employee
{
    char name[50];
    int age;
    double salary;
    struct employee* next;
};

// Function to insert a new employee at the end
void insert_at_end(struct employee** head)
{
    struct employee* new_node = (struct employee*)malloc(sizeof(struct employee));
    printf("Enter name: ");
    scanf("%s", new_node->name);
    printf("Enter age: ");
    scanf("%d", &new_node->age);
    printf("Enter salary: ");
    scanf("%lf", &new_node->salary);

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        (*head)->next = new_node;
    }
    *head = new_node;
}

// Function to display all employees
void display_employees(struct employee* head)
{
    struct employee* current = head;
    while (current)
    {
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("Salary: %.2lf\n", current->salary);
        printf("\n");
        current = current->next;
    }
}

int main()
{
    struct employee* head = NULL;

    // Insert some employees
    insert_at_end(&head);
    insert_at_end(&head);
    insert_at_end(&head);

    // Display all employees
    display_employees(head);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define the main struct for expenses
typedef struct {
    int id;
    char *description;
    float amount;
    char *date;
} Expense;

// Define the linked list node struct
typedef struct Node {
    Expense *expense;
    struct Node *next;
} Node;

// Define the linked list head struct
typedef struct {
    Node *head;
    Node *tail;
    int count;
} LinkedList;

// Function to create a new linked list
LinkedList *create_list() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    return list;
}

// Function to append a new expense to the linked list
void append_expense(LinkedList *list, Expense *expense) {
    Node *node = malloc(sizeof(Node));
    node->expense = expense;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }

    list->count++;
}

// Function to print the linked list of expenses
void print_list(LinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        printf("ID: %d\n", current->expense->id);
        printf("Description: %s\n", current->expense->description);
        printf("Amount: %f\n", current->expense->amount);
        printf("Date: %s\n\n", current->expense->date);
        current = current->next;
    }
}

// Function to free the linked list of expenses
void free_list(LinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *next = current->next;
        free(current->expense->description);
        free(current->expense->date);
        free(current->expense);
        free(current);
        current = next;
    }

    free(list);
}

// Function to get the user input
void get_user_input(Expense *expense) {

    // Get the description
    printf("Enter the expense description: ");
    char *description = malloc(100);
    scanf(" %[^\n]s", description);
    expense->description = description;

    // Get the amount
    printf("Enter the expense amount: ");
    float amount;
    scanf(" %f", &amount);
    expense->amount = amount;

    // Get the date
    printf("Enter the expense date (dd/mm/yyyy): ");
    char *date = malloc(11);
    scanf(" %[^\n]s", date);
    expense->date = date;
}

// Function to create a new expense
Expense *create_expense() {
    Expense *expense = malloc(sizeof(Expense));

    // Get the user input
    get_user_input(expense);

    // Generate a unique ID
    static int id = 1;
    expense->id = id++;

    return expense;
}

// Function to add a new expense to the linked list
void add_expense(LinkedList *list) {
    Expense *expense = create_expense();
    append_expense(list, expense);
}

// Function to print the menu
void print_menu() {
    printf("\n");
    printf("1. Add a new expense\n");
    printf("2. Print the list of expenses\n");
    printf("3. Quit\n");
    printf("\n");
    printf("Enter your choice: ");
}

// Function to get the user choice
int get_user_choice() {
    int choice;
    scanf(" %d", &choice);
    return choice;
}

// Main function
int main() {
    // Create a new linked list
    LinkedList *list = create_list();

    // Loop until the user quits
    int choice;
    do {
        // Print the menu
        print_menu();

        // Get the user choice
        choice = get_user_choice();

        // Switch on the user choice
        switch (choice) {
            case 1:
                // Add a new expense
                add_expense(list);
                break;
            case 2:
                // Print the list of expenses
                print_list(list);
                break;
            case 3:
                // Quit the program
                break;
            default:
                // Invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    // Free the linked list
    free_list(list);

    return 0;
}
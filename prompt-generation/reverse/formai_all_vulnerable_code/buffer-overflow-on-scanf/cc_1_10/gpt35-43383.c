//FormAI DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char item[20];  // Expense item
    float cost;     // Expense cost
    char category[15]; // Category of expense
    char date[11];  // Date of expense
    struct Expense *next; // Pointer to next expense
};

struct Category {
    char name[15];      // Name of the category
    float total_cost;   // Total expense in the category
    struct Category *next; // Pointer to next category
};

// Function prototypes
void add_expense(struct Expense **head);
void view_expenses(struct Expense *head);
void view_expenses_by_category(struct Expense *head);
void view_categories(struct Category *head);
void add_category(struct Category **head);
void update_category(struct Expense *head, struct Category *head_cat);
void delete_expense(struct Expense **head, struct Category *head_cat);
void delete_category(struct Category **head);
void print_separator();

int main() {
    int choice = 0;
    struct Expense *expense_head = NULL;
    struct Category *category_head = NULL;

    do {
        printf("\n\t EXPENSE TRACKER \n");
        printf("==================================\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. View expenses by category\n");
        printf("4. View categories\n");
        printf("5. Add category\n");
        printf("6. Update category\n");
        printf("7. Delete expense\n");
        printf("8. Delete category\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_expense(&expense_head);
                break;
            case 2:
                view_expenses(expense_head);
                break;
            case 3:
                view_expenses_by_category(expense_head);
                break;
            case 4:
                view_categories(category_head);
                break;
            case 5:
                add_category(&category_head);
                break;
            case 6:
                update_category(expense_head, category_head);
                break;
            case 7:
                delete_expense(&expense_head, category_head);
                break;
            case 8:
                delete_category(&category_head);
                break;
            case 9:
                printf("Exiting program... \n");
                break;
            default:
                printf("Invalid choice. Please try again. \n");
                break;
        }
    } while(choice != 9);

    return 0;
}

void add_expense(struct Expense **head) {
    struct Expense *new_expense = malloc(sizeof(struct Expense));
    new_expense->next = NULL;

    // Get input from user
    printf("Enter expense item: ");
    scanf("%s", new_expense->item);
    printf("Enter expense cost: ");
    scanf("%f", &new_expense->cost);
    printf("Enter expense category: ");
    scanf("%s", new_expense->category);
    printf("Enter expense date (yyyy-mm-dd): ");
    scanf("%s", new_expense->date);

    // Add to linked list
    if(*head == NULL) {
        *head = new_expense;
    } else {
        struct Expense *current = *head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = new_expense;
    }

    printf("Expense added successfully. \n");
}

void view_expenses(struct Expense *head) {
    printf("\n%20s %10s %15s %10s\n", "Item", "Cost", "Category", "Date");
    print_separator();

    struct Expense *current = head;

    while(current != NULL) {
        printf("%20s %10.2f %15s %10s\n", current->item, 
            current->cost, current->category, current->date);
        current = current->next;
    }
}

void view_expenses_by_category(struct Expense *head) {
    char category_name[15];
    printf("Enter category name: ");
    scanf("%s", category_name);

    printf("\n%20s %10s %10s\n", "Item", "Cost", "Date");
    print_separator();

    struct Expense *current = head;

    while(current != NULL) {
        if(strcmp(current->category, category_name) == 0) {
            printf("%20s %10.2f %10s\n", current->item, current->cost, current->date);
        }
        current = current->next;
    }
}

void view_categories(struct Category *head) {
    printf("\n%15s %10s\n", "Category", "Total Cost");
    print_separator();

    struct Category *current = head;

    while(current != NULL) {
        printf("%15s %10.2f\n", current->name, current->total_cost);
        current = current->next;
    }
}

void add_category(struct Category **head) {
    struct Category *new_category = malloc(sizeof(struct Category));
    new_category->next = NULL;

    printf("Enter category name: ");
    scanf("%s", new_category->name);

    // Add to linked list
    if(*head == NULL) {
        *head = new_category;
    } else {
        struct Category *current = *head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = new_category;
    }

    printf("Category added successfully. \n");
}

void update_category(struct Expense *head, struct Category *head_cat) {
    char category_name[15];
    printf("Enter category name: ");
    scanf("%s", category_name);

    // Find category in linked list
    struct Category *current_cat = head_cat;

    while(current_cat != NULL) {
        if(strcmp(current_cat->name, category_name) == 0) {
            break;
        }
        current_cat = current_cat->next;
    }

    if(current_cat == NULL) {
        printf("Category does not exist. \n");
        return;
    }

    // Update the total cost for the category
    struct Expense *current_expense = head;
    float total_cost = 0;

    while(current_expense != NULL) {
        if(strcmp(current_expense->category, category_name) == 0) {
            total_cost += current_expense->cost;
        }
        current_expense = current_expense->next;
    }

    current_cat->total_cost = total_cost;

    printf("Category updated successfully. \n");
}

void delete_expense(struct Expense **head, struct Category *head_cat) {
    char item_name[20];
    printf("Enter expense item to delete: ");
    scanf("%s", item_name);

    struct Expense *current_expense = *head;
    struct Expense *previous_expense = NULL;

    while(current_expense != NULL) {
        if(strcmp(current_expense->item, item_name) == 0) {

            // Update the total cost for the category
            struct Category *current_cat = head_cat;

            while(current_cat != NULL) {
                if(strcmp(current_cat->name, current_expense->category) == 0) {
                    current_cat->total_cost -= current_expense->cost;
                    break;
                }
                current_cat = current_cat->next;
            }

            if(previous_expense == NULL) {
                *head = current_expense->next;
            } else {
                previous_expense->next = current_expense->next;
            }
            free(current_expense);
            printf("Expense deleted successfully. \n");
            return;
        }

        previous_expense = current_expense;
        current_expense = current_expense->next;
    }

    printf("Expense not found. \n");
}

void delete_category(struct Category **head) {
    char category_name[15];
    printf("Enter category name to delete: ");
    scanf("%s", category_name);

    struct Category *current = *head;
    struct Category *previous = NULL;

    while(current != NULL) {
        if(strcmp(current->name, category_name) == 0) {
            // Remove category from linked list
            if(previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);

            // Remove all expenses that belong to this category
            struct Expense *current_expense = *head;
            struct Expense *previous_expense = NULL;

            while(current_expense != NULL) {
                if(strcmp(current_expense->category, category_name) == 0) {
                    if(previous_expense == NULL) {
                        *head = current_expense->next;
                    } else {
                        previous_expense->next = current_expense->next;
                    }
                    struct Expense *temp = current_expense;
                    current_expense = current_expense->next;
                    free(temp);
                } else {
                    previous_expense = current_expense;
                    current_expense = current_expense->next;
                }
            }

            printf("Category deleted successfully. \n");
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Category not found. \n");
}

void print_separator() {
    printf("----------------------------------------------------------\n");
}
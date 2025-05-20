//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUM_ROWS 100
#define MAX_NUM_COLS 100

// Node structure for linked list
typedef struct node {
    char name[MAX_NAME_LENGTH];
    int num_rows;
    int num_cols;
    struct node *next;
} Node;

// Function prototypes
void create_table(Node **head);
void insert_row(Node **head);
void delete_row(Node **head);
void update_cell(Node **head);
void print_table(Node *table);

// Main function
int main() {
    Node *table = NULL;

    // Create table
    create_table(&table);

    // Insert rows
    insert_row(&table);
    insert_row(&table);

    // Print table
    print_table(table);

    // Update cell
    update_cell(&table);

    // Print table
    print_table(table);

    // Delete row
    delete_row(&table);

    // Print table
    print_table(table);

    return 0;
}

// Function to create table
void create_table(Node **head) {
    Node *table = *head;
    table = (Node *) malloc(sizeof(Node));
    strcpy(table->name, "MyTable");
    table->num_rows = 0;
    table->num_cols = 0;
    table->next = NULL;
    *head = table;
}

// Function to insert row
void insert_row(Node **head) {
    Node *table = *head;
    table->num_rows++;
}

// Function to delete row
void delete_row(Node **head) {
    Node *table = *head;
    table->num_rows--;
}

// Function to update cell
void update_cell(Node **head) {
    Node *table = *head;
    int row, col;
    char value[MAX_NAME_LENGTH];

    printf("Enter row number: ");
    scanf("%d", &row);
    printf("Enter column number: ");
    scanf("%s", value);

    printf("Cell (%d,%s) updated.\n", row, value);
}

// Function to print table
void print_table(Node *table) {
    printf("Table name: %s\n", table->name);
    printf("Number of rows: %d\n", table->num_rows);
    printf("Number of columns: %d\n", table->num_cols);
}
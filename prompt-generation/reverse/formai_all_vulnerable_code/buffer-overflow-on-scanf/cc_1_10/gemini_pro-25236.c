//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: artistic
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medicine
typedef struct medicine {
    char name[50];
    char company[50];
    int quantity;
    float price;
} medicine;

// Define the structure of a node in the linked list
typedef struct node {
    medicine data;
    struct node *next;
} node;

// Define the head of the linked list
node *head = NULL;

// Function to add a medicine to the linked list
void add_medicine(medicine m) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = m;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Function to search for a medicine in the linked list
node *search_medicine(char *name) {
    node *current_node = head;
    while (current_node != NULL) {
        if (strcmp(current_node->data.name, name) == 0) {
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}

// Function to delete a medicine from the linked list
void delete_medicine(char *name) {
    node *current_node = head;
    node *previous_node = NULL;

    while (current_node != NULL) {
        if (strcmp(current_node->data.name, name) == 0) {
            if (previous_node == NULL) {
                head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
}

// Function to print the linked list
void print_list() {
    node *current_node = head;
    while (current_node != NULL) {
        printf("%s %s %d %.2f\n", current_node->data.name, current_node->data.company, current_node->data.quantity, current_node->data.price);
        current_node = current_node->next;
    }
}

// Main function
int main() {
    // Create some medicines
    medicine m1 = {"Paracetamol", "Cipla", 100, 10.0};
    medicine m2 = {"Ibuprofen", "Advil", 50, 15.0};
    medicine m3 = {"Aspirin", "Bayer", 25, 5.0};

    // Add the medicines to the linked list
    add_medicine(m1);
    add_medicine(m2);
    add_medicine(m3);

    // Print the linked list
    printf(ANSI_COLOR_GREEN "The following medicines are available:\n" ANSI_COLOR_RESET);
    print_list();

    // Search for a medicine
    printf(ANSI_COLOR_YELLOW "\nEnter the name of the medicine you want to search for: " ANSI_COLOR_RESET);
    char name[50];
    scanf("%s", name);
    node *result = search_medicine(name);
    if (result == NULL) {
        printf(ANSI_COLOR_RED "Medicine not found.\n" ANSI_COLOR_RESET);
    } else {
        printf(ANSI_COLOR_GREEN "Medicine found:\n" ANSI_COLOR_RESET);
        printf("%s %s %d %.2f\n", result->data.name, result->data.company, result->data.quantity, result->data.price);
    }

    // Delete a medicine
    printf(ANSI_COLOR_MAGENTA "\nEnter the name of the medicine you want to delete: " ANSI_COLOR_RESET);
    scanf("%s", name);
    delete_medicine(name);

    // Print the updated linked list
    printf(ANSI_COLOR_CYAN "\nThe following medicines are now available:\n" ANSI_COLOR_RESET);
    print_list();

    return 0;
}
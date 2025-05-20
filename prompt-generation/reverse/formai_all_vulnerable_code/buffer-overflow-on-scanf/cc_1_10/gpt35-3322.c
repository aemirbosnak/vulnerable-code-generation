//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to store element details
struct Element {
    char name[50];
    char symbol[10];
    int atomic_number;
    float atomic_weight;
};

// function to add new element to the table
void addElement(struct Element table[], int *num_elements) {
    struct Element new_element;
    printf("\nEnter details of new element:\n");
    printf("Name: ");
    scanf("%s", new_element.name);
    printf("Symbol: ");
    scanf("%s", new_element.symbol);
    printf("Atomic number: ");
    scanf("%d", &new_element.atomic_number);
    printf("Atomic weight: ");
    scanf("%f", &new_element.atomic_weight);
    table[*num_elements] = new_element;
    (*num_elements)++;
    printf("\nNew element added to the table!\n");
}

// function to display the entire table of elements
void displayTable(struct Element table[], int num_elements) {
    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("|    Name      |   Symbol   |  Atomic Number  |  Atomic Weight  |\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < num_elements; i++) {
        printf("|%-14s|", table[i].name);
        printf("%-12s|", table[i].symbol);
        printf("%-17d|", table[i].atomic_number);
        printf("%-17.2f|\n", table[i].atomic_weight);
    }
    printf("------------------------------------------------------------\n");
}

// function to search for an element by its symbol
void searchBySymbol(struct Element table[], int num_elements) {
    char symbol[10];
    printf("\nEnter symbol to search: ");
    scanf("%s", symbol);
    for (int i = 0; i < num_elements; i++) {
        if (strcmp(table[i].symbol, symbol) == 0) {
            printf("\n%s (%s)\n", table[i].name, table[i].symbol);
            printf("Atomic number: %d\n", table[i].atomic_number);
            printf("Atomic weight: %.2f\n", table[i].atomic_weight);
            return;
        }
    }
    printf("\nElement not found in the table.\n");
}

int main() {
    struct Element table[118];
    int num_elements = 0;
    int choice;
    printf("\n---- C Periodic Table Quiz ----\n");
    printf("Please select an option below:\n");
    while (1) {
        printf("1. Add new element to the table\n");
        printf("2. Display the entire table of elements\n");
        printf("3. Search for an element by symbol\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addElement(table, &num_elements);
                break;
            case 2:
                displayTable(table, num_elements);
                break;
            case 3:
                searchBySymbol(table, num_elements);
                break;
            case 4:
                printf("\nExiting the program...\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }
    return 0;
}
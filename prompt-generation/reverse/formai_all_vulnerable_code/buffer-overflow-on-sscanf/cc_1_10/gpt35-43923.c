//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 20
#define TABLE_SIZE 118

// Element struct to store element information
typedef struct Element {
    char symbol[3];
    char name[30];
    int atomic_number;
    float atomic_weight;
} Element;

// Function to convert user input symbol to uppercase
void uppercase(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}

// Function to load the periodic table from a file
void load_table(Element table[]) {
    FILE *fp = fopen("periodictable.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not read periodic table.\n");
        exit(1);
    }

    char line[100];
    int i = 0;
    while (fgets(line, 100, fp) != NULL && i < TABLE_SIZE) {
        sscanf(line, "%d %s %f %[^\n]s", &table[i].atomic_number, table[i].symbol, &table[i].atomic_weight, table[i].name);
        i++;
    }

    fclose(fp);
}

// Function to get user input and check if it's valid
bool get_input(char *input) {
    printf("Enter the chemical symbol of an element (or 'exit' to quit): ");
    scanf("%s", input);
    uppercase(input);
    if (strcmp(input, "EXIT") == 0) {
        return false;
    }
    if (strlen(input) < 1 || strlen(input) > 2) {
        printf("Error: Invalid input.\n");
        return false;
    }
    return true;
}

// Function to search for an element by symbol
void search_symbol(Element table[], char *symbol) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (strcmp(table[i].symbol, symbol) == 0) {
            printf("%s (%s)\n", table[i].name, table[i].symbol);
            printf("Atomic Number: %d\n", table[i].atomic_number);
            printf("Atomic Weight: %f\n", table[i].atomic_weight);
            return;
        }
    }
    printf("Element not found.\n");
}

// Function to search for an element by name
void search_name(Element table[], char *name) {
    bool found = false;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (strstr(table[i].name, name) != NULL) {
            printf("%s (%s)\n", table[i].name, table[i].symbol);
            printf("Atomic Number: %d\n", table[i].atomic_number);
            printf("Atomic Weight: %f\n", table[i].atomic_weight);
            found = true;
        }
    }
    if (!found) {
        printf("Element not found.\n");
    }
}

// Main function
int main() {
    Element table[TABLE_SIZE];
    load_table(table);

    char input[MAX_INPUT_SIZE];
    bool running = true;
    while (running) {
        if (get_input(input)) {
            search_symbol(table, input);
            search_name(table, input);
        } else {
            running = false;
        }
    }

    return 0;
}
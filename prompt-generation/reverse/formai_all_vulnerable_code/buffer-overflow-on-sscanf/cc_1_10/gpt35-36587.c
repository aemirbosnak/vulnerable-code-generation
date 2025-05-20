//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118

typedef struct Element {
    int atomic_number;
    char symbol[3];
    char name[50];
    char category[20];
    float atomic_weight;
} Element;

void initialize_table(Element* table) {
    FILE *file = fopen("periodic_table.txt", "r");
    if (file == NULL) {
        printf("Error: cannot open file\n");
        exit(1);
    }

    char line[100];
    int current_element = 0;

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d,%2s,%[^,],%[^,],%f", 
            &table[current_element].atomic_number, 
            table[current_element].symbol, 
            table[current_element].name, 
            table[current_element].category, 
            &table[current_element].atomic_weight);
        current_element++;
    }

    fclose(file);
}

void print_table(Element* table) {
    printf("%-4s %-2s %-20s %-15s %s\n", "No.", "Sb", "Name", "Category", "Weight");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printf("%-4d %-2s %-20s %-15s %5.2f\n", 
            table[i].atomic_number, 
            table[i].symbol, 
            table[i].name, 
            table[i].category, 
            table[i].atomic_weight);
    }
}

int get_number(char input[]) {
    int number;
    if (sscanf(input, "%d", &number) == 1) {
        return number;
    }
    printf("Invalid input. Please enter a number.\n");
    return -1;
}

void search_by_number(Element* table) {
    char input[10];
    printf("Enter atomic number: ");
    fgets(input, sizeof(input), stdin);
    int number = get_number(input);

    if (number != -1) {
        if (number >= 1 && number <= MAX_ELEMENTS) {
            printf("%-4s %-2s %-20s %-15s %s\n", "No.", "Sb", "Name", "Category", "Weight");
            printf("%-4d %-2s %-20s %-15s %5.2f\n", 
                table[number-1].atomic_number, 
                table[number-1].symbol, 
                table[number-1].name, 
                table[number-1].category, 
                table[number-1].atomic_weight);
        } else {
            printf("Invalid atomic number.\n");
        }
    }
}

void search_by_symbol(Element* table) {
    char symbol[3];
    printf("Enter symbol: ");
    fgets(symbol, sizeof(symbol), stdin);

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (strcmp(table[i].symbol, symbol) == 0) {
            printf("%-4s %-2s %-20s %-15s %s\n", "No.", "Sb", "Name", "Category", "Weight");
            printf("%-4d %-2s %-20s %-15s %5.2f\n", 
                table[i].atomic_number, 
                table[i].symbol, 
                table[i].name, 
                table[i].category, 
                table[i].atomic_weight);
            return;
        }
    }

    printf("Element not found.\n");
}

void search_table(Element* table) {
    char input[10];
    printf("Enter search type (1: by atomic number, 2: by symbol): ");
    fgets(input, sizeof(input), stdin);

    int type = get_number(input);

    if (type == 1) {
        search_by_number(table);
    } else if (type == 2) {
        search_by_symbol(table);
    } else {
        printf("Invalid search type.\n");
    }
}

int main() {
    Element periodic_table[MAX_ELEMENTS];
    initialize_table(periodic_table);

    printf("Welcome to the Periodic Table quiz!\n\n");
    printf("There are %d known chemical elements in the periodic table.\n", MAX_ELEMENTS);
    printf("To search for an element, enter the atomic number or symbol.\n");

    while (1) {
        printf("\nEnter command (quit, show, search): ");
        char command[10];
        fgets(command, sizeof(command), stdin);

        if (strncmp(command, "quit", 4) == 0) {
            printf("Goodbye!\n");
            break;
        } else if (strncmp(command, "show", 4) == 0) {
            print_table(periodic_table);
        } else if (strncmp(command, "search", 6) == 0) {
            search_table(periodic_table);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
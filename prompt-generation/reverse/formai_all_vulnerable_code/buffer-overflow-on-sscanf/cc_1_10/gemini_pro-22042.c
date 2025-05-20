//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ELEMENTS 118
#define MAX_NAME 20
#define MAX_SYMBOL 3
#define MAX_ATOMIC_NUMBER 3

typedef struct {
    int atomic_number;
    char name[MAX_NAME];
    char symbol[MAX_SYMBOL];
    double atomic_weight;
    char group;
    char period;
    char block;
} element;

element periodic_table[ELEMENTS];

void load_periodic_table() {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("periodic_table.txt", "r");
    if (fp == NULL) {
        perror("Error opening periodic table file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%d %s %s %lf %c %c %c", &periodic_table[i].atomic_number, periodic_table[i].name, periodic_table[i].symbol, &periodic_table[i].atomic_weight, &periodic_table[i].group, &periodic_table[i].period, &periodic_table[i].block);
        i++;
    }

    fclose(fp);
}

void print_periodic_table() {
    int i;

    printf("%-10s %-20s %-3s %-10s %-2s %-2s %-2s\n", "Atomic Number", "Name", "Symbol", "Atomic Weight", "Group", "Period", "Block");
    for (i = 0; i < ELEMENTS; i++) {
        printf("%-10d %-20s %-3s %-10.2lf %-2c %-2c %-2c\n", periodic_table[i].atomic_number, periodic_table[i].name, periodic_table[i].symbol, periodic_table[i].atomic_weight, periodic_table[i].group, periodic_table[i].period, periodic_table[i].block);
    }
}

void search_periodic_table() {
    char input[MAX_NAME];
    int i;

    printf("Enter the name or symbol of the element you want to search for: ");
    scanf("%s", input);

    for (i = 0; i < ELEMENTS; i++) {
        if (strcmp(input, periodic_table[i].name) == 0 || strcmp(input, periodic_table[i].symbol) == 0) {
            printf("Atomic Number: %d\n", periodic_table[i].atomic_number);
            printf("Name: %s\n", periodic_table[i].name);
            printf("Symbol: %s\n", periodic_table[i].symbol);
            printf("Atomic Weight: %.2lf\n", periodic_table[i].atomic_weight);
            printf("Group: %c\n", periodic_table[i].group);
            printf("Period: %c\n", periodic_table[i].period);
            printf("Block: %c\n", periodic_table[i].block);
            break;
        }
    }

    if (i == ELEMENTS) {
        printf("No matching element found\n");
    }
}

int main() {
    int choice;

    load_periodic_table();

    do {
        printf("\nPeriodic Table Quiz\n");
        printf("1. Print Periodic Table\n");
        printf("2. Search Periodic Table\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_periodic_table();
                break;
            case 2:
                search_periodic_table();
                break;
            case 3:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}
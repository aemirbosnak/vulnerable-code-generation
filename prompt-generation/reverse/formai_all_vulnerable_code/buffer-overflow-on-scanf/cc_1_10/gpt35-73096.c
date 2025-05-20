//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element {
    char symbol[3];
    char name[20];
    int atomicNumber;
};

void addElement(struct element table[], int *size);
void displayTable(struct element table[], int size);
void searchTable(struct element table[], int size);
void deleteElement(struct element table[], int *size);

int main() {
    int size = 0;
    struct element table[118];
    int choice;
    do {
        printf("\nC PERIODIC TABLE QUIZ\n");
        printf("1. Add element to table\n");
        printf("2. Display table\n");
        printf("3. Search for element\n");
        printf("4. Delete element from table\n");
        printf("5. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addElement(table, &size);
                break;
            case 2:
                displayTable(table, size);
                break;
            case 3:
                searchTable(table, size);
                break;
            case 4:
                deleteElement(table, &size);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 5);
    return 0;
}

void addElement(struct element table[], int *size) {
    char symbol[3];
    char name[20];
    int atomicNumber;

    printf("\nEnter element symbol: ");
    scanf("%s", symbol);
    printf("Enter element name: ");
    scanf("%s", name);
    printf("Enter atomic number: ");
    scanf("%d", &atomicNumber);

    strcpy(table[*size].symbol, symbol);
    strcpy(table[*size].name, name);
    table[*size].atomicNumber = atomicNumber;
    (*size)++;

    printf("\nElement added to table.\n");
}

void displayTable(struct element table[], int size) {
    if (size == 0) {
        printf("\nTable is empty.\n");
    }
    else {
        printf("\n\t  SYMBOL\t\tNAME\t\tATOMIC NUMBER\n");
        printf("\t-------------------------------------------------\n");
        for (int i = 0; i < size; i++) {
            printf("\t  %-2s\t\t%-15s\t%d\n", table[i].symbol, table[i].name, table[i].atomicNumber);
        }
        printf("\t-------------------------------------------------\n");
        printf("\n");
    }
}

void searchTable(struct element table[], int size) {
    char symbol[3];
    printf("\nEnter element symbol: ");
    scanf("%s", symbol);

    for (int i = 0; i < size; i++) {
        if (strcmp(table[i].symbol, symbol) == 0) {
            printf("\nElement found:\n");
            printf("Symbol: %s\n", table[i].symbol);
            printf("Name: %s\n", table[i].name);
            printf("Atomic number: %d\n", table[i].atomicNumber);
            return;
        }
    }
    printf("\nElement not found.\n");
}

void deleteElement(struct element table[], int *size) {
    char symbol[3];
    printf("\nEnter element symbol: ");
    scanf("%s", symbol);

    for (int i = 0; i < *size; i++) {
        if (strcmp(table[i].symbol, symbol) == 0) {
            for (int j = i; j < *size - 1; j++) {
                strcpy(table[j].symbol, table[j+1].symbol);
                strcpy(table[j].name, table[j+1].name);
                table[j].atomicNumber = table[j+1].atomicNumber;
            }
            (*size)--;
            printf("\nElement deleted from table.\n");
            return;
        }
    }
    printf("\nElement not found.\n");
}
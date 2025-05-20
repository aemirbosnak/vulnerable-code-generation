//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

struct Element {
    char symbol[3];
    char name[25];
    int atomicNumber;
    float atomicMass;
};

void addElement(struct Element elements[], int *count) {
    printf("\nEnter the symbol of the element: ");
    scanf("%s", elements[*count].symbol);
    printf("Enter the name of the element: ");
    scanf("%s", elements[*count].name);
    printf("Enter the atomic number of the element: ");
    scanf("%d", &elements[*count].atomicNumber);
    printf("Enter the atomic mass of the element: ");
    scanf("%f", &elements[*count].atomicMass);
    (*count)++;
}

void displayTable(struct Element elements[], int count) {
    printf("\nPeriodic Table\n");
    for(int i = 0; i < count; i++) {
        printf("%s\t%s\t%d\t%.2f\n", elements[i].symbol, elements[i].name, elements[i].atomicNumber, elements[i].atomicMass);
    }
}


int main() {
    struct Element elements[118];
    int count = 0;
    int choice;
    while(1) {
        printf("\nMenu\n");
        printf("1. Add Element\n");
        printf("2. Display Table\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addElement(elements, &count);
                break;
            case 2:
                displayTable(elements, count);
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
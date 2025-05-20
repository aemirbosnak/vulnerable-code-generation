//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: protected
#include <stdio.h>
#include <string.h>

// structure to hold element data
typedef struct Element {
    int atomicNumber;
    char symbol[3];
    char name[50];
    char category[20];
    float atomicMass;
} Element;

// array of elements
Element elements[] = {
    {1, "H", "Hydrogen", "Nonmetal", 1.008},
    {2, "He", "Helium", "Noble gas", 4.003},
    {3, "Li", "Lithium", "Alkali metal", 6.941},
    {4, "Be", "Beryllium", "Alkaline earth metal", 9.012},
    // ... add more elements here ...
    {118, "Og", "Oganesson", "Unknown", 294.214}
};

// function to get element from atomic number
Element getElementByAtomicNumber(int atomicNumber) {
    int elementsCount = sizeof(elements) / sizeof(elements[0]);
    for (int i = 0; i < elementsCount; i++) {
        if (elements[i].atomicNumber == atomicNumber) {
            return elements[i];
        }
    }
    // return an element with atomicNumber -1 if not found
    Element notFound = {-1, "", "", "", 0.0};
    return notFound;
}

// function to get element from symbol
Element getElementBySymbol(char symbol[]) {
    int elementsCount = sizeof(elements) / sizeof(elements[0]);
    for (int i = 0; i < elementsCount; i++) {
        if (strcmp(elements[i].symbol, symbol) == 0) {
            return elements[i];
        }
    }
    // return an element with atomicNumber -1 if not found
    Element notFound = {-1, "", "", "", 0.0};
    return notFound;
}

// function to print element information
void printElement(Element element) {
    printf("%s (%s)\n", element.name, element.symbol);
    printf("Atomic number: %d\n", element.atomicNumber);
    printf("Category: %s\n", element.category);
    printf("Atomic mass: %.3f\n", element.atomicMass);
}

int main() {
    int choice;
    do {
        printf("----- C Periodic Table Quiz -----\n");
        printf("1. Get element by atomic number\n");
        printf("2. Get element by symbol\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            int atomicNumber;
            printf("Enter atomic number: ");
            scanf("%d", &atomicNumber);
            Element element = getElementByAtomicNumber(atomicNumber);
            if (element.atomicNumber != -1) {
                printElement(element);
            } else {
                printf("Element not found.\n");
            }
        } else if (choice == 2) {
            char symbol[3];
            printf("Enter symbol: ");
            scanf("%s", symbol);
            Element element = getElementBySymbol(symbol);
            if (element.atomicNumber != -1) {
                printElement(element);
            } else {
                printf("Element not found.\n");
            }
        } else if (choice != 3) {
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}
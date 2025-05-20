//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
    float atomic_mass;
};

typedef struct element Element;

// Function to display menu
void display_menu() {
    printf("\n\n***** C PERIODIC TABLE QUIZ *****\n\n");
    printf("1. Start Quiz\n");
    printf("2. Add New Element\n");
    printf("3. Display Periodic Table\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
}

// Function to start Quiz
void start_quiz() {
    FILE *fp;
    Element e;
    char guess[3];

    fp = fopen("periodic_table.dat", "rb");   // Open data file in read mode

    if (fp == NULL) {
        printf("\nError opening file\n");
        return;
    }

    printf("\nQUIZ STARTED!\n");
    printf("Guess the element from its symbol:\n");

    while (fread(&e, sizeof(Element), 1, fp) == 1) {
        printf("\n%s: ", e.symbol);
        scanf("%s", guess);

        if (strcmp(guess, e.symbol) == 0) {
            printf("Correct!\n");
        } else {
            printf("Incorrect! The correct answer is %s.\n", e.symbol);
        }
    }

    fclose(fp);
}

// Function to add new element
void add_element() {
    Element e;

    printf("\nEnter element symbol: ");
    scanf("%s", e.symbol);

    printf("Enter element name: ");
    scanf("%s", e.name);

    printf("Enter atomic number: ");
    scanf("%d", &e.atomic_number);

    printf("Enter atomic mass: ");
    scanf("%f", &e.atomic_mass);

    FILE *fp;
    fp = fopen("periodic_table.dat", "ab"); // Open data file in append mode

    if (fp == NULL) {
        printf("\nError opening file\n");
        return;
    }

    fwrite(&e, sizeof(Element), 1, fp);  // Write data to file

    printf("\nElement added to file successfully!\n");

    fclose(fp);
}

// Function to display Periodic Table
void display_periodic_table() {
    FILE *fp;
    Element e;

    fp = fopen("periodic_table.dat", "rb");   // Open data file in read mode

    if (fp == NULL) {
        printf("\nError opening file\n");
        return;
    }

    printf("\n\n**** PERIODIC TABLE ****\n\n");
    printf("Symbol\tName\tAtomic Number\tAtomic Mass\n");

    while (fread(&e, sizeof(Element), 1, fp) == 1) {
        printf("%s\t%s\t%d\t\t%.2f\n", e.symbol, e.name, e.atomic_number, e.atomic_mass);
    }

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: start_quiz();
                    break;
            case 2: add_element();
                    break;
            case 3: display_periodic_table();
                    break;
            case 4: printf("\nExiting program...\n");
                    exit(0);
            default: printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
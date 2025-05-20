//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ELEMENTS 118

// Element struct to hold element details
typedef struct {
    char symbol[3];
    char name[30];
    int atomic_number;
    double atomic_mass;
} Element;

// Function to retrieve element data from file
void read_elements(Element *elements) {
    FILE *fp;
    fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char line[100];
    int index = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%s %s %d %lf", elements[index].symbol, elements[index].name, &elements[index].atomic_number, &elements[index].atomic_mass);
        index++;
    }
    fclose(fp);
}

// Function to display periodic table
void display_table(Element *elements) {
    printf("        +---------------+\n");
    printf("        |               |\n");
    printf("        |  H    He     |\n");
    printf("  +-----+---------------+\n");
    printf("  | Li  |  Be    B  C  N |\n");
    printf("  +-----+---------------+\n");
    printf("  | Na  |  Mg    Al Si P |\n");
    printf("  +-----+---------------+\n");
    printf("  | K  Ca|  Sc Ti V  Cr |\n");
    printf("  +-----+---------------+\n");
    printf("  | Mn Fe|  Co Ni Cu Zn |\n");
    printf("  +-----+---------------+\n");
    printf("  | Ga  |  Ge    As Se Br|\n");
    printf("  +-----+---------------+\n");
    printf("  | Rb Sr|  Y  Zr Nb Mo |\n");
    printf("  +-----+---------------+\n");
    printf("  | Tc Ru|  Rh Pd Ag Cd |\n");
    printf("  +-----+---------------+\n");
    printf("  | In Sn|  Sb Te  I Xe |\n");
    printf("  +-----+---------------+\n");
    printf("  | Cs Ba|  La Hf Ta  W |\n");
    printf("  +-----+---------------+\n");
    printf("  | Re Os|  Ir Pt Au Hg |\n");
    printf("  +-----+---------------+\n");
    printf("  | Tl Pb|  Bi Po At Rn |\n");
    printf("  +-----+---------------+\n");
    printf("     Fr Ra|  Ac Rf Db Sg |\n");
    printf("        +---------------+\n");

}

// Function to get user's choice and display corresponding element
void get_element(Element *elements) {
    int choice = 0;
    do {
        printf("Enter the atomic number of an element to see its details (enter 0 to exit): ");
        scanf("%d", &choice);
        if (choice < 0 || choice > NUM_ELEMENTS || choice == 85) {
            printf("Invalid choice, please enter valid atomic number\n");
        } else if (choice != 0) {
            printf("\nSymbol: %s\nName: %s\nAtomic Number: %d\nAtomic Mass: %.4f\n\n", elements[choice-1].symbol, elements[choice-1].name, elements[choice-1].atomic_number, elements[choice-1].atomic_mass);
        }
    } while(choice != 0);

}

int main() {

    Element elements[NUM_ELEMENTS];
    read_elements(elements);

    printf("Welcome to the C Periodic Table Quiz!\n\n");
    printf("Here is the periodic table:\n");
    display_table(elements);

    get_element(elements);

    printf("Thanks for using the quiz!\n");

    return 0;
}
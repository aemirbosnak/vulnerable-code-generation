//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAX_ELEMENTS 118 //maximum number of elements in the periodic table
#define MAX_NAME_LENGTH 15 //maximum length of element name
#define MAX_SYMBOL_LENGTH 3 //maximum length of element symbol
#define MAX_ATOMIC_NUMBER_LENGTH 5 //maximum length of atomic number
#define MAX_ATOMIC_WEIGHT_LENGTH 10 //maximum length of atomic weight

typedef struct {
    char name[MAX_NAME_LENGTH]; //element name
    char symbol[MAX_SYMBOL_LENGTH]; //element symbol
    int atomic_number; //atomic number
    double atomic_weight; //atomic weight
} Element;

Element elements[MAX_ELEMENTS]; //array to store all elements

void read_elements_from_file(FILE* file) {
    int i = 0;
    while(i < MAX_ELEMENTS && fscanf(file, "%s %s %d %lf", elements[i].name, elements[i].symbol, &elements[i].atomic_number, &elements[i].atomic_weight)!= EOF) {
        i++;
    }
}

void print_elements_table() {
    printf("+----------------------+----------------------+\n");
    printf("| Element Name         | Element Symbol       |\n");
    printf("+----------------------+----------------------+\n");
    for(int i = 0; i < MAX_ELEMENTS; i++) {
        printf("| %-15s | %-3s |\n", elements[i].name, elements[i].symbol);
    }
    printf("+----------------------+----------------------+\n");
}

void print_element_details(int index) {
    printf("+----------------------+----------------------+\n");
    printf("| Element Name         | %s                 |\n", elements[index].name);
    printf("| Element Symbol       | %s                 |\n", elements[index].symbol);
    printf("| Atomic Number        | %d                  |\n", elements[index].atomic_number);
    printf("| Atomic Weight        | %lf                 |\n", elements[index].atomic_weight);
    printf("+----------------------+----------------------+\n");
}

int main() {
    FILE* file = fopen("elements.txt", "r"); //open the file containing element details
    if(file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    read_elements_from_file(file); //read elements from file
    fclose(file);

    printf("Periodic Table of Elements\n");
    print_elements_table();

    int choice;
    while(1) {
        printf("\nEnter your choice:\n");
        printf("1. Display element details\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element index (0 to %d): ", MAX_ELEMENTS - 1);
                scanf("%d", &choice);
                print_element_details(choice);
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
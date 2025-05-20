//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENTS 118

//struct that defines a single element in periodic table
typedef struct {
    char symbol[3]; //atomic symbol
    char name[20]; //element name
    int atomic_number; //atomic number
    float atomic_weight; //atomic weight
} Element;

//array of elements in periodic table
Element periodic_table[MAX_ELEMENTS] = {
    {"H", "Hydrogen", 1, 1.008},
    {"He", "Helium", 2, 4.003},
    {"Li", "Lithium", 3, 6.941},
    {"Be", "Beryllium", 4, 9.012},
    {"B", "Boron", 5, 10.81},
    {"C", "Carbon", 6, 12.01},
    {"N", "Nitrogen", 7, 14.01},
    {"O", "Oxygen", 8, 16.00},
    {"F", "Fluorine", 9, 19.00},
    {"Ne", "Neon", 10, 20.18},
    //add all the remaining elements in similar way
};

//function to get input from user
int get_input() {
    int choice;
    printf("Choose an option from the following:\n\n");
    printf("1. Find element by atomic number\n");
    printf("2. Find element by symbol\n");
    printf("3. Find element by name\n");
    printf("4. Exit\n\n");
    scanf("%d", &choice);
    return choice;
}

//function to search element by atomic number
void find_element_by_number() {
    int atomic_number, i;
    printf("Enter atomic number: ");
    scanf("%d", &atomic_number);
    for(i = 0; i < MAX_ELEMENTS; i++) {
        if(periodic_table[i].atomic_number == atomic_number) {
            printf("Symbol: %s \nName: %s \nAtomic weight: %f\n\n", periodic_table[i].symbol, periodic_table[i].name, periodic_table[i].atomic_weight);
            return;
        }
    }
    printf("Element not found\n\n");
}

//function to search element by symbol
void find_element_by_symbol() {
    char symbol[3];
    int i;
    printf("Enter symbol: ");
    scanf("%s", symbol);
    for(i = 0; i < MAX_ELEMENTS; i++) {
        if(strcmp(periodic_table[i].symbol, symbol) == 0) {
            printf("Name: %s \nAtomic number: %d \nAtomic weight: %f\n\n", periodic_table[i].name, periodic_table[i].atomic_number, periodic_table[i].atomic_weight);
            return;
        }
    }
    printf("Element not found\n\n");
}

//function to search element by name
void find_element_by_name() {
    char name[20];
    int i;
    printf("Enter name: ");
    scanf("%s", name);
    for(i = 0; i < MAX_ELEMENTS; i++) {
        if(strcmp(periodic_table[i].name, name) == 0) {
            printf("Symbol: %s \nAtomic number: %d \nAtomic weight: %f\n\n", periodic_table[i].symbol, periodic_table[i].atomic_number, periodic_table[i].atomic_weight);
            return;
        }
    }
    printf("Element not found\n\n");
}

int main() {
    int choice;
    do {
        choice = get_input();
        switch(choice) {
            case 1:
                find_element_by_number();
                break;
            case 2:
                find_element_by_symbol();
                break;
            case 3:
                find_element_by_name();
                break;
            case 4:
                printf("Thank you for using the program\n");
                break;
            default:
                printf("Invalid input, try again\n");
        }
    } while(choice != 4);
    return 0;
}
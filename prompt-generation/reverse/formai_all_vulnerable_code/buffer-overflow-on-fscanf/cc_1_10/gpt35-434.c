//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define the maximum number of elements in the periodic table
#define MAX_ELEMENTS 119

//define the structure to hold each element's properties
typedef struct {
    char symbol[3];
    char name[30];
    int atomic_number;
    float atomic_weight;
} element;

//declare the array to hold all the elements of the periodic table
element periodic_table[MAX_ELEMENTS];

//define a function to load the periodic table from file
void load_periodic_table() {
    //open the file for reading
    FILE *file = fopen("periodic_table.txt", "r");
    
    //if the file cannot be opened, print an error and exit
    if (file == NULL) {
        printf("Error: cannot open periodic_table.txt\n");
        exit(1);
    }
    
    //loop through each line of the file and read in the element properties
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        //read in the symbol, name, atomic number, and atomic weight of the element
        fscanf(file, "%s %s %d %f\n", periodic_table[i].symbol,
               periodic_table[i].name, &periodic_table[i].atomic_number,
               &periodic_table[i].atomic_weight);
    }
    
    //close the file
    fclose(file);
}

//define a function to prompt the user for the atomic number of an element and return the element's name
char* get_element_name(int atomic_number) {
    //loop through each element in the periodic table to find the matching atomic number
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (periodic_table[i].atomic_number == atomic_number) {
            return periodic_table[i].name;
        }
    }
    
    //if no element with the given atomic number is found, return NULL
    return NULL;
}

//define the main function
int main() {
    //load the periodic table from file
    load_periodic_table();
    
    //prompt the user for the atomic number of an element and read in the response
    int atomic_number;
    printf("Enter the atomic number of an element: ");
    scanf("%d", &atomic_number);
    
    //get the name of the element with the given atomic number
    char *element_name = get_element_name(atomic_number);
    
    //if the element was found, print its name
    if (element_name != NULL) {
        printf("The element with atomic number %d is %s.\n", atomic_number, element_name);
    } else {
        printf("No element was found with atomic number %d.\n", atomic_number);
    }
    
    //return 0 to indicate successful program completion
    return 0;
}
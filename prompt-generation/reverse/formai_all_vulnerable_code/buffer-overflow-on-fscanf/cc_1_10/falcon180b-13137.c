//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LEN 50
#define MAX_SYMBOL_LEN 3

struct element {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    int atomic_number;
    int group;
    int period;
    int category;
};

void read_elements(struct element *elements) {
    FILE *fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error opening elements.txt\n");
        exit(1);
    }
    
    int count = 0;
    while (fscanf(fp, "%s %s %d %d %d %d", elements[count].name, elements[count].symbol, &elements[count].atomic_number, &elements[count].group, &elements[count].period, &elements[count].category) == 6) {
        count++;
    }
    
    fclose(fp);
}

int main() {
    struct element elements[MAX_ELEMENTS];
    read_elements(elements);
    
    int num_elements = 0;
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].name[0] == '\0') {
            break;
        }
        num_elements++;
    }
    
    printf("There are %d elements in the periodic table:\n", num_elements);
    
    char input[MAX_NAME_LEN];
    while (1) {
        printf("\nEnter the name of an element or type 'quit' to exit: ");
        scanf("%s", input);
        
        if (strcmp(input, "quit") == 0) {
            break;
        }
        
        int i = 0;
        while (elements[i].name[0]!= '\0') {
            if (strcmp(elements[i].name, input) == 0) {
                printf("\n%s\n", elements[i].name);
                printf("Symbol: %s\n", elements[i].symbol);
                printf("Atomic number: %d\n", elements[i].atomic_number);
                printf("Group: %d\n", elements[i].group);
                printf("Period: %d\n", elements[i].period);
                printf("Category: %d\n", elements[i].category);
                printf("\n");
                break;
            }
            i++;
        }
        
        if (elements[i].name[0] == '\0') {
            printf("Element not found.\n");
        }
    }
    
    return 0;
}
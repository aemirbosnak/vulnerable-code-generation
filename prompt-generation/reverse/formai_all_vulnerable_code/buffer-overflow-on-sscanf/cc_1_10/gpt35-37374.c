//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char symbol[3];
    int atomic_number;
    char name[25];
    float atomic_weight;
} Element;

Element periodic_table[118];

// Function to load the periodic table from a file
void load_periodic_table() {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("periodic_table.txt", "r");
    if (fp == NULL) {
        printf("Error: could not load periodic table.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%s %d %s %f", 
            periodic_table[i].symbol,
            &periodic_table[i].atomic_number,
            periodic_table[i].name, 
            &periodic_table[i].atomic_weight);
        i++;
    }

    fclose(fp);
}

// Function to display the periodic table
void display_periodic_table() {
    for (int i = 0; i < 118; i++) {
        printf("%s\t%d\t%s\t%.3f\n",
            periodic_table[i].symbol,
            periodic_table[i].atomic_number,
            periodic_table[i].name,
            periodic_table[i].atomic_weight);
    }
}

int main() {
    int choice, atomic_num;
    char symbol[3];
    Element *element_ptr;
    load_periodic_table();

    while (1) {
        printf("\n1. Display periodic table\n");
        printf("2. Search by atomic number\n");
        printf("3. Search by symbol\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_periodic_table();
                break;
            case 2:
                printf("Enter atomic number: ");
                scanf("%d", &atomic_num);

                element_ptr = NULL;
                for (int i = 0; i < 118; i++) {
                    if (periodic_table[i].atomic_number == atomic_num) {
                        element_ptr = &periodic_table[i];
                        break;
                    }
                }

                if (element_ptr != NULL) {
                    printf("\n%s\nAtomic Number: %d\nAtomic Weight: %.3f\n",
                        element_ptr->name,
                        element_ptr->atomic_number,
                        element_ptr->atomic_weight
                    );
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 3:
                printf("Enter symbol: ");
                scanf("%s", symbol);

                element_ptr = NULL;
                for (int i = 0; i < 118; i++) {
                    if (strcmp(periodic_table[i].symbol, symbol) == 0) {
                        element_ptr = &periodic_table[i];
                        break;
                    }
                }

                if (element_ptr != NULL) {
                    printf("\n%s\nAtomic Number: %d\nAtomic Weight: %.3f\n",
                        element_ptr->name,
                        element_ptr->atomic_number,
                        element_ptr->atomic_weight
                    );
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define functions
void print_menu();
void display_elements();
void display_element_details(int atomic_number);
void search_element_by_symbol(char symbol[]);
void search_element_by_name(char name[]);

// Define main function
int main(void) {
    int choice = 0;
    char symbol[3], name[50];
    printf("Welcome to the Shape-Shifting Periodic Table Quiz!\n\n");
    do {
        print_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                display_elements();
                break;
            case 2:
                printf("Enter element symbol: ");
                scanf("%2s", symbol); // Only read first 2 chars
                search_element_by_symbol(symbol);
                break;
            case 3:
                printf("Enter element name: ");
                scanf(" %[^\n]s", name); // Read whole name input
                search_element_by_name(name);
                break;
            case 4:
                printf("Exiting program. Thanks for playing!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}

// Implement print_menu
void print_menu() {
    printf("------------------------------\n");
    printf("Choose an option:\n");
    printf("1. Display all elements\n");
    printf("2. Search element by symbol\n");
    printf("3. Search element by name\n");
    printf("4. Quit\n");
    printf("------------------------------\n");
}

// Implement display_elements
void display_elements() {
    printf("------------------------------\n");
    printf("Here are all the elements:\n");
    printf("------------------------------\n");
    printf("1. Hydrogen\tH\n");
    printf("2. Helium\tHe\n");
    printf("3. Lithium\tLi\n");
    printf("4. Beryllium\tBe\n");
    printf("5. Boron\tB\n");
    printf("6. Carbon\tC\n");
    printf("7. Nitrogen\tN\n");
    printf("8. Oxygen\tO\n");
    printf("9. Fluorine\tF\n");
    printf("10. Neon\tNe\n");
}

// Implement display_element_details
void display_element_details(int atomic_number) {
    printf("------------------------------\n");
    switch(atomic_number) {
        case 1:
            printf("Hydrogen\nSymbol: H\nAtomic number: 1\n");
            printf("------------------------------\n");
            break;
        case 2:
            printf("Helium\nSymbol: He\nAtomic number: 2\n");
            printf("------------------------------\n");
            break;
        case 3:
            printf("Lithium\nSymbol: Li\nAtomic number: 3\n");
            printf("------------------------------\n");
            break;
        case 4:
            printf("Beryllium\nSymbol: Be\nAtomic number: 4\n");
            printf("------------------------------\n");
            break;
        case 5:
            printf("Boron\nSymbol: B\nAtomic number: 5\n");
            printf("------------------------------\n");
            break;
        case 6:
            printf("Carbon\nSymbol: C\nAtomic number: 6\n");
            printf("------------------------------\n");
            break;
        case 7:
            printf("Nitrogen\nSymbol: N\nAtomic number: 7\n");
            printf("------------------------------\n");
            break;
        case 8:
            printf("Oxygen\nSymbol: O\nAtomic number: 8\n");
            printf("------------------------------\n");
            break;
        case 9:
            printf("Fluorine\nSymbol: F\nAtomic number: 9\n");
            printf("------------------------------\n");
            break;
        case 10:
            printf("Neon\nSymbol: Ne\nAtomic number: 10\n");
            printf("------------------------------\n");
            break;
        default:
            printf("Element not found. Try again.\n");
            break;
    }
}

// Implement search_element_by_symbol
void search_element_by_symbol(char symbol[]) {
    // Convert to upper case
    symbol[0] = toupper(symbol[0]);
    symbol[1] = toupper(symbol[1]);
    if(strcmp(symbol, "H") == 0) {
        display_element_details(1);
    } else if(strcmp(symbol, "HE") == 0) {
        display_element_details(2);
    } else if(strcmp(symbol, "LI") == 0) {
        display_element_details(3);
    } else if(strcmp(symbol, "BE") == 0) {
        display_element_details(4);
    } else if(strcmp(symbol, "B") == 0) {
        display_element_details(5);
    } else if(strcmp(symbol, "C") == 0) {
        display_element_details(6);
    } else if(strcmp(symbol, "N") == 0) {
        display_element_details(7);
    } else if(strcmp(symbol, "O") == 0) {
        display_element_details(8);
    } else if(strcmp(symbol, "F") == 0) {
        display_element_details(9);
    } else if(strcmp(symbol, "NE") == 0) {
        display_element_details(10);
    } else {
        printf("Element not found. Try again.\n");
    }
}

// Implement search_element_by_name
void search_element_by_name(char name[]) {
    // Convert to upper case
    for(int i = 0; i < strlen(name); i++) {
        name[i] = toupper(name[i]);
    }
    if(strcmp(name, "HYDROGEN") == 0) {
        display_element_details(1);
    } else if(strcmp(name, "HELIUM") == 0) {
        display_element_details(2);
    } else if(strcmp(name, "LITHIUM") == 0) {
        display_element_details(3);
    } else if(strcmp(name, "BERYLLIUM") == 0) {
        display_element_details(4);
    } else if(strcmp(name, "BORON") == 0) {
        display_element_details(5);
    } else if(strcmp(name, "CARBON") == 0) {
        display_element_details(6);
    } else if(strcmp(name, "NITROGEN") == 0) {
        display_element_details(7);
    } else if(strcmp(name, "OXYGEN") == 0) {
        display_element_details(8);
    } else if(strcmp(name, "FLUORINE") == 0) {
        display_element_details(9);
    } else if(strcmp(name, "NEON") == 0) {
        display_element_details(10);
    } else {
        printf("Element not found. Try again.\n");
    }
}
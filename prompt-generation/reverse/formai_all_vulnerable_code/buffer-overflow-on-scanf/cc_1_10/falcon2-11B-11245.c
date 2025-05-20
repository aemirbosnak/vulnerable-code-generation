//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct PeriodicTable {
    char symbol[3];
    char name[30];
    char group[5];
    char period[5];
    char block[5];
    char atomic_number[10];
    int atomic_mass_u;
    char element_type[20];
};

struct PeriodicTable elements[100];

int main() {
    int choice;
    int num;
    int element_number;
    int element_number_input;

    printf("Welcome to the Periodic Table Quiz!\n");

    do {
        printf("Enter 1 to start the quiz\n");
        printf("Enter 2 to exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Please enter the atomic number of the element:\n");
                scanf("%d", &element_number);
                element_number_input = element_number;
                while (element_number_input > 100 || element_number_input < 1) {
                    printf("Invalid atomic number! Please try again.\n");
                    scanf("%d", &element_number);
                    element_number_input = element_number;
                }
                for (int i = 0; i < 100; i++) {
                    if (elements[i].atomic_number[0] == element_number_input) {
                        printf("Congratulations! You have correctly identified %s.\n", elements[i].name);
                        break;
                    }
                }
                printf("Sorry, the element you entered is not in the periodic table. Please try again.\n");
                break;
            case 2:
                printf("Thank you for playing the Periodic Table Quiz!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 2);

    return 0;
}
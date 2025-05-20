//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 10

typedef struct Medicine {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Medicine;

void error_exit(const char *msg) {
    fprintf(stderr, "%s: %s\n", __func__, msg);
    exit(1);
}

int main() {
    Medicine inventory[MAX_MEDICINES];
    int num_medicines = 0;

    while (1) {
        printf("\nMedical Store Management System\n");
        printf("------------------------------\n");
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. View Inventory\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        int choice;
        if (scanf("%d", &choice) != 1) {
            error_exit("Invalid input.");
        }

        switch (choice) {
            case 1:
                if (num_medicines >= MAX_MEDICINES) {
                    error_exit("Maximum number of medicines reached.");
                }
                printf("Enter medicine name: ");
                scanf("%s", inventory[num_medicines].name);
                printf("Enter medicine quantity: ");
                scanf("%d", &inventory[num_medicines].quantity);
                num_medicines++;
                break;

            case 2:
                if (num_medicines == 0) {
                    error_exit("Inventory is empty.");
                }
                printf("Enter medicine name to remove: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);

                int i;
                for (i = 0; i < num_medicines; i++) {
                    if (strcmp(name, inventory[i].name) == 0) {
                        inventory[i].quantity = 0;
                        num_medicines--;
                        break;
                    }
                }

                if (i == num_medicines) {
                    error_exit("Medicine not found.");
                }
                break;

            case 3:
                printf("\nCurrent Inventory:\n");
                int j;
                for (j = 0; j < num_medicines; j++) {
                    printf("%s: %d\n", inventory[j].name, inventory[j].quantity);
                }
                break;

            case 4:
                exit(0);

            default:
                error_exit("Invalid choice.");
        }
    }

    return 0;
}
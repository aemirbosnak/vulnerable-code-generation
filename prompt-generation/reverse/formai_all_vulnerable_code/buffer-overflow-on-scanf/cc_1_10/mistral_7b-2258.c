//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MEDICINE_NAME_LENGTH 50
#define MAX_QUANTITY 100

typedef struct Medicine {
    char name[MAX_MEDICINE_NAME_LENGTH];
    int stock;
} Medicine;

void printMedicineList(Medicine medicines[], int numMedicines) {
    int i;
    for (i = 0; i < numMedicines; i++) {
        printf("%s: %d\n", medicines[i].name, medicines[i].stock);
    }
}

int main() {
    Medicine medicines[MAX_QUANTITY];
    int numMedicines = 0;
    char command[5];
    int quantity;

    while (1) {
        printf("\nMedical Store Management System\n");
        printf("Commands:\n");
        printf("  add <name> <quantity>\n");
        printf("  list\n");
        printf("  quit\n");
        printf("Enter command: ");
        scanf("%s", command);

        switch(command[0]) {
            case 'a':
                if (numMedicines < MAX_QUANTITY) {
                    scanf("%s %d", medicines[numMedicines].name, &quantity);
                    medicines[numMedicines++].stock = quantity;
                    for (int i = 0; i < numMedicines; i++) {
                        if (strcmp(medicines[i].name, medicines[numMedicines - 1].name) == 0) {
                            printf("Error: Duplicate medicine name!\n");
                            i = numMedicines;
                            numMedicines--;
                            break;
                        }
                    }
                } else {
                    printf("Error: Store is full!\n");
                }
                break;

            case 'l':
                printMedicineList(medicines, numMedicines);
                break;

            case 'q':
                printf("Quitting...\n");
                exit(0);

            default:
                printf("Error: Unknown command!\n");
                break;
        }
    }

    return 0;
}
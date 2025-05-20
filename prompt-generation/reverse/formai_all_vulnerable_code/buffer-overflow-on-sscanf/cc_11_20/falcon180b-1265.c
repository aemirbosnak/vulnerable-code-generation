//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

int main() {
    FILE *file;
    char line[100];
    int count = 0;
    Medicine medicines[MAX_SIZE];

    file = fopen("medicines.txt", "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        sscanf(line, "%s %d %f", medicines[count].name, &medicines[count].quantity, &medicines[count].price);
        count++;
    }

    fclose(file);

    char choice;
    do {
        printf("\n\nWelcome to the Medical Store Management System!\n");
        printf("Please choose an option:\n");
        printf("1. Add Medicine\n");
        printf("2. Update Medicine\n");
        printf("3. Delete Medicine\n");
        printf("4. View Medicines\n");
        printf("5. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter medicine name: ");
                scanf("%s", medicines[count].name);
                printf("Enter quantity: ");
                scanf("%d", &medicines[count].quantity);
                printf("Enter price: ");
                scanf("%f", &medicines[count].price);
                count++;
                break;
            case '2':
                printf("Enter medicine name to update: ");
                scanf("%s", line);
                for (int i = 0; i < count; i++) {
                    if (strcmp(medicines[i].name, line) == 0) {
                        printf("Enter new quantity: ");
                        scanf("%d", &medicines[i].quantity);
                        printf("Enter new price: ");
                        scanf("%f", &medicines[i].price);
                        break;
                    }
                }
                break;
            case '3':
                printf("Enter medicine name to delete: ");
                scanf("%s", line);
                for (int i = 0; i < count; i++) {
                    if (strcmp(medicines[i].name, line) == 0) {
                        for (int j = i; j < count - 1; j++) {
                            medicines[j] = medicines[j + 1];
                        }
                        count--;
                        break;
                    }
                }
                break;
            case '4':
                printf("Medicines:\n");
                for (int i = 0; i < count; i++) {
                    printf("%s %d %f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
                }
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '5');

    return 0;
}
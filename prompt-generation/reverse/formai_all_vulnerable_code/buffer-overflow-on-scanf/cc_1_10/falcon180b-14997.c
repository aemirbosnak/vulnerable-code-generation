//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

void displayMenu() {
    printf("\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Update item\n");
    printf("4. Display items\n");
    printf("5. Exit\n");
    printf("\n");
}

int main() {
    FILE *fp;
    struct Item items[MAX_SIZE];
    int choice, id, count = 0;

    fp = fopen("items.txt", "rb");

    if (fp == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    while (fread(&items[count], sizeof(struct Item), 1, fp) == 1) {
        count++;
    }

    fclose(fp);

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter item ID: ");
            scanf("%d", &id);

            if (count >= MAX_SIZE) {
                printf("Warehouse full.\n");
            } else {
                printf("Enter item name: ");
                scanf("%s", items[count].name);
                items[count].id = id;
                items[count].quantity = 0;
                items[count].price = 0.0;
                count++;

                fp = fopen("items.txt", "ab");
                fseek(fp, 0, SEEK_END);
                fwrite(&items[count - 1], sizeof(struct Item), 1, fp);
                fclose(fp);

                printf("Item added.\n");
            }
            break;

        case 2:
            printf("Enter item ID: ");
            scanf("%d", &id);

            for (int i = 0; i < count; i++) {
                if (items[i].id == id) {
                    for (int j = i; j < count - 1; j++) {
                        items[j] = items[j + 1];
                    }
                    count--;
                    break;
                }
            }

            fp = fopen("items.txt", "wb");
            for (int i = 0; i < count; i++) {
                fwrite(&items[i], sizeof(struct Item), 1, fp);
            }
            fclose(fp);

            printf("Item removed.\n");
            break;

        case 3:
            printf("Enter item ID: ");
            scanf("%d", &id);

            for (int i = 0; i < count; i++) {
                if (items[i].id == id) {
                    printf("Enter new item name: ");
                    scanf("%s", items[i].name);
                    printf("Enter new quantity: ");
                    scanf("%d", &items[i].quantity);
                    printf("Enter new price: ");
                    scanf("%f", &items[i].price);

                    fp = fopen("items.txt", "rb");
                    fseek(fp, 0, SEEK_END);
                    fwrite(&items[i], sizeof(struct Item), 1, fp);
                    fclose(fp);

                    printf("Item updated.\n");
                }
            }
            break;

        case 4:
            printf("\n");
            for (int i = 0; i < count; i++) {
                printf("%d. %s - %d units - $%.2f\n", items[i].id, items[i].name, items[i].quantity, items[i].price);
            }
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
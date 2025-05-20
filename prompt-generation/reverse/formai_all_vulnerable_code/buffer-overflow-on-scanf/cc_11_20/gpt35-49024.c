//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    int id;
    char name[50];
    float price;
    int quantity;
};

int main() {
    int choice, id, quantity, i;
    float price;
    char name[50];
    struct medicine med;
    FILE *fp;
    fp = fopen("medicine.dat", "rb+");

    while (1) {
        printf("\n\n======= MEDICAL STORE MANAGEMENT SYSTEM =======\n\n");
        printf("1. Add Medicine\n");
        printf("2. Update Medicine\n");
        printf("3. Delete Medicine\n");
        printf("4. Search Medicine\n");
        printf("5. Show Stock\n");
        printf("6. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter medicine ID: ");
                scanf("%d", &med.id);

                printf("Enter medicine name: ");
                scanf("%s", med.name);

                printf("Enter medicine price: ");
                scanf("%f", &med.price);

                printf("Enter quantity available: ");
                scanf("%d", &med.quantity);

                fseek(fp, 0, SEEK_END);
                fwrite(&med, sizeof(struct medicine), 1, fp);
                break;

            case 2:
                printf("\nEnter medicine ID to update: ");
                scanf("%d", &id);

                rewind(fp);

                while (fread(&med, sizeof(struct medicine), 1, fp) == 1) {
                    if (med.id == id) {
                        printf("Enter new name: ");
                        scanf("%s", med.name);

                        printf("Enter new price: ");
                        scanf("%f", &med.price);

                        printf("Enter new quantity: ");
                        scanf("%d", &med.quantity);

                        fseek(fp, -sizeof(struct medicine), SEEK_CUR);
                        fwrite(&med, sizeof(struct medicine), 1, fp);
                        break;
                    }
                }
                break;

            case 3:
                printf("\nEnter medicine ID to delete: ");
                scanf("%d", &id);

                FILE *tempfp;
                tempfp = fopen("temp.dat", "wb");

                rewind(fp);

                while (fread(&med, sizeof(struct medicine), 1, fp) == 1) {
                    if (med.id != id) {
                        fwrite(&med, sizeof(struct medicine), 1, tempfp);
                    }
                }

                fclose(fp);
                fclose(tempfp);

                remove("medicine.dat");
                rename("temp.dat", "medicine.dat");

                fp = fopen("medicine.dat", "rb+");
                break;

            case 4:
                printf("\nEnter medicine ID to search: ");
                scanf("%d", &id);

                rewind(fp);

                while (fread(&med, sizeof(struct medicine), 1, fp) == 1) {
                    if (med.id == id) {
                        printf("Medicine found!\n");
                        printf("ID: %d\n", med.id);
                        printf("Name: %s\n", med.name);
                        printf("Price: %f\n", med.price);
                        printf("Quantity: %d\n", med.quantity);
                        break;
                    }
                }
                break;

            case 5:
                rewind(fp);
                printf("\nMEDICINE STOCK:\n\n ID\tNAME\tPRICE\tQUANTITY\n\n");

                while (fread(&med, sizeof(struct medicine), 1, fp) == 1) {
                    printf("%d\t%s\t%f\t%d\n", med.id, med.name, med.price, med.quantity);
                }
                break;

            case 6:
                fclose(fp);
                exit(0);

            default:
                printf("\nInvalid choice!\n\n");
                break;
        }
    }

    return 0;
}
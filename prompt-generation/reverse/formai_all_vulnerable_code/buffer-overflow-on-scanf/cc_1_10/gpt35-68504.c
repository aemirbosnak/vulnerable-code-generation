//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    int med_id;
    char med_name[50];
    int med_qty;
    float med_price;
};

int main() {
    int n, choice, id, qty, i;
    float price;
    char name[50];
    FILE* fp;
    struct medicine med;
    printf("Welcome to the Medical Store Management System!\n");
    while(1) {
        printf("\nEnter your choice:\n1. Add medicine to inventory\n2. Update medicine quantity\n3. Display inventory\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                fp = fopen("inventory.txt", "a");
                printf("\nEnter the following details:\n");
                printf("Medicine ID: ");
                scanf("%d", &id);
                med.med_id = id;
                printf("Medicine Name: ");
                scanf("%s", name);
                strcpy(med.med_name, name);
                printf("Medicine Quantity: ");
                scanf("%d", &qty);
                med.med_qty = qty;
                printf("Medicine Price: ");
                scanf("%f", &price);
                med.med_price = price;
                fwrite(&med, sizeof(struct medicine), 1, fp);
                fclose(fp);
                printf("\nMedicine added to inventory successfully!\n");
                break;

            case 2:
                fp = fopen("inventory.txt", "r+");
                printf("\nEnter the ID of the medicine you want to update: ");
                scanf("%d", &id);
                while(fread(&med, sizeof(struct medicine), 1, fp)) {
                    if(med.med_id == id) {
                        printf("Enter the updated quantity for %s: ", med.med_name);
                        scanf("%d", &qty);
                        med.med_qty = qty;
                        fseek(fp, (-1)*sizeof(struct medicine), SEEK_CUR);
                        fwrite(&med, sizeof(struct medicine), 1, fp);
                        fclose(fp);
                        printf("\nMedicine quantity updated successfully!\n");
                        break;
                    }
                }
                if(med.med_id != id) {
                    printf("\nMedicine not found in inventory!\n");
                }
                break;

            case 3:
                fp = fopen("inventory.txt", "r");
                printf("\nCurrent Inventory:\n");
                printf("ID\tName\t\tQuantity\tPrice\n");
                while(fread(&med, sizeof(struct medicine), 1, fp)) {
                    printf("%d\t%s\t\t%d\t\t%.2f\n", med.med_id, med.med_name, med.med_qty, med.med_price);
                }
                fclose(fp);
                break;

            case 4:
                printf("\nThank you for using the Medical Store Management System!\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }
    return 0;
}
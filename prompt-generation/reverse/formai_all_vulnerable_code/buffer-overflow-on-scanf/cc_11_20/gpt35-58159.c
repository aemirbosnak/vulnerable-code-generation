//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: mind-bending
#include <stdio.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50
#define MAX_COMPANY_NAME_LENGTH 50
#define MAX_QUANTITY 99999

typedef struct {
    char name[MAX_NAME_LENGTH];
    char company[MAX_COMPANY_NAME_LENGTH];
    float price;
    int quantity;
} medicine_t;

int main() {
    medicine_t medicines[MAX_MEDICINES] = { 0 };
    int num_medicines = 0;

    int choice = 0;
    do {
        printf("\n---------------------\n");
        printf("MEDICAL STORE MANAGEMENT SYSTEM\n");
        printf("---------------------\n");
        printf("1) ADD MEDICINE\n");
        printf("2) SELL MEDICINE\n");
        printf("3) VIEW ALL MEDICINES\n");
        printf("4) EXIT\n\n");

        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (num_medicines >= MAX_MEDICINES) {
                    printf("CANNOT ADD MORE MEDICINES.\n");
                    break;
                }

                printf("\nENTER MEDICINE NAME: ");
                scanf("%s", medicines[num_medicines].name);

                printf("ENTER COMPANY NAME: ");
                scanf("%s", medicines[num_medicines].company);

                printf("ENTER PRICE: ");
                scanf("%f", &medicines[num_medicines].price);

                printf("ENTER QUANTITY: ");
                scanf("%d", &medicines[num_medicines].quantity);

                num_medicines++;
                break;
            }

            case 2: {
                printf("\nENTER MEDICINE NAME TO SELL: ");
                char sell_med_name[MAX_NAME_LENGTH];
                scanf("%s", sell_med_name);

                int sell_med_index = -1;
                for (int i = 0; i < num_medicines; i++) {
                    if (strcmp(medicines[i].name, sell_med_name) == 0) {
                        sell_med_index = i;
                        break;
                    }
                }

                if (sell_med_index < 0) {
                    printf("COULD NOT FIND MEDICINE: %s\n", sell_med_name);
                    break;
                }

                printf("ENTER QUANTITY TO SELL: ");
                int sell_quantity;
                scanf("%d", &sell_quantity);

                if (sell_quantity > medicines[sell_med_index].quantity) {
                    printf("NOT ENOUGH QUANTITY TO SELL.\n");
                    break;
                }

                medicines[sell_med_index].quantity -= sell_quantity;
                printf("SELLING SUCCESSFUL.\n");
                break;
            }

            case 3: {
                printf("\nALL MEDICINES:\n");
                for (int i = 0; i < num_medicines; i++) {
                    printf("MEDICINE %d\n", i+1);
                    printf("\tNAME: %s\n", medicines[i].name);
                    printf("\tCOMPANY: %s\n", medicines[i].company);
                    printf("\tPRICE: %.2f\n", medicines[i].price);
                    printf("\tQUANTITY: %d\n", medicines[i].quantity);
                }
                break;
            }

            case 4: {
                printf("\nTHANK YOU FOR USING MEDICAL STORE MANAGEMENT SYSTEM.\n");
                break;
            }

            default: {
                printf("\nINVALID CHOICE.\n");
                break;
            }
        }
    } while (choice != 4);

    return 0;
}
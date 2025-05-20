//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
};

int main() {
    int choice, i, n, m_id = 0, total_medicines = 0;
    struct medicine *medicines;

    while (1) {
        printf("\n1. Add medicine\n2. Update medicine\n3. Sell medicine\n4. Display all medicines\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter number of medicines to add: ");
                scanf("%d", &n);

                medicines = realloc(medicines, (total_medicines + n) * sizeof(struct medicine));

                for (i = 0; i < n; i++) {
                    printf("\nEnter name of medicine: ");
                    scanf("%s", medicines[total_medicines+i].name);

                    printf("\nEnter quantity of medicine: ");
                    scanf("%d", &medicines[total_medicines+i].quantity);

                    printf("\nMedicine added successfully with id = %d\n", ++m_id);
                }

                total_medicines += n;
                break;

            case 2:
                if (total_medicines == 0) {
                    printf("\nNo medicines available\n");
                    break;
                }

                printf("\nEnter id of medicine to update: ");
                scanf("%d", &i);

                if (i < 1 || i > total_medicines) {
                    printf("\nInvalid medicine id\n");
                    break;
                }

                printf("\nEnter new quantity of medicine: ");
                scanf("%d", &medicines[i-1].quantity);

                printf("\nMedicine updated successfully\n");
                break;

            case 3:
                if (total_medicines == 0) {
                    printf("\nNo medicines available\n");
                    break;
                }

                printf("\nEnter id of medicine to sell: ");
                scanf("%d", &i);

                if (i < 1 || i > total_medicines) {
                    printf("\nInvalid medicine id\n");
                    break;
                }

                if (medicines[i-1].quantity == 0) {
                    printf("\nMedicine not available\n");
                    break;
                }

                medicines[i-1].quantity--;
                printf("\nMedicine sold successfully\n");
                break;

            case 4:
                if (total_medicines == 0) {
                    printf("\nNo medicines available\n");
                    break;
                }

                printf("\nName\t\tQuantity\n");

                for (i = 0; i < total_medicines; i++) {
                    printf("%s\t\t%d\n", medicines[i].name, medicines[i].quantity);
                }

                break;

            case 5:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice\n");
                break;
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine {
    char name[100];
    int quantity;
    float price;
};

int main() {
    int option, count = 0, choice, search_index;
    struct medicine *medicines = NULL;
    char search_name[100];
    float total_price = 0.0;
    FILE *fptr;

    while (1) {
        printf("\n\n--- Medical Store Management System Menu ---\n");
        printf("1. Add Medicine\n");
        printf("2. List All Medicine\n");
        printf("3. Search Medicine\n");
        printf("4. Sell Medicine\n");
        printf("5. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\n--- Add New Medicine ---\n");
                count++;
                medicines = realloc(medicines, count * sizeof(struct medicine));
                printf("Medicine Name: ");
                scanf("%s", medicines[count-1].name);
                printf("Quantity: ");
                scanf("%d", &medicines[count-1].quantity);
                printf("Price: ");
                scanf("%f", &medicines[count-1].price);
                break;
            
            case 2:
                printf("\n--- List Of All Medicines ---\n");
                printf("\nName\tQuantity\tPrice\n");
                for (int i=0; i<count; i++) {
                    printf("%s\t", medicines[i].name);
                    printf("%d\t\t", medicines[i].quantity);
                    printf("%.2f\n", medicines[i].price);
                }
                break;
            
            case 3:
                printf("\n--- Search Medicine ---\n");
                printf("Enter Name Of Medicine: ");
                scanf("%s", search_name);
                search_index = -1;
                for (int i=0; i<count; i++) {
                    if (strcmp(search_name, medicines[i].name) == 0) {
                        search_index = i;
                        break;
                    }
                }
                if (search_index == -1) {
                    printf("Medicine Not Found!\n");
                } else {
                    printf("Name: %s\t", medicines[search_index].name);
                    printf("Quantity: %d\t", medicines[search_index].quantity);
                    printf("Price: %.2f\n", medicines[search_index].price);
                }
                break;
            
            case 4:
                printf("\n--- Sell Medicine ---\n");
                printf("Enter Name Of Medicine: ");
                scanf("%s", search_name);
                search_index = -1;
                for (int i=0; i<count; i++) {
                    if (strcmp(search_name, medicines[i].name) == 0) {
                        search_index = i;
                        break;
                    }
                }
                if (search_index == -1) {
                    printf("Medicine Not Found!\n");
                } else {
                    printf("Name: %s\t", medicines[search_index].name);
                    printf("Quantity Available: %d\t", medicines[search_index].quantity);
                    printf("Price: %.2f\n", medicines[search_index].price);
                    printf("Enter Quantity To Sell: ");
                    scanf("%d", &choice);
                    if (choice > medicines[search_index].quantity) {
                        printf("Requested Quantity Not Available!\n");
                    } else {
                        medicines[search_index].quantity -= choice;
                        total_price += choice * medicines[search_index].price;
                        printf("%d %s Sold Successfully!\n", choice, medicines[search_index].name);
                    }
                }
                break;
            
            case 5:
                printf("\n--- Save And Exit ---\n");
                fptr = fopen("medicines.txt", "w");
                if (fptr == NULL) {
                    printf("Error Creating File!\n");
                    exit(1);
                }
                for (int i=0; i<count; i++) {
                    fprintf(fptr, "%s\n", medicines[i].name);
                    fprintf(fptr, "%d\n", medicines[i].quantity);
                    fprintf(fptr, "%.2f\n", medicines[i].price);
                }
                fclose(fptr);
                printf("Total Sales: %.2f\n", total_price);
                printf("Exiting... Thank You!");
                return 0;
            
            default:
                printf("\nInvalid Option Selected! Please Try Again.\n");

        }
    }

    free(medicines);
    return 0;
}
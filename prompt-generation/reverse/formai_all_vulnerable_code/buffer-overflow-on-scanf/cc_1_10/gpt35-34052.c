//FormAI DATASET v1.0 Category: File handling ; Style: multivariable
#include <stdio.h>

struct product {
    char name[50];
    int id;
    float price;
};

int main() {
    int choice;
    struct product p;
    FILE *fp;

    printf("Enter the operation you want to perform:\n");
    printf("(1) Create a new file\n");
    printf("(2) Append to an existing file\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            fp = fopen("products.txt", "w");
            if(fp == NULL) {
                printf("Error creating file.\n");
                return 1;
            }

            printf("Enter the product name: ");
            scanf("%s", p.name);
            printf("Enter the product ID: ");
            scanf("%d", &p.id);
            printf("Enter the product price: ");
            scanf("%f", &p.price);

            fprintf(fp, "%s %d %.2f\n", p.name, p.id, p.price);

            fclose(fp);
            printf("File created successfully.\n");
            break;

        case 2:
            fp = fopen("products.txt", "a");
            if(fp == NULL) {
                printf("Error opening file.\n");
                return 1;
            }

            printf("Enter the product name: ");
            scanf("%s", p.name);
            printf("Enter the product ID: ");
            scanf("%d", &p.id);
            printf("Enter the product price: ");
            scanf("%f", &p.price);

            fprintf(fp, "%s %d %.2f\n", p.name, p.id, p.price);

            fclose(fp);
            printf("Data written to file successfully.\n");
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
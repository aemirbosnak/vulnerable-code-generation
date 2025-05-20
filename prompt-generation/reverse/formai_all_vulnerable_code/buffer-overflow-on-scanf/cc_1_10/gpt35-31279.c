//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    int id;
    char name[50];
    float price;
    int stock;
};

void display(struct medicine m[], int n);
void add(struct medicine m[], int *n);
void search(struct medicine m[], int n);
void update(struct medicine m[], int n);
void delete(struct medicine m[], int *n);

int main() {
    struct medicine med[20];
    int n = 0;
    int choice;

    do {
        printf("\n--- Medical Store Management System ---\n");
        printf("\n1. Display all medicines\n2. Add medicine\n3. Search medicine\n4. Update medicine\n5. Delete medicine\n6. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(med, n);
                break;
            case 2:
                add(med, &n);
                break;
            case 3:
                search(med, n);
                break;
            case 4:
                update(med, n);
                break;
            case 5:
                delete(med, &n);
                break;
            case 6:
                printf("\nExiting...\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while (choice != 6);
    
    return 0;
}

void display(struct medicine m[], int n) {
    if (n == 0) {
        printf("\nNo medicines to display!\n");
    } else {
        printf("\nID.\tName\t\tPrice\tStock\n");
        for (int i = 0; i < n; i++) {
            printf("%d\t%s\t\t%.2f\t%d\n", m[i].id, m[i].name, m[i].price, m[i].stock);
        }
    }
}

void add(struct medicine m[], int *n) {
    printf("\nEnter the medicine details:\n");

    printf("\nID: ");
    scanf("%d", &m[*n].id);

    printf("Name: ");
    scanf("%s", m[*n].name);

    printf("Price: ");
    scanf("%f", &m[*n].price);

    printf("Stock: ");
    scanf("%d", &m[*n].stock);

    (*n)++;
    printf("\nMedicine added successfully!\n");
}

void search(struct medicine m[], int n) {
    int id, found = 0;

    printf("\nEnter the medicine ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (m[i].id == id) {
            printf("\nMedicine found!\n");
            printf("\nID.\tName\t\tPrice\tStock\n");
            printf("%d\t%s\t\t%.2f\t%d\n", m[i].id, m[i].name, m[i].price, m[i].stock);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nMedicine not found!\n");
    }
}

void update(struct medicine m[], int n) {
    int id, found = 0;

    printf("\nEnter the medicine ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (m[i].id == id) {
            printf("\nEnter the new details for medicine %d:\n", id);

            printf("\nName: ");
            scanf("%s", m[i].name);

            printf("Price: ");
            scanf("%f", &m[i].price);

            printf("Stock: ");
            scanf("%d", &m[i].stock);

            printf("\nMedicine updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nMedicine not found!\n");
    }
}

void delete(struct medicine m[], int *n) {
    int id, found = 0;

    printf("\nEnter the medicine ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *n; i++) {
        if (m[i].id == id) {
            for (int j = i; j < (*n)-1; j++) {
                m[j] = m[j+1];
            }

            (*n)--;
            printf("\nMedicine deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nMedicine not found!\n");
    }
}
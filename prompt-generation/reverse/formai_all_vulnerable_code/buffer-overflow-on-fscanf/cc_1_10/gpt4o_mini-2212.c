//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_LENGTH 256

typedef struct {
    char date[MAX_LENGTH];
    char item[MAX_LENGTH];
    int quantity;
    float price;
    float total;
} SalesRecord;

SalesRecord records[MAX_RECORDS];
int record_count = 0;

void add_record(const char *date, const char *item, int quantity, float price) {
    if (record_count >= MAX_RECORDS) {
        printf("Maximum record limit reached. Cannot add more records.\n");
        return;
    }
    strcpy(records[record_count].date, date);
    strcpy(records[record_count].item, item);
    records[record_count].quantity = quantity;
    records[record_count].price = price;
    records[record_count].total = quantity * price;
    record_count++;
}

void display_records() {
    printf("\nSales Records:\n");
    printf("-----------------------------------------------------------\n");
    printf("| %-10s | %-20s | %-8s | %-8s | %-10s |\n", "Date", "Item", "Quantity", "Price", "Total");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < record_count; i++) {
        printf("| %-10s | %-20s | %-8d | $%-7.2f | $%-10.2f |\n",
               records[i].date, records[i].item, records[i].quantity,
               records[i].price, records[i].total);
    }
    printf("-----------------------------------------------------------\n");
}

void find_max_sales_item() {
    if (record_count == 0) {
        printf("No records available to analyze.\n");
        return;
    }

    char max_item[MAX_LENGTH];
    float max_sales = 0.0f;
    
    for (int i = 0; i < record_count; i++) {
        if (records[i].total > max_sales) {
            max_sales = records[i].total;
            strcpy(max_item, records[i].item);
        }
    }
    
    printf("Item with max sales is '%s' with total sales of $%.2f\n", max_item, max_sales);
}

void find_total_revenue() {
    float total_revenue = 0.0f;
    
    for (int i = 0; i < record_count; i++) {
        total_revenue += records[i].total;
    }
    
    printf("Total revenue generated from sales is $%.2f\n", total_revenue);
}

void save_records_to_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < record_count; i++) {
        fprintf(file, "%s,%s,%d,%.2f,%.2f\n",
                records[i].date, records[i].item, records[i].quantity,
                records[i].price, records[i].total);
    }
    
    fclose(file);
    printf("Records saved to '%s'\n", filename);
}

void load_records_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }

    while (fscanf(file, "%[^,],%[^,],%d,%f,%f\n",
                  records[record_count].date,
                  records[record_count].item,
                  &records[record_count].quantity,
                  &records[record_count].price,
                  &records[record_count].total) != EOF) {
        record_count++;
        if (record_count >= MAX_RECORDS) {
            printf("Maximum record limit reached while loading.\n");
            break;
        }
    }
    
    fclose(file);
    printf("Records loaded from '%s'\n", filename);
}

int main() {
    int choice;
    char date[MAX_LENGTH];
    char item[MAX_LENGTH];
    int quantity;
    float price;

    do {
        printf("\nData Mining Sales Records\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Find Max Sales Item\n");
        printf("4. Calculate Total Revenue\n");
        printf("5. Save Records to File\n");
        printf("6. Load Records from File\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter date (format: YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter item name: ");
                scanf(" %[^\n]", item);
                printf("Enter quantity sold: ");
                scanf("%d", &quantity);
                printf("Enter price per item: ");
                scanf("%f", &price);
                add_record(date, item, quantity, price);
                break;
            case 2:
                display_records();
                break;
            case 3:
                find_max_sales_item();
                break;
            case 4:
                find_total_revenue();
                break;
            case 5:
                save_records_to_file("sales_records.csv");
                break;
            case 6:
                load_records_from_file("sales_records.csv");
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}
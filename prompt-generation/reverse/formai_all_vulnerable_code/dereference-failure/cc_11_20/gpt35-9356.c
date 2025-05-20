//FormAI DATASET v1.0 Category: Data mining ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CUSTOMERS 1000
#define MAX_ITEMS 100

struct customer {
    char name[50];
    int items[MAX_ITEMS];
    int num_items;
};

struct itemset {
    int items[MAX_ITEMS];
    int support;
};

int main() {
    struct customer customers[MAX_CUSTOMERS];
    int num_customers = 0;
    int num_items = 0;
    
    // read in customer data
    FILE *fp = fopen("customers.txt", "r");
    if (fp == NULL) {
        printf("error: could not open customers.txt\n");
        return 1;
    }
    char line[1000];
    while (fgets(line, sizeof(line), fp)) {
        // parse customer name and items
        char *name = strtok(line, ",");
        strcpy(customers[num_customers].name, name);
        char *item = strtok(NULL, ",");
        while (item != NULL) {
            int item_id = atoi(item);
            customers[num_customers].items[customers[num_customers].num_items] = item_id;
            customers[num_customers].num_items++;
            if (item_id > num_items) {
                num_items = item_id;
            }
            item = strtok(NULL, ",");
        }
        num_customers++;
    }
    fclose(fp);
    
    // compute item support
    struct itemset itemsets[num_items];
    for (int i = 0; i < num_items; i++) {
        itemsets[i].support = 0;
        for (int j = 0; j < num_customers; j++) {
            for (int k = 0; k < customers[j].num_items; k++) {
                if (customers[j].items[k] == i+1) {
                    itemsets[i].support++;
                    break;
                }
            }
        }
    }
    
    // print frequent itemsets
    printf("Frequent Itemsets:\n");
    for (int i = 0; i < num_items; i++) {
        if (itemsets[i].support > num_customers/2) {
            printf("{%d} (support = %d)\n", i+1, itemsets[i].support);
        }
    }
    
    return 0;
}
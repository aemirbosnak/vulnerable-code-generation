//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_TRANSACTIONS 100
#define SUPPORT_THRESHOLD 2

typedef struct {
    int itemset[MAX_ITEMS];
    int size;
} Itemset;

typedef struct {
    Itemset* itemsets;
    int count;
} FrequentItemset;

int transactions[MAX_TRANSACTIONS][MAX_ITEMS];
int transaction_count = 0;

void load_transactions(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%d", &transactions[transaction_count][0]) != EOF) {
        int i = 1;
        while (fscanf(file, "%d", &transactions[transaction_count][i]) && 
               transactions[transaction_count][i] != -1) {
            i++;
        }
        transaction_count++;
    }
    fclose(file);
}

int count_support(Itemset* itemset) {
    int count = 0;
    for (int t = 0; t < transaction_count; t++) {
        int match = 1;
        for (int i = 0; i < itemset->size; i++) {
            int item_found = 0;
            for (int j = 0; transactions[t][j] != -1; j++) {
                if (transactions[t][j] == itemset->itemset[i]) {
                    item_found = 1;
                    break;
                }
            }
            if (!item_found) {
                match = 0;
                break;
            }
        }
        if (match) count++;
    }
    return count;
}

FrequentItemset* apriori() {
    FrequentItemset* frequent_itemsets = malloc(sizeof(FrequentItemset));
    frequent_itemsets->itemsets = malloc(sizeof(Itemset) * MAX_ITEMS);
    frequent_itemsets->count = 0;

    for (int i = 1; i < MAX_ITEMS; i++) {
        Itemset itemset;
        itemset.size = 1;
        itemset.itemset[0] = i;

        int support = count_support(&itemset);
        if (support >= SUPPORT_THRESHOLD) {
            frequent_itemsets->itemsets[frequent_itemsets->count++] = itemset;
        }
    }

    return frequent_itemsets;
}

void print_frequent_itemsets(FrequentItemset* frequent_itemsets) {
    for (int i = 0; i < frequent_itemsets->count; i++) {
        printf("{ ");
        for (int j = 0; j < frequent_itemsets->itemsets[i].size; j++) {
            printf("%d ", frequent_itemsets->itemsets[i].itemset[j]);
        }
        printf("} - Support: %d\n", count_support(&frequent_itemsets->itemsets[i]));
    }
}

void free_frequent_itemsets(FrequentItemset* frequent_itemsets) {
    free(frequent_itemsets->itemsets);
    free(frequent_itemsets);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_transactions(argv[1]);

    FrequentItemset* frequent_itemsets = apriori();
    printf("Frequent Itemsets:\n");
    print_frequent_itemsets(frequent_itemsets);

    free_frequent_itemsets(frequent_itemsets);
    return EXIT_SUCCESS;
}
//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A simple data mining example that finds the most frequent item in a list of transactions. */

int main(void) {
    // Define the list of transactions.
    const char *transactions[] = {
        "apple orange banana",
        "apple banana",
        "apple orange banana grape",
        "apple orange banana pear",
        "apple orange banana grape pear"
    };

    // Get the number of transactions.
    int num_transactions = sizeof(transactions) / sizeof(transactions[0]);

    // Create a map to store the frequency of each item.
    char **items = malloc(num_transactions * sizeof(char *));
    for (int i = 0; i < num_transactions; i++) {
        items[i] = malloc(100 * sizeof(char));
    }

    int *frequencies = malloc(num_transactions * sizeof(int));
    for (int i = 0; i < num_transactions; i++) {
        frequencies[i] = 0;
    }

    // Iterate over the transactions and update the frequency of each item.
    for (int i = 0; i < num_transactions; i++) {
        char *transaction = transactions[i];
        char *item;
        while (item = strtok(transaction, " ")) {
            int index = -1;
            for (int j = 0; j < num_transactions; j++) {
                if (strcmp(items[j], item) == 0) {
                    index = j;
                    break;
                }
            }
            if (index == -1) {
                index = num_transactions;
                items[index] = malloc(100 * sizeof(char));
                strcpy(items[index], item);
                frequencies[index] = 0;
            }
            frequencies[index]++;
            transaction = NULL;
        }
    }

    // Find the item with the highest frequency.
    int max_frequency = 0;
    int max_index = -1;
    for (int i = 0; i < num_transactions; i++) {
        if (frequencies[i] > max_frequency) {
            max_frequency = frequencies[i];
            max_index = i;
        }
    }

    // Print the item with the highest frequency.
    printf("The most frequent item is: %s\n", items[max_index]);

    // Free the memory allocated for the map.
    for (int i = 0; i < num_transactions; i++) {
        free(items[i]);
    }
    free(items);
    free(frequencies);

    return 0;
}
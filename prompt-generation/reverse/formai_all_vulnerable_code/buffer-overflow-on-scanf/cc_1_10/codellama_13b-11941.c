//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables
    char *data[100];
    char *query[100];
    int i, j;
    int num_data, num_query;
    int matches[100];

    // Get number of data and query items
    printf("Enter number of data items: ");
    scanf("%d", &num_data);
    printf("Enter number of query items: ");
    scanf("%d", &num_query);

    // Get data items
    for (i = 0; i < num_data; i++) {
        printf("Enter data item %d: ", i + 1);
        scanf("%s", data[i]);
    }

    // Get query items
    for (i = 0; i < num_query; i++) {
        printf("Enter query item %d: ", i + 1);
        scanf("%s", query[i]);
    }

    // Initialize matches array
    for (i = 0; i < num_query; i++) {
        matches[i] = 0;
    }

    // Loop through data items
    for (i = 0; i < num_data; i++) {
        // Loop through query items
        for (j = 0; j < num_query; j++) {
            // Check if data item matches query item
            if (strcmp(data[i], query[j]) == 0) {
                matches[j]++;
            }
        }
    }

    // Print matches
    for (i = 0; i < num_query; i++) {
        printf("Query item %d matches %d data items\n", i + 1, matches[i]);
    }

    return 0;
}
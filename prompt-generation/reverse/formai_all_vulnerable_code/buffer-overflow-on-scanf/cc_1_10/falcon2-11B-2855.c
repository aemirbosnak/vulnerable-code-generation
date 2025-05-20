//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_NUM_ITEMS 1000

int main() {
    // Declare arrays to store items and their frequencies
    int items[MAX_NUM_ITEMS];
    int frequencies[MAX_NUM_ITEMS];

    // Prompt the user to input the number of items
    int numItems;
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    // Prompt the user to input the items and their frequencies
    int i;
    for (i = 0; i < numItems; i++) {
        char item[MAX_LENGTH];
        printf("Enter item %d: ", i+1);
        fgets(item, MAX_LENGTH, stdin);
        items[i] = atoi(item);
        printf("Enter frequency of item %d: ", i+1);
        scanf("%d", &frequencies[i]);
    }

    // Sort the items based on their frequencies
    int j;
    for (i = 0; i < numItems; i++) {
        for (j = i+1; j < numItems; j++) {
            if (frequencies[i] > frequencies[j]) {
                int temp = items[i];
                items[i] = items[j];
                items[j] = temp;
                temp = frequencies[i];
                frequencies[i] = frequencies[j];
                frequencies[j] = temp;
            }
        }
    }

    // Print the sorted items and their frequencies
    printf("Sorted Items and their Frequencies:\n");
    for (i = 0; i < numItems; i++) {
        printf("%d: %d\n", items[i], frequencies[i]);
    }

    return 0;
}
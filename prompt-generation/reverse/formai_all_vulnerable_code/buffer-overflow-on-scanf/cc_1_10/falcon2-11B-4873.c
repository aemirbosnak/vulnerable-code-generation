//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char line[100];
    char* tokens[5];
    int num_bags;

    printf("Welcome to the airport baggage handling system!\n");

    // Get the number of bags
    printf("Enter the number of bags: ");
    scanf("%d", &num_bags);

    // Simulate the arrival of bags
    for (int i = 1; i <= num_bags; i++) {
        printf("Bag %d arrived.\n", i);

        // Get the details of the bag
        printf("Enter the details of the bag: ");
        fgets(line, sizeof(line), stdin);

        // Extract the details from the input line
        int j = 0;
        while (isspace(line[j])) {
            j++;
        }
        tokens[0] = strndup(line + j, strlen(line + j));
        j += strlen(tokens[0]);

        while (isalnum(line[j])) {
            tokens[j - 1] = strndup(line + j, strlen(line + j));
            j += strlen(tokens[j - 1]);
        }
        tokens[j - 1] = strndup(line + j, strlen(line + j));

        // Print the details of the bag
        printf("Bag %d is %s.\n", i, tokens[0]);
    }

    // Simulate the sorting of bags
    for (int i = 1; i <= num_bags; i++) {
        printf("Bag %d is sorted.\n", i);
    }

    // Simulate the loading of bags onto planes
    for (int i = 1; i <= num_bags; i++) {
        printf("Bag %d is loaded onto plane %d.\n", i, rand() % 10 + 1);
    }

    // Simulate the unloading of bags from planes
    for (int i = 1; i <= num_bags; i++) {
        printf("Bag %d is unloaded from plane %d.\n", i, rand() % 10 + 1);
    }

    printf("Simulation complete!\n");

    return 0;
}
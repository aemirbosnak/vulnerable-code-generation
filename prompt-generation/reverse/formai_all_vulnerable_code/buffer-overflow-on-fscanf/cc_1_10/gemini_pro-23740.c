//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// A simple data mining program that analyzes a dataset of customer purchases.

// Define the data structure for a customer purchase.
typedef struct {
    int customer_id;
    int product_id;
    int quantity;
    double price;
} purchase;

// Load the dataset into memory.
purchase* load_dataset(char* filename, int* num_purchases) {
    // Open the file.
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Read the number of purchases.
    fscanf(file, "%d\n", num_purchases);

    // Allocate memory for the purchases.
    purchase* purchases = malloc(*num_purchases * sizeof(purchase));
    if (purchases == NULL) {
        printf("Error allocating memory for purchases\n");
        fclose(file);
        return NULL;
    }

    // Read the purchases.
    for (int i = 0; i < *num_purchases; i++) {
        fscanf(file, "%d %d %d %lf\n", &purchases[i].customer_id, &purchases[i].product_id, &purchases[i].quantity, &purchases[i].price);
    }

    // Close the file.
    fclose(file);

    // Return the purchases.
    return purchases;
}

// Analyze the dataset.
void analyze_dataset(purchase* purchases, int num_purchases) {
    // Find the most popular product.
    int most_popular_product_id = -1;
    int most_popular_product_count = 0;
    for (int i = 0; i < num_purchases; i++) {
        int product_id = purchases[i].product_id;
        int count = 0;
        for (int j = 0; j < num_purchases; j++) {
            if (purchases[j].product_id == product_id) {
                count++;
            }
        }
        if (count > most_popular_product_count) {
            most_popular_product_id = product_id;
            most_popular_product_count = count;
        }
    }

    // Find the average purchase price.
    double average_purchase_price = 0.0;
    for (int i = 0; i < num_purchases; i++) {
        average_purchase_price += purchases[i].price;
    }
    average_purchase_price /= num_purchases;

    // Find the most loyal customer.
    int most_loyal_customer_id = -1;
    int most_loyal_customer_count = 0;
    for (int i = 0; i < num_purchases; i++) {
        int customer_id = purchases[i].customer_id;
        int count = 0;
        for (int j = 0; j < num_purchases; j++) {
            if (purchases[j].customer_id == customer_id) {
                count++;
            }
        }
        if (count > most_loyal_customer_count) {
            most_loyal_customer_id = customer_id;
            most_loyal_customer_count = count;
        }
    }

    // Print the results.
    printf("Most popular product: %d\n", most_popular_product_id);
    printf("Average purchase price: %lf\n", average_purchase_price);
    printf("Most loyal customer: %d\n", most_loyal_customer_id);
}

// Free the memory allocated for the dataset.
void free_dataset(purchase* purchases, int num_purchases) {
    free(purchases);
}

// Main function.
int main(int argc, char* argv[]) {
    // Check the command line arguments.
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Load the dataset.
    int num_purchases;
    purchase* purchases = load_dataset(argv[1], &num_purchases);
    if (purchases == NULL) {
        return 1;
    }

    // Analyze the dataset.
    analyze_dataset(purchases, num_purchases);

    // Free the memory allocated for the dataset.
    free_dataset(purchases, num_purchases);

    return 0;
}
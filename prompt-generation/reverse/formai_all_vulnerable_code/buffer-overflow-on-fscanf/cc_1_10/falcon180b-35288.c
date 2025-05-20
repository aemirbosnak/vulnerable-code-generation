//Falcon-180B DATASET v1.0 Category: Data mining ; Style: modular
#include <stdio.h>

// Define a struct to hold customer data
typedef struct {
    int customer_id;
    char name[50];
    int age;
    float income;
} customer_t;

// Function to read customer data from a file and store in an array of structs
void read_customer_data(customer_t customers[], int num_customers, FILE *fp) {
    int i = 0;
    while (i < num_customers && fscanf(fp, "%d %s %d %f", &customers[i].customer_id, customers[i].name, &customers[i].age, &customers[i].income)!= EOF) {
        i++;
    }
}

// Function to calculate the average income of customers in a given age range
float calculate_average_income(customer_t customers[], int num_customers, int min_age, int max_age) {
    int count = 0;
    float total_income = 0;
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].age >= min_age && customers[i].age <= max_age) {
            total_income += customers[i].income;
            count++;
        }
    }
    return total_income / count;
}

int main() {
    // Open the customer data file
    FILE *fp = fopen("customer_data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read customer data from the file
    customer_t customers[100];
    int num_customers = 0;
    read_customer_data(customers, 100, fp);
    num_customers = fscanf(fp, "%*[^\n]");
    fclose(fp);

    // Calculate the average income of customers aged 25-30
    float avg_income = calculate_average_income(customers, num_customers, 25, 30);
    printf("Average income of customers aged 25-30: $%.2f\n", avg_income);

    return 0;
}
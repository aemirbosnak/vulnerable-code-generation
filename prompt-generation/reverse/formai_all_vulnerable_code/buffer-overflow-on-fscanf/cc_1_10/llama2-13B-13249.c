//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to hold a customer record
struct customer {
    char name[50];
    char address[100];
    int age;
};

// Function to read a customer record from the database
struct customer read_customer(const char* filename) {
    struct customer c;
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return c;
    }
    // Read name
    fscanf(fp, "%49s", c.name);
    // Read address
    fscanf(fp, "%99s", c.address);
    // Read age
    int age;
    fscanf(fp, "%d", &age);
    c.age = age;
    fclose(fp);
    return c;
}

// Function to write a customer record to the database
void write_customer(const char* filename, struct customer c) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(fp, "%49s", c.name);
    fprintf(fp, "%99s", c.address);
    fprintf(fp, "%d", c.age);
    fclose(fp);
}

// Function to display the contents of the database
void display_customers(const char* filename) {
    struct customer c;
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    while (fscanf(fp, "%49s%99s%d", c.name, c.address, &c.age) == 3) {
        printf("%s %s %d\n", c.name, c.address, c.age);
    }
    fclose(fp);
}

int main() {
    // Open the database file in read-write mode
    FILE* db = fopen("customers.dat", "r+");
    if (db == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the first customer record
    struct customer c1 = read_customer("customers.dat");
    printf("First customer: %s %s %d\n", c1.name, c1.address, c1.age);

    // Add a new customer record
    struct customer c2 = {
        .name = "John Doe",
        .address = "123 Main St",
        .age = 35,
    };
    write_customer("customers.dat", c2);

    // Display the contents of the database
    display_customers("customers.dat");

    // Close the database file
    fclose(db);
    return 0;
}
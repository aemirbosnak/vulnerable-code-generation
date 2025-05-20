//Falcon-180B DATASET v1.0 Category: Data mining ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a data record
typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
    float income;
} data_record;

// Function to read data from a CSV file
void read_data(data_record *data, int num_records, char *filename) {
    FILE *fp;
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    for (i = 0; i < num_records; i++) {
        fscanf(fp, "%d,%s,%d,%s,%f", &data[i].id, data[i].name, &data[i].age, data[i].gender, &data[i].income);
    }

    fclose(fp);
}

// Function to perform data mining
void mine_data(data_record *data, int num_records, int attribute, int value) {
    int i, count = 0;

    for (i = 0; i < num_records; i++) {
        if (data[i].age == value) {
            printf("Record %d: %s\n", data[i].id, data[i].name);
            count++;
        }
    }

    if (count == 0) {
        printf("No records found\n");
    }
}

int main() {
    data_record data[100];
    int num_records = 10;
    char filename[50] = "data.csv";
    int attribute;
    int value;

    // Read data from CSV file
    read_data(data, num_records, filename);

    // Perform data mining
    printf("Enter the attribute to mine: ");
    scanf("%d", &attribute);
    printf("Enter the value to mine: ");
    scanf("%d", &value);

    mine_data(data, num_records, attribute, value);

    return 0;
}
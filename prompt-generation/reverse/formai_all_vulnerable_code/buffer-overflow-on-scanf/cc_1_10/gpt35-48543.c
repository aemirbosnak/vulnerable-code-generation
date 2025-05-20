//FormAI DATASET v1.0 Category: Table Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//
// FUNCTION DECLARATIONS
//

void print_table(int table[], int size);
int count_data(int table[], int size);
int sum_data(int table[], int size);
int max_data(int table[], int size);
int min_data(int table[], int size);
void fill_table_random(int table[], int size, int max_value);

//
// MAIN FUNCTION
//

int main()
{
    int size, choice, max_value;

    // Prompt user for table size
    printf("Enter the size of the table: ");
    scanf("%d", &size);

    // Prompt user for maximum value for random number generation
    printf("Enter the maximum value for random number generation: ");
    scanf("%d", &max_value);

    // Create table and fill it with random numbers
    int table[size];
    fill_table_random(table, size, max_value);

    // Print menu and get user choice
    do {
        printf("\nMenu:\n");
        printf("1. Print table\n");
        printf("2. Count data\n");
        printf("3. Sum data\n");
        printf("4. Max data\n");
        printf("5. Min data\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Execute user choice
        switch (choice) {
            case 1:
                print_table(table, size);
                break;
            case 2:
                printf("Data count: %d\n", count_data(table, size));
                break;
            case 3:
                printf("Data sum: %d\n", sum_data(table, size));
                break;
            case 4:
                printf("Max data: %d\n", max_data(table, size));
                break;
            case 5:
                printf("Min data: %d\n", min_data(table, size));
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}

//
// FUNCTION DEFINITIONS
//

void print_table(int table[], int size)
{
    printf("Table: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", table[i]);
    }
    printf("\n");
}

int count_data(int table[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (table[i] != 0) {
            count++;
        }
    }
    return count;
}

int sum_data(int table[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += table[i];
    }
    return sum;
}

int max_data(int table[], int size)
{
    int max = table[0];
    for (int i = 1; i < size; i++) {
        if (table[i] > max) {
            max = table[i];
        }
    }
    return max;
}

int min_data(int table[], int size)
{
    int min = table[0];
    for (int i = 1; i < size; i++) {
        if (table[i] < min) {
            min = table[i];
        }
    }
    return min;
}

void fill_table_random(int table[], int size, int max_value)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        table[i] = rand() % (max_value + 1);
    }
}
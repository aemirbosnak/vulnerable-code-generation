//FormAI DATASET v1.0 Category: Math exercise ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 50

void generate_numbers(int* numbers, int count);
double calculate_mean(int* numbers, int count);
double calculate_standard_deviation(int* numbers, int count);
void print_results(int* numbers, int count, double mean, double stdev);

int main()
{
    int numbers[MAX_NUMBERS];
    int count;
    double mean, stdev;

    printf("Enter the number of elements to generate (1-%d): ", MAX_NUMBERS);
    scanf("%d", &count);

    if (count > MAX_NUMBERS)
    {
        printf("Maximum number of elements is %d.\n", MAX_NUMBERS);
        return 1;
    }

    generate_numbers(numbers, count);

    mean = calculate_mean(numbers, count);
    stdev = calculate_standard_deviation(numbers, count);

    print_results(numbers, count, mean, stdev);

    return 0;
}

void generate_numbers(int* numbers, int count)
{
    int i;

    srand((unsigned int)time(NULL));

    for (i = 0; i < count; i++)
    {
        numbers[i] = rand() % 100 + 1;
    }
}

double calculate_mean(int* numbers, int count)
{
    int i;
    double sum = 0.0;

    for (i = 0; i < count; i++)
    {
        sum += numbers[i];
    }

    return sum / count;
}

double calculate_standard_deviation(int* numbers, int count)
{
    int i;
    double mean = calculate_mean(numbers, count);
    double sum = 0.0;

    for (i = 0; i < count; i++)
    {
        sum += (numbers[i] - mean) * (numbers[i] - mean);
    }

    return sqrt(sum / count);
}

void print_results(int* numbers, int count, double mean, double stdev)
{
    int i;

    printf("\n");
    printf("Generated numbers: ");
    for (i = 0; i < count; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\n");
    printf("Mean: %f\n", mean);
    printf("Standard deviation: %f\n", stdev);
}
//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: detailed
#include <stdio.h>

#define MAX_DAYS 7

void get_data(double arr[], int size);
void show_data(double arr[], int size);
double get_average(double arr[], int size);
double get_max(double arr[], int size);

int main(void)
{
    double steps[MAX_DAYS];
    int i = 0;
    double average, max;

    printf("Enter steps taken for each of the past %d days:\n", MAX_DAYS);

    get_data(steps, MAX_DAYS);

    printf("\nYour steps for the past %d days are:\n", MAX_DAYS);

    show_data(steps, MAX_DAYS);

    average = get_average(steps, MAX_DAYS);

    printf("\nYour average steps for the past %d days are: %.2lf\n", MAX_DAYS, average);

    max = get_max(steps, MAX_DAYS);

    printf("\nYour maximum steps for the past %d days are: %.0lf\n", MAX_DAYS, max);

    return 0;
}

void get_data(double arr[], int size)
{
    int i = 0;

    for (i = 0; i < size; i++)
    {
        printf("Day %d: ", i+1);
        scanf("%lf", &arr[i]);
    }
}

void show_data(double arr[], int size)
{
    int i = 0;

    for (i = 0; i < size; i++)
    {
        printf("Day %d: %.0lf\n", i+1, arr[i]);
    }
}

double get_average(double arr[], int size)
{
    int i = 0;
    double sum = 0.0;

    for (i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum / size;
}

double get_max(double arr[], int size)
{
    int i = 0;
    double max = arr[0];

    for (i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}
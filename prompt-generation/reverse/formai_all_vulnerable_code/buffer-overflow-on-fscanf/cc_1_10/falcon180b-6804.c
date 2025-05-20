//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// Function to compare two strings in a case-insensitive manner
int compare_strings(const char* str1, const char* str2)
{
    while (*str1 && *str2 && tolower(*str1) == tolower(*str2))
    {
        str1++;
        str2++;
    }

    return tolower(*str1) - tolower(*str2);
}

// Function to swap two strings
void swap_strings(char** str1, char** str2)
{
    char* temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

// Function to partition the array based on the pivot element
int partition(char* arr[], int low, int high, char* pivot)
{
    while (low <= high)
    {
        while (compare_strings(arr[low], pivot) < 0)
            low++;

        while (compare_strings(arr[high], pivot) > 0)
            high--;

        if (low <= high)
        {
            swap_strings(&arr[low], &arr[high]);
            low++;
            high--;
        }
    }

    return low;
}

// Function to sort the array using quicksort algorithm
void quicksort(char* arr[], int low, int high)
{
    if (low < high)
    {
        char* pivot = arr[high];
        int pi = partition(arr, low, high, pivot);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Function to read words from the input file and store them in an array
void read_words(FILE* fp, char* arr[], int* count)
{
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(fp, "%s", word)!= EOF)
    {
        if (i >= MAX_WORDS - 1)
        {
            printf("Error: Maximum number of words exceeded.\n");
            exit(1);
        }

        strcpy(arr[i], word);
        i++;
        (*count)++;
    }
}

// Function to write the sorted words to the output file
void write_words(FILE* fp, char* arr[], int count)
{
    for (int i = 0; i < count; i++)
        fprintf(fp, "%s\n", arr[i]);
}

// Main function
int main(int argc, char* argv[])
{
    if (argc!= 3)
    {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL)
    {
        printf("Error: Unable to open output file.\n");
        fclose(input_file);
        return 1;
    }

    int count = 0;
    char* arr[MAX_WORDS];

    read_words(input_file, arr, &count);
    quicksort(arr, 0, count - 1);
    write_words(output_file, arr, count);

    fclose(input_file);
    fclose(output_file);

    return 0;
}
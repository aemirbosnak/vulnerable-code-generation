//Falcon-180B DATASET v1.0 Category: Data mining ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to calculate the frequency of each item in the given dataset
void frequency(int dataset[], int size, int freq[], int item)
{
    int i;
    for(i=0; i<size; i++)
    {
        if(dataset[i] == item)
            freq[i]++;
    }
}

// Function to sort the dataset in ascending order
void sort(int dataset[], int size)
{
    int i, j, temp;
    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-i-1; j++)
        {
            if(dataset[j] > dataset[j+1])
            {
                temp = dataset[j];
                dataset[j] = dataset[j+1];
                dataset[j+1] = temp;
            }
        }
    }
}

// Function to perform the data mining operation
void data_mining(int dataset[], int size, int freq[], int item)
{
    frequency(dataset, size, freq, item);
    sort(dataset, size);
}

// Main function to take user input and call the data_mining function
int main()
{
    int i, n, item, dataset[100], freq[100];
    printf("Enter the number of elements in the dataset: ");
    scanf("%d", &n);
    printf("Enter the elements of the dataset:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &dataset[i]);
    }
    printf("Enter the item whose frequency you want to find: ");
    scanf("%d", &item);
    data_mining(dataset, n, freq, item);
    printf("The frequency of %d in the dataset is: %d\n", item, freq[item-1]);
    return 0;
}
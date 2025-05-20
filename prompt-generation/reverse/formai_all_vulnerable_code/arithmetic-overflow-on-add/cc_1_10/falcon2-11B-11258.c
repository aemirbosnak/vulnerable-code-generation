//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
/*
* Bucket Sort Implementation in C
*
* Author: [Your Name]
* Date: [Today's Date]
* License: [License]
*
* This program implements the Bucket Sort algorithm in C.
* The algorithm sorts a given array of integers by grouping them into buckets
* based on their values, and then sorting the items within each bucket.
* The time complexity of the algorithm is O(n+k), where n is the number of items
* to be sorted and k is the number of buckets.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*
*/

#include <stdio.h>

/*
* Function to swap two elements in an array
*
* Parameters:
* - a: pointer to the first element to swap
* - b: pointer to the second element to swap
*/
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
* Function to implement the Bucket Sort algorithm
*
* Parameters:
* - arr: pointer to the array to be sorted
* - n: number of elements in the array
*/
void bucketSort(int arr[], int n) {
    int buckets[10];  // assuming a maximum of 10 buckets

    // calculate the number of buckets based on the size of the array
    int numBuckets = n / 10;

    // initialize the buckets
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = 0;
    }

    // count the number of elements in each bucket
    for (int i = 0; i < n; i++) {
        buckets[arr[i] / 10]++;
    }

    // sort each bucket
    for (int i = 0; i < numBuckets; i++) {
        if (buckets[i] > 0) {
            for (int j = 0; j < buckets[i]; j++) {
                arr[i * 10 + j] = i * 10;
            }
        }
    }
}

/*
* Function to print an array
*
* Parameters:
* - arr: pointer to the array to be printed
* - n: number of elements in the array
*/
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
* Main function
*/
int main() {
    int arr[] = {12, 5, 9, 2, 7, 6, 3, 1, 8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    // sort the array using the Bucket Sort algorithm
    bucketSort(arr, n);

    printf("\nSorted array: ");
    printArray(arr, n);

    return 0;
}
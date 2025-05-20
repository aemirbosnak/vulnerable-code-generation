//FormAI DATASET v1.0 Category: Memory Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checkEquality(int arr[], int size) {  // Function to check if all elements in array are equal
    int i;
    for(i=1; i<size; i++) {
        if(arr[i] != arr[0]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // Initializations
    int size, i, j, count=0;
    printf("Enter the size of the array:");
    scanf("%d", &size);
    int arr[size], revealed[size];
    srand(time(0));  // Initializing random seed
    
    for(i=0; i<size; i++) {
        int num = rand() % 100;  // Generating random numbers for array
        int flag = 0;
        for(j=0; j<i; j++) {
            if(arr[j] == num) {  // Checking if the number is already present in array
                flag = 1;
                break;
            }
        }
        if(flag == 1) {  // If number is already in array, decrement the counter
            i--;
        } else {  // Otherwise, assign the number to array and set revealed to 0
            arr[i] = num;
            revealed[i] = 0;
        }
    }
    
    while(!checkEquality(revealed, size)) {  // Loop until all elements are revealed
        printf("Enter the index of the array to unveil:");
        scanf("%d", &i);
        if(revealed[i] == 1) {  // If element is already revealed, show the message
            printf("Element is already revealed. Try again.\n");
            continue;
        }
        printf("Value at index %d is %d\n", i, arr[i]);
        revealed[i] = 1;  // Change the value of revealed to 1
        printf("Enter the index of the array to unveil:");
        scanf("%d", &j);
        if(revealed[j] == 1) {  // Same as above
            printf("Element is already revealed. Try again.\n");
            revealed[i] = 0;  // Reverting back the value of revealed to 0, as it was 1 before
            continue;
        }
        printf("Value at index %d is %d\n", j, arr[j]);
        revealed[j] = 1;  // Same as above
        if(arr[i] == arr[j]) {  // If both numbers are same
            printf("You found a match!\n");
            count++;  // Increase the counter
        } else {
            revealed[i] = 0;  // Revert back revealed[i] to 0
            revealed[j] = 0;  // Same as above
            printf("Not a match :(\n");
        }
    }
    
    printf("You found all matches! Total moves taken: %d", count);
    return 0;
}
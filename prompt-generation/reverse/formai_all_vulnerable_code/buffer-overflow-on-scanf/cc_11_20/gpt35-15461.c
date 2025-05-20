//FormAI DATASET v1.0 Category: Memory Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int arr[SIZE];
    int pos1, pos2, temp, i, j;
    
    srand(time(NULL));
    
    // Initialize the array with unique random numbers
    for(i=0; i<SIZE; i++) {
        arr[i] = rand() % (SIZE*2);
        for(j=0; j<i; j++) {
            if(arr[i] == arr[j]) {
                i--;
                break;
            }
        }
    }
    
    // Shuffle the array
    for(i=0; i<SIZE; i++) {
        pos1 = rand() % SIZE;
        pos2 = rand() % SIZE;
        temp = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = temp;
    }
    
    // Play the game
    int first, second, count=0;
    int found[SIZE] = {0};
    while(count < SIZE) {
        printf("Enter two indices between 0 and %d to reveal their values: ", SIZE-1);
        scanf("%d %d", &first, &second);
        if(first >= 0 && first < SIZE && second >= 0 && second < SIZE && first != second) {
            // Check if the indices have already been matched
            if(found[first] || found[second]) {
                printf("One or both of the indices have already been matched. Please try again.\n");
            }
            else {
                printf("The values at indices %d and %d are %d and %d.\n", first, second, arr[first], arr[second]);
                if(arr[first] == arr[second]) {
                    printf("MATCHED!\n");
                    found[first] = 1;
                    found[second] = 1;
                    count += 2;
                }
            }
        }
        else {
            printf("Invalid input. Please enter two distinct indices between 0 and %d.\n", SIZE-1);
        }
    }
    
    printf("Congratulations! You have matched all the numbers.\n");
    
    return 0;
}
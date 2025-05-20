//FormAI DATASET v1.0 Category: Memory Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void shuffle(int arr[], int n);
void print(int arr[], int n);
void play(int arr[], int n);

int main()
{
    int arr[MAX];
    int n = 0;
    
    printf("Enter the number of elements in the memory game (must be even and less than or equal to %d): ", MAX);
    scanf("%d", &n);
    
    if(n % 2 != 0 || n > MAX) {
        printf("Invalid input.\n");
        return 0;
    }
    
    // initialize array with alternating positive and negative numbers
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            arr[i] = (i + 1) / 2;
        } else {
            arr[i] = -((i + 1) / 2);
        }
    }
    
    shuffle(arr, n);
    play(arr, n);
    
    return 0;
}

// shuffles array in place
void shuffle(int arr[], int n)
{
    srand(time(NULL));
    for(int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// prints array
void print(int arr[], int n)
{
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// plays memory game
void play(int arr[], int n)
{
    int visible[n]; // indicates which elements are visible to player
    for(int i = 0; i < n; i++) {
        visible[i] = 0;
    }
    
    int score = 0;
    int guesses = 0;
    
    while(score < n / 2) {
        print(visible, n); // show player which elements are visible
        
        int index1, index2;
        do { // prompt player to choose two elements until valid selection is made
            printf("Enter first index to flip: ");
            scanf("%d", &index1);
            printf("Enter second index to flip: ");
            scanf("%d", &index2);
        } while(index1 < 0 || index1 >= n || index2 < 0 || index2 >= n || index1 == index2 || visible[index1] || visible[index2]);
        
        printf("Flipping cards %d and %d...\n", index1, index2);
        printf("%d %d\n", arr[index1], arr[index2]);
        guesses++;
        
        if(arr[index1] == arr[index2]) {
            printf("Match found!\n");
            visible[index1] = 1;
            visible[index2] = 1;
            score++;
        } else {
            printf("No match.\n");
        }
    }
    
    printf("Congratulations! You won after %d guesses.\n", guesses);
}
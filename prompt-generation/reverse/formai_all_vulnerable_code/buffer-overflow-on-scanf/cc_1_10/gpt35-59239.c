//FormAI DATASET v1.0 Category: Memory Game ; Style: Cryptic
#include<stdio.h>  
#include<stdlib.h>  
#include<time.h>  

// Cryptic memory game

void shuffle(int arr[], int n) {  
    // Uses random swaps to shuffle the array  
    srand(time(NULL));  
    for (int i = n - 1; i > 0; i--) {  
        int j = rand() % (i + 1);  
        int temp = arr[i];  
        arr[i] = arr[j];  
        arr[j] = temp;  
    }  
}  

int main(){  
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};  
    shuffle(arr, 10); // Randomly shuffle the array  

    printf("Cryptic Memory Game Begins...\n\n");  
    printf("Remember the sequence of numbers and type it in reverse order.\n");  

    for (int i = 0; i < 10; i++) {  
        printf("%d ", arr[i]);  
        if (i == 4) {  
            printf("\n"); // Separates the array into two lines for clarity  
        }  
    }  

    printf("\n\nType the sequence in reverse order: ");  
    int input[10];  
    for (int i = 0; i < 10; i++) {  
        scanf("%d", &input[i]);  
    }  

    int correct = 1; // Default value is true  
    for (int i = 0; i < 10; i++) {  
        if (arr[i] != input[9 - i]) {  
            correct = 0; // If any element is incorrect, change the value to false  
        }  
    }  

    if (correct) {  
        printf("\nCorrect! You have a great memory!\n");  
    } else {  
        printf("\nIncorrect Try again!!\nThe correct sequence was: ");  
        for (int i = 0; i < 10; i++) {  
            printf("%d ", arr[i]);  
            if (i == 4) {  
                printf("\n");  
            }  
        }  
        printf("\n");  
    }  

    return 0;  
}
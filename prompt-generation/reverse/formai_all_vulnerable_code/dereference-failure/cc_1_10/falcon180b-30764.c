//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shuffle_array(int arr[], int n) {
    for(int i=0; i<n; i++) {
        int j = rand()%n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void print_array(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int check_match(int arr[], int n, int i, int j) {
    if(arr[i] == arr[j]) {
        return 1;
    }
    return 0;
}

void recursive_memory_game(int arr[], int n, int turns) {
    int player_turns = 0;
    while(player_turns < turns) {
        int row, col;
        printf("Enter row and column: ");
        scanf("%d%d", &row, &col);
        if(row >= 0 && row < n && col >= 0 && col < n) {
            if(player_turns == 0) {
                int card1 = arr[row*n+col];
                int card2 = arr[(row*n+col)+n];
                if(check_match(arr, n, row*n+col, (row*n+col)+n)) {
                    printf("Match found!\n");
                    player_turns++;
                }
                else {
                    printf("Mismatch.\n");
                }
            }
            else {
                if(check_match(arr, n, row*n+col, (row*n+col)+n)) {
                    printf("Match found!\n");
                    player_turns++;
                }
                else {
                    printf("Mismatch.\n");
                }
            }
        }
        else {
            printf("Invalid input.\n");
        }
    }
}

int main() {
    int n;
    printf("Enter number of cards: ");
    scanf("%d", &n);
    int arr[n*2];
    for(int i=0; i<n*2; i++) {
        arr[i] = i+1;
    }
    shuffle_array(arr, n*2);
    printf("Original array:\n");
    print_array(arr, n*2);
    int turns;
    printf("Enter number of turns: ");
    scanf("%d", &turns);
    recursive_memory_game(arr, n, turns);
    printf("Final array:\n");
    print_array(arr, n*2);
    return 0;
}
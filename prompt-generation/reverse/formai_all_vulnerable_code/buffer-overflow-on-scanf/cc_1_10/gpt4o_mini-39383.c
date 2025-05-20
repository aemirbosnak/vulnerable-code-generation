//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100

void surreal_sort(int arr[], int n);
void display_array(int arr[], int n);
void whisper_to_the_numbers(int arr[], int n);
void dance_of_reverse(int arr[], int start, int end);
void dreams_of_five(int arr[], int n);

int main() {
    int numbers[MAX_NUMBERS];
    int num_count;

    // Greet the user with a surreal message
    printf("Welcome to the Dreamscape Sorting Machine!\n\n");
    printf("How many numbers do you wish to conjure from the ether (max %d)? ", MAX_NUMBERS);
    scanf("%d", &num_count);

    if (num_count > MAX_NUMBERS || num_count < 1) {
        printf("A whirlwind of impossibilities has ensued! Please enter a valid number of dreams.\n");
        return EXIT_FAILURE;
    }

    // Filling the array with numbers drawn from the void
    srand(time(NULL));
    for (int i = 0; i < num_count; i++) {
        numbers[i] = rand() % 1000; // Between 0 to 999, conjured from chaos
    }

    // Display the original array
    printf("\nBehold the unyielding chaos of numbers:\n");
    display_array(numbers, num_count);
    
    // Whispers to the numbers, stirring the order within
    whisper_to_the_numbers(numbers, num_count);

    // Sorting the numbers in a surreal dance
    surreal_sort(numbers, num_count);
    
    // Dreaming a final version of the array
    printf("\nAfter the surreal sorting ritual, the numbers have transformed:\n");
    display_array(numbers, num_count);

    return EXIT_SUCCESS;
}

void surreal_sort(int arr[], int n) {
    int swapped, temp;
    do {
        swapped = 0;
        for (int i = 0; i < n - 1; i++) {
            // If the current number chooses to trade places with the next
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
                printf("Numbers have danced: %d <-> %d\n", arr[i], arr[i + 1]);
            }
        }
        // As we ascend the spiral staircase of dreams, the last number settles
        n--;
    } while (swapped);
}

void display_array(int arr[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void whisper_to_the_numbers(int arr[], int n) {
    printf("\nWhispers waft through the air as the numbers listen...\n");
    for (int i = 0; i < n; i++) {
        printf("Shhh... %d is contemplating its fate.\n", arr[i]);
    }
}

void dance_of_reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void dreams_of_five(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 5 == 0) {
            printf("Dreamy number spotted: %d\n", arr[i]);
        }
    }
}
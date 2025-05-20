//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: puzzling
#include <stdio.h>

void welcome_message() {
    printf("Welcome to the Enigmatic Searching Chamber!\n");
    printf("Within these lines of code lies a treasure.\n");
    printf("Your quest is to find the mystical number hidden in the abyss of the array!\n");
}

void generate_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i * 7; // Filling the array with multiples of 7
    }
}

void display_array(int arr[], int size) {
    printf("Behold the array:\n");
    for (int i = 0; i < size; i++) {
        printf("[%d]: %d  ", i, arr[i]);
    }
    printf("\n");
}

int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

void ask_for_input(int *target) {
    printf("Enter the mystical number you seek: ");
    scanf("%d", target);
}

void unveil_result(int index, int target) {
    if (index != -1) {
        printf("Congratulations, brave seeker! You've found the number %d at index %d!\n", target, index);
    } else {
        printf("Alas! The number %d is not within these realms!\n", target);
    }
}

int main() {
    welcome_message();
    
    const int SIZE = 20;
    int mystic_array[SIZE];
    
    generate_array(mystic_array, SIZE);
    display_array(mystic_array, SIZE);
    
    int target_number;
    ask_for_input(&target_number);
    
    int found_index = linear_search(mystic_array, SIZE, target_number);
    unveil_result(found_index, target_number);
    
    printf("Thank you for visiting the Enigmatic Searching Chamber!\n");
    printf("May your journeys be filled with adventure!\n");
    
    return 0;
}
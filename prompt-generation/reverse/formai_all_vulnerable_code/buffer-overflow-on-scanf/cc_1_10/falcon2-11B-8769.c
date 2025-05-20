//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, num_of_elements = 0, correct = 0, incorrect = 0, input, original[100];
    
    printf("How many elements would you like to remember?\n");
    scanf("%d", &num_of_elements);
    
    printf("Enter the elements you would like to remember:\n");
    
    for(i = 0; i < num_of_elements; i++) {
        scanf("%d", &original[i]);
    }
    
    printf("Here are the elements you need to remember:\n");
    
    for(i = 0; i < num_of_elements; i++) {
        printf("%d ", original[i]);
    }
    
    printf("\nNow, please enter the elements you remember:\n");
    
    for(i = 0; i < num_of_elements; i++) {
        scanf("%d", &input);
        
        if(input == original[i]) {
            correct++;
        } else {
            incorrect++;
        }
    }
    
    printf("\nYou got %d correct and %d incorrect guesses.\n", correct, incorrect);
    
    printf("Would you like to play again? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    
    if(choice == 'y') {
        printf("\nAlright, let's start again!\n");
        
        for(i = 0; i < num_of_elements; i++) {
            original[i] = rand() % 100;
        }
        
        printf("Here are the elements you need to remember:\n");
        
        for(i = 0; i < num_of_elements; i++) {
            printf("%d ", original[i]);
        }
    } else {
        printf("\nAlright, goodbye!\n");
    }
    
    return 0;
}
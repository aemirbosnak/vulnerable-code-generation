//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// function to shuffle an array of integers
void shuffle(int arr[], int n) {
    int i, j, temp;

    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// main function
int main() {
    int num, seq[10], i;

    // ask user to input sequence
    printf("Enter sequence of numbers: ");
    scanf("%d", &num);

    // initialize sequence with input
    for (i = 0; i < num; i++) {
        scanf("%d", &seq[i]);
    }

    // shuffle sequence
    shuffle(seq, num);

    // ask user to input sequence
    printf("Enter sequence of numbers: ");
    scanf("%d", &num);

    // check if user input is correct
    for (i = 0; i < num; i++) {
        if (seq[i]!= num) {
            printf("Sorry, incorrect sequence.\n");
            break;
        }
    }

    // congratulate user if input is correct
    if (i == num) {
        printf("Congratulations, you got it right!\n");
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &num);
        if (num == 'y') {
            main();
        }
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_card(int card[5][5]) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i, j, k, num, card[5][5];
    char ch;
    srand(time(NULL));

    // Initialize the card with random numbers from 1 to 75
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            num = rand() % 75 + 1;
            card[i][j] = num;
            printf("%d ", num);
        }
        printf("\n");
    }

    // Get the winning pattern from the user
    printf("Enter the winning pattern (e.g. 1,2,3,4,5): ");
    scanf("%s", &ch);

    // Convert the winning pattern to an integer array
    int win_pattern[5];
    k = 0;
    while (ch!= '\0') {
        if (ch >= '0' && ch <= '9') {
            win_pattern[k++] = ch - '0';
        }
        ch = getchar();
    }

    // Check if the user's card matches the winning pattern
    int match_count = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (card[i][j] == win_pattern[k]) {
                match_count++;
                k++;
            }
        }
    }

    // Print the user's card and the winning pattern
    printf("\nYour card:\n");
    print_card(card);
    printf("\nWinning pattern: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", win_pattern[i]);
    }
    printf("\n");

    // Check if the user has won
    if (match_count == 5) {
        printf("\nCongratulations! You won!\n");
    } else {
        printf("\nSorry, you didn't win this time.\n");
    }

    return 0;
}
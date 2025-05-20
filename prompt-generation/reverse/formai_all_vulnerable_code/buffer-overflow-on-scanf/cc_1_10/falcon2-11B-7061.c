//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to generate random bingo numbers
void generate_bingo_numbers(int num_of_numbers, int min_num, int max_num) {
    for (int i = 0; i < num_of_numbers; i++) {
        srand(time(0));
        int random_num = rand() % (max_num - min_num + 1) + min_num;
        printf("%d ", random_num);
    }
    printf("\n");
}

// Function to check if a bingo has been achieved
bool check_bingo(int bingo_numbers[][5], int num_of_bingo_numbers) {
    bool has_bingo = false;
    for (int i = 0; i < num_of_bingo_numbers; i++) {
        bool bingo = true;
        for (int j = 0; j < 5; j++) {
            if (bingo_numbers[i][j]!= bingo_numbers[i][j] + 1) {
                bingo = false;
                break;
            }
        }
        if (bingo) {
            has_bingo = true;
            break;
        }
    }
    return has_bingo;
}

int main() {
    srand(time(0));
    int num_of_bingo_numbers = 5;
    int min_num = 1;
    int max_num = 25;
    int bingo_numbers[num_of_bingo_numbers][5];

    printf("Welcome to the C Bingo Simulator!\n");
    printf("Please enter the number of bingo numbers to generate:\n");
    int num_of_numbers;
    scanf("%d", &num_of_numbers);

    generate_bingo_numbers(num_of_numbers, min_num, max_num);
    printf("Bingo numbers:\n");
    for (int i = 0; i < num_of_bingo_numbers; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", bingo_numbers[i][j]);
        }
        printf("\n");
    }

    printf("\nPlease enter the bingo numbers you have:\n");
    for (int i = 0; i < num_of_bingo_numbers; i++) {
        for (int j = 0; j < 5; j++) {
            int bingo_num;
            scanf("%d", &bingo_num);
            bingo_numbers[i][j] = bingo_num;
        }
    }

    if (check_bingo(bingo_numbers, num_of_bingo_numbers)) {
        printf("Congratulations! You have achieved a bingo!\n");
    } else {
        printf("Sorry, you haven't achieved a bingo yet.\n");
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Table Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 10

void init_table(int table[TABLE_SIZE]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = 0;
    }
}

void print_table(int table[TABLE_SIZE]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d ", table[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int table[TABLE_SIZE];
    init_table(table);

    int player_score = 0;
    int computer_score = 0;

    while (player_score < 10 || computer_score < 10) {
        print_table(table);

        int choice;
        printf("Enter your choice (1-%d): ", TABLE_SIZE - 1);
        scanf("%d", &choice);

        if (choice < 1 || choice > TABLE_SIZE - 1) {
            printf("Invalid choice.\n");
            continue;
        }

        if (table[choice - 1]!= 0) {
            printf("Cell already chosen.\n");
            continue;
        }

        table[choice - 1] = (rand() % 2)? 1 : -1;

        if (table[choice - 1] == 1) {
            player_score++;
        } else {
            computer_score++;
        }

        if (player_score >= 10 || computer_score >= 10) {
            break;
        }
    }

    printf("Final scores:\n");
    printf("Player: %d\n", player_score);
    printf("Computer: %d\n", computer_score);

    return 0;
}